#ifndef CIRLL_H
#define CIRLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
    int val;
    struct __node *next;
} node_t;

typedef struct __list {
    node_t *head;
    node_t *tail;
} list_t;

list_t *cirll_split(list_t **list);
int cirll_insert_head(list_t **list, int x);
void cirll_print(list_t *list);
void cirll_delete_list(list_t *list);

#endif