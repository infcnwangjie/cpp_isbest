#include "test.h"
#include <chrono>
using namespace std;





test::test()
{

}

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, const char * argv[]) {
      Mat  img =cvLoadImage("c:/work/猫.jpg");
    cvNamedWindow("test",CV_WINDOW_AUTOSIZE);
    cvShowImage("test", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("test");
    return 0;
}
