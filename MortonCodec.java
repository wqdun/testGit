package com.navinfo.xd.utils;

import java.util.ArrayList;
import java.util.List;

public class MortonCodec {
	private static final int LEVEL_MIN = 0;
	private static final int LEVEL_MAX = 26;

	/**
	 * 根据经度/纬度计算莫顿码
	 *
	 * @param dLon
	 *            经度
	 * @param dLat
	 *            纬度
	 * @param level
	 *            剖分等级
	 * @return 莫顿码
	 */
	public long getMortonFromLonLat(double dLon, double dLat, int level) {
		if ((level < LEVEL_MIN) || (level > LEVEL_MAX)) {
			return -1;
		}
		long morton = 0;
		int col = (int) Math.pow(2, level); // 当前level等级下，一共有多少列
		int row = col; // 当前level等级下，一共有多少行
		double width = 180.0 / col; // 当前level等级下，一个mesh的大小
		// 行数
		int rowNum = getDimensionCode(dLat, width, col);
		// 列数
		int colNum = getDimensionCode(dLon, width, row);
		morton = interleave(rowNum, colNum);
		// 0级最高位
		if (dLon < 0) {
			morton |= 1 << (2 * level);
		}
		if (dLat < 0) {
			morton |= 1 << (2 * level - 1);
		}
		return morton;
	}

	/**
	 * 根据矩形范围计算其覆盖的所有Mesh的莫顿码
	 *
	 * @param rect
	 *            矩形范围
	 * @param level
	 *            剖分等级
	 * @return 莫顿码集合
	 */
	public ArrayList<Long> getMortonFromRect(BoundingBox rect, int level) {
		if ((level < LEVEL_MIN) || (level > LEVEL_MAX)) {
			return null;
		}
		int col = (int) Math.pow(2, level); // 当前level等级下，一共有多少列
		int row = col * 2; // 当前level等级下，一共有多少行
		double width = 180.0 / col; // 当前level等级下，一个mesh的大小
		int colNumStart = getDimensionCode(rect.minX, width, row);
		int colNumEnd = getDimensionCode(rect.maxX, width, row);
		int rowNumStart = getDimensionCode(rect.minY, width, col);
		int rowNumEnd = getDimensionCode(rect.maxY, width, col);
		ArrayList<Long> mortonList = new ArrayList<Long>();
		for (int i = rowNumStart; i < rowNumEnd; i++) {
			for (int j = colNumStart; j < colNumEnd; j++) {
				Long morton = interleave(i, j);
				// 0级最高位
				if (i >= col) { // row / 2
					morton |= 1 << (2 * level);
				}
				if (j >= row) {
					morton |= 1 << (2 * level - 1);
				}
				mortonList.add(morton);
			}
		}
		return mortonList;
	}

	/**
	 * 根据莫顿码计算Mesh边界
	 *
	 * @param morton
	 *            莫顿码
	 * @param level
	 *            剖分等级
	 * @return 矩形范围
	 */
	public BoundingBox getMortonBound(int morton, int level) {
		if ((level < LEVEL_MIN) || (level > LEVEL_MAX)) {
			return null;
		}
		// 0级
		if (level == 0) {
			if (morton == 0) {
				return new BoundingBox(0.0, -90.0, 180.0, 90.0);
			} else if (morton == 1) {
				return new BoundingBox(-180.0, -90.0, 0.0, 90.0);
			} else {
				return null;
			}
		}
		// de-interleaving
		RCPair pair = deInterleave(morton, level);
		int rowNum = pair.rowNum;
		int colNum = pair.colNum;
		// 根据行列求坐标
		int col = (int) Math.pow(2, level); // 当前level等级下，一共有多少列
		int row = col * 2; // 当前level等级下，一共有多少行
		double width = 180.0 / col; // 当前level等级下，一个mesh的大小
		double minX = 0;
		double maxX = 0;
		if (colNum < (row / 2)) {
			minX = width * colNum;
			maxX = width * (colNum + 1);
		} else {
			minX = -width * (row - colNum - 1);
			maxX = -width * (row - colNum);
		}
		double minY = 0;
		double maxY = 0;
		if (rowNum < (col / 2)) {
			minY = width * rowNum;
			maxY = width * (rowNum + 1);
		} else {
			minY = -width * (rowNum - col - 1);
			maxY = -width * (rowNum - col);
		}
		return new BoundingBox(minX, minY, maxX, maxY);
	}

	private class RCPair {
		public final int rowNum;
		public final int colNum;

		public RCPair(int row, int column) {
			this.rowNum = row;
			this.colNum = column;
		}
	}

