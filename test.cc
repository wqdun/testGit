#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <cmath>
#include <vector>

using namespace std;


int *pi;

typedef struct {
    vector<vector<int>> vVInt;
    int i;
} vv_t;

vv_t *pvv;


int fun() {
    vector<int> v = {100, 2, 3, 4, 7};

    vv_t vv;
    vv.vVInt.push_back(v);
    pvv = &vv;
}


int main() {
    fun();

    cout << fixed << (pvv->vVInt)[0][1] << endl;

    *pi = pvv->i;
    cout << fixed << *pi << endl;

    // free(pi);
    // cout << fixed << *pi << endl;
}