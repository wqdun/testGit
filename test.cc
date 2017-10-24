#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <errno.h>

using namespace std;

typedef struct point {
    double x;
    double y;
    double z;
    double intensity;
    double daySecond;
} point_t;


void WriteBINFile_C()
{
    FILE* fp = fopen("c.bin","wb");
    if(!fp) {
        cout << "open failed with errno:" << errno << endl;
    }
    
    point_t p1 = {1, 2, 3, 4, 5};
    point_t p2 = {2, 3, 4, 5, 6};
    point_t ps[100] = {p1, p2};
    
    string str = "-7.231225:1.987737:-2.009471:13.000000:22144.888645\n";
    const char *cstr = str.c_str();
    int len = strlen(cstr);
    cout << len << endl;

    fwrite(cstr, 1, len, fp);
    fwrite(cstr, 1, len, fp);

    fclose(fp);
}

void ReadBINFile_C()
{
    // FILE* fp = fopen("/home/dun/.ros/19_01_53.lidar","rb");
    FILE* fp = fopen("c.bin","rb");
    char str[5500000];

    // for(int i = 0; i < 1000; i++)
    // {
    //     for(int j = 0; j < 1000; j++)
    //     {
            fread(str, 2, 2, fp);
    //     }
    // }
    // str[5500000] = '\0';
    cout << strlen(str) << endl;
    cout << str[2] << (int)str[5] << endl;
    fclose(fp);
}


// bool DealFile(string fileName) //随便写个函数说明
// {
//     FILE *file;
// unsigned long int fileSize ,pos;
// int readLen ;

// //MAX_BUFFER_LEN 在头文件里定义，这里能够保证数据不丢失，也不至于内存逸出
// char *buffer = new char[MAX_BUFFER_LEN];
// file = fopen(fileName.c_str(),"r+b");
// if(file == NULL) return false;
// fseek(file,0,2);
// fileSize = ftell(file); //取得文件的大小
// fseek(file,0,0);
// do{
// readLen = fread(buffer,sizeof(char),MAX_BUFFER_LEN,file);
// if(readLen > 0)
// {
// pos += readLen;
// //对读取的文件做处理
// }
// }while(pos < fileSize); //循环读取文件
// delete[] buffer;
// fclose(file); //释放资源
// return true;

// }


int main()
{
    unsigned long int start, end;

    sleep(5);
    cout << "1000 ms" << endl;

    // start = GetTickCount();
    // WriteBINFile_C();
    // // end = GetTickCount();
    // printf("C语言写二进制文件操作运行时间为：%ld ms\n", end - start);
    // ReadBINFile_C();
    // DealFile();
    // size_t tmp = 160000;
    // cout << endl;
    // cout << (tmp >> 8) << endl;
    // cout << tmp / 256 << endl;

}
