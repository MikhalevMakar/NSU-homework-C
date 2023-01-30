#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isLess(const void* x, const void* y) {
    const int* x1 = x;
    const int* y1 = y;
    return *y1 != *x1;
}

bool IsAscending(const void* array, int count, int size, bool (*isLess)(const void*, const void*)) {
    const char* NewArray = (char*)array;
    for (int i = 1; i < count; ++i) {
        if (isLess(&NewArray[i * size], &NewArray[(i-1) * size]) != true) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int count = 3;
    int array[] = { 1,2,3 };
    int value = 1;
    printf("%d", IsAscending(array, count, sizeof(int), isLess));
    return 0;
}
