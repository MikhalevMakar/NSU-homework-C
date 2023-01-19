#include <stdio.h>
#include <windows.h>
#include <omp.h> 
#include <xmmintrin.h>

typedef struct TBarrier {
    volatile int ReleaseCount;
    volatile int JoinCount;
} TBarrier;

void WaitBarrier(TBarrier* barrier) {
    int threadId = omp_get_thread_num();
    int threadCount = omp_get_num_threads();
    if (threadId == 0) {
       
        #pragma omp atomic
        ++barrier->JoinCount;

        while (barrier->JoinCount != threadCount) {
            _mm_pause();
        }
        
        ++barrier->ReleaseCount;
#pragma omp atomic
        barrier->JoinCount ^= barrier->JoinCount;
    } 

    else { 
        int releaseCount = barrier->ReleaseCount; 
#pragma omp atomic
        ++barrier->JoinCount;

        while (barrier->ReleaseCount == releaseCount) {
            _mm_pause();
        }
    }
}


int main() {
    TBarrier b = {0, 0};
    int i;
    int threadCount = 4;
#pragma omp parallel for num_threads(threadCount)
    for (i = 0; i < threadCount * 10000; ++i) {

        printf("thread %d\n", omp_get_thread_num());
        WaitBarrier(&b);
        printf("thread %d\n", omp_get_thread_num());
        WaitBarrier(&b);
    }
    
    return 0;
}
