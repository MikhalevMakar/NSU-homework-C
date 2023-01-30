#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
enum { N = 2,M = 2};

int sum_for_array(int array[N][M]) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            sum += array[i][j];
        }
    }
    return sum;
}
int main() {
    int sum1 = 0;
    int array[N][M];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("array[%d][%d]=", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    sum1 = sum_for_array(array);
    printf("%d", sum1);
    return 0;
}
