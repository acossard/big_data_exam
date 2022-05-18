#include <iostream>

namespace common {
    const unsigned long long num_steps = 500000000; //number of x bins

    void print_results(double e, int n_threads){
            printf("e value: %.20f\n Number of steps: %llu\n Number of threads: %d\n",e,num_steps,n_threads);
    }
}
