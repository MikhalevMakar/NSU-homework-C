#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

static bool CheckArifProg(int* progArr, int N, int min, int max) {
    int d = (max - min) / (N - 1);
    int index = min;
    for (int i = 0; i < N; ++i) {
        if (progArr[index] != 1) {
            return false;
        }
        index += d;
    }
    return true;
}



static int* InputElementsProg(int N, int* min, int* max) {
    int* progArr = calloc(INT_MAX, sizeof(int));
    assert(progArr != NULL);
    int index = 0;
    for (int i = 0; i < N; ++i) {
        assert(scanf("%d", &index) == 1);
        if (*min > index) {
            *min = index;
        }

        if (*max < index) {
            *max = index;
        }

        if (progArr[index] == 1) {
            return NULL;
        }
        progArr[index] = 1;
    }
    return progArr;
}

int main() {
    int N = 0;
    assert(scanf("%d", &N) == 1);
    int min = INT_MAX;
    int max = INT_MIN;
    int* progArr = InputElementsProg(N, &min, &max);
    if (progArr == NULL) {
        printf("false\n");
        return 0;
    }
    printf("%d", CheckArifProg(progArr, N, min, max));
    return 0;
}
