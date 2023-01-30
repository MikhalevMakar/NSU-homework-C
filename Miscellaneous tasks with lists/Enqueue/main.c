#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct List {
    int Value;
    struct List* Next;
}List;

typedef struct QQ {
    struct List* forEnqueue;
    struct List* forDequeue;
}QQ;

void Push(List** list,int digit) {
    List* head = malloc(sizeof(List));
    head->Value = digit;
    head->Next = *list;
    *list = head;
}

int Pop(List** list) {
    assert(*list != NULL);
    int value = (*list)->Value;
    List* future = (*list)->Next;
    free(*list);
    *list = future;
    return value;
}
void Enqueue(QQ* Queue, int value ) {
    Push(&(Queue->forEnqueue),value);
}

int Dequeue(QQ* Queue) {
    if (Queue->forDequeue == NULL) {
        while (Queue->forEnqueue != NULL) {
            int value = Pop(&(Queue->forEnqueue));
            Push(&(Queue->forDequeue), value);
        }
    }
    return ("%d\n", Pop(&(Queue->forDequeue)));
}
void PrintQueue(int digit) {
    printf("%d\n", digit);
}
int main() {
    QQ queue;
    queue.forEnqueue = NULL;
    queue.forDequeue = NULL;
    Enqueue(&queue,1);
    Enqueue(&queue,2);
    int digit = Dequeue(&queue);
    PrintQueue(digit);
    Enqueue(&queue, 3);
    digit = Dequeue(&queue);
    PrintQueue(digit);
    digit = Dequeue(&queue);
    PrintQueue(digit);
    return 0;
}
