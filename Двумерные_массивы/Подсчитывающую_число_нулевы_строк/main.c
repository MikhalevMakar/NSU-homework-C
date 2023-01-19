#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
enum {N = 2, M = 2};

int counting_zeros(int array[N][M]) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int sum1 = 0;
        
        for (int j = 0; j < M; ++j) {
            if (array[i][j] == 0) {
                sum1 += 1;
            }
        }

        if (sum1 == M) {
            sum += 1;
        }
    }

    return sum;
}
int main() {
    int sum0 = 0;
    int array[N][M];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("array[%d][%d]=", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    sum0 = counting_zeros(array);
    printf("%d", sum0);
    return 0;
}
