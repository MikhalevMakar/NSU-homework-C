#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

int SearchSumDivisiors(int value) {
int sum = 0;
for (int i = 1; i < value; ++i) {
if (value % i == 0) {
sum += i;
}
}
return sum;
}

void PerfectDivisors(int N) {
int count = 0;
for (int i = 6; i < INT_MAX; ++i) {
if (SearchSumDivisiors(i) == i) {
printf("%d ", i);
count++;
}
if (N == count) {
return;
}
}
}

int main() {
int N = 0;
assert(scanf("%d", &N) == 1);
PerfectDivisors(N);
return 0;
}
