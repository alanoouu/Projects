
void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int i, j;
 
	// Remove memory aliases
	float *local_avg = avg;
	float *local_passing_avg = passing_avg;
	int *local_num_passed = num_passed; 

   *local_num_passed = 0;
    *local_avg = 0.0;
    *local_passing_avg = 0.0;

/*	float local_F[N];
	for (int b = 0; i < N; ++i){
		local_F[b] = F[b];
		//local_F[b+1] = F[b+1];		// loop unrolling
	}*/

    // init ranks and compute averages

//	int local_R[N];  Doing this will increase the cycle time

	//int k[2] = {0,0};
    for (i = 0; i < N; ++i) {
	
	// init ranks
	R[i] = 1;

	// compute ranks- reduced number of loops
	for (j = 0; j < N; ++j) {
            if (F[i] < F[j]) {
                R[i] += 1;
            }
        }

	// compute averages - reduced number of loops
	 *local_avg += F[i];
        if (F[i] >= 50.0) {
            *local_passing_avg += F[i];
            *local_num_passed += 1;
        }
    }
	*avg = *local_avg;
	*passing_avg = *local_passing_avg;
	*num_passed = *local_num_passed;
	
 

    // compute ranks
/*    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (F[i] < F[j]) {
                R[i] += 1;
            }
        }
    } */  
/*

// compute averages
    for (i = 0; i < N; ++i) {
        *local_avg += F[i];
        if (F[i] >= 50.0) {
           *local_passing_avg += F[i];
            *local_num_passed += 1;
        }
    }
	*avg = *local_avg;
	*passing_avg = *local_passing_avg;
	*num_passed = *local_num_passed;
*/
    // check for div by 0
    if (N > 0) *avg = *avg / N;

	int *pointer = num_passed;
    if (*pointer) *passing_avg /= *pointer;
//	if (*num_passed) *passing_avg /= *num_passed;
} // compute_ranks

