cmake_minimum_required(VERSION 2.8)

PROJECT(advection)
SET(VTK_DIR "/home/kdawes/vtk-v6.1.0-82840f008383c7767c693edb82ddddab1d9f9a51/")

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

INCLUDE_DIRECTORIES(./common ./euler)

add_executable(advection ./common/common.cxx ./euler/euler.cxx ./common/vtkcommon.cxx ./euler/main.cxx )

target_link_libraries(advection ${VTK_LIBRARIES})
#if(VTK_LIBRARIES)
 # target_link_libraries(vtkcommon common euler main ${VTK_LIBRARIES})
#else()
 # target_link_libraries(vtkcommon common euler main vtkHybrid)
#endif()


