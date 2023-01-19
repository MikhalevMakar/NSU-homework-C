#include <stdio.h>
#include <stdlib.h>
typedef struct List {
    int Value;
    struct List* Next;
}List;
List* ScanList(unsigned int  n) {
    if (n == 0) {
        return NULL;
    }
    List* list = malloc(sizeof(*list));
    scanf("%d", &list->Value);
    list->Next = ScanList(n - 1);
    return list;
}
void FreeList(List* list) {
    while (list != NULL) {
        List* pointer = list->Next;
        free(list);
        list= pointer;
    }
}

List* FilterList(List* list, List* filter) {
    if (list == NULL) {
        return NULL;
    }
    else if (filter == NULL) {
        FreeList(list);
        return NULL;
    }
    else if (list->Value > filter->Value) {
        filter = filter->Next;
        return FilterList(list, filter);
    }
    else if (list->Value < filter->Value) {
        List* pointer = list->Next;
        free(list);
        return FilterList(pointer, filter);
    }
    else if (list->Value == filter->Value) {
        filter = filter->Next;
        list->Next = FilterList(list->Next, filter);
        return list;
    }
}
void PrintList(List* head) {
    while (head != NULL) {
        printf("%d\n", head->Value);
        head = head->Next;
    }
}
int main(void) {
    unsigned int n1, n2;
    scanf("%d%d", &n1, &n2);
    List* list = ScanList(n1);
    List* filter = ScanList(n2);
    List* head = FilterList(list, filter);
    PrintList(head);
    FreeList(head);
    return 0;
}
