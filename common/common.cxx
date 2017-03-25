// ****************************************************************************
//  Function: GetNumberOfPoints
//
//  Arguments:
//     dims: an array of size 3 with the number of points in X, Y, and Z.
//           2D data sets would have Z=1
//
//  Returns:  the number of points in a rectilinear mesh
//
// ****************************************************************************

int GetNumberOfPoints(const int *dims)
{
    // 3D
    //return dims[0]*dims[1]*dims[2];
    // 2D
    return dims[0]*dims[1];
}

// ****************************************************************************
//  Function: GetNumberOfCells
//
//  Arguments:
//
//      dims: an array of size 3 with the number of points in X, Y, and Z.
//            2D data sets would have Z=1
//
//  Returns:  the number of cells in a rectilinear mesh
//
// ****************************************************************************

int GetNumberOfCells(const int *dims)
{
    // 3D
    //return (dims[0]-1)*(dims[1]-1)*(dims[2]-1);
    // 2D
    return (dims[0]-1)*(dims[1]-1);
}


// ****************************************************************************
//  Function: GetPointIndex
//
//  Arguments:
//      idx:  the logical index of a point.
//              0 <= idx[0] < dims[0]
//              1 <= idx[1] < dims[1]
//              2 <= idx[2] < dims[2] (or always 0 if 2D)
//      dims: an array of size 3 with the number of points in X, Y, and Z.
//            2D data sets would have Z=1
//
//  Returns:  the point index
//
// ****************************************************************************

int GetPointIndex(const int *idx, const int *dims)
{
    // 3D
    //return idx[2]*dims[0]*dims[1]+idx[1]*dims[0]+idx[0];
    // 2D
    return idx[1]*dims[0]+idx[0];
}


// ****************************************************************************
//  Function: GetCellIndex
//
//  Arguments:
//      idx:  the logical index of a cell.
//              0 <= idx[0] < dims[0]-1
//              1 <= idx[1] < dims[1]-1 
//              2 <= idx[2] < dims[2]-1 (or always 0 if 2D)
//      dims: an array of size 3 with the number of points in X, Y, and Z.
//            2D data sets would have Z=1
//
//  Returns:  the cell index
//
// ****************************************************************************

int GetCellIndex(const int *idx, const int *dims)
{
    // 3D
    //return idx[2]*(dims[0]-1)*(dims[1]-1)+idx[1]*(dims[0]-1)+idx[0];
    // 2D
    return idx[1]*(dims[0]-1)+idx[0];
}

// ****************************************************************************
//  Function: GetLogicalPointIndex
//
//  Arguments:
//      idx (output):  the logical index of the point.
//              0 <= idx[0] < dims[0]
//              1 <= idx[1] < dims[1] 
//              2 <= idx[2] < dims[2] (or always 0 if 2D)
//      pointId:  a number between 0 and (GetNumberOfPoints(dims)-1).
//      dims: an array of size 3 with the number of points in X, Y, and Z.
//            2D data sets would have Z=1
//
//  Returns:  None (argument idx is output)
//
// ****************************************************************************

void GetLogicalPointIndex(int *idx, int pointId, const int *dims)
{
    // 3D
    // idx[0] = pointId%dim[0];
    // idx[1] = (pointId/dims[0])%dims[1];
    // idx[2] = pointId/(dims[0]*dims[1]);

    // 2D
    idx[0] = pointId%dims[0];
    idx[1] = pointId/dims[0];
}


// ****************************************************************************
//  Function: GetLogicalCellIndex
//
//  Arguments:
//      idx (output):  the logical index of the cell index.
//              0 <= idx[0] < dims[0]-1
//              1 <= idx[1] < dims[1]-1 
//              2 <= idx[2] < dims[2]-1 (or always 0 if 2D)
//      cellId:  a number between 0 and (GetNumberOfCells(dims)-1).
//      dims: an array of size 3 with the number of points in X, Y, and Z.
//            2D data sets would have Z=1
//
//  Returns:  None (argument idx is output)
//
// ****************************************************************************

void GetLogicalCellIndex(int *idx, int cellId, const int *dims)
{
    // 3D
    // idx[0] = cellId%(dims[0]-1);
    // idx[1] = (cellId/(dims[0]-1))%(dims[1]-1);
    // idx[2] = cellId/((dims[0]-1)*(dims[1]-1));

    // 2D
    idx[0] = cellId%(dims[0]-1);
    idx[1] = cellId/(dims[0]-1);
}

