#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
typedef struct TTree {
    int Value;
    struct TTree* Left;
    struct TTree* Right;
}TTree;

void AddTree(TTree** tree, int currentValue) {
    if (*tree == NULL) {
        *tree = malloc(sizeof(TTree));
        assert(*tree != NULL);
        (*tree)->Value = currentValue;
        (*tree)->Right = NULL;
        (*tree)->Left = NULL;
        return;
    }

    else if (currentValue <= (*tree)->Value) {
        AddTree(&(*tree)->Left, currentValue);
    }
    else {
        AddTree(&(*tree)->Right, currentValue);
    }
}

int ConvertBinarySearchTreeToArray(TTree* tree, int* array, int count) {
    if (tree == NULL) {
        return count;
    }
    count = ConvertBinarySearchTreeToArray(tree->Left, array, count);
    array[count] = tree->Value;
    count++;
    count = ConvertBinarySearchTreeToArray(tree->Right, array, count);
    return count;
}

int main() {
    int N, currentValue = 0;
    assert(scanf("%d", &N) == 1);
    TTree* root = NULL;
    for (int i = 1; i <= N; ++i) {
        assert(scanf("%d", &currentValue) == 1);
        AddTree(&root, currentValue);
    }
    int count = 0;
    int* array = malloc(sizeof(int)*N);
    int readCount = ConvertBinarySearchTreeToArray(root, array, count);
    for (int i = 0; i < N;++i) {
        printf("array[%d] = %d\n", i,array[i]);
    }
    printf("%d", readCount);
    return 0;

}
