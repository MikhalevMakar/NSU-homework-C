#include <stdio.h>
#include <math.h>
int f(float a, int n) {
    int sum = 0;
    int y = a;
    int z = (a - y) * pow(10, n);
        while (z!=0) {
        sum += (z % 10);
        z /= 10;
    }
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    float a;
    scanf("%f", &a);
    printf("%d\n", f(a, n));
        return 0;
}
