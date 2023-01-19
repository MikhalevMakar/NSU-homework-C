#include <stdio.h>
int fact(int a) {
    int summ = 1;
    for (int i = 1; i <= a; i++) {
        summ *= i;
    }
    return summ;
}
int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", fact(a));
    return 0;
}
