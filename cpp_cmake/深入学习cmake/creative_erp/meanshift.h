#ifndef MEANSHIFTUTIL_H
#define MEANSHIFTUTIL_H
#include <vector>
#include <map>
#include <math.h>
#include <string>
typedef unsigned int uint;

struct Point{
    int x;
    int y;
    int frequency=0;
};


struct Cluster
{
    std::vector<double> centroid;
    std::vector<uint> samples;
};

class Meanshift{
public:
    Meanshift(std::vector<Point> datas):points(datas){}
    Meanshift(){}
    ~Meanshift(){}

    //计算聚集点
    std::vector<Cluster> k_means(std::vector<std::vector<double> > trainX, uint k, uint maxepoches);

private:
    std::vector<Point> points;
    //修改集群数据
    void modifyClusterDatas();
    Point  computeCenterPoint(std::vector<Point> points
                              );
    double cal_distance(std::vector<double> a, std::vector<double> b);
};


#endif // MEANSHIFT_H
