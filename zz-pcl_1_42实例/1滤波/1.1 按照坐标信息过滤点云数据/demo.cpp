
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>//直通滤波器
#include <pcl/visualization/cloud_viewer.h>
int
main (int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::PCDReader reader;
    reader.read("../temp3.pcd",*cloud);
//    // Fill in the cloud data
//    cloud->width  = 5;
//    cloud->height = 1;
//    cloud->points.resize (cloud->width * cloud->height);

//    for (std::size_t i = 0; i < cloud->points.size (); ++i)
//    {
//        cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
//        cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
//        cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
//    }
    std::cerr<<"Pointcloud before filtering: "<<cloud->width*cloud->height
                <<" data points("<<pcl::getFieldsList(*cloud)<<")."<<std::endl;
//    for (std::size_t i = 0; i < cloud->points.size (); ++i)
//        std::cerr << "    " << cloud->points[i].x << " "
//                  << cloud->points[i].y << " "
//                  << cloud->points[i].z << std::endl;

    // Create the filtering object
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud (cloud);
    pass.setFilterFieldName ("z");
    pass.setFilterLimits (0.0, 0.555);
    //pass.setFilterLimitsNegative (true);
    pass.filter (*cloud_filtered);

    std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height
              << " data points (" << pcl::getFieldsList (*cloud_filtered) << ")." << std::endl;

//    std::cerr << "Cloud after filtering: " << std::endl;
//    for (std::size_t i = 0; i < cloud_filtered->points.size (); ++i)
//        std::cerr << "    " << cloud_filtered->points[i].x << " "
//                  << cloud_filtered->points[i].y << " "
//                  << cloud_filtered->points[i].z << std::endl;

    pcl::visualization::CloudViewer viewer("viewer");
    viewer.showCloud(cloud_filtered);
    while(!viewer.wasStopped())
    {
    }
    return (0);
}