#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isEqual(const void* x, const void* y) {
    const int* x1 = x;
    const int* y1 = y;
    return *y1 == *x1;
}

int Count(const void* array, int n, int size, const void* value, bool (*isEqual)(const void*, const void*)) {
    int  count = 0;
    const char* NewArray = (char*)array;
    for (int i = 0; i < n; ++i) {
        if (isEqual(&NewArray[i * size], value) == true) {
            count++;
        }
    }
    return count;
}
int main(void) {
    int size = 3;
    int array[] = { 1,2,3 };
    int value = 1;
    printf("%d", Count(array, size, sizeof(int), &value, isEqual));
    return 0;
}
