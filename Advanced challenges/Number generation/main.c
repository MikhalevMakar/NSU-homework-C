#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

void OutPut(long long m) {
    printf("%lld ",  m);
}


void GeneratNumBEValue(long long value) {
    
    long long curValue = value;
    long long  exp = 0;
    long long mult = 1;

    while(1){
        mult *= 10;
        exp = curValue * value;
        curValue = (exp % mult) * 10 + value;
        
        if (curValue / mult == value) {
            OutPut(curValue);
            return;
        }

    }
}

int main() {
    long long N = 0;
    assert(scanf("%lld", &N) == 1);

    GeneratNumBEValue(N);

    return 0;
}
