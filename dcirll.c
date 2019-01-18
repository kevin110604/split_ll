#include "dcirll.h"


dcir_list_t *dcirll_split(dcir_list_t **list)
{
    dcir_list_t *right;
    dcir_node_t *head, *tail, *p, *q;
    head = (*list)->head;
    tail = (*list)->tail;
    if (!list || !head || head->next == head)
        return NULL;

    right = malloc(sizeof(dcir_list_t));
    p = head;
    q = tail;
    while (1) {
        if (p->next == q)
            break;
        p = p->next;
        if (p->next == q)
            break;
        q = q->prev;
    }
    (*list)->tail = p;
    p->next = head;
    (*list)->head->prev = p;

    right->head = q;
    q->prev = tail;
    right->tail = tail;
    tail->next = q;

    return right;
}


int dcirll_insert_head(dcir_list_t **list, int x)
{
    if (list == NULL)
        return -1;

    dcir_node_t *newnode = malloc(sizeof(dcir_node_t));
    if (newnode == NULL)
        return -1;

    newnode->val = x;
    
    if ((*list)->head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        (*list)->head = newnode;
        (*list)->tail = newnode;
        return 0;
    }
    
    (*list)->head->prev = newnode;
    newnode->next = (*list)->head;
    newnode->prev = (*list)->tail;
    (*list)->head = newnode;
    (*list)->tail->next = newnode;
    return 0;
}

void dcirll_print(dcir_list_t *list)
{
    dcir_node_t *p;
    if (list == NULL)
        return;
    if (list->head == NULL)
        return;
    
    for (p = list->head; p != list->tail; p = p->next)
        printf("%d ", p->val);
    printf("%d\n", p->val);
}

void dcirll_delete_list(dcir_list_t *list)
{
    dcir_node_t *p, *tmp;
    if (list == NULL)
        return;
    if (list->head == NULL) {
        free(list);
        return;
    }
    
    for (p = list->head; p != list->tail; p = tmp) {
        tmp = p->next;
        free(p);
    }
    free(p);
    free(list);
}