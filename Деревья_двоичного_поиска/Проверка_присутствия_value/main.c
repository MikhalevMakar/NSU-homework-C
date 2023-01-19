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


TTree* FindValue(TTree* tree, int value) {
    while (tree != NULL) {
        if (tree->Value == value) {
            return tree;
        }
        else if (tree->Value < value) {
            tree = tree->Right;
        }
        else {
            tree = tree->Left;
        }
    }
    return NULL;
}

int main() {
    int N, value, currentValue = 0;
    assert(scanf("%d", &N) == 1);
    assert(scanf("%d", &value) == 1);
    TTree* root = NULL;
    for (int i = 1; i <= N; ++i) {
        assert(scanf("%d", &currentValue) == 1);
        AddTree(&root, currentValue);
    }
    TTree* tree = FindValue(root, value);
    printf("%p", tree);
    return 0;
}
