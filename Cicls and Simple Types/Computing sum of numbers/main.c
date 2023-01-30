#include <stdio.h>
#include <math.h>
int summ(int a) {
    int sum = 0;
    while (a != 0) {
        sum += (a % 10);
        a /= 10;
    }
    return sum;
}
int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", summ(a));
}
