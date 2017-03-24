
int GetNumberOfPoints(const int *dims);

int GetNumberOfCells(const int *dims);

int GetPointIndex(const int *idx, const int *dims);

int GetCellIndex(const int *idx, const int *dims);

void GetLogicalPointIndex(int *idx, int pointId, const int *dims);

void GetLogicalCellIndex(int *idx, int cellId, const int *dims);

void EvaluateVectorFieldAtLocation(const float *pt, const int *dims, const float *X, 
                              const float *Y, const float *F, float *rv);
