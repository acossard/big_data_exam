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


int main()
{
    StopWatch stopWatch; //this object will be destroyed when out of scope

    int A, B;
    double E, D;
    int n_threads=1;
      
    double step = 1.0/(double) common::num_steps; //x-step 
    double sums[128];    
    double sum = 0.0;    

    #pragma omp parallel    
    {
    

    double tmp;
  
    #pragma omp for
    for (A=1; A<=15; A++ )
    {
        n_threads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();
 
        std::cout << "n threads "<<n_threads<<std::endl;
        std::cout << "thread id "<<thread_id<<std::endl;
        
        D=1;
        for (B=1; B<=A ; B++ )
        {
            D = D * B;
        }
        tmp = E + 1 / D;

        #pragma omp critical
        E += tmp; 
    }


    }
   
   
    for(unsigned int j=0; j<128; j++){
        sum += sums[j];
    }

    std::cout<<"Estimated Value of e is "<< E + 1 <<std::endl;

    common::print_results(E+1,n_threads);
    
    return 0;
}