#include <../common/common.cxx>

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
float speedCal(float *velocity){
	return sqrt(pow(velocity[0],2)+pow(velocity[1],2));
}

void
AdvectWithEulerStep(const float *pt, const int *dims, const float *X, 
                    const float *Y, const float *F, 
                    float h, int nsteps, float *output_locations, float *speeds)
{
	//starting location  wich is also step 1
	output_location[0]= pt[0];
	output_location[1]= pt[1];
    float startEvaluationField[2];
	EvaluateVectorFieldAtLocation(pt,dims,X,Y,F,startEvaluationField);
	//finding current speed of partical is 
	speed[0] = speedCal(startEvaluationField);
	
	for ( int i = 1; i <nsteps; i++){
			//new location
			output_locations[2*i] = output_locations[(i-1)*2] + startEvaluationField[0]*h;
			output_locations[2*i+1] = output_location[(i-1)*2 +1]+startEvaluationField[1]*h;
			float newPt[2]= {output_locations[2*i],output_locations[2*i+1]);
			EvaluateVectorFieldAtLocation(newPt,dims,X,Y,F,startEvaluationField);
			speed[i] = speedCal(startEvaluationField);		
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

float
CalculateArcLength(const float *output_locations, int nlocations)
{
	float arcLength = 0.0;
	for (int i=0; i<nlocations-1; i++){
			float arcX = output_locations[2*i+2] -output_locations[2*i];
		    float arcY = output_locations[2*i+3] -output_locations[2*i+1];
			arcLength+= sqrt(pow(arcX,2)+pow(arcY,2));

 	}
    return arcLength;
}
