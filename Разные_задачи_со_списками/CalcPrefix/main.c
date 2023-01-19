#include <stdio.h>
#include <stdlib.h>
typedef struct List {
    char Value;
    struct List* Next;
}List;
List* ScanList(int n) {
    if (n == 0) {
        return NULL;
    }
    List* head = malloc(sizeof(List));
    scanf("%c", &head->Value);
    head->Next = ScanList(n - 1);
    return head;
}
double CalcPrefix(List** list) {
    List* previous = *list;
    *list = (*list)->Next;
    if (previous->Value == '+') {
        return (CalcPrefix(&(*list)) + CalcPrefix(&(*list)));
    }
    else if (previous->Value == '-') {
    
        return (CalcPrefix(&(*list)) - CalcPrefix(&(*list)));
    }
    else if (previous->Value == '*') {
        return (CalcPrefix(&(*list)) * CalcPrefix(&(*list)));
    }
    else if (previous->Value == '/') {
        return (CalcPrefix(&(*list)) / CalcPrefix(&(*list)));
    }
    else if (previous->Value >= '0' && previous->Value <= '9') {
        return (previous->Value - '0');
    }
    else {
        printf("not Ok");
        return 0;
    }
}
int main() {
    int n;
    scanf("%d ", &n);
    List* list = ScanList(n);
    double result = CalcPrefix(&list);
    printf("%f", result);
    return 0;
}
