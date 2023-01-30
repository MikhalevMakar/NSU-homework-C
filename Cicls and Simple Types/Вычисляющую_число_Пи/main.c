#include <stdio.h>
#include <math.h>
float mult(int  n) {
    float summ = 0;
    int i;
    for (i = 1; i <= n; i++) {
        summ += pow(i, -2) * 6;
    }
    summ = sqrt(summ);
    return summ;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%f\n", mult(n));
    return 0;
}
