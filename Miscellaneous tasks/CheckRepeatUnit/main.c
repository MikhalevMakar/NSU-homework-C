#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
enum { BYTES = 32};

bool CheckRepeatUnit(unsigned int value, int i) {
unsigned int checkValue = 1610612736 » i;
if ((checkValue & value ) == checkValue) {
return true;
}
else {
return false;
}
}

int UnitRepeatCounter(unsigned int value) {
int count = 0;
for (int i = 0; i < BYTES - 2; ++i) {
if (CheckRepeatUnit(value, i) == true) {
++count;
}
}
return count;
}


int main() {
unsigned int value = 0;
assert(scanf("%d", &value) == 1);
printf("%d", UnitRepeatCounter(value));
return 0;
}

