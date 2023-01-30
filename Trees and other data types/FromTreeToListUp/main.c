#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TTree {
    int Value;
    struct TTree* Left;
    struct TTree* Right;
}TTree;

typedef struct List {
    int Value;
    struct List* Next;
}List;

TTree* AddTree(int currentValue) {
    TTree* tree = malloc(sizeof(TTree));
    assert(tree != NULL);
    tree->Value = currentValue;
    tree->Right = NULL;
    tree->Left = NULL;
    return tree;
}

List* CreateList(int n) {
    if (n == 0) {
        return NULL;
    }
    List* list = malloc(sizeof(*list));
    assert(scanf("%d", &list->Value) == 1);
    list->Next = CreateList(n - 1);
    return list;
}

TTree* ConvertToBinarySearchTree(List** list, int count) {
    if (count <= 0 || *list == NULL) {
        return NULL;
    }
    TTree* tree = malloc(sizeof(TTree));
    assert(tree != NULL);
    int middle = count / 2;
    tree->Left = ConvertToBinarySearchTree(list, middle);
    tree->Value = (*list)->Value;
    (*list) = (*list)->Next;
    tree->Right = ConvertToBinarySearchTree(list, count - middle - 1);
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
    int N = 0;
    assert(scanf("%d", &N) == 1);
    List* list = CreateList(N);
    TTree* tree = ConvertToBinarySearchTree(&list, N);
    Print(tree);
    return 0;
}
