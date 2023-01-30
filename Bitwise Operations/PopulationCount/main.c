#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

enum { ShiftOneByte = 1, ShiftTwoByte = 2, ShiftFourByte = 4, ShiftEightByte = 8, ShiftSixteenByte = 16};

unsigned int  PopulationCount(unsigned int value) {
    value = (value & 0x55555555) + ((value >> ShiftOneByte) & 0x55555555);
    value = (value & 0x33333333) + ((value >> ShiftTwoByte) & 0x33333333);
    value = (value & 0xf0f0f0f) + ((value >> ShiftFourByte) & 0xf0f0f0f);
    value = (value & 0xff00ff) + ((value >> ShiftEightByte) & 0xff00ff);
    value = (value & 0x7fff) + ((value >> ShiftSixteenByte) & 0x7fff);
    return value;
}

int main() {
    unsigned int value = INT_MAX-1;
    printf("%d", PopulationCount(value));
    return 0;
}

/*
#include <stdio.h>
unsigned char PopulationCount(unsigned char x) {
    x = (x & 0x55) + ((x & 0xaa) >> 1);
    x = ((x & 0x33)) + ((x & 0xcc) >> 2);
    x = (x & 0x0f) + ((x & 0xf0) >> 4);
    return x;
}
int main() {
    unsigned char x;
    scanf("%hhu", &x);
    unsigned char  a = PopulationCount(x);
    printf("%hhu\n", a);
    return 0;
*/
