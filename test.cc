#include <iostream>
#include <stdio.h>
#include <time.h>
#include <map>
#include <cmath>
using namespace std;

int main() {
    double gpsTime = 368123.32;
    double daySecond = fmod(gpsTime, 86400); // gpsTime % (24 * 3600);
    cout << fixed << daySecond << endl;
}