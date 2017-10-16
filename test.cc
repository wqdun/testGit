#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <cmath>
#include <vector>

using namespace std;
double getDaySecond(const double rosTime, const double pktTime) {
  int rosHour = (int)rosTime / 3600 % 24;
  const int rosMinute = (int)rosTime / 60 % 60;
  const int pktMinute = (int)pktTime / 60;
  const int errMinute = rosMinute - pktMinute;
  cout << rosHour << ":" << rosMinute << ":" << fmod(rosTime, 60) << endl;
  cout << "00:" << pktMinute << endl;
  cout << errMinute<< endl;

  if(errMinute > 10) {
    // cout << "errMinute > 10" << endl;
    ++rosHour;
  }
  else
  if(errMinute < -10) {
    // cout << "errMinute < -10" << endl;
    --rosHour;
  }
  // else {
  //   // do nothing when errMinute in [-10, 10]
  // }

  // in case: -1 || 24
  rosHour = (rosHour + 24) % 24;

  return pktTime + 3600 * rosHour;
}


int main() {
    double dayS = getDaySecond(1508111941, 12);

    double dayHour = (int)dayS / 3600;
    double dayMinute = (int)dayS / 60 % 60;
    double daySecond = fmod(dayS, 60);
    cout << dayHour << ":" << dayMinute << ":" << daySecond << endl;
    cout << fixed << dayS << endl;



}