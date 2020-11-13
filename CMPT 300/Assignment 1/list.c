#include "list.h"
#include <stdio.h>

// Link all nodes and lists for free node and list management
void initiateNodesAndLists() {
    // Link free lists
    for (int i = 0; i < MAX_LIST_COUNT - 1; i++) {
        listArr[i].next = &listArr[i + 1];
    }
    listArr[MAX_LIST_COUNT - 1].next = NULL;
    nextOpenList = &listArr[0];

    // Link free nodes
    for (int i = 0; i < MAX_NODE_COUNT - 1; i++) {
        nodeArr[i].next = &nodeArr[i + 1];
    }
    nodeArr[MAX_LIST_COUNT - 1].next = NULL;
    nextOpenNode = &nodeArr[0];
}

/* LIST *ListCreate()
 makes a new, empty list, and returns its reference on
success. Returns a NULL pointer on failure. */

LIST *ListCreate() {
    struct LIST *newList;

    // If there is no space for a new list then return NULL
    if (nextOpenList == NULL) {
        printf("List not created");
        return NULL;
    } else {
        newList = nextOpenList;
        newList->head = NULL;
        newList->tail = NULL;
        newList->count = 0;
        nextOpenList = newList->next;
        return newList;
    }
}

/*int ListCount(list)
returns the number of items in list. */

int ListCount(LIST *L) {
    return L->count;
}

/*void *ListFirst(list)
 returns a pointer to the first item in list and makes
the first item the current item. */

void *ListFirst(LIST *L) {
    if (L->head == NULL){
        return NULL;
    } else {
        L->current = L->head;
        return L->head->item;
    }
}

/*void *ListLast(list)
 returns a pointer to the last item in list and makes
the last item the current one. */

void *ListLast(LIST *L) {
    if (L->tail == NULL){
        return NULL;
    } else {
        L->current = L->tail;
        return L->tail->item;
    }
}

/*void *ListNext(list)
 advances list's current item by one, and returns a
pointer to the new current item. If this operation advances the current item beyond
the end of the list, a NULL pointer is returned. */

void *ListNext(LIST *L) {
    if (L->current == NULL || L->current->next == NULL){
        return NULL;
    } else{
        L->current = L->current->next;
    }
    return L->current->item;
}

/*void *ListPrev(list)
 backs up list's current item by one, and returns a
pointer to the new current item. If this operation backs up the current item beyond
the start of the list, a NULL pointer is returned. */

void *ListPrev(LIST *L) {
    if (L->current == NULL || L->current->prev == NULL) {
        return NULL;
    } else {
        L->current = L->current->prev;
    }
    return L->current->item;
}

/*void *ListCurr(list)
 returns a pointer to the current item in list. */

void *ListCurr(LIST *L) {
    if (L->current == NULL) {
        return NULL;
    } else {
        return L->current->item;
    }
}

/*int ListAdd(list, item)
 adds the new item to list directly after the
current item, and makes item the current item. If the current pointer is before the
start of the list, the item is added at the start. If the current pointer is beyond the
end of the list, the item is added at the end. Returns 0 on success, -1 on failure. */

node *createNode(void *data, node *nextParam, node *prevParam) {
    node *temp;

    // if there are no free nodes left
    if (nextOpenNode == NULL) {
        return NULL;
    }

    temp = nextOpenNode;
    nextOpenNode = temp->next;

    temp->item = data;
    temp->next = nextParam;
    temp->prev = prevParam;
    return temp;
}

// Node directions for case 1: the node added is the first and only item
node *createFirstNode(LIST *L, void *data) {
    node *newNode;

    newNode = createNode(data, NULL, NULL);
    L->head = newNode;
    L->tail = newNode;
    L->current = newNode;
}

int ListAdd(LIST *L, void *data) {
    node *newNode;

    // if node creation is unsuccessful
    if (newNode == NULL) {
        return -1;
    }

        // Case 1: No item in list
    else if (L->count == 0) {
        newNode = createFirstNode(L, data);
    } else if (L->current == L->tail) {
        // Case 2: current is last item in list
        newNode = createNode(data, NULL, L->current);
        L->current->next = newNode;
        L->current = newNode;
        L->tail = newNode;
    } else {
        // Case 3: elsewhere in the list
        newNode = createNode(data, L->current->next, L->current);
        L->current->next->prev = newNode;
        L->current->next = newNode;
        L->current = newNode;
    }

    L->count++;

    return 0;
}

/* int ListInsert(list, item)
adds item to list directly before the current
item, and makes the new item the current one. If the current pointer is before the
start of the list, the item is added at the start. If the current pointer is beyond the
end of the list, the item is added at the end. Returns 0 on success, -1 on failure. */

