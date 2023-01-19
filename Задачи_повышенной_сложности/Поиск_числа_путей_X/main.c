#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void  MultiplicationMatrix(int* matrix1, int* matrix2, int* matrixResult, int N) {
    for (int i = 0; i < N; ++i) {
        int value = 0;
        for (int k = 0; k < N; ++k) {
            for (int j = 0; j < N; ++j) {
                value += matrix1[i * N + j] * matrix2[j * N + k];
            }
            matrixResult[i * N + k] = value;
        }
    }
}

void ChangeValueInresultMatrix(int* matrixResult, int* matrix2, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix2[i * N + j] = matrixResult[i * N + j];
        }
    }
}

void SearchCountPath(int* matrix1, int* matrix2, int* matrixResult, int N) {
    int count = 0;
    assert(scanf("%d", &count) == 1);

    if (count == 1) {
        ChangeValueInresultMatrix(matrixResult, matrix2, N);
        return;
    }

    else {
        for (int i = 0; i < count - 1; ++i) {
            MultiplicationMatrix(matrix1, matrix2, matrixResult, N);
            ChangeValueInresultMatrix(matrixResult, matrix2, N);
        }
    }
    return;
}

int main() {
    int N, M, valueFrom, valueTo = 0;
    assert(scanf("%d %d", &N, &M) == 2);

    int* matrix1 = calloc(N * N, sizeof(int));
    assert(matrix1 != NULL);

    int* matrix2 = calloc(N * N, sizeof(int));
    assert(matrix2 != NULL);

    int* resultMatrix = calloc(N * N, sizeof(int));
    assert(resultMatrix != NULL);

    for (int i = 0; i < M; ++i) {
        assert(scanf("%d %d", &valueFrom, &valueTo) == 2);
        matrix1[(valueFrom - 1) * N + valueTo - 1] = 1;
        matrix2[(valueFrom - 1) * N + valueTo - 1] = 1;
    }
    
    SearchCountPath(matrix1, matrix2, resultMatrix, N);
    assert(scanf("%d %d", &valueFrom, &valueTo) == 2);

    printf("%d", resultMatrix[(valueFrom - 1) * N + valueTo - 1]);
    return 0;
}
