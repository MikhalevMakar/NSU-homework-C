#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void ReverseWordOrder(int N, char arr[], int begin, int count) {
for (int i = begin; i < begin + count; ++i) {
char curSymbol = arr[i];
arr[i] = arr[N+begin-i-1];
arr[N+begin-i-1] = curSymbol;
}
}

void ReverseOrderRow(char arr[], int N) {
int count = 0;
for (int i = 1; i <= N; ++i) {
if (arr[i] == ' ' || i == N) {
ReverseWordOrder(i, arr, count, (i-count)/2);
count = i+1;
}
}
}

int main() {
int N = 11;
char arr[12] = "how are you";
arr[N] = '\0';
ReverseWordOrder(N, arr, 0, N/2);
ReverseOrderRow(arr, N);
printf("%s", arr);
return 0;
}