int ListInsert(LIST *L, void *data) {
    node *newNode;

    // if node creation is unsuccessful
    if (newNode == NULL) {
        return -1;
    }

        // Case 1: first and only item in list
    else if (L->count == 0) {
        newNode = createFirstNode(L, data);
    } else if (L->current == L->head) {
        // Case 2: current is first item in list
        newNode = createNode(data, L->current, NULL);
        L->current->prev = newNode;
        L->current = newNode;
        L->head = newNode;
    } else {
        // Case 3: elsewhere in the list
        newNode = createNode(data, L->current, L->current->prev);
        L->current->prev->next = newNode;
        L->current->prev = newNode;
        L->current = newNode;
    }

    L->count++;

    return 0;
}



/* int ListAppend(list, item)
adds item to the end of list, and makes the
new item the current one. Returns 0 on success, -1 on failure. */

int ListAppend(LIST *L, void *data) {
    node *newNode;

    if (newNode == NULL) {
        return -1;
    }

        // Case 1: only item in list
    else if (L->count == 0) {
        newNode = createFirstNode(L, data);
    } else {
        newNode = createNode(data, NULL, L->tail);
        L->current->next = newNode;
        L->current = newNode;
        L->tail = newNode;
    }

    L->count++;

    return 0;
}

/* int ListPrepend(list, item)
 adds item to the front of list, and makes
the new item the current one. Returns 0 on success, -1 on failure. */

int ListPrepend(LIST *L, void *data) {
    node *newNode;

    if (newNode == NULL) {
        return -1;
    }
        // Case 1: only item in list
    else if (L->head == NULL) {
        newNode = createFirstNode(L, data);
    } else {
        newNode = createNode(data, L->head, NULL);
        L->current->prev = newNode;
        L->current = newNode;
        L->head = newNode;
    }

    L->count++;

    return 0;
}

/* void *ListRemove(list)
Return current item and take it out of list. Make
        the next item the current one. */

void *ListRemove(LIST *L) {

    void *currentItem = L->current->item;
    node *nodeToBeRemoved = L->current;

    // Set the item in to be deleted node to NULL
    L->current->item = NULL;

    // Case 1: Only node in list
    if(L->count == 1) {
        L->head = NULL;
        L->tail = NULL;
    }

        // Case 2: First node in list
    else if(L->current == L->head) {
        L->head = L->head->next;
    }
        // Case 3: Last node in list
    else if(L->current == L->tail) {
        L->tail = L->tail->prev;
    }
        // Case 4: Node in between
    else {
        L->current->next->prev = L->current->prev;
        L->current->prev->next = L->current->next;
    }

    // Move current pointer to point to the next node
    L->current = L->current->next;

    // Return to free list
    nodeToBeRemoved->next = NULL;
    nodeToBeRemoved->prev = nextOpenNode;
    nextOpenNode = nodeToBeRemoved;

    L->count--;

    return currentItem;
}

/* void ListConcat(list1, list2)
adds list2 to the end of list1. The
        current pointer is set to the current pointer of list1. List2 no longer exists after the
operation. */

void ListConcat(LIST *L1, LIST *L2) {
    // If neither lists are empty and the addition of two lists is not over max node count
    if ((L1 != NULL) && (L2 != NULL) && !((L1->count + L2->count) >= MAX_NODE_COUNT)){
        // Connect the two lists
        L1->tail->next = L2->head;
        L2->head->prev = L1->tail;
        L1->tail = L2->tail;
        L1->count = L1->count + L2->count;

        // empty list
        L2->head = NULL;
        L2->tail = NULL;
        L2->current = NULL;
        L2->count = 0;

        // Return as next open list
        L2->next = nextOpenList;
        nextOpenList = L2;
    }
}

/*void ListFree(list, itemFree)
 delete list. itemFree is a pointer to a
routine that frees an item. It should be invoked (within ListFree) as:
(*itemFree)(itemToBeFreed); */

//void ListFree(LIST *L, itemFree);

/*void *ListTrim(list)
 Return last item and take it out of list. Make the
new last item the current one. */

void *ListTrim(LIST *L) {
    void *lastItem = L->tail->item;
    node *temp = L->tail->prev;

    // If only item
    if (L->count == 1) {
        // Move to next open node for reuse
        L->tail->prev = nextOpenNode;
        nextOpenNode = L->tail;

        L->tail = NULL;
        L->head = NULL;
    } else {
        L->tail->item = NULL;
        L->tail->prev->next = NULL;
        L->tail->prev = NULL;

        // Set as next free node
        L->tail->prev = nextOpenNode;
        nextOpenNode = L->tail;
    }

    L->tail = temp;
    L->current = L->tail;

    L->count--;
    return lastItem;
}


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

