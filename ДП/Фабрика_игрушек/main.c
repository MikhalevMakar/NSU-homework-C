#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Cube {
    int a;
    int b;
    int c;
}Cube;

typedef struct SortedCube {
    int BaseArea;
    int Height;
}SortedCube;

void Swap(SortedCube* array, int right, int left) {
    SortedCube rewriting = array[right];
    array[right] = array[left];
    array[left] = rewriting;
}

int  QuickSortImpl(SortedCube* array, int right, int left) {
    int pivot = array[(right + left) / 2].BaseArea;
    
    while (left <= right) {
        
        while (array[left].BaseArea < pivot) {
            left += 1;
        }
        
        while (array[right].BaseArea > pivot) {
            right -= 1;
        }

        if (left <= right) {
            
            if (array[left].BaseArea > array[right].BaseArea) {
                Swap(array, right, left);
            }

            left += 1;
            right -= 1;
        }
    }

    return left;
}

void QuickSort(SortedCube* array, int left, int right) {
    int support = QuickSortImpl(array, right, left);
    
    if (left < support - 1) {
        QuickSort(array, left, support - 1);
    }

    if (right > support) {
        QuickSort(array, support, right);
    }
}

void FillValue(int numCubes, Cube* cube) {
    for (int i = 0; i < numCubes;++i) {
        assert(scanf("%d %d %d", &cube[i].a, &cube[i].b, &cube[i].c) == 3);
    }
}

Cube* CreateCubes(int numCubes) {

    Cube* cube = calloc(numCubes, sizeof(Cube));
    assert(cube != NULL);
    
    FillValue(numCubes, cube);
    
    return cube;
}

SortedCube* CreateBase(int numCubes, Cube* cube) {
    
    int numBase = 3 * numCubes;
    SortedCube* maxBase = malloc(numBase * sizeof(SortedCube));
    assert(maxBase != NULL);
    
    int indexBase = 0;

    int indexCube = 0;

    while (indexCube < numCubes && (indexBase+2) < numBase) {

        maxBase[indexBase].BaseArea = cube[indexCube].a * cube[indexCube].b;
        maxBase[indexBase].Height = cube[indexCube].c;
        
        maxBase[++indexBase].BaseArea = cube[indexCube].b * cube[indexCube].c;
        maxBase[indexBase].Height = cube[indexCube].a;

        maxBase[++indexBase].BaseArea = cube[indexCube].a * cube[indexCube].c;
        maxBase[indexBase].Height = cube[indexCube].b;
        
        ++indexCube;
        ++indexBase;

    }

    free(maxBase);
    free(cube);
    return maxBase;
}

int BulldingTower(int numCubes, Cube* cube) {
    SortedCube* maxBase = CreateBase(numCubes, cube);
    QuickSort(maxBase, 0, 3*numCubes-1);
    
    int heightTower = 0;

    for (int i = 0; i < 3 * numCubes;++i) {
        heightTower += maxBase[i].Height;
    }

    return heightTower;
}

int main() {
    int numCubes = 0;
    assert(scanf("%d", &numCubes) == 1);

    Cube* cube = CreateCubes(numCubes);
    
    printf("%d\n", BulldingTower(numCubes, cube));

    return 0;
}