// ****************************************************************************
//  Function: EvaluateVectorFieldAtLocation
//
//  Arguments:
//     pt: a two-dimensional location
//     dims: an array of size two.  
//              The first number is the size of the array in argument X, 
//              the second the size of Y.
//     X: an array (size is specified by dims).  
//              This contains the X locations of a rectilinear mesh.
//     Y: an array (size is specified by dims).  
//              This contains the Y locations of a rectilinear mesh.
//     F: a vector field defined on the mesh.  Its size is 2*dims[0]*dims[1].
//        The first value in the field is the x-component for the first point.
//        The second value in the field is the y-component for the first point.
//
//     rv (output): the interpolated field value. (0,0) if the location is out of bounds.
//
// ****************************************************************************
//interpolate point top x and bottom X then use those points to interpolate y
void EvaluateVectorFieldAtLocation(const float *pt, const int *dims, const float *X, 
                              const float *Y, const float *F, float *rv)

{
	//find which cell pt is in
    int cell[2];
    int cellY[2];
    int cellX[2];
    float pointsF[4];
    cell[0] =0;
    cell[1] = 0;
    cellX[0]=0;
    cellX[1]=0;
    cellY[0]=0;
    cellY[1]=0;
    if((pt[0] <X[0]) || (pt[0] >X[dims[0]-1])){
        rv[0] = 0;
        rv[1] = 0;
        return;
    }
    if((pt[1]< Y[0] )||( pt[1] > Y[dims[1]-1])){
      rv[0] = 0;
      rv[1] = 0;
      return;
    }

    for (int i =0 ; i<dims[0]-1; i++){
         if (pt[0] > X[i] && pt[0] <X[i+1]){
            cell[0] = i;
            cellX[0] = i;
            cellX[1] = i+1;     
         }
    }
    
    for (int j=0; j<dims[1]-1; j++){
         if (pt[1] > Y[j] && pt[1] <Y[j+1]){
            cellY[0] =j ;
            cellY[1] = j+1;     
            cell[1] = j;     
         }
    }
	
	   // Need to convrer from cell index to point index
	   //Get points from Lower left corner and Vecolocty values
	   int  LLC = GetPointIndex(cell, dims);
	   float LLCV[2];
	   LLCV[0] = F[LLC*2];
	   LLCV[1] = F[LLC*2 +1];
	   //Get Points from upper left corner
	   int  ULC = GetPointIndex(cell, dims)+dims[0];
	   float ULCV[2];
	   ULCV[0] = F[ULC*2];
	   ULCV[1] = F[ULC*2 +1];
	   //Get points from lower right corner
	   int  LRC = GetPointIndex(cell, dims)+1;
	   float LRCV[2];
	   LRCV[0] = F[LRC*2];
	   LRCV[1] = F[LRC*2 +1];
	   //Get points from upper right corner
	   int  URC = GetPointIndex(cell, dims)+dims[0] +1;
	   float URCV[2];
	   URCV[0] = F[URC*2];
	   URCV[1] = F[URC*2 +1];
	   float tofX = (pt[0]-X[cellX[0]]) / (X[cellX[1]]-X[cellX[0]]);
	   float tofY = (pt[1]-Y[cellY[0]]) / (Y[cellY[1]]-Y[cellY[0]]);
	   float ITV[2];
	   float IBV[2];
	   float IBTV[2];
	   //Interpolate top 
	   ITV[0] = ULCV[0] + tofX*(URCV[0]-ULCV[0]);
	   ITV[1] = ULCV[1] + tofX*(URCV[1]-ULCV[1]);
	   //interpolate bottom
	   IBV[0] = LLCV[0] + tofX*(LRCV[0]-LLCV[0]);
	   IBV[1] = LLCV[1] + tofX*(LRCV[1]-LLCV[1]);
	   //interpolate between top and bottom
	   IBTV[0] = IBV[0]+ tofY*(ITV[0]-IBV[0]);
	   IBTV[1] = IBV[1]+ tofY*(ITV[1]-IBV[1]);
	   rv[0] = IBTV[0];
	   rv[1] = IBTV[1];

}
