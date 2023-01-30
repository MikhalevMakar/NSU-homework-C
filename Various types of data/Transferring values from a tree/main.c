#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct TTree {
    int Value;
    struct TTree* Left;
    struct TTree* Right;
}TTree;

typedef struct List {
    int Value;
    struct List* Next;
}List;

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

void CreateList(List** list, int currentValue) {
    List* head = malloc(sizeof(List));
    assert(head != NULL);
    head->Value = currentValue;
    head->Next = *list;
    *list = head;
}

void ConvertBinarySearchTreeToArray(TTree* tree, List** list) {
    if (tree == NULL) {
        return;
    }
    ConvertBinarySearchTreeToArray(tree->Left, list);
    CreateList(list, tree->Value);
    ConvertBinarySearchTreeToArray(tree->Right, list);
}

void Print(List* list) {
    while (list != NULL) {
        printf("%d ", list->Value);
        list = list->Next;
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
    List* list = NULL;
    ConvertBinarySearchTreeToArray(root, &list);
    Print(list);
    return 0;
}
