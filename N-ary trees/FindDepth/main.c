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

int SearchDepth(Tree* root) {
    if (root == NULL) {
        return 0;
    }
    
    int depth = 0;
    
    for (int i = 0; i < root->Count; ++i) {
        int curDeph = 1 + SearchDepth(root->Subtree[i]);
        
        if (curDeph > depth) {
            depth = curDeph;
        }

    }
    return depth;
}

int main() {
    int value = 0;
    Tree* root = NULL;

    assert(scanf("%d", &value) == 1);

    root = MakeLeaf(value);
    CreateNTree(root);
    CreateNTree(root->Subtree[0]);

    
    int depth = SearchDepth(root);
    
    printf("%d", depth);
    return 0;
}
