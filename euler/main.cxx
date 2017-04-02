#include <common.h>
#include <vtkcommon.h>
#include <euler.h>
#include <rk.h>
#include <vtkDataSetReader.h>
#include <vtkRectilinearGrid.h>

#include <vtkCamera.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

int main(int argc,char **argv)
{
    int  i, j;

    vtkDataSetReader *rdr = vtkDataSetReader::New();
    rdr->SetFileName(argv[1]);
    rdr->Update();

    int dims[3];
    vtkRectilinearGrid *rgrid = (vtkRectilinearGrid *) rdr->GetOutput();
    rgrid->GetDimensions(dims);

    float *X = (float *) rgrid->GetXCoordinates()->GetVoidPointer(0);
    float *Y = (float *) rgrid->GetYCoordinates()->GetVoidPointer(0);
    float *F_3D = (float *) rgrid->GetPointData()->GetVectors()->GetVoidPointer(0);
    float *F = Convert3DVectorDataTo2DVectorData(dims, F_3D);
    
    
    const int npts = 10;
    float pt[npts][3] =
         {
            {10.1119, 1.22062, 0},
            {8.62376, 13.3839, 0},
            {1.55026, 1.26123, 0},
            {6.9736, 0.653565, 0},
            {2, 2.74117, 0},
            {8.93699, 10.4111, 0},
            {6.08791, -0.533753, 0},
            {10.0543, 1.38024, 0},
            {3.84128, -0.768977, 0},
            {6.66757, 6.0259, 0},
         };


    for (i = 0 ; i < npts ; i++)
    {
       float vec[2];
       EvaluateVectorFieldAtLocation(pt[i], dims, X, Y, F, vec);
       cerr << "Velocity at (" << pt[i][0] <<", "<<pt[i][1] << ") is (" << vec[0] << ", " << vec[1] << ")" << endl;
    }

    float h=atof(argv[2]);
    int nsteps;
    //const int nsteps = 5000;
    sscanf(argv[3],"%d",&nsteps);
    float **output_Euler = new float*[2*(npts+1)];
    float **output_RK = new float*[2*(npts+1)];
    float **speeds_Euler = new float*[npts+1];
    float **speeds_RK = new float*[npts+1];
   cout << " Number of step" <<nsteps<<endl; 
   cout << " Number of h" <<h<<endl; 
   for (i = 0 ; i < npts ; i++)
    {
       output_Euler[i] = new float[(nsteps+1)*2];
       output_RK[i] = new float[(nsteps+1)*2];
       speeds_Euler[i] = new float[nsteps];
       speeds_RK[i] = new float[nsteps];
       AdvectWithRKStep(pt[i], dims, X, Y, F, h, nsteps, output_RK[i], speeds_RK[i]);
       AdvectWithEulerStep(pt[i], dims, X, Y, F, h, nsteps, output_Euler[i], speeds_Euler[i]);
       float length_Euler = CalculateArcLength(output_Euler[i], nsteps+1);
       float length_RK = CalculateArcLength(output_RK[i], nsteps+1);
    
       cerr << "Arc length for Euler (" << pt[i][0] << ", " << pt[i][1] << ") is " << length_Euler << endl;
       cerr << "Arc length for RK (" << pt[i][0] << ", " << pt[i][1] << ") is " << length_RK << endl;
    }

    vtkPolyData *pd_Euler = CreateVTKPolyData(npts, nsteps, output_Euler, speeds_Euler);
    vtkPolyData *pd_RK = CreateVTKPolyData(npts, nsteps, output_RK, speeds_RK);

    //This can be useful for debugging
/*
    vtkDataSetWriter *writer = vtkDataSetWriter::New();
    writer->SetFileName("paths.vtk");
    writer->SetInputData(pd);
    writer->Write();
 */

    vtkSmartPointer<vtkDataSetMapper> win1Mapper =
      vtkSmartPointer<vtkDataSetMapper>::New();
    win1Mapper->SetInputData(pd_Euler);
    win1Mapper->SetScalarRange(0, 0.15);
  
    vtkSmartPointer<vtkActor> win1Actor =
      vtkSmartPointer<vtkActor>::New();
    win1Actor->SetMapper(win1Mapper);
  
vtkSmartPointer<vtkDataSetMapper> win2Mapper =
      vtkSmartPointer<vtkDataSetMapper>::New();
    win2Mapper->SetInputData(pd_RK);
    win2Mapper->SetScalarRange(0, 0.15);
  
    vtkSmartPointer<vtkActor> win2Actor =
      vtkSmartPointer<vtkActor>::New();
    win2Actor->SetMapper(win2Mapper);
  

     vtkSmartPointer<vtkRenderer> ren1 =
      vtkSmartPointer<vtkRenderer>::New();
  
 vtkSmartPointer<vtkRenderer> ren2 =
      vtkSmartPointer<vtkRenderer>::New();
  
    vtkSmartPointer<vtkRenderWindow> renWin =
      vtkSmartPointer<vtkRenderWindow>::New();
    renWin->AddRenderer(ren1);
    renWin->AddRenderer(ren2);
    vtkSmartPointer<vtkRenderWindowInteractor> iren =
      vtkSmartPointer<vtkRenderWindowInteractor>::New();
    iren->SetRenderWindow(renWin);
    ren1->AddActor(win1Actor);
    ren2->AddActor(win2Actor);
    ren1->SetBackground(0.0, 0.0, 0.0);
    ren2->SetBackground(0.0, 0.0, 0.0);
    renWin->SetSize(800, 500);
  
    ren1->GetActiveCamera()->SetFocalPoint(5,5,0);
    ren2->GetActiveCamera()->SetFocalPoint(5,5,0);
    ren1->GetActiveCamera()->SetPosition(5,5,30);
    ren2->GetActiveCamera()->SetPosition(5,5,30);
    ren1->GetActiveCamera()->SetViewUp(0,1,0);
    ren2->GetActiveCamera()->SetViewUp(0,1,0);
    ren1->GetActiveCamera()->SetClippingRange(20, 120);
    ren2->GetActiveCamera()->SetClippingRange(20, 120);
    ren1->GetActiveCamera()->SetDistance(30);
    ren2->GetActiveCamera()->SetDistance(30);

    // This starts the event loop and invokes an initial render.
    //
    iren->Initialize();
    iren->Start();

    delete [] F;
    pd_Euler->Delete();
    pd_RK->Delete();
}
