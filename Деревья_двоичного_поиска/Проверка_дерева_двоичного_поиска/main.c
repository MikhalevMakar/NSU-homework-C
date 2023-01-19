#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

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

int FindMax(TTree* tree) {
    while (tree->Right != NULL) {
        tree = tree->Right;
    }
    return tree->Value;
}

int FindMin(TTree* tree) {
    while (tree->Left != NULL) {
        tree = tree->Left;
    }
    return tree->Value;
}

bool IsBinarySearchTree(TTree* t, int minValue, int maxValue) {
        if (t == NULL) {
            return true;
        }
        bool result = minValue <= t->Value && t->Value <= maxValue;
        result = result && IsBinarySearchTree(t->Left, minValue, t->Value) && IsBinarySearchTree(t->Right, t->Value, maxValue);
        return result;
}

int main() {
    int N, currentValue = 0;
    assert(scanf("%d", &N) == 1);
    TTree* root = NULL;
    for (int i = 1; i <= N; ++i) {
        assert(scanf("%d", &currentValue) == 1);
        AddTree(&root, currentValue);
    }
    int max = FindMax(root);
    int min = FindMin(root);
    bool result = IsBinarySearchTree(root, min, max);
    printf("%d", result);
    return 0;
}
