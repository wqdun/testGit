#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <string>
using namespace std;


int main()
{
    string str = "abcdef中国汽车";
    string t = "tt";
    auto pos = str.find("abc");

    // if(!str.compare(t))
    // {
    //      std::cout << "1 str is equal to t" << std::endl;
    //  }
    // else if(pos == 0)
    //  {
    //      std::cout << "2 t is match at the begin of str" << std::endl;
    //  }
    //  else if(pos + t.length() == str.length())
    //  {
    //      std::cout << "3 t is match at the begin of str" << std::endl;
    //  }
     // else
        if(pos != string::npos)
     {
         std::cout << "4 t is match at the middle of str" << std::endl;
     }
     else
     {
         std::cout << "5 t is not matched in str" << std::endl;
     }
     cout << string::npos << "\n";

return 0;
}
