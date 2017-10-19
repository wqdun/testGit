// #include <iomanip.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
// #include <string>
using namespace std;

int main()
{
  ofstream f1;
  f1.open("../mee.txt", ios::app);
  if(!f1)
    return 0;
  f1<<std::fixed<<"姓名："<<"廉东方"<<endl;
  f1<<std::fixed<<"家庭地址："<<"河南郑州"<<endl;
  f1.close();
  // return 0;


 time_t tt = time(NULL);
 tm* t= localtime(&tt);
 printf("%d-%02d-%02d %02d:%02d:%02d\n",
  t->tm_year + 1900,
  t->tm_mon + 1,
  t->tm_mday,
  t->tm_hour,
  t->tm_min,
  t->tm_sec);


    cout << t->tm_min << t->tm_sec << endl;

    char fileName[20];
    int n = sprintf(fileName, "%02d_%02d_%02d.imu", t->tm_hour, t->tm_min, t->tm_sec);
    cout << fileName << endl;


    ofstream f2(fileName);
  if(!f2)
    return 0;
  f2<<std::fixed<<"姓名："<<"廉东方"<< 3 << 4 << endl;
  f2<<std::fixed<<"家庭地址："<<"河南郑州"<<endl;
  f2.close();

    // string fileName = t->tm_min + ":" + t->tm_sec + ".lidar";
    // cout << fileName << endl;
    // sprintf(s, "%8d%8d", 123, 4567);



  char buffer [50];
  // int n, a=5, b=3;
  // n=sprintf (buffer, "%02d plus %d is %d", a, b, a+b);
  // printf ("[%s] is a string %d chars long\n",buffer,n);
  // return 0;

#define FILENAME "stat.dat"

     fstream _file;
     _file.open(fileName, ios::in);
     if(!_file)
     {
         cout<<fileName<<"没有被创建\n";
      }
      else
      {
          cout<<fileName<<"已经存在\n";
      }
      // return 0;

      int aa = 30;
    cout << "---------" << endl;
    for(int i = 0; i < 2; ++i) {
        static
        stringstream ss;
        cout << cout.precision() << endl;
        // ss.clear();
        ss.str("");
        if(0 == i)
            ss<<7.908907453;
        else
            ss<<21;

        // cout << ss;
        static
        string s1;

        s1 = ss.str();
        // string s1(ss);
        cout<< fixed << setprecision(10)
            << 8.56154654651321<<endl; // 30

        // string s2;
        // ss>>s2;
        // cout<<s2<<endl; // 30
        cout << "--------" << endl;
    }


    for(int i = 0; i < 5; ++i) {
        static
        int ii = (cout<<11, 1);
        cout << ii << endl;


    }

cout << 1508323827 % 86400  << endl;



}
