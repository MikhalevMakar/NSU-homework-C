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
    head->Next = ScanList(n - 1);
    return head;
}
void FreeList(struct Tlist* head) {
    while (head != NULL) {
        struct Tlist* pointer=head->Next;
        free(head);
        head = pointer;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    struct Tlist* head = ScanList(n);
    FreeList(head);
    return 0;
}
