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
    List* head = malloc(sizeof(List));
    scanf("%d", &head->Value);
    head->Next = ScanList(n - 1);
    return head;
}
void  Rotate(List** list) {
    if ((*list)->Next == NULL) {
        return;
    }
    List* head = *list;
    List* current = *list;
    *list = head->Next;
    while (current->Next != NULL) {
        current  =  current->Next;
    }
    current->Next = head;
    head->Next = NULL;
}
void PrintList(List* head) {
    while (head != NULL) {
        printf("%d\n", head->Value);
        head = head->Next;
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
    List* list=ScanList(n);
    if (list != NULL) {
        Rotate(&list);
    }
    PrintList(list);
    FreeList(list);
    return 0;
}
