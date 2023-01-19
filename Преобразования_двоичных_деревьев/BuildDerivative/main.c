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

void BuildMinus(Tree** tree, char var) {
    Tree* Left = (*tree)->Left;
    Tree* Right = (*tree)->Right;
    if (Left->Value != var) {
        (*tree)->Left->Value = '0';
    }

    if (Right->Value != var) {
        (*tree)->Right->Value = '0';
    }

    if (Left->Value == var) {
        (*tree)->Left->Value = '1';
    }

    if (Right->Value == var) {
        (*tree)->Right->Value = '1';
    }
}

void BuildPlus(Tree** tree, char var) {
    Tree* Left = (*tree)->Left;
    Tree* Right = (*tree)->Right;

    if (Left->Value != var) {
        (*tree)->Left->Value = '0';
    }

    if (Right->Value != var) {
        (*tree)->Right->Value = '0';
    }

    if (Left->Value == var) {
        (*tree)->Left->Value = '1';
    }

    if (Right->Value == var) {
        (*tree)->Right->Value = '1';
    }
}

void BuildMul(Tree** tree, char var) {
    Tree* Left = (*tree)->Left;
    Tree* Right = (*tree)->Right;
    Tree* curLeft = NULL;
    Tree* curRight = NULL;

    (*tree)->Value = '+';

    char RightValue = Right->Value;
    char LeftValue = Left->Value;
    
    if (Left->Value != var ) {
        DestroyTree(Left);

        curLeft = CreateTree('0', NULL, NULL);
        curRight = CreateTree(RightValue, NULL, NULL);

        (*tree)->Left = CreateTree('*', curLeft, curRight);
    }
    
    else if (Left->Value == var) {
        DestroyTree(Left);

        curLeft = CreateTree('1', NULL, NULL);
        curRight = CreateTree(RightValue, NULL, NULL);
        
        (*tree)->Left = CreateTree('*', curLeft, curRight);
    }

    if (Right->Value != var) {
        DestroyTree(Right);

        curLeft = CreateTree(LeftValue, NULL, NULL);
        curRight = CreateTree('0', NULL, NULL);

        (*tree)->Right = CreateTree('*', curLeft, curRight);
    }

    else if (Right->Value == var) {
        DestroyTree(Right);

        curLeft = CreateTree(LeftValue, NULL, NULL);
        curRight = CreateTree('1', NULL, NULL);

        (*tree)->Right = CreateTree('*', curLeft, curRight);
    }
}

Tree* BuildDerivative(Tree* tree, char var) {
    if (tree == NULL) {
        return NULL;
    }

    tree->Left = BuildDerivative(tree->Left, var);
    tree->Right = BuildDerivative(tree->Right, var);
    
    if (tree->Value == '*') {
        BuildMul(&tree, var);
    }

    else if (tree->Value == '+') {
        BuildPlus(&tree, var);
    }

    else if (tree->Value == '-') {
        BuildMinus(&tree, var);
    }

    return tree;
}

int main() {
    Tree* tree = ScanTree();

    char var = 'x';
    tree = BuildDerivative(tree, var);
    
    PrintTree(tree);
    DestroyTree(tree);
    return 0;
}
