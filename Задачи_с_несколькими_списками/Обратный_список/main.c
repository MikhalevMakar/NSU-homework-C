#include <stdio.h>
#include <stdlib.h>
typedef struct List {
    int Value;
    struct List* Next;
}List;
List* ScanList(n) {
    if (n == 0) {
        return NULL;
    }
    List* head = malloc(sizeof(List));
    scanf("%d", &head->Value);
    head->Next = ScanList(n - 1);
    return head;
}
List* ReverseList(List* list, int n) {
    List* future = NULL;
    while (list != NULL) {
        List* previous = list;
        list = list->Next;
        previous->Next = future;
        future = previous;
    }
    return future;
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
    int n;
    scanf("%d", &n);
    List* list = ScanList(n);
    List* head = ReverseList(list, n);
    PrintList(head);
    FreeList(head);
    return 0;
}
