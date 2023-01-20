#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int FindMin(int v1, int v2, int v3) {
if (v1 > v2) {
v1 = v2;
}
return (v1 > v3) ? v3 : v1;
}

void HammingNumbers(int N, int* arr) {
int I2 = 0;
int I3 = 0;
int I5 = 0;
int minValue = 0;
if (N == 0) {
return;
}
arr[0] = 1;
for (int i = 1; i < N; ++i) {
minValue = FindMin(arr[I2] * 2, arr[I3] * 3, arr[I5] * 5);
arr[i] = minValue;
I2 += (minValue >= arr[I2] * 2);
I3 += (minValue >= arr[I3] * 3);
I5 += (minValue >= arr[I5] * 5);
}
}


int main() {
int N = 0;
assert(scanf("%d", &N) == 1);
int* arr = malloc(N * sizeof(int));
HammingNumbers(N, arr);
for (int i = 0; i < N; ++i) {
printf("%d ", arr[i]);
}
return 0;
}
