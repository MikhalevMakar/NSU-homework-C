#include stdio.h
#include stdlib.h
#include assert.h
typedef struct Tree {
    int Value;
    struct Tree RightBranch;
    struct Tree LeftBranch;
}TTree;
TTree AddTree(TTree left,TTree right,int value){
    TTree tree = malloc(sizeof(TTree));
    tree-RightBranch = right;
    tree-LeftBranch = left;
    tree-Value = value;
    return tree;
}
TTree ScanTree(int count) {
    int value;
    if (count == 0) {
        return NULL;
    }
    if(scanf(%d, &value) != 1) {
        assert(value !=1);
    }
    int leftCount = (count - 1)  2;
    TTree left = ScanTree(leftCount);
    int rightCount = count - 1 - leftCount;
    TTree right = ScanTree(rightCount);
    return AddTree(left,right,value);
}
void DestroyTree(TTree tree) {
    TTree right = tree-RightBranch;
    TTree left = tree-LeftBranch;
    free(tree);
    if (left != NULL) {
        DestroyTree(left);
    }
    if (right != NULL) {
        DestroyTree(right);
    }
}
int main() {
    int count;
    scanf(%d, &count);
    TTree headTree = ScanTree(count);
    DestroyTree(headTree);
    return 0;
}
