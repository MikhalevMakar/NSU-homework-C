#include <stdio.h>
#include <stdlib.h>
struct Tlist {
    int Value;
    struct Tlist* Next;
};
struct Tlist* ScanList(unsigned int n) {
    if (n == 0) {
        return NULL;
    }
    struct Tlist* head = malloc(sizeof(*head));
    head->Value = n % 10;
    head->Next = ScanList(n/10);
    return head;
}
void PrintList(struct Tlist* head) {
    while (head != NULL) {
        printf("%d\n", head->Value);
        head = head->Next;
    }
}
    int main() {
    unsigned int n;
    scanf("%d", &n);
    struct Tlist* head = ScanList(n);
    PrintList(head);
    return 0;
}
