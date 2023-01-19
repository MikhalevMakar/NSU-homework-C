#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* CreateArray(int N) {
    int* array = malloc(N*sizeof(int));
    assert(array != NULL);
    
    for (int i = 0; i < N;++i) {
        assert(scanf("%d", &array[i]) == 1);
    }

    return array;
}

void ReverseArray(int* array, int N) {
    for (int i = 0; i < N/2; ++i) {
        int curValue = array[N-i-1];
        array[N - i - 1] = array[i];
        array[i] = curValue;
    }

}
void Print(int N, int* array) {
    for (int i = 0; i < N; ++i) {
        printf("%d ", array[i]);
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);
    int* array = CreateArray(N);
    ReverseArray(array, N);
    Print(N, array);
    return 0;
}
