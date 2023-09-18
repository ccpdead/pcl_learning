
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/visualization/cloud_viewer.h>

int
main (int argc, char** argv)
{
//    pcl::PCLPointCloud2::Ptr cloud (new pcl::PCLPointCloud2 ());
//    pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    // Fill in the cloud data
    pcl::PCDReader reader;
    // Replace the path below with the path where you saved your file
    reader.read ("../temp3.pcd", *cloud); // Remember to download the file first!

    std::cerr << "PointCloud before filtering: " << cloud->width * cloud->height
              << " data points (" << pcl::getFieldsList (*cloud) << ")." << std::endl;

    // Create the filtering object
    pcl::VoxelGrid<pcl::PointXYZ> sor;
    sor.setInputCloud (cloud);
    sor.setLeafSize (0.002f, 0.002f, 0.002f);
    sor.filter (*cloud_filtered);

    std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height
              << " data points (" << pcl::getFieldsList (*cloud_filtered) << ")." << std::endl;

//    pcl::PCDWriter writer;
//    writer.write ("../temp3_downsampled.pcd", *cloud_filtered,
//                  Eigen::Vector4f::Zero (), Eigen::Quaternionf::Identity (), false);

    pcl::visualization::CloudViewer viewer("viewer");
    viewer.showCloud(cloud_filtered);
    while(!viewer.wasStopped())
    {
    }
    return (0);
}
