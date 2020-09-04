#include "opencv_supply.h"
using namespace cv;

OPENCV_SUPPLY::OPENCV_SUPPLY()
{
}



double same_rate(unsigned char * img1_data,unsigned char * img2_data, int img1_w,int img1_h,int img2_w,int img2_h){
    double rate=0;

    cv::Mat img1(img1_h, img1_w, CV_8UC3, img1_data);

    cv::Mat img2(img2_h, img2_w, CV_8UC3, img2_data);

    Mat img1_hsv, img2_hsv;
    cv::cvtColor(img1, img1_hsv, COLOR_BGR2HSV);
    cv::cvtColor(img2, img2_hsv, COLOR_BGR2HSV);

    // 定义直方图参数与属性
    int h_bins = 32; int s_bins = 32;
    int histSize[] = { h_bins, s_bins };
    // hue varies from 0 to 179, saturation from 0 to 255
    float h_ranges[] = { 0, 180 };
    float s_ranges[] = { 0, 256 };
    const float* ranges[] = { h_ranges, s_ranges };
    int channels[] = { 0, 1 };
   cv:: Mat img1Hist,img2Hist;

    cv::calcHist(&img1_hsv, 1, channels, Mat(), img1Hist, 2, histSize, ranges, true, false);
    cv::normalize(img1Hist, img1Hist, 0, 256, NORM_MINMAX, -1, Mat());

    cv::calcHist(&img2_hsv, 1, channels, Mat(), img2Hist, 2, histSize, ranges, true, false);
    cv::normalize(img2Hist, img2Hist, 0, 256, NORM_MINMAX, -1, Mat());
    rate= cv::compareHist(img1Hist,img2Hist,HISTCMP_CORREL);

    return rate;
}


unsigned char  *  find_it( unsigned char * image_meta , unsigned char * model_data,
                           int src_w ,int src_h,
                           int model_w,int model_h)
{

    cv::Mat image(src_h, src_w, CV_8UC3, image_meta);



    cv::Mat model(model_h, model_w, CV_8UC3, model_data);

    cv::Mat model_hsv, image_hsv;
    cv::cvtColor(model, model_hsv, COLOR_BGR2HSV);
    cv::cvtColor(image, image_hsv, COLOR_BGR2HSV);

    // 定义直方图参数与属性
    int h_bins = 32; int s_bins = 32;
    int histSize[] = { h_bins, s_bins };
    // hue varies from 0 to 179, saturation from 0 to 255
    float h_ranges[] = { 0, 180 };
    float s_ranges[] = { 0, 256 };
    const float* ranges[] = { h_ranges, s_ranges };
    int channels[] = { 0, 1 };
    cv::Mat roiHist;

    calcHist(&model_hsv, 1, channels, Mat(), roiHist, 2, histSize, ranges, true, false);
    normalize(roiHist, roiHist, 0, 256, NORM_MINMAX, -1, Mat());

    //计算反向投影
   cv:: Mat backproj;
    calcBackProject(&image_hsv, 1, channels, roiHist, backproj, ranges, 1.0);

    uchar* buffer = (uchar*)malloc(sizeof(uchar)*src_h*src_w);
    memcpy(buffer, backproj.data, src_h*src_w);
    return buffer;
}


uchar* cpp_canny(int height, int width, uchar* data) {
    cv::Mat src(height, width, CV_8UC1, data);
    cv::Mat dst;
    Canny(src, dst, 100, 200);

    uchar* buffer = (uchar*)malloc(sizeof(uchar)*height*width);
    memcpy(buffer, dst.data, height*width);
    return buffer;

}
