#include "meanshift.h"
#include "math.h"
#include <iostream>
#include <list>
#include<iostream>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;


double Meanshift::cal_distance(vector<double> a, vector<double> b)
{
    uint da = a.size();
    uint db = b.size();
    if (da != db) cerr << "Dimensions of two vectors must be same!!\n";
    double val = 0.0;
    for (uint i = 0; i < da; i++)
    {
        val += pow((a[i] - b[i]), 2);
    }
    return pow(val, 0.5);
}
vector<DigtalCluster> Meanshift::k_means_ForDigitals(vector<vector<double> > trainX, uint k, uint maxepoches)
{
    const uint row_num = trainX.size();
    const uint col_num = trainX[0].size();
    /*初始化聚类中心*/
    vector<DigtalCluster> clusters(k);
    uint seed = (uint)time(NULL);
    for (uint i = 0; i < k; i++)
    {
        srand(seed);
        int c = rand() % row_num;
        clusters[i].centroid = trainX[c];
        seed = rand();
    }
    /*多次迭代直至收敛，本次试验迭代100次*/
    for (uint it = 0; it < maxepoches; it++)
    {
        /*每一次重新计算样本点所属类别之前，清空原来样本点信息*/
        for (uint i = 0; i < k; i++)
        {
            clusters[i].samples.clear();
        }
        /*求出每个样本点距应该属于哪一个聚类*/
        for (uint j = 0; j < row_num; j++)
        {
            /*都初始化属于第0个聚类*/
            uint c = 0;
            double min_distance = cal_distance(trainX[j],clusters[c].centroid);
            for (uint i = 1; i < k; i++)
            {
                double distance = cal_distance(trainX[j], clusters[i].centroid);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    c = i;
                }
            }
            clusters[c].samples.push_back(j);
        }
        /*更新聚类中心*/
        for (uint i = 0; i < k; i++)
        {
            vector<double> val(col_num, 0.0);
            for (uint j = 0; j < clusters[i].samples.size(); j++)
            {
                uint sample = clusters[i].samples[j];
                for (uint d = 0; d < col_num; d++)
                {
                    val[d] += trainX[sample][d];
                    if (j == clusters[i].samples.size() - 1)
                        clusters[i].centroid[d] = val[d] / clusters[i].samples.size();
                }
            }
        }
    }
    return clusters;
}



void meanshift_test(){
    list<int> dlist={1,3,4,5,6};

    for(int ditem:dlist){
        cout<<"dlist:"<<ditem<<endl;
    }

    list<int>::iterator iter;
    for(iter=dlist.begin();iter!=dlist.end();iter++){
        cout<<"dlist_*iter:"<<*iter<<endl;
    }

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
}
