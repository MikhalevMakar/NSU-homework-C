#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

static void GenerationValue(int N, int* palindrArr) {
    if (N == 0) {
        return;
    }

    int createValue = 0;
    int index = 0;
    palindrArr[index] = createValue;

    for (int firstBit = 0; firstBit < 32; ++firstBit) {
        int secondBit = -1;
        while (secondBit < firstBit) {
            index++;
            if (N == index) {
                return;
            }
            createValue = 1 << firstBit;
            
            if (secondBit != -1) {
                createValue |= 1 << secondBit;
            }
            palindrArr[index] = createValue;
            secondBit++;
        }
    }
}

int main() {
    int N = 0;
    assert(scanf("%d", &N) == 1);
    int* palindromArr = malloc(N * sizeof(int));
    assert(palindromArr != NULL);

    GenerationValue(N, palindromArr);

    for (int i = 0; i < N; ++i) {
        printf("%d ", palindromArr[i]);
    }
    return 0;
}
