#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct List {
    int Value;
    struct List* Next;
}List;


void Push(List** list, int value) {
    List* head = malloc(sizeof(List));
    assert(head != NULL);
    head->Value = value;
    head->Next = *list;
    *list = head;
}

int Pop(List** list) {
    assert(*list != NULL);
    List* futureFree = (*list)->Next;
    int value = (*list)->Value;
    free(*list);
    *list = futureFree;
    return value;
}


List* ScanList(int n) {
    if (n == 0) {
        return NULL;
    }

    List* head = malloc(sizeof(List));
    assert(scanf("%d", &head->Value) == 1);
    head->Next = ScanList(n - 1);
    return head;
}

void HanoiTower(List** list1, List** list2, List** list3, int N) {
    if (N == 0) {
        return;
    }

    HanoiTower(list1, list3, list2, N-1);

    Push(list2, (*list1)->Value);
    
    *list1 = (*list1)->Next;

    HanoiTower(list3, list2, list1, N-1);
}

int main() {
    int N = 0;
    assert(scanf("%d", &N) == 1);

    List* list1 = ScanList(N);

    List* list2 = NULL;
    List* list3 = NULL;

    HanoiTower(&list1, &list2, &list3, N-1);
    
    printf("\n");

    while (list2 != NULL) {
        printf("%d ", list2->Value);
        list2 = list2->Next;
        
    }

    return 0;
}

// просто копирование списка :)

/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct List {
    int Value;
    struct List* Next;
}List;


void Push(List** list, int value) {
    List* head = malloc(sizeof(List));
    assert(head != NULL);
    head->Value = value;
    head->Next = *list;
    *list = head;
}

int Pop(List** list) {
    assert(*list != NULL);
    List* futureFree = (*list)->Next;
    int value = (*list)->Value;
    free(*list);
    *list = futureFree;
    return value;
}


List* ScanList(int n) {
    if (n == 0) {
        return NULL;
    }

    List* head = malloc(sizeof(List));
    scanf("%d", &head->Value);
    head->Next = ScanList(n - 1);
    return head;
}

List* CopyList(List* list1, List* list2, List* list3) {
    while (list1 != NULL) {
        Push(&list2, list1->Value);
        list1 = list1->Next;
    }

    while (list2 != NULL) {
        Push(&list3, Pop(&list2));
    }
    return list3;
}


int main() {
    int n = 0;

    scanf("%d", &n);

    List* list1 = ScanList(n);

    List* list2 = NULL;
    List* list3 = NULL;

    list3 = CopyList(list1, list2, list3);

    while (list3 != NULL) {
        printf("%d", list3->Value);
        list3 = list3->Next;
    }

    return 0;
}

*/
