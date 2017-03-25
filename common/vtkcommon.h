#include <vtkImageData.h>
#include <vtkPNGWriter.h>
#include <vtkPointData.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkUnsignedCharArray.h>
#include <vtkFloatArray.h>
#include <vtkDataSetReader.h>
#include <vtkRectilinearGrid.h>
#include <vtkFloatArray.h>
#include <vtkPolyData.h>
#include <vtkDataSetWriter.h>
#include <vtkTubeFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkSphereSource.h>




void WriteImage(vtkImageData *img, const char *filename);
vtkImageData *NewImage(int width, int height);
float *Convert3DVectorDataTo2DVectorData(const int *dims, const float *F);
vtkPolyData *CreateVTKPolyData(int nseeds, int nsteps, float **output_locations, float **speeds);
