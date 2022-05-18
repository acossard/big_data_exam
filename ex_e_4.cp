//---------------------------------------------------------------------
// This program is made to compute pi numerical value.
// It will numerically compute the integral of
//
//                   4/(1+x*x)
//
// from 0 to 1 using variable number of steps.
// The value of this integral is pi. The knowing of pi is quite 
// precise and the result can be compared to the "real" value.
//
// The is the basic sequential program.
// It uses a timer class defined in a separate header file.
//
// History: 
// Written by Gabriele Gaetano Fronzé, 01/18.
// Based on Tim Mattson implementation, 11/99.
//---------------------------------------------------------------------

#include "StopWatch.h"
#include <iostream>
#include "common.h"
#include <omp.h>
#include <vector>
#include <numeric>

int main()
{
    StopWatch stopWatch; //this object will be destroyed when out of scope

    int A, B;
    double E, D;
    int n_threads=1;
    std::vector<double> sums;  
    double step = 1.0/(double) common::num_steps; //x-step
    
    #pragma omp parallel    
    {

    n_threads = omp_get_num_threads();
    uint thread_id = omp_get_thread_num();

    
    if(thread_id == 0) sums.resize(n_threads);
    #pragma omp barrier

    #pragma omp for
    for (A=1; A<=15; A++ )
    {

        D=1;
        for (B=1; B<=A ; B++ )
        {
            D = D * B;
        }
        sums[thread_id] += 1 / D;
    }
        
         E = 1 + std::accumulate(sums.begin(), sums.end(), 0);
    }
   
    std::cout<<"Estimated Value of e is "<< E <<std::endl;

    common::print_results(E+1,n_threads);
    
    return 0;
}
