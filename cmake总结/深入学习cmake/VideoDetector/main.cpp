
#include<opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include <QLibrary>

#include<opencv2/imgproc/imgproc.hpp>
#include "opencv_supply_32bit.h"
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
        helloWorld();
       VideoCapture cap;
       cap.open("D:/vs_nty/1.avi"); //打开视频,以上两句等价于VideoCapture cap("E://2.avi");

       //cap.open("http://www.laganiere.name/bike.avi");//也可以直接从网页中获取图片，前提是网页有视频，以及网速够快
       if(!cap.isOpened())//如果视频不能正常打开则返回
           return 0;
       Mat frame;
       while(1)
       {
           cap>>frame;//等价于cap.read(frame);
          Mat result;
           cv::resize(frame,result,Size(900,700));

           if(frame.empty())//如果某帧为空则退出循环
               break;
           imshow("video", result);
           waitKey(20);//每帧延时20毫秒
       }
       cap.release();//释放资源

  return 0;
}
