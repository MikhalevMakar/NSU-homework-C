#include <stdio.h>
#include <xmmintrin.h>
#include <assert.h>

enum {sizeLine = 8, sizeMatrix = 4};

void MatrixTransposition(float** matrix) {
    __m128  prevLine1, prevLine2, line1,line2;

    for (int i = 0; i <= 2; ++i) {
         prevLine1 = _mm_loadu_ps(matrix[i]);
         prevLine2 = _mm_loadu_ps(matrix[i+1]);
        
        line1 = _mm_unpacklo_ps(prevLine1, prevLine2);
        line2 = _mm_unpackhi_ps(prevLine1, prevLine2);

        prevLine1 = _mm_movelh_ps(line1, line2);
        prevLine2 = _mm_movehl_ps(line2, line1);

        _mm_storeu_ps(matrix[i], prevLine1);
        _mm_storeu_ps(matrix[++i], prevLine2);
    }

    for (int i = 0; i < 2; ++i) {
        prevLine1 = _mm_loadu_ps(matrix[i]);
        prevLine2 = _mm_loadu_ps(matrix[i + 2]);

        line1 = _mm_movelh_ps(prevLine1, prevLine2);
        line2 = _mm_movehl_ps(prevLine2, prevLine1);
        _mm_storeu_ps(matrix[i],  line1);
        _mm_storeu_ps(matrix[i+2],  line2);
    }
}

//1 2 3 4 5 6 7 8  9 10 11 12 13 14 15 16

int main() {

    float** matrix = malloc(sizeMatrix * sizeof(float*));
    assert(matrix != NULL);
        
    for (int i = 0; i < sizeMatrix; ++i) {
        matrix[i] = malloc(sizeMatrix* sizeof(float));
        assert(matrix[i] != NULL);
    }

    for (int i = 0; i < sizeMatrix; ++i) {
        for (int j = 0; j < sizeMatrix; ++j) {
            assert(scanf("%f", &matrix[i][j]) == 1);
        }
    }

    MatrixTransposition(matrix);
    
    for (int i = 0; i < sizeMatrix; ++i) {
        for (int j = 0; j < sizeMatrix; ++j) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
