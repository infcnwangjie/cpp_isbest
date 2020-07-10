#ifndef MEANSHIFTUTIL_H
#define MEANSHIFTUTIL_H
#include <vector>
#include <map>
#include <math.h>
#include <string>

struct Point{
    int x;
    int y;
    int frequency=0;
};


struct ClusterStruct{
    Point centroid;
    std::vector<Point> points;
    std::vector<int> frequency;
};


class MeanshiftUtil{

public:
    MeanshiftUtil(){}
    MeanshiftUtil(std::vector<Point> datas):datas(datas){
    }
    ~MeanshiftUtil(){}

    void setDatas(std::vector<Point> datas){
        this->datas.assign(datas.begin(),datas.end());
    }

    /*
    method:clustering
    used to: clustering by frequent
    */
    void clustering(std::vector<Point> datas,std::vector<ClusterStruct> clusters){


    }

    std::vector<ClusterStruct> divideDatas(int radius=50)
    {
        std::vector<ClusterStruct> clusters;
        std::vector<int> frequents(this->datas.size(),0);

        // outer for
        int index=0;
        for (Point item : this->datas) {

            Point   clusterCentPoint=item;

            while(true){

                std::vector<Point> pointsInCircle;
                for(Point iterPoint:this->datas){

                    double x_x_mul=pow(clusterCentPoint.x-iterPoint.x,2);
                    double y_y_mul=pow(clusterCentPoint.y-iterPoint.y,2);
                    double distance_center=sqrt(x_x_mul+y_y_mul);
                    if (distance_center<=radius){
                        pointsInCircle.push_back(iterPoint);
                        iterPoint.frequency+=1;
                        frequents[index++]+=1;

                    }
                }

                //end for
                Point oldCenter=clusterCentPoint;
                double xTotal,yTotal;

                for(auto tempPoint: pointsInCircle ){
                    xTotal+=tempPoint.x;
                    yTotal+=tempPoint.y;
                }
                Point newCenter;
                newCenter.x=xTotal/pointsInCircle.size();
                newCenter.y=yTotal/pointsInCircle.size();
                newCenter.frequency=1;

                clusterCentPoint=newCenter;

                if(oldCenter.x==newCenter.x && oldCenter.y==newCenter.y){
                    break;//break while
                }


            }
            //end while

            bool hasSameCluster=false;
            if(clusters.size()>0){
                for(auto  cluster:clusters){

                    double x_x_mul=pow(cluster.centroid.x-clusterCentPoint.x,2);
                    double y_y_mul=pow(cluster.centroid.y-clusterCentPoint.y,2);
                    double distance_center=sqrt(x_x_mul+y_y_mul);

                    if(distance_center<=radius){
                        hasSameCluster=true;



                        break;

                    }

                }

            }

            if(hasSameCluster==false){
                ClusterStruct newcluster;
                newcluster.centroid=clusterCent;

                clusters.push_back(newcluster);
            }

        }

    }





private:
    std::vector<Point> datas;


};



#endif // MEANSHIFT_H
