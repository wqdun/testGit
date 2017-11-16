import java.util.*;

public class Test {


    private int getDimensionCode(double x, double width, int nBlockNum) {
        int nCode = 0;
        if (x < 0) {
            nCode = (nBlockNum - 1) + (int) (x / width); // 加负数等于减
        } else {
            nCode = (int) (x / width);
        }
        return nCode;
    }

    public static int[] getXY(Integer id) {
        String binaryStr = Integer.toBinaryString(id);
        int length = binaryStr.length();
        if (length % 2 != 0) {
            binaryStr = "0" + binaryStr;
        }
        StringBuffer binaryXStr = new StringBuffer();// 列
        StringBuffer binaryYStr = new StringBuffer();// 行

        System.out.println(binaryStr);

        System.out.println(binaryStr.substring(3, 8));
        System.out.println("Hello1");

        for (int i = 0; i < binaryStr.length(); i = i + 2) {
            binaryYStr.append(binaryStr.substring(i, i + 1));
            if (binaryStr.length() > i + 1) {
                binaryXStr.append(binaryStr.substring(i + 1, i + 2));
            }
        }
        System.out.println(binaryXStr);
        System.out.println(binaryYStr);
        System.out.println("Hello");
        System.out.println(Integer.valueOf("10101", 2));

        return new int[] { Integer.valueOf(binaryXStr.toString(), 2),
                Integer.valueOf(binaryYStr.toString(), 2) };
    }

    public static void main(String[] args) {
        int a = (int)Math.pow(2, 3);
        System.out.println(a);
        int rowNum = 12456;
        int s = Integer.toBinaryString(rowNum).length();
        System.out.println(Integer.toBinaryString(rowNum));
        System.out.println(s);
        Test tst = new Test();
        System.out.println(getXY(26327323)[0]);
        System.out.println(getXY(26327323)[1]);

    }
}