#ifndef MEANSHIFTUTIL_H
#define MEANSHIFTUTIL_H
#include <vector>
#include <map>
#include <math.h>
#include <string>
typedef unsigned int uint;



struct DigtalCluster
{
    std::vector<double> centroid;
    std::vector<uint> samples;
};



class Meanshift{
public:
    Meanshift(){}
    ~Meanshift(){}

    //计算聚集点
    std::vector<DigtalCluster> k_means_ForDigitals(std::vector<std::vector<double> > trainX, uint k, uint maxepoches);


private:
    //计算俩数值之间的距离
    double cal_distance(std::vector<double> a, std::vector<double> b);

};


#endif // MEANSHIFT_H
