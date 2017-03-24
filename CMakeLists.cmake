cmake_minimum_required(VERSION 2.8)

PROJECT(advection)
SET(VTK_DIR )

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(vtkcommon common euler main)

if(VTK_LIBRARIES)
  target_link_libraries(vtkcommon common euler main ${VTK_LIBRARIES})
else()
  target_link_libraries(vtkcommon common euler main vtkHybrid)
endif()


