#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Tree {
    char Value;
    struct Tree* Right;
    struct Tree* Left;
}Tree;

Tree* CreateTree(char value, Tree* left, Tree* right) {
    Tree* tree = malloc(sizeof(Tree));
    assert(tree != NULL);

    tree->Right = right;
    tree->Left = left;
    tree->Value = value;

    return tree;
}

Tree* ScanTree() {
    char value = getchar();

    switch (value) {

    case '-': case '+': case '/': case '*': {
        Tree* Left = ScanTree();
        Tree* Right = ScanTree();
        return CreateTree(value, Left, Right);
    }

    default:
        return CreateTree(value, NULL, NULL);
    }
}

void PrintTree(Tree* tree) {
    if (tree == NULL) {
        return;
    }

    printf("%c[", tree->Value);
    PrintTree(tree->Left);
    PrintTree(tree->Right);
    printf("]");
}

void DestroyTree(Tree* tree) {
    if (tree != NULL) {
        DestroyTree(tree->Left);
        DestroyTree(tree->Right);
        free(tree);
    }
}

bool IsZero(Tree* tree) {
    return tree != NULL && tree->Value == '0' && tree->Left == NULL && tree->Right == NULL;
}

bool IsOne(Tree* tree) {
    return tree != NULL && tree->Value == '1' && tree->Left == NULL && tree->Right == NULL;
}

void SimplifyMul(Tree** tree) {
    Tree* Left = (*tree)->Left;
    Tree* Right = (*tree)->Right;

    if (IsZero(Left) || IsZero(Right)) {
        DestroyTree(Left);
        DestroyTree(Right);
        (*tree)->Left = (*tree)->Right = NULL;
        (*tree)->Value = '0';
    }

    else if (IsOne(Left) || IsOne(Right)) {
        if (Left->Value == '1') {
            (*tree)->Value = Right->Value;
            DestroyTree(Left);
            DestroyTree(Right);
            (*tree)->Left = (*tree)->Right = NULL;
        }
        else {
            (*tree)->Value = Left->Value;
            DestroyTree(Left);
            DestroyTree(Right);
            (*tree)->Left = (*tree)->Right = NULL;
        }
    }
}

void SimplifyPlusZero(Tree** tree) {
    Tree* Left = (*tree)->Left;
    Tree* Right = (*tree)->Right;

    if (IsZero(Left) || IsZero(Right)) {
        if (IsZero(Right) == true) {
            (*tree)->Value = Left->Value;
        }
        else {
            (*tree)->Value = Right->Value;
        }
        DestroyTree(Left);
        DestroyTree(Right);
        (*tree)->Left = (*tree)->Right = NULL;
    }
}

void SimplifyMinusZero(Tree** tree) {
    Tree* Left = (*tree)->Left;
    Tree* Right = (*tree)->Right;

    if (Right->Value == '0') {
        (*tree)->Value = Left->Value;
        DestroyTree(Left);
        DestroyTree(Right);
        (*tree)->Left = (*tree)->Right = NULL;
    }

}

void SimplifyDivision(Tree** tree) {
    Tree* Left = (*tree)->Left;
    Tree* Right = (*tree)->Right;

    assert(Right->Value != '0');
    
    if (Left->Value == '0') {
        (*tree)->Value = '0';
        DestroyTree(Left);
        DestroyTree(Right);
        (*tree)->Left = (*tree)->Right = NULL;
    }
    
    else if (Right->Value == '1') {
        (*tree)->Value = Left->Value;
        DestroyTree(Left);
        DestroyTree(Right);
        (*tree)->Left = (*tree)->Right = NULL;
    }
}

Tree* SimplifyExpression(Tree* tree) {
    if (tree == NULL) {
        return NULL;
    }

    tree->Left = SimplifyExpression(tree->Left);
    tree->Right = SimplifyExpression(tree->Right);

    if (tree->Value == '*') {
        SimplifyMul(&tree);
    }

    else if (tree->Value == '+') {
        SimplifyPlusZero(&tree);
    }

    else if (tree->Value == '-') {
        SimplifyMinusZero(&tree);
    }

    else if (tree->Value == '/') {
        SimplifyDivision(&tree);
    }

    return tree;
}

int main() {
    Tree* tree = ScanTree();
    tree = SimplifyExpression(tree);
    PrintTree(tree);
    DestroyTree(tree);
    return 0;
}
