//
// Created by alan on 1/27/18.
//

#ifndef ASS1_NODE_H
#define ASS1_NODE_H

typedef struct node {
    void *item;
    struct node *next;
    struct node *prev;
} node;

#endif //ASS1_NODE_H
