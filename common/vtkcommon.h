#include <vtkImageData.h>
#include <vtkPolyData.h>

void WriteImage(vtkImageData *img, const char *filename);
vtkImageData *NewImage(int width, int height);
float *Convert3DVectorDataTo2DVectorData(const int *dims, const float *F);
vtkPolyData *CreateVTKPolyData(int nseeds, int nsteps, float **output_locations, float **speeds);
