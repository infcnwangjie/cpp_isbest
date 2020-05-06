#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>

#include <opencv2\imgproc\types_c.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(QPushButton::clicked), this, SLOT(this->on_pushButton_clicked));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    using namespace cv;

    Mat image = imread("c:/work/cat.jpg");//括号里为自己图像的路径

//    namedWindow("cat");
//    imshow("cat", image);

    cvtColor(image,image,CV_BGR2RGB);
    QImage img = QImage((const unsigned char*)(image.data),image.cols,image.rows, image.cols*image.channels(),  QImage::Format_RGB888);
    this->ui->label->clear();
    this->ui->label->setPixmap(QPixmap::fromImage(img));

//    waitKey(0);
}
