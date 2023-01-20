#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool IsPalindrom(int value) {
int leftDevider = 1;
int count = 0;
while (value / leftDevider >= 10) {
leftDevider *= 10;
count++;
}
if (count == 0) {
return true;
}
int rigthDevider = 10;
count = count / 2 + 1;
int curValue = value % rigthDevider;
while (count != 0) {
if ((value / leftDevider) % 10 != curValue) {
return false;
}
—count;
leftDevider /= 10;
rigthDevider *= 10;
curValue = (value % rigthDevider) / 10;
}
return true;
}

static void GenerationPalindrom(int N, int* palindrArr) {
int value = 1;
int count = 0;
while (count != N) {
if (IsPalindrom(value) == true && IsPalindrom(value*value) == true) {
palindrArr[count] = value;
++count;
}
++value;
}
}

int main() {
int N = 0;
assert(scanf("%d", &N) == 1);
int* palindromArr = malloc(N * sizeof(int));
assert(palindromArr != NULL);
GenerationPalindrom(N, palindromArr);
for (int i = 0; i < N; ++i) {
printf("%d ", palindromArr[i]);
}
return 0;
}

