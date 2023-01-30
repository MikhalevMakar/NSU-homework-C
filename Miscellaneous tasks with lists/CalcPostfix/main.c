#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef struct List {
    double Value;
    struct List* Next;
}List;

void Push(List** list, double a ) {
     List* head = malloc(sizeof(List));
     head->Value = a;
     head->Next = *list;
     *list = head;
}
double Pop(List** list) {
    List* previous = *list;
    *list = (*list)->Next;
    return previous->Value;
}
double CalcPostfix(List** steck) {
    double result = 0;
    int digit = 0;
    int signd = 0;
    while (true) {
        char c = getchar();
        if (c == '\n') {
            break;
        }
        if (c >= '0' && c <= '9') {
            Push(&steck,c -'0');
            digit++;
        }
        else if (c == '*') {
            result = Pop(&steck)*Pop(&steck);
            Push(&steck, result);
            signd++;
        }
        else if (c == '+') {
            result = Pop(&steck)+Pop(&steck);
            Push(&steck, result);
            signd++;
        }
        else if (c == '-') {
            result = Pop(&steck)-Pop(&steck);
            Push(&steck, result);
            signd++;
        }
        else if (c == '/') {
            result = Pop(&steck) / Pop(&steck);
            Push(&steck, result);
            signd++;
        }
        else {
            printf("bad input ");
            return 0;
        }
    }
    assert(2 * signd == digit);
    return result;
}

int main() {
    List* steck = NULL;
    double result =CalcPostfix(&steck);
    printf("%f", result);
    return 0;
}
