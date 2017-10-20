#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    unsigned char u8 = 64;
    double f64 = (u8 << 24) / 1000000.0;
    cout << fixed << f64 << endl;
}
