#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

int main()
{
    // 问候用户
    // std::string name;
    // std::cout << "What is your name? ";
    // std::getline(std::cin, name);
    // std::cout << "Hello " << name << ", nice to meet you.\n";

    // 逐行读文件
    std::istringstream input;
    input.str("1\"2\"3\"4\"5\"6\"7\"");
    int sum = 0;
    std::string line;
    while(std::getline(input, line, '\"')) {
        cout << line;
    }
    for ( ; std::getline(input, line); ) {
        sum += std::stoi(line);
    }
    std::cout << "\nThe sum is: " << sum << "\n";
}
