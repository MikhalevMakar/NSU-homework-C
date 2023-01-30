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

int PopulationCount(unsigned int x) {
    unsigned int checkValue = 1;
    int count = 0;
    for (int i = 0; i < 31; ++i) {
        if ((checkValue & x) == checkValue) {
            count++;
        }
        checkValue = checkValue << 1;
    }
    return count;
}

void FindMax(Tree* root, unsigned int* max) {
    if (root == NULL) {
        return;
    }

    if (PopulationCount(root->Value) > PopulationCount(*max)) {
        *max = root->Value;
    }

    for (int i = 0; i < root->Count; ++i) {
        FindMax(root->Subtree[i], max);
    }
}

int main() {
    int value = 0;
    Tree* root = NULL;
    Tlist* list = NULL;
    assert(scanf("%d", &value) == 1);
    root = MakeLeaf(value);
    if (root != NULL) {
        CreateNTree(root);
        CreateNTree(root->Subtree[0]);
        unsigned int max = 0;
        FindMax(root, &max);
        printf("%d", max);
    }
    return 0;
}
