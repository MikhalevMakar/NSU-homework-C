#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Tree {
    int Value;
    struct TTree** Subtree;
    int Count;
}Tree;

typedef struct List {
    Tree* Value;
    struct List* Next;
}List;

typedef struct QQ {
    struct List* forEnqueue;
    struct List* forDequeue;
}QQ;


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

void Push(List** list, Tree* digit) {
    List* head = malloc(sizeof(List));
    head->Value = digit;
    head->Next = *list;
    *list = head;
}

Tree* Pop(List** list) {
    assert(*list != NULL);
    Tree* value = (*list)->Value;
    List* future = (*list)->Next;
    free(*list);
    *list = future;
    return value;
}

void Enqueue(QQ* Queue, Tree* value) {
    Push(&(Queue->forEnqueue), value);
}

Tree* Dequeue(QQ* Queue) {
    if (Queue->forDequeue == NULL) {
        while (Queue->forEnqueue != NULL) {
            Tree* value = Pop(&(Queue->forEnqueue));
            Push(&(Queue->forDequeue), value);
        }
    }
    return Pop(&(Queue->forDequeue));
}

int SizeQueue(List* list) {
    if (list == NULL) {
        return 0;
    }

    return 1 + SizeQueue(list->Next);
}
QQ* CreateQQ(Tree* tree) {
    QQ* queue = malloc(sizeof(QQ));
    assert(queue != NULL);
    queue->forDequeue = NULL;
    queue->forEnqueue = malloc(sizeof(List));
    queue->forEnqueue->Value = tree;
    queue->forEnqueue->Next = NULL;
    return queue;
}
void PrintTree(Tree* tree) {
    QQ* queue = CreateQQ(tree);
    int SubSize = 1;

    while (queue->forEnqueue != NULL || queue->forDequeue != NULL) {
        --SubSize;
        tree = Dequeue(queue);

        printf("%d ", tree->Value);

        for (int i = 0; i < tree->Count; ++i) {
            Tree* node = tree->Subtree[i];
            Enqueue(queue, tree->Subtree[i]);
        }

        if (SubSize == 0) {
            printf("\n");
            SubSize = SizeQueue((queue->forEnqueue)+SizeQueue(queue->forDequeue));
        }

    }
}

/*
1 3 2 3 4
2 5 6
*/

int main() {
    int value = 0;
    Tree* root = NULL;

    assert(scanf("%d", &value) == 1);

    root = MakeLeaf(value);
    
    CreateNTree(root);
    CreateNTree(root->Subtree[0]);
    
    PrintTree(root);
    
    return 0;
}
