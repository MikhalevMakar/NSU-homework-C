#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Tree {
    int Value;
    struct Tree* RightBranch;
    struct Tree* LeftBranch;
}TTree;
TTree* AddTree(int value, TTree* left, TTree* right) {
    TTree* tree = malloc(sizeof(TTree));
    assert(tree != NULL);
    tree->RightBranch = right;
    tree->LeftBranch = left;
    tree->Value = value;
    return tree;
}
TTree* ScanTree(int count) {
    if (count <= 0) {
        return NULL;
    }
    else {
        int value;
        scanf("%d", &value);
        int leftCount = (count - 1) / 2;
        TTree* left = ScanTree(leftCount);
        int rightCount = count - 1 - leftCount;
        TTree* right = ScanTree(rightCount);
        return AddTree(value, left, right);
    }
}

TTree*  CopyTree(TTree* tree) {
    if (tree == NULL) {
        return NULL;
    }
    TTree* copyTree = AddTree(tree->Value, tree->LeftBranch, tree->RightBranch);
    copyTree->LeftBranch = CopyTree(tree->LeftBranch);
    copyTree->RightBranch =    CopyTree(tree->RightBranch);
    return copyTree;

}

void DestroyTree(TTree* tree) {
    TTree* right = tree->RightBranch;
    TTree* left = tree->LeftBranch;
    free(tree);
    if (left != NULL) {
        DestroyTree(left);
    }
    if (right != NULL) {
        DestroyTree(right);
    }
}

void PrintPrefix(TTree* tree) {
    if (tree == NULL) {
        printf(".");
        return;
    }
    else {
        printf("%d[", tree->Value);
        PrintPrefix(tree->LeftBranch);
        PrintPrefix(tree->RightBranch);
        printf("]");
    }
}

int main() {
    int count;
    scanf("%d", &count);
    TTree* headTree = ScanTree(count);
    PrintPrefix(headTree);
    printf("\n");
    headTree  = CopyTree(headTree);
    MirrorTree(&headTree);
    PrintPrefix(headTree);
    DestroyTree(headTree);
    return 0;
}
