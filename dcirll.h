#ifndef DCIRLL_H
#define DCIRLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct __dcir_node {
    int val;
    struct __dcir_node *next;
    struct __dcir_node *prev;
} dcir_node_t;

typedef struct __dcir_list {
    dcir_node_t *head;
    dcir_node_t *tail;
} dcir_list_t;

dcir_list_t *dcirll_split(dcir_list_t **list);
int dcirll_insert_head(dcir_list_t **list, int x);
void dcirll_print(dcir_list_t *list);

#endif