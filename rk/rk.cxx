#include <common.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <euler.h>
using namespace std;
// ****************************************************************************
//  Function: AdvectWithEulerStep
//
//  Arguments:
//     pt: the seed location (two-dimensions)
//     dims: an array of size two.  
//              The first number is the size of the array in argument X, 
//              the second the size of Y.
//     X: an array (size is specified by dims).  
//              This contains the X locations of a rectilinear mesh.
//     Y: an array (size is specified by dims).  
//              This contains the Y locations of a rectilinear mesh.
//     F: a vector field defined on the mesh.  Its size is 2*dims[0]*dims[1].
//     h: The size of the Euler step
//     nsteps: The number of Euler steps to take
//     output_locations (output): An array of size 2*(nsteps+1).  It's first entry
//        should be the seed location.  The second entry should be the result
//        of the first advection step.  The final entry should be the result
//        of the final advection step.
//     speeds (output): An array of size (nsteps+1).  It's first entry should be the
//        speed at the seed location.  It's final entry should be the speed
//        at the location of the result of the final advection step.
//        Recall that speed is the magnitude of the velocity.
//
// ****************************************************************************
//float SpeedCal(float *velocity){
//	return sqrt(pow(velocity[0],2)+pow(velocity[1],2));
//}

void
AdvectWithRKStep(const float *pt, const int *dims, const float *X,
                    const float *Y, const float *F, 
                    float h, int nsteps, float *output_locations, float *speeds)
{
	//starting location  wich is also step 1
	output_locations[0]= pt[0];
	output_locations[1]= pt[1];

	float startEvaluationField1[2];
	float startEvaluationField2[2];
	float startEvaluationField3[2];
	float startEvaluationField4[2];

	float point1[2], point2[2], point3[2], point4[2];
	float fieldSum[2];

	EvaluateVectorFieldAtLocation(pt,dims,X,Y,F,startEvaluationField1);
	//finding current speed of partical is 
        //cout<< "Evaluation at : "<< 0 << " - " << startEvaluationField[0] << " : " << startEvaluationField[1]<<endl;	
        //cout<< "OutputLocation at : "<<0<< " - " << pt[0] << " : " << pt[1]<<endl;	
	speeds[0] = SpeedCal(startEvaluationField1);
	
	for ( int i = 1; i <=nsteps; i++){

		    point1[0] = output_locations[(i-1)*2];
			point1[1] = output_locations[(i-1)*2 + 1];

			point2[0] = point1[0] + ( (h / 2) * startEvaluationField1[0] );
			point2[1] = point1[1] + ( (h / 2) * startEvaluationField1[1] );
			EvaluateVectorFieldAtLocation(point2,dims,X,Y,F,startEvaluationField2);

			point3[0] = point1[0] + ( (h / 2) * startEvaluationField2[0] );
			point3[1] = point1[1] + ( (h / 2) * startEvaluationField2[1] );
			EvaluateVectorFieldAtLocation(point3,dims,X,Y,F,startEvaluationField3);

			point4[0] = point1[0] + ( h * startEvaluationField3[0] );
			point4[1] = point1[1] + ( h * startEvaluationField3[1] );
			EvaluateVectorFieldAtLocation(point3,dims,X,Y,F,startEvaluationField4);

			fieldSum[0] = startEvaluationField1[0] + 2.0*startEvaluationField2[0] + 2.0*startEvaluationField3[0] + startEvaluationField4[0];
		    fieldSum[1] = startEvaluationField1[1] + 2.0*startEvaluationField2[1] + 2.0*startEvaluationField3[1] + startEvaluationField4[1];

		//new location
			output_locations[2*i] = output_locations[(i-1)*2] + ( (h / 6) * fieldSum[0]);
			output_locations[2*i+1] = output_locations[(i-1)*2 +1]+ ( (h / 6) * fieldSum[1]);


			float newPt[2]= {output_locations[2*i],output_locations[2*i+1]};
			EvaluateVectorFieldAtLocation(newPt,dims,X,Y,F,startEvaluationField1);
			speeds[i] = SpeedCal(startEvaluationField1);
          //              cout<< "Evaluation at : "<<i<< " - " << startEvaluationField[0] << " : " << startEvaluationField[1]<<endl;	
            //            cout<< "OutputLocation at : "<<i<< " - " << newPt[0] << " : " << newPt[1]<<endl;	
    }

}

// ****************************************************************************
//  Function: CalculateArcLength
//
//  Arguments:
//     locations: an array of 2D locations.
//     nlocations: the number of locations in the array "locations".
//
//  Returns: the arc length, meaning the distance between each successive
//           pair of points
//
// ****************************************************************************
/*
float
CalculateArcLength(const float *output_locations, int nlocations)
{
	float arcLength = 0.f;
	for (int i=0; i<nlocations-1; i++){
		    float arcX = output_locations[2*i+2] -output_locations[2*i];
		    float arcY = output_locations[2*i+3] -output_locations[2*i+1];
			arcLength+= sqrt(pow(arcX,2)+pow(arcY,2));

 	}
    return arcLength;
}
*/