#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Tree {
    int Value;
    struct TTree** Subtree;
    int Count;
}Tree;

void AddSubTree(Tree* tree, Tree* subTree) {
    Tree** u = realloc(tree->Subtree, sizeof(*u) * (tree->Count + 1));
    assert(u);
    tree->Subtree = u;
    tree->Subtree[tree->Count] = subTree;
    tree->Count += 1;
}

Tree* MakeLeaf(int value) {
    Tree* tree = calloc(1, sizeof(Tree));
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

void FindMax(Tree* root, int* max) {
    if (root == NULL) {
        return;
    }

    if (*max < root->Value) {
        *max = root->Value;
    }

    for (int i = 0; i < root->Count; ++i) {
        FindMax(root->Subtree[i], max);
    }

}

int main() {
    int value = 0;
    Tree* root = NULL;

    assert(scanf("%d", &value) == 1);

    root = MakeLeaf(value);
    CreateNTree(root);
    CreateNTree(root->Subtree[0]);

    int max = INT_MIN;
    FindMax(root, &max);
    
    printf("%d", max);

    return 0;
}
