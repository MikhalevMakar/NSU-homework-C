#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

float SearchMiddle(float L, float R){
return (L+R)/2;
}

float Sqrt(float a, float e) {
float L = e;
float R = a + 1;
float middle = SearchMiddle(L, R);
while (R - L >= e) {
if (middle*middle > a + e) {
R = middle;
}
else {
L = middle;
}
middle = SearchMiddle(L, R);
printf("%f\n", middle);
}
return middle;
}

int main() {
float a, e = 0;
scanf("%f %f", &a, &e);
printf("%f", Sqrt(a, e));
return 0;
}
