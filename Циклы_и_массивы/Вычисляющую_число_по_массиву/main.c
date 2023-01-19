#include <stdio.h>
#include <malloc.h>
#include <math.h>
int translade(char *number,int N) {
    int sum = 0;
    for (int i = N-1; i>=0; i--) {
        sum += (number[i] - '0') * pow(10,i);
    }
    return sum;
}
int main() {
    int N;
    scanf("%d", &N);
    char* number = (char*)malloc(N * (sizeof(char)));
    if (number != NULL) {
        scanf("%s", number);
        printf("%d", translade(number,N));
    }
        free(number);
    return 0;
}
