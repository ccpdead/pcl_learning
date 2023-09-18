/**
* statistical_removal.cpp
*/
#include "iostream"
#include "pcl/io/pcd_io.h"
#include "pcl/point_types.h"
#include "pcl/filters/statistical_outlier_removal.h"

int main(int argc, char** argv){

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    //fill in the cloud data
    pcl::PCDReader reader;
    reader.read<pcl::PointXYZ>("../temp1.pcd",*cloud);
    std::cerr<<"Clound befor filtering:"<<std::endl;
    std::cerr<<*cloud<<std::endl;

    //create the filltering object
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ>sor;
    sor.setInputCloud(cloud);
    sor.setMeanK(100);
    sor.setStddevMulThresh(1);
    sor.filter(*cloud_filtered);

    std::cerr<<"cloud after filtering:"<<std::endl;
    std::cerr<<*cloud_filtered<<std::endl;

    pcl::PCDWriter writer;
    writer.write<pcl::PointXYZ>("../temp1_inliers_.pcd",*cloud_filtered,false);

    sor.setNegative(true);
    sor.filter(*cloud_filtered);
    writer.write<pcl::PointXYZ>("../temp1_outliers.pcd",*cloud_filtered,false);
    return 0;
}