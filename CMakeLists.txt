cmake_minimum_required(VERSION 2.8)

PROJECT(advection)
SET(VTK_DIR "/home/phil/581Advection/vtk-v6.2.0-95aea46c32ab995f3359cf6d9c5b9691e73e4ae9/")

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

INCLUDE_DIRECTORIES(./common ./euler)

add_executable(advection ./common/vtkcommon.cxx ./euler/main.cxx)

target_link_libraries(advection ${VTK_LIBRARIES})
#if(VTK_LIBRARIES)
 # target_link_libraries(vtkcommon common euler main ${VTK_LIBRARIES})
#else()
 # target_link_libraries(vtkcommon common euler main vtkHybrid)
#endif()


