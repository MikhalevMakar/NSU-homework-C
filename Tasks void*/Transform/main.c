#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void MultiplicationBy10(void* x) {
    int* y = x;
    *y = (*y) * 10;
}

void Transform(void* array, size_t count, size_t size, void (*t)(void*)) {
    char* NewArray = (char)array;
    for (int i = 0; i < count; ++i) {
        t(&NewArray[i * size]);
    }
}

int main(void) {
    size_t size = 3;
    int array[size] = { 1,2,3 };
    Transform(array, size, sizeof(int), MultiplicationBy10);
    return 0;
}
