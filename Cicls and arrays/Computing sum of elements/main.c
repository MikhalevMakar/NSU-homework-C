#include <stdio.h>
#include <string.h>
#include <malloc.h>
int summ(int * number,int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        printf("%d\n",number[i]);
        sum += number[i] ;
    }
    return sum;
}
int* make_array(int* number, int N) {
    for (int i = 0; i < N; i++) {
        number[i] = 0;
    }
    return number;
}
int* write_array(int* number, int N,int digit) {
    for (int i=0;i<N;i++) {
        int b = digit % 10;
        number[i] = b;
        digit/= 10;
    }
    return number;
}
int sum(int* number, int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += number[i];
    }
    return sum;
}
int  main() {
    int digit,N;
    scanf("%d", &N);
    int* number = (int*)malloc(N * (sizeof(int)));
    make_array(number,N);
    scanf("%d", &digit);
     write_array(number,N,digit);
    printf("%d", sum(number, N));
    free(number);
    return 0;
}
