#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int SearchMinPointer(int* pointerX, int* pointerY, int N) {
    int min = INT_MAX;
    int index = 0;
    for (int i = 0; i < N;++i) {
        int length = pointerX[i] * pointerX[i] + pointerY[i] * pointerY[i];
        if (min > length) {
            min = length;
            index = i;
        }
    }
    return index;
}

float SearchMiddle(float L, float R) {
    return (L + R) / 2;
}

float Sqrt(float a) {
    float e = 0.0001;
    float L = e;
    float R = a + 1;
    float middle = SearchMiddle(L, R);
    while (R - L >= e) {
        if (middle * middle > a + e) {
            R = middle;
        }
        else {
            L = middle;
        }
        middle = SearchMiddle(L, R);
    }
    return middle;
}
float Sqr(float x) {
    return (x * x);
}
float СountingСos(int x2, int y2, int x1, int y1) {
    float value = (float)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return (x2 - x1) / Sqrt(value);
}

int  FindNextVector(int* pointX, int* pointY, char* visit, int N, int S, int previousIndex) {
    float maxCos = -1;
    int index = 0;
    for (int i = 0; i < N; ++i) {
        if (visit[i] == 0 && i != S && previousIndex != i) {
            float curCos = СountingСos(pointX[i], pointY[i], pointX[S], pointY[S]);
            if (maxCos < curCos) {
                maxCos = curCos;
                index = i;
            }
            printf("%d\n", index);
        }
    }
    return index;
}

void BuildingShell(int* pointX, int* pointY, char* visit, float* pointShell, int N) {
    int S = SearchMinPointer(pointX, pointY, N);
    int index = FindNextVector(pointX, pointY, visit, N, S, S);
    int prevIndex = S;
    visit[index] = 1;
    while (index != S) {
        pointShell[index] = Sqrt(Sqr((float)pointX[index])+Sqr((float)pointY[index]));
        visit[index] = 1;
        int curIndex = index;
        index = FindNextVector(pointX, pointY, visit, N, index, prevIndex);
        prevIndex = index;
    }
    pointShell[index] = Sqrt(Sqr((float)pointX[index]) + Sqr((float)pointY[index]));
}

int main() {
    int N = 0;
    assert(scanf("%d", &N) == 1);
    
    int* pointX = malloc(sizeof(int)*N);
    assert(pointX != NULL);

    int* pointY = malloc(sizeof(int)*N);
    assert(pointY != NULL);
    
    for (int i = 0; i < N;++i) {
        assert(scanf("%d %d", &pointX[i], &pointY[i]) == 2);
    }

    char* visit = calloc(N, sizeof(char));
    assert(visit != NULL);

    float* pointShell = calloc(N, sizeof(float));
    assert(pointShell != NULL);

    BuildingShell(pointX, pointY, visit, pointShell, N);
    for (int i = 0; i < N; ++i) {
        printf("%f ", pointShell[i]);
    }

    return 0;
}
