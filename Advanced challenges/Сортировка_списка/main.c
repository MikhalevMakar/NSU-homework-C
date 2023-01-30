#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TList {
    int Value;
    struct TList* Next;

}TList;

TList* CreateList(int  n) {
    
    if (n == 0) {
        return NULL;
    }

    TList* node = malloc(sizeof(TList));
    assert(node != NULL);
    assert(scanf("%d", &node->Value) == 1);
    node->Next = CreateList(n - 1);
    return node;

}
void FreeList(TList* list) {
    while (list != NULL) {
        TList* pointer = list->Next;
        free(list);
        list = pointer;
    }
}

TList* GetMiddle(TList* list) {

    TList* middle = list;
    TList* end = list;
    
    while (end->Next != NULL && end->Next->Next != NULL) {
        end = end->Next->Next;
        middle = middle->Next;
    }
    return middle;
}

TList* MergeSortImpl(TList* list1, TList* list2) {

    if (list1 == NULL) {
        return list2;
    }

    else if (list2 == NULL) {
        return list1;
    }

    else if (list1->Value > list2->Value) {
        list2->Next = MergeSortImpl(list1, list2->Next);
        return list2;
    }

    else {
        list1->Next = MergeSortImpl(list1->Next, list2);
        return list1;
    }
}


TList* MergeSort(TList* list) {
    
    if (list == NULL || list->Next == NULL) {
        return list;
    }

    TList* mid = GetMiddle(list);
    TList* begin = list;

    TList* tail = mid->Next ;
    mid->Next = NULL;
    
    begin = MergeSort(begin);
    tail = MergeSort(tail);

    return MergeSortImpl(begin, tail);

}

void PrintList(TList* head) {
    while (head != NULL) {
        printf("%d ", head->Value);
        head = head->Next;
    }
}

int main(void) {

    int N = 0;
    
    assert(scanf("%d", &N) == 1);

    TList* list = CreateList(N);
    
    TList* head = MergeSort(list);

    PrintList(head);

    FreeList(head);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TList {
    int Value;
    struct TList* Next;

}TList;

TList* CreateList(int  n) {

    if (n == 0) {
        return NULL;
    }

    TList* node = malloc(sizeof(TList));
    assert(node != NULL);
    assert(scanf("%d", &node->Value) == 1);
    node->Next = CreateList(n - 1);
    return node;

}
void FreeList(TList* list) {
    while (list != NULL) {
        TList* pointer = list->Next;
        free(list);
        list = pointer;
    }
}

TList* MergeSort(TList* list) {

    TList* node1 = NULL;
    TList* node2 = NULL;
    TList* node3 = NULL;

    while (list != NULL) {

        node2 = list;
        list = list->Next;

        if (node1 == NULL) {
            node2->Next = node1;
            node1 = node2;
        }

        else if (node2->Value < node1->Value) {
            node2->Next = node1;
            node1 = node2;
        }

        else {
            node3 = node1;
            node2->Next = node3->Next;
            node3->Next = node2;
        }

    }

    return node1;
}



void PrintList(TList* head) {
    while (head != NULL) {
        printf("%d ", head->Value);
        head = head->Next;
    }
}

int main(void) {

    int N = 0;

    assert(scanf("%d", &N) == 1);

    TList* list = CreateList(N);

    TList* head = MergeSort(list);

    PrintList(head);

    FreeList(head);

    return 0;
}
