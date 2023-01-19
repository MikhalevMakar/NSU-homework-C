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

TTree* NodeTree(TTree* tree, int value) {
    TTree* root = malloc(sizeof(TTree));
    assert(root != NULL);
    root->Value = value;
    root->Right = NULL;
    root->Left = NULL;
    return root;
}

TTree* Insert(TTree* root ,int value) {
    if (root == NULL) {
        root = NodeTree(root, value);
    }

    else if (root->Value > value){
        root->Left = Insert(root->Left, value);
    }

    else  {
        root->Right = Insert(root->Right, value);
    }
    return root;
}

void PrintTree(TTree* root)
{
    if (root == NULL)
    {
        printf("*");
        return;
    }

    else
    {
        printf("%d[", root->Value);
        PrintTree(root->Left);
        printf(" ");
        PrintTree(root->Right);
        printf("]");
    }
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
    TTree* head = Insert(root,value);
    PrintTree(root);
    return 0;
}
