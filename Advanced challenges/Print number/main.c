#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

void FillNumber(int* number, int count) {
    for (int i = 0; i < count;++i) {
        assert(scanf("%d", &number[i]) == 1);
    }
}

int* CreateNumbers(int count) {
    int* number = malloc(count*sizeof(int));
    
    assert(number != NULL);

    FillNumber(number, count);
    
    return number;
}

int FindMin(int* numbers, int count) {
    int min = INT_MAX;
    for (int i = 0; i < count;++i) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    return min;
}

int FindMax(int* numbers, int count) {
    int max = INT_MIN;
    for (int i = 0; i < count; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    return max;
}

int FindMissedValue(int count, int* numbers) {
    int min = FindMin(numbers, count);
    int max = FindMax(numbers, count);
    
    int a = max - min + 1;
    int bin = sqrt(a)+1;
    int sizeH = count / bin;
    int* H = calloc(sizeH, sizeof(int));
    assert(H != NULL);

    for (int i = 0; i < count; ++i) {
        H[(numbers[i]-min) / bin] += 1;
    }

    int index = 0;
    
    for (int i = 0; i < count/bin; ++i) {
        if (H[i] != bin) {
            index = i;
        }
    }
    
    for (int i = 0; i < bin;++i) {
        if (index * bin + i < count && numbers[index*bin+i] != index * bin + i + 1) {
            return index* bin + i + 1;
        }
    }
}

int main() {
    int count = 1;
    assert(scanf("%d", &count) == 1);
    //1 2 3 4 5 6 7 9
    int* numbers = CreateNumbers(count);

    printf("%d", FindMissedValue(count, numbers));
    return 0;
}
