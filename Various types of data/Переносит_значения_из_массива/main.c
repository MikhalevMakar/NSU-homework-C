#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
typedef struct TTree {
    int Value;
    struct TTree* Left;
    struct TTree* Right;
}TTree;

TTree* AddTree(int currentValue) {
    TTree* tree = malloc(sizeof(TTree));
    assert(tree != NULL);
    tree->Value = currentValue;
    tree->Right = NULL;
    tree->Left = NULL;
    return tree;
}
TTree* ConvertBinarySearchTreeToArray(int* array, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int middle = (left + right) / 2;
    TTree* tree = AddTree(array[middle]);
    tree->Left = ConvertBinarySearchTreeToArray(array, left, middle - 1);
    tree->Right = ConvertBinarySearchTreeToArray(array, middle + 1, right);
    return tree;
}

void Print(TTree* tree) {
    if (tree == NULL) {
        printf(".");
        return;
    }
    else {
        printf("%d[", tree->Value);
        Print(tree->Left);
        Print(tree->Right);
        printf("]");
    }
}

int main() {
    int N, currentValue = 0;
    assert(scanf("%d", &N) == 1);
    int* array = malloc(sizeof(int)*N);
    for (int i = 0; i < N; ++i) {
        assert(scanf("%d", &array[i]) == 1);
    }
    TTree* tree = ConvertBinarySearchTreeToArray(array, 0, N-1);
    Print(tree);
    return 0;

}
