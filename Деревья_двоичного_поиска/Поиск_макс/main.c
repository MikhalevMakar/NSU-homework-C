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

int FindMax(TTree* tree) {
    while(tree->Right != NULL) {
        tree = tree->Right;
    }
    return tree->Value;
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
    printf("%d", max);
    return 0;

}
