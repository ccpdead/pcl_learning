cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(cloud_viewer)


find_package(PCL REQUIRED
        PATHS /usr/local/pcl-1-9
        NO_DEFAULT_PATH
)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (range_image_border_extraction range_image_border_extraction.cpp)
target_link_libraries (range_image_border_extraction ${PCL_LIBRARIES})