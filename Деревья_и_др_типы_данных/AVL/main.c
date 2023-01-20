#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

TTree* CreateAWL(int H, int* countValue) {
        if (H <= 0) {
            return NULL;
        }
        TTree* tree = malloc(sizeof(TTree));
        assert(tree != NULL);
        tree->Left = CreateAWL(H - 1, countValue);
        tree->Value = *countValue;
        ++*countValue;
        tree->Right = CreateAWL(H - 2, countValue);
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
    int H = 0;
    int countValue = 0;
    assert(scanf("%d", &countValue) == 1);
    assert(scanf("%d", &H) == 1);
    TTree* tree = CreateAWL(H, &countValue);
    Print(tree);
    return 0;
}
