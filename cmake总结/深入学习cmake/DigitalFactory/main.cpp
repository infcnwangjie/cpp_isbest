#include "mainwindow.h"

#include <QApplication>
#include <meanshift.h>
#include<vector>
#include <iostream>
using namespace  std;

int main(int argc, char *argv[])
{


    vector<vector<double> > trainX;
    //对9个数据{1 2 3 11 12 13 21 22 23}聚类
    vector<double> point1={10,20};
    vector<double> point2={5,9};
    vector<double> point3={12,17};
    vector<double> point4={18,54};
    vector<double> point5={17,60};
    vector<double> point6={6,10};
    vector<double> point7={3,8};
    vector<double> point8={13,19};
    vector<double> point9={30,70};
    vector<double> point10={33,69};
    vector<double> point11={10,24};

    trainX.push_back(point1);
    trainX.push_back(point2);
    trainX.push_back(point3);
    trainX.push_back(point4);
    trainX.push_back(point5);
    trainX.push_back(point6);
    trainX.push_back(point7);
    trainX.push_back(point8);
    trainX.push_back(point9);
    trainX.push_back(point10);
    trainX.push_back(point11);


    Meanshift meanshift;
    /*k-means聚类*/
    vector<DigtalCluster> clusters_out = meanshift.k_means_ForDigitals(trainX, 5, 100);

    /*输出分类结果*/
    for (uint i = 0; i < clusters_out.size(); i++)
    {
        cout << "Cluster " << i << " :" << endl;

        /*子类中心*/
        cout << "\t" << "Centroid: " << "\n\t\t[ ";
        for (uint j = 0; j < clusters_out[i].centroid.size(); j++)
        {
            cout << clusters_out[i].centroid[j] << " ";
        }
        cout << "]" << endl;

        /*子类样本点*/
        cout << "\t" << "Samples:\n";
        for (uint k = 0; k < clusters_out[i].samples.size(); k++)
        {
            uint c = clusters_out[i].samples[k];
            cout << "\t\t[ ";
            for (uint m = 0; m < trainX[0].size(); m++)
            {
                cout << trainX[c][m] << " ";
            }
            cout << "]\n";
        }
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
