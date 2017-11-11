#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

template<typename T>
T string2num(const string& str) {
    std::istringstream iss(str);
    T num;
    iss >> num;
    return num;
}

int main(int args, char **argv) {
    std::ifstream fin("test2.cpp");
    if(!fin) {
        cout << "failed open, check if exist.\n";
        exit(1);
    }
    std::cout << std::boolalpha;
    // std::cout << "fin.is_open() = " << fin.is_open() << '\n';
    // std::cout << "fin.good() = " << fin.good() << '\n';

    // char str[10000];
    // fin >> str;
    // cout << str << "\n";

    // int offset = 9;
    // fin.seekg(offset, ios::cur);
    // int n = 12;
    // char str1[3];
    // // fin.getline(str1, n + 1);
    // // cout << str1 << endl;
    // // char no[100];
    // string no, k1, k2;
    // fin >> no;
    // cout << no << "\n";
    // fin >> k1;
    // cout << k1 << "\n";

    // // n = 2;  //! to skip ':' and ' '
    // // fin.seekg(n + 1, ios::cur);
    // // fin >> k1 >> k2;
    // // cout << no << " " << k1 << " " << k2 << endl;
    // cout << fin.eof() << "\n";
    // fin.close();
    const size_t BUFFER_SIZE = 100;
    char *line = new char[BUFFER_SIZE];
    while(fin.getline(line, BUFFER_SIZE)) {
        cout << line << "\n";
        // string line, line1, line2, line3, line4;
        // fin >> line >> line1 >> line2 >> line3 >> line4;
        // cout << line << line1 << line2 << line3 << line4 << endl;
    }
    delete[] line;


    string str = "Hello 10";
    string a;
    string b;
    stringstream ss(str);
    ss >> a >> b;
    cout << a << b << "\n";
    cout << string2num(b) << "\n";
    return 0;



#if 0

    char line[1024]={0};
    std::string x = "";
    std::string y = "";
    std::string z = "";
    while(fin.getline(line, sizeof(line))) {
        cout << line << "\n";
        // stringstream word(line);
        // word >> x;
        // word >> y;
        // word >> z;
        // std::cout << "x: " << x << std::endl;
        // std::cout << "y: " << y << std::endl;
        // std::cout << "z: " << z << std::endl;
    }
    fin.clear();
    fin.close();
    return 0;

#endif
}