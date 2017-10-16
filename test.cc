#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <cmath>
#include <vector>

using namespace std;
  typedef struct {
    double pitch;
    double roll;
    double heading;
    // geometry_msgs::Point currentWGS;
    vector<double> vInt;
  } imuInfo_t;
imuInfo_t LookUpMap(const map<double, imuInfo_t> &map, const double x);


int main() {
    // cout << fixed << 11345 % 60 << endl;

    map<double, imuInfo_t> temp;
    temp[1.34] = {1, 2, 3};
    imuInfo_t tempImu;
    tempImu.vInt = {1, 2, 3};
    tempImu = {0};
    cout << "tempImu.heading" << tempImu.heading << endl;
    cout << "tempImu.heading" << tempImu.vInt.size() << endl;

    cout << temp.size() << endl;
    cout << int(temp.empty()) << endl;
    cout << LookUpMap(temp, 1).heading << endl;


}

imuInfo_t LookUpMap(const map<double, imuInfo_t> &map, const double x) {
    // ROS_INFO_STREAM("map.size():" << map.size() << ":x:" << x);
    const auto little_iter = map.cbegin();
    const auto big_iter = map.crbegin();
    cout << little_iter->first << endl;
    if(x <= little_iter->first) {
      // ROS_INFO_STREAM(x << " is too small.");
      return little_iter->second;
  }
    if(x >= big_iter->first) {
      // ROS_INFO_STREAM(x << " is too big.");
      return big_iter->second;
    }

    const auto next = map.lower_bound(x);
    // to float type, 2.0000000000000000000001 might be equal to 2
    // in this case, --temp may fail
    if(next == little_iter) {
      // ROS_INFO_STREAM(x << " is the small endpoint.");
      return little_iter->second;
    }

    auto temp = next;
    const auto previous = (--temp);

    // calculate correspond imuInfo
    imuInfo_t tempImuInfo;
    tempImuInfo.pitch = (next->second.pitch - previous->second.pitch) / (next->first - previous->first) * (x - previous->first) + previous->second.pitch;
    tempImuInfo.roll = (next->second.roll - previous->second.roll) / (next->first - previous->first) * (x - previous->first) + previous->second.roll;
    tempImuInfo.heading = (next->second.heading - previous->second.heading) / (next->first - previous->first) * (x - previous->first) + previous->second.heading;
    // geometry_msgs::Point tempPoint;

    // tempImuInfo.currentWGS.x = (next->second.currentWGS.x - previous->second.currentWGS.x) / (next->first - previous->first) * (x - previous->first) + previous->second.currentWGS.x;
    // tempImuInfo.currentWGS.y = (next->second.currentWGS.y - previous->second.currentWGS.y) / (next->first - previous->first) * (x - previous->first) + previous->second.currentWGS.y;
    // tempImuInfo.currentWGS.z = (next->second.currentWGS.z - previous->second.currentWGS.z) / (next->first - previous->first) * (x - previous->first) + previous->second.currentWGS.z;

    return tempImuInfo;
  }

