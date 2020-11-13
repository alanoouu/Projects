//
// Created by alan on 1/25/18.
//

#ifndef ASS1_LIST_H
#define ASS1_LIST_H

#include <stdio.h>
#include "node.h"

typedef struct LIST {
    struct node *head;
    struct node *tail;
    struct node *current;
    int count;
    struct LIST *next;
} LIST;

#define MAX_LIST_COUNT   10
#define MAX_NODE_COUNT   10

// Global variables for list and nodes
LIST listArr[MAX_LIST_COUNT];
struct node nodeArr[MAX_NODE_COUNT];

// keep track of next open node and list
struct node *nextOpenNode;
LIST *nextOpenList;

void initiateNodesAndLists();

/* LIST *ListCreate()
 makes a new, empty list, and returns its reference on
success. Returns a NULL pointer on failure. */

LIST *ListCreate();

/*int ListCount(list)
returns the number of items in list. */

int ListCount(LIST *L);

/*void *ListFirst(list)
 returns a pointer to the first item in list and makes
the first item the current item. */

void *ListFirst(LIST *L);

/*void *ListLast(list)
 returns a pointer to the last item in list and makes
the last item the current one. */

void *ListLast(LIST *L);

/*void *ListNext(list)
 advances list's current item by one, and returns a
pointer to the new current item. If this operation advances the current item beyond
the end of the list, a NULL pointer is returned. */

void *ListNext(LIST *L);

/*void *ListPrev(list)
 backs up list's current item by one, and returns a
pointer to the new current item. If this operation backs up the current item beyond
the start of the list, a NULL pointer is returned. */

void *ListPrev(LIST *L);

/*void *ListCurr(list)
 returns a pointer to the current item in list. */

void *ListCurr(LIST *L);

/*int ListAdd(list, item)
 adds the new item to list directly after the
current item, and makes item the current item. If the current pointer is before the
start of the list, the item is added at the start. If the current pointer is beyond the
end of the list, the item is added at the end. Returns 0 on success, -1 on failure. */

node *createNode(void *data, node *nextParam, node *prevParam);

int ListAdd(LIST *L, void *data);

/* int ListInsert(list, item)
adds item to list directly before the current
item, and makes the new item the current one. If the current pointer is before the
        start of the list, the item is added at the start. If the current pointer is beyond the
        end of the list, the item is added at the end. Returns 0 on success, -1 on failure. */

int ListInsert(LIST *L, void *data);

/* int ListAppend(list, item)
adds item to the end of list, and makes the
        new item the current one. Returns 0 on success, -1 on failure. */

int ListAppend(LIST *L, void *data);

/* int ListPrepend(list, item)
 adds item to the front of list, and makes
the new item the current one. Returns 0 on success, -1 on failure. */

int ListPrepend(LIST *L, void *data);

/* void *ListRemove(list)
Return current item and take it out of list. Make
        the next item the current one. */

void *ListRemove(LIST *L);

/* void ListConcat(list1, list2)
adds list2 to the end of list1. The
        current pointer is set to the current pointer of list1. List2 no longer exists after the
operation. */

void ListConcat(LIST *L1, LIST *L2);

/*void ListFree(list, itemFree)
 delete list. itemFree is a pointer to a
routine that frees an item. It should be invoked (within ListFree) as:
(*itemFree)(itemToBeFreed); */

//void ListFree(LIST *L, itemFree);

/*void *ListTrim(list)
 Return last item and take it out of list. Make the
new last item the current one. */

void *ListTrim(LIST *L);

/*void *ListSearch(list, comparator, comparisonArg)
searches list starting at the current item until the end is reached or a match is
found. In this context, a match is determined by the comparator parameter. This
parameter is a pointer to a routine that takes as its first argument an item pointer,
and as its second argument comparisonArg. Comparator returns 0 if the item and
comparisonArg don't match, or 1 if they do. Exactly what constitutes a match is
up to the implementor of comparator. If a match is found, the current pointer is
left at the matched item and the pointer to that item is returned. If no match is
found, the current pointer is left beyond the end of the list and a NULL pointer is
returned */

//void *ListSearch(LIST *L, comparator, comparisonArg);

#endif //ASS1_LIST_H
