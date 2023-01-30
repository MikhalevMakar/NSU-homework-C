#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum {ShiftOneByte = 1, ShiftTwoByte = 2, ShiftFourByte = 4};

void ReverseBitsInArray(unsigned char* array, int sizeArray) {
    for (int i = 0; i < sizeArray; ++i) {
        array[i] = ((array[i] & 0x55) << ShiftOneByte) | ((array[i] & 0xaa) >> ShiftOneByte);
        array[i] = ((array[i] & 0xcc) >> ShiftTwoByte) | ((array[i] & 0x33) << ShiftTwoByte);
        array[i] = (array[i] >> ShiftFourByte) | (array[i] << ShiftFourByte);
    }

    for (int i = 0; i < sizeArray / 2; ++i ) {
        unsigned char curValue = array[sizeArray-i-1];
        array[sizeArray - i - 1] = array[i];
        array[i] = curValue;
    }
}

int main() {
    unsigned char* array = malloc(sizeof(unsigned char)*5);
    assert(array != NULL);
    for (int i = 0; i < 5;++i) {
        scanf("%d", &array[i]);
    }
    ReverseBitsInArray(array, 5);
    for (int i = 0; i < 5;++i) {
        printf("%d\n", array[i]);
    }
    return 0;
}
