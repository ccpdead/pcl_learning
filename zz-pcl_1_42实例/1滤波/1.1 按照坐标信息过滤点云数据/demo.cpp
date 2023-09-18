#include "iostream"
#include "boost/thread/thread.hpp"
#include "pcl/range_image/range_image.h"
#include "pcl/io/pcd_io.h"
#include "pcl/visualization/range_image_visualizer.h"
#include "pcl/visualization/pcl_visualizer.h"
#include "pcl/features/range_image_border_extractor.h"
#include "pcl/keypoints/narf_keypoint.h"
#include "pcl/features/narf_descriptor.h"
#include "pcl/console/parse.h"

typedef pcl::PointXYZ PointType;

//Parameters
float angular_resolution = 0.5f;
float support_size = 0.2f;
pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;//创建一个相机坐标系
bool setUnseenToMaxRange = false;
bool rotation_invariant = true;

void
printUsage(const char* progName)
{
    std::cout<<"\n\nUsage:"<<progName<<" [options]<scene.pcd>\n\n"
             <<"Options:\n"
             <<"---------------------------------------------"
             <<"-r <float>  angular resolution in degrees"
}