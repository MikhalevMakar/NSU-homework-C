#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0

typedef struct List {
    int Value;
    struct List* Next;
}List;
List* ScanList(int n) {
    if (n == 0) {
        return NULL;
    }

    List* list = malloc(sizeof(List));
    scanf("%d", &list->Value);
    list->Next = ScanList(n - 1);

    return list;
}
void RemoveDuplicates(List* list) {
    while (list->Next != NULL) {
        if (list->Value == list->Next->Value) {
            List* next= list->Next->Next;
            free(list->Next);
            list->Next = next;
        }
        else {
            list = list->Next;
        }
    }
}
void PrintList(List* list) {
    while (list != NULL) {
        printf("%d ", list->Value);
        list = list->Next;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    List* list = ScanList(n);
    if (list != NULL) {
        RemoveDuplicates(list);
    }
    PrintList(list);
    return  0;
}
