#include <stdio.h>
#include <stdlib.h>
typedef struct List {
    int Value;
    struct List* Next;
}List;
List* ScanList(int n) {
    if (n == 0) {
        return NULL;
    }
    List* list = malloc(sizeof(*list));
    scanf("%d", &list->Value);
    list->Next = ScanList(n - 1);
    return list;
}
void DeleteNth(List** list, int N) {
    int count = 0;
    List* previous=*list;
    if (N == 0) {
        previous = (*list)->Next;
        free(*list);
        *list = previous;
        return;
    }
    while ((count != N-1) & (previous->Next != NULL)) {
        previous = previous->Next;
        ++count;
    }
    if ((count == N-1) & (previous->Next != NULL)) {
        List* current  = previous->Next;
        previous->Next = current->Next;
        free(corrent);
    }
}
void PrintList(List* list) {
    while (list != NULL) {
        printf("%d ", list->Value);
        list = list->Next;
    }
}

void FreeList(List* list) {
    while (list->Next != NULL) {
        struct Tlist* pointer = list->Next;
        free(list);
        list = pointer;
    }
}

int main() {
    int n, N;
    scanf("%d %d", &n, &N);
    List* list = ScanList(n);
    DeleteNth(&list, N);
    PrintList(list);
    FreeList(list);
    return 0;

}
