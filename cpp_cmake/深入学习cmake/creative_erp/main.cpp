#include "mainwindow.h"

#include <QApplication>
#include <meanshift.h>
#include<vector>
#include <iostream>
using namespace  std;

int main(int argc, char *argv[])
{


    vector<vector<double> > trainX(9,vector<double>(1,0));
    //对9个数据{1 2 3 11 12 13 21 22 23}聚类
    double data = 1.0;
    for (uint i = 0; i < 9; i++)
    {
        trainX[i][0] = data;
        if ((i+1) % 3 == 0) data += 8;
        else data++;
    }

    Meanshift meanshift;
    /*k-means聚类*/
    vector<Cluster> clusters_out = meanshift.k_means(trainX, 3, 100);

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
