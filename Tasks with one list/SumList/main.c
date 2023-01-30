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
int SumList(struct Tlist* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->Value;
        head = head->Next;
    }
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    struct Tlist* head = ScanList(n);
    int result = SumList(head);
    printf("%d", result);
    return 0;
}
