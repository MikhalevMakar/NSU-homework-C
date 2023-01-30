#include <stdio.h>
#include <stdlib.h>
enum {N=2, m=2};

float Degree(float x, int i) {
    float z = x;
    if (i == 0) {
        z = 1;
    }
    if (i >= 2) {
        for (int k = 2; k <= i; ++k) {
            z = z * x;
        }
    }
    return z;
}

float CalcPoly(float array[N][m], float x, float y) {
    float sum = 0;
    
    for (int i = 0; i < N; ++i) {
        float z = Degree(x,i);
        for (int j = 0; j < m; ++j) {
            float h = Degree(y,j);
            sum += array[i][j] * z * h;
        }
    }

    return sum;
}

int main() {
    float y = 0, x = 0;
    scanf("%f %f", &x, &y);
    float array[N][m];
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("array[%d][%d]=", i, j);
            scanf("%f", &array[i][j]);
        }
    }

    float sum = CalcPoly(array, x, y);
    printf("%f", sum);
    return 0;
}
