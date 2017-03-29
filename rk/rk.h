//float SpeedCal(float *velocity);

void AdvectWithRKStep(const float *pt, const int *dims, const float *X,
                    const float *Y, const float *F, 
                    float h, int nsteps, float *output_locations, float *speeds);
//float CalculateArcLength(const float *output_locations, int nlocations);
