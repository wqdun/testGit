#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

static tm GpsWeekTime2HumanTime(const double gpsTime) {
    tm tt;
    // time_t t = time(NULL);
    // tt = gmtime(&t);
    tt.tm_sec = 1;
    tt.tm_min = 1;
    tt.tm_hour = 1;
    return tt;

}
// typedef unsigned char uint8_t;





int main() {
    // struct
    unsigned char status[4] = {0x61, 0x67, 0xB9, 0x5A};
    // const unsigned int *p = (const unsigned int *)status;

    unsigned int time = (status[3] << 24) + (status[2] << 16) + (status[1] << 8) + status[0];

    cout << time << endl;
    cout << 0x04da << endl;


    cout << GpsWeekTime2HumanTime(20).tm_sec << endl;
}




