#include <stdio.h>
#include "list.h"

int main() {
    initiateNodesAndLists();
    LIST *localList = ListCreate();

    printf("Number of items in list (before addition of any items): %i\n", ListCount(localList));

    char *test1 = "lol";
    ListAdd(localList, test1);

    printf("Number of items in list (after inserting first item): %i\n", ListCount(localList));
    printf("Current pointer points to first item: %s \n", localList->current->item);

    char *test2 = "fun";
    ListAdd(localList, test2);

    printf("Number of items in list (after inserting second item): %i\n", ListCount(localList));
    printf("Current pointer points to second item: %s \n", localList->current->item);

    char *test3 = "great";
    ListAdd(localList, test3);

    printf("Number of items in list (after inserting third item): %i\n", ListCount(localList));
    printf("Current pointer points to third item: %s \n", localList->current->item);

    printf("\n");

    ListFirst(localList);
    printf("Current pointer points back to first item after running ListFirst(): %s \n", localList->current->item);

    ListLast(localList);
    printf("Current pointer points back to third item after running ListLast(): %s \n", localList->current->item);

    ListPrev(localList);
    printf("Current pointer points back to second item after running ListPrev(): %s \n", localList->current->item);

    ListNext(localList);
    printf("Current pointer points back to third item after running ListNext(): %s \n", localList->current->item);

    printf("\n");

    printf("Current pointer points to: %s \n", ListCurr(localList));

    printf("\n");

    char *test4 = "excellent";
    ListInsert(localList, test4);
    printf("After ListInsert(), current pointer points to: %s \n", ListCurr(localList));

    char *test5 = "school";
    char *test6 = "duck";

    printf("\n");

    ListPrev(localList);
    printf("Current pointer points back to second item after running ListPrev(): %s \n", localList->current->item);
    printf("Before ListPrepend(), current pointer points to: %s \n", ListCurr(localList));
    ListPrepend(localList, test5);
    printf("After ListPrepend(), current pointer points to: %s \n", ListCurr(localList));

    printf("\n");

    printf("Before ListAppend(), current tail is: %s \n", ListLast(localList));
    ListAppend(localList, test6);
    printf("After ListAppend(), current tail is: %s \n", ListLast(localList));

    printf("\n");

    printf("Before ListRemove(), current pointer points to: %s \n", ListCurr(localList));
    ListRemove(localList);
    printf("After ListRemove(), current pointer points to: %s \n", ListCurr(localList));

    printf("\n");

    LIST *localList2 = ListCreate();
    char *test7 = "loop";
    ListAdd(localList2, test7);

    printf("Before ListConcat(), current tail is: %s \n", ListLast(localList));
    ListConcat(localList, localList2);
    printf("After ListConcat(), current tail is: %s \n", ListLast(localList));

    printf("\n");

    printf("Before ListTrim(), current tail is: %s \n", ListLast(localList));
    ListTrim(localList);
    printf("After ListTrim(), current tail is: %s \n", ListLast(localList));

    return 0;
}