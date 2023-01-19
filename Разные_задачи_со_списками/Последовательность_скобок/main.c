#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef struct List {
   int Value;
   struct List* Next;
}List;

void Push(List** list, char a ) {
    List* head = malloc(sizeof(List));
    head->Value = a;
    head->Next = *list;
    *list = head;
}

char Pop(List** list) {
   List* previous = *list;
   *list = (*list)->Next;
   return previous->Value;
   printf("1");
}
int  IsMatch(char left, char right) {
   if ((left == '(' && right == ')') || (left == '{' && right == '}') || (left == '[' && right == ']')) {
       return 1;
   }
   return 0;
}
int main() {
   char  c;
   List* list = NULL;
   while (true) {
       c = getchar();
       if (c == '\n') {
           break;
       }
       if (c == ')' || c == '}' || c == ']')  {
           if (list == NULL || IsMatch( Pop(&list) , c) == 0) {
           printf("NotOk");
           return 0;
           }
       }
       else {
           Push(&list,c);
       }
   }
   if (list != NULL) {
       printf("not ok");
   }
   else {
       printf("ok");
   }
   return 0;
}
