#include <stdio.h>
#include <stdlib.h>
struct Tlist {
    int Value;
    struct Tlist* Next;
};
struct Tlist* ScanList(int n) {
    if (n == 0) {
        return NULL;
    }
    struct Tlist* head = malloc(sizeof(*head));
    scanf("%d", &head->Value);
    head->Next = ScanList(n-1);
    return head;
}
void PrintList(struct Tlist* head) {
    int count = 1;
    while (head != NULL){
        printf("%d:%d\n",count, head->Value);
        count++;
        head = head->Next;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    struct Tlist* head = ScanList(n);
    PrintList(head);
    return 0;
}