	/**
	 * 根据经度/纬度计算行/列值
	 *
	 * @param x
	 *            经度/纬度
	 * @param width
	 *            mesh大小（单位：度）
	 * @param nBlockNum
	 *            经度/纬度方向上的mesh数量
	 * @return 行/列值
	 */
	private int getDimensionCode(double x, double width, int nBlockNum) {
		int nCode = 0;
		if (x < 0) {
			nCode = (nBlockNum - 1) + (int) (x / width); // 加负数等于减
		} else {
			nCode = (int) (x / width);
		}
		return nCode;
	}

	/**
	 * 根据行列值交织编码
	 *
	 * @param dLon
	 *            经度
	 * @param dLat
	 *            纬度
	 * @param level
	 *            剖分等级
	 * @return 莫顿码
	 */
	public Long interleave(int rowNum, int colNum) {
		long morton = 0;
		int s = Integer.toBinaryString(rowNum).length();
		int e = Integer.toBinaryString(colNum).length();
		int size = s > e ? s : e;
		for (int i = 0; i < size; i++) {
			morton |= (colNum & (1 << i)) << i | (rowNum & (1 << i)) << (i + 1);
		}
		return morton;
	}

	/**
	 * 根据莫顿码去交织解码
	 *
	 * @param morton
	 *            莫顿码
	 * @param level
	 *            剖分等级
	 * @return 行列值
	 */
	private RCPair deInterleave(long morton, int level) {
		int rowNum = 0;
		int colNum = 0;
		for (int i = 0; i <= level; i++) {
			int nBit = i;
			int nDoubleBit = nBit * 2;
			int levelCode = (int) (morton & (3 << nDoubleBit)) >> nDoubleBit; // 0x11
			rowNum |= ((levelCode & 2) >> 1) << nBit; // 0x10
			colNum |= (levelCode & 1) << nBit; // 0x01
		}
		return new RCPair(rowNum, colNum);
	}


	public static List<Integer> getTileNumList(int id, int level) {// 包含本身
		// 获得最大行列号
		int maxY = (int) Math.pow(2, level);
		int maxX = (int) Math.pow(2, level + 1);
		List<Integer> listTileNum = new ArrayList<Integer>();
		int[] res = getXY(id);
		for (int i = -1; i < 2; i++) {// x
			for (int j = -1; j < 2; j++) {// y
				if (res[0] + i >= 0 && res[1] + j >= 0 && res[0] + i < maxX
						&& res[1] + j < maxY) {
					int tileNum = getTileNum(new int[] { res[0] + i, res[1] + j });
					listTileNum.add(tileNum);
				}
			}
		}
		return listTileNum;
	}

	/***************************
	 * 通过行列号获得格网ID
	 *
	 * @param xy
	 * @return
	 */
	public static int getTileNum(int[] xy) {
		String binaryStrX = Integer.toBinaryString(xy[0]);
		String binaryStrY = Integer.toBinaryString(xy[1]);
		StringBuffer binaryStr = new StringBuffer();
		for (int i = 0; i < binaryStrX.length() || i < binaryStrY.length(); i++) {
			if (i >= binaryStrX.length()) {
				binaryStr.append("0");
			} else {
				binaryStr.append(binaryStrX.substring(binaryStrX.length() - i
						- 1, binaryStrX.length() - i));
			}
			if (i >= binaryStrY.length()) {
				binaryStr.append("0");
			} else {
				binaryStr.append(binaryStrY.substring(binaryStrY.length() - i
						- 1, binaryStrY.length() - i));
			}
		}
		return Integer.valueOf(binaryStr.reverse().toString(), 2);
	}

	/****************************
	 * 通过格网ID获得行列号
	 *
	 * @param id
	 * @return
	 */
	public static int[] getXY(Integer id) {
		String binaryStr = Integer.toBinaryString(id);
		int length = binaryStr.length();
		if (length % 2 != 0) {
			binaryStr = "0" + binaryStr;
		}
		StringBuffer binaryXStr = new StringBuffer();// 列
		StringBuffer binaryYStr = new StringBuffer();// 行
		for (int i = 0; i < binaryStr.length(); i = i + 2) {
			binaryYStr.append(binaryStr.substring(i, i + 1));
			if (binaryStr.length() > i + 1) {
				binaryXStr.append(binaryStr.substring(i + 1, i + 2));
			}
		}
		return new int[] { Integer.valueOf(binaryXStr.toString(), 2),
				Integer.valueOf(binaryYStr.toString(), 2) };
	}


	public static void main(String[] args) {
		MortonCodec mc = new MortonCodec();
		long cruuentMesh =mc.getMortonFromLonLat(120,50,13);
		System.out.println(cruuentMesh);

		List<Integer> tiles = TileUtils.getTileNumList((int)cruuentMesh, 13);
		for (int i = 0; i < tiles.size() ; i++) {
			System.out.println(tiles.get(i));

		}
	}
}
