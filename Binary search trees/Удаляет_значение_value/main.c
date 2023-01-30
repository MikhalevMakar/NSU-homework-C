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
TTree* FindPreviousValue(TTree* tree, int value) {
    TTree* previous = tree;
    while (tree != NULL) {
        if (tree->Value == value) {
            return previous;
        }

        else if (tree->Value < value) {
            previous = tree;
            tree = tree->Right;
        }

        else {
            previous = tree;
            tree = tree->Left;
        }

    }
    return NULL;
}
void Delete(TTree* rootValue, TTree* root, int value) {
    TTree* previous;
    if (rootValue->Right != NULL) {
        while (rootValue->Right != NULL) {
            previous = rootValue;
            rootValue->Value = rootValue->Right->Value;
            rootValue = rootValue->Right;
        }
        free(rootValue);
        previous->Right = NULL;
    }
    else if (rootValue->Left != NULL) {
        while (rootValue->Left != NULL) {
            previous = rootValue;
            rootValue->Value = rootValue->Left->Value;
            rootValue = rootValue->Left;
        }
        free(rootValue);
        previous->Left = NULL;
    }
    else {
        previous = FindPreviousValue(root, value);
        if (previous->Right != NULL && previous->Right->Value == value) {
            free(previous->Right);
            previous->Right = NULL;
        }
        else {
            free(previous->Left);
            previous->Left = NULL;
        }
    }
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
    TTree* rootValue = FindValue(root, value);
    assert(rootValue != NULL);
    Delete(rootValue, root, value);
    PrintTree(root);
    return 0;
}
