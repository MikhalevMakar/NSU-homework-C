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

int FindSecondMax(TTree* tree) {
    TTree* previousTree = tree;
    tree = tree->Right;
    while (tree->Right != NULL) {
        previousTree = tree;
        tree = tree->Right;
    }
    if (tree->Left != NULL) {
        while (tree->Left != NULL ) {
            tree = tree->Left;
        }
        return tree->Value;
    }
    else {
        return previousTree->Value;
    }
}

int main() {
    int N, currentValue = 0;
    assert(scanf("%d", &N) == 1);
    TTree* root = NULL;
    for (int i = 1; i <= N; ++i) {
        assert(scanf("%d", &currentValue) == 1);
        AddTree(&root, currentValue);
    }
    int secondMax = FindSecondMax(root);
    printf("%d", secondMax);
    return 0;

}
