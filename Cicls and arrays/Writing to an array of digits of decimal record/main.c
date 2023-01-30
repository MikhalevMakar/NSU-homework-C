#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int lenght(int number) {
  int cnt = 0;
  while (number != 0) {
    number = number / 10;
    cnt += 1;
  }
  return cnt;
}
char* array(int number,int cnt,char*a) {
  for (int i = 0; i <cnt; i++) {
    a[i] = 0;
  }
  return a;
}
char* write(int number,int cnt,char* a) {
  for (int i = 0; i < cnt; i++) {
    a[i] = ((number % 10) + '0');
    number=number/10;
  }
  return a;
}
int  main() {
  int number;
    scanf("%d", &number);
  int cnt =lenght(number);
    char* a[cnt];
  array(number,cnt,a);
  write(number, cnt,a);
  printf("%s", a);
  return 0;
}
