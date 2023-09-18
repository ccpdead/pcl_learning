cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(cloud_viewer)

find_package(PCL REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

#add_executable (demo concave_hull_2d.cpp)
add_executable (demo convex_hull_2d.cpp)
target_link_libraries (demo ${PCL_LIBRARIES})