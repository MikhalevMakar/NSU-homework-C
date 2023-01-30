#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Tree {
    int Value;
    struct Tree** Subtree;
    int Count;
}Tree;

typedef struct Tlist {
    int Value;
    struct Tlist* Next;
}Tlist;

void Push(Tlist** list, int value) {
    Tlist* head = malloc(sizeof(Tlist));
    assert(head != NULL);
    head->Value = value;
    head->Next = *list;
    *list = head;
}


void AddSubTree(Tree* tree, Tree* subTree) {
    Tree** u = realloc(tree->Subtree, sizeof(*u) * (tree->Count + 1));
    assert(u);
    tree->Subtree = u;
    tree->Subtree[tree->Count] = subTree;
    tree->Count += 1;
}

Tree* MakeLeaf(int value) {
    Tree* tree = malloc(sizeof(Tree));
    assert(tree);
    tree->Value = value;
    tree->Subtree = NULL;
    tree->Count = 0;
    return tree;
}

void CreateNTree(Tree* root) {
    int countSubtree = 0;
    int value = 0;
    assert(scanf("%d", &countSubtree) == 1);
    for (int i = 0; i < countSubtree; ++i) {
        assert(scanf("%d", &value) == 1);
        AddSubTree(root, MakeLeaf(value));
    }
}

unsigned int Min(unsigned int x, unsigned int y) {
    return (x > y)? y : x;
}

void DephValue(Tree* root, unsigned int count, int value, unsigned int* shortestPath) {
    if (root == NULL) {
        return;
    }

    if (root->Value == value) {
        *shortestPath = Min(*shortestPath, count);
        return;
    }

    for (int i = 0; i < root->Count; ++i) {
        DephValue(root->Subtree[i], count + 1, value, shortestPath);
    }
}

int main() {
    int curValue = 0;
    Tree* root = NULL;
    Tlist* list = NULL;
    assert(scanf("%d", &curValue) == 1);
    root = MakeLeaf(curValue);
    if (root != NULL) {
        CreateNTree(root);
        CreateNTree(root->Subtree[0]);
        unsigned int shortestPath = INT_MAX;
        int value = 0;
        assert(scanf("%d", &value) == 1);
        DephValue(root, 0, value, &shortestPath);
        printf("%d", shortestPath);
    }
    return 0;
}
