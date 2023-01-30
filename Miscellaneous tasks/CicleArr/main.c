#include <stdio.h>
int NOD(int v1, int v2) {
while (v1 != v2) {
if (v1 > v2) {
v1 = v1 - v2;
}

else {
v2 = v2 - v1;
}
}
return v1;
}

void ShiftArray(int* array, int n, int k) {
int nod = NOD(n, k);
for (int i = 0; i < nod; ++i) {
for (int j = 0; j < n / nod; ++j) {
int curValue = array[i];
array[i] = array[(i + k) % n];
array[(i + k) % n] = curValue;
}
}
}

int main(void) {
int n = 5;
int array[n];
for (int i = 0; i < n; ++i) {
scanf("%d", &array[i]);
}
ShiftArray(array, n, 2);
return 0;
}
