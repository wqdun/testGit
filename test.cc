#include <iostream>
#include <stdio.h>
#include <time.h>
#include <map>
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

double fun() {
  return 1 + 2 * 3;
}

// typedef unsigned char uint8_t;

typedef struct {
      double x;
      double y;
      double z;
} point_t;

typedef struct {
      double pitch;
      double roll;
      double heading;
      point_t currentWGS;
} imuInfo_t;

map<double, imuInfo_t> mTime2ImuInfo;

int main() {
    // struct
    unsigned char status[4] = {0x61, 0x67, 0xB9, 0x5A};
    // const unsigned int *p = (const unsigned int *)status;

    unsigned int time = (status[3] << 24) + (status[2] << 16) + (status[1] << 8) + status[0];

    cout << time << endl;
    cout << 0x04da << endl;

    imuInfo_t tmp;
    tmp.currentWGS.x = 1;
    tmp.currentWGS.y = 1;
    cout << tmp.currentWGS.y << endl;
    mTime2ImuInfo[1] = tmp;
    cout << mTime2ImuInfo.size() << endl;
    mTime2ImuInfo.clear();
    cout << mTime2ImuInfo.size() << endl;
    int i, j, k;
    i = j = k = 55;
    cout << i << j << k << endl;


    double rosTime = 1507795435.31;
    int hour = (int)rosTime / 3600 % 24;


    int minute = (int)rosTime / 60 % 60;

    int daySecond = (int)rosTime % (24 * 3600);

    cout << daySecond << ":" << 24 * 3600 << ":" << minute << endl;
    // cout << GpsWeekTime2HumanTime(20).tm_sec << endl;
    cout << fun() << endl;
}




