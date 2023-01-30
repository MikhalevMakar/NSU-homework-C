#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

int Max(int a, int b) {
    return (a > b) ? a : b;
}

void OutPut(int m, int M) {
    printf("%d %d \n", m, M);
}

void AlgoritmKanda(const int N, const int* arr) {
    
    int curSum = 0;
    int m = 0;
    int M = 0;
    int maxSum = 0;

// 1 -1 2 -3 2 4 2 5 -3

    for (int i = 0; i < N; ++i) {
        
        curSum = Max(arr[i], arr[i] + maxSum);
        maxSum = Max(curSum, maxSum);
        
        if (curSum == maxSum) {
            M = i;
        }

        if (curSum <= 0) {
            m = i+1;
        }
    }
    OutPut(m, M);
}

int main() {
    int N = 0;
    assert(scanf("%d", &N) == 1);
    int* arr = malloc(sizeof(int) * N);
    assert(arr != NULL);

    for (int i = 0; i < N; ++i) {
        assert(scanf("%d", &arr[i]) == 1);
    }

    AlgoritmKanda(N, arr);
    free(arr);

    return 0;
}
