#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct student
{
   char name[20];
   int num;
   int age;
   char sex;
};
int main( )
{
   student stud[3]={"Li",1001,18,'f',"Fun",1002,19,'m',"Wang",1004,17,'f'};
   fstream iofile("stud.dat",ios::in|ios::out|ios::binary);
   if(!iofile)
   {
      cout<<"open error!"<<endl;
      // abort( );//退出程序
      exit(1);
   }
    // for(int i=0;i<3;i++)
    //     iofile.write((char*)&stud[i],sizeof(stud[i]));
    iofile.write((char*)&stud[0],sizeof(stud));

    // student stud[3];
    iofile.read((char*)&stud[0],sizeof(stud));

    iofile.close( );
       for(int i=0;i<3;i++)
   {
      cout<<"NO."<<i+1<<endl;
      cout<<"name:"<<stud[i].name<<endl;
      cout<<"num:"<<stud[i].num<<endl;;
      cout<<"age:"<<stud[i].age<<endl;
      cout<<"sex:"<<stud[i].sex<<endl<<endl;
   }
    return 0;
}