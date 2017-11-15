#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image;
    cout << "imgout" << endl;
    image = imread("./lena.jpg", 1);
    namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}