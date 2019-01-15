#include "cirll.h"


list_t *cirll_split(list_t **list)
{
    node *head, *tail;
    head = (*list)->head;
    tail = (*list)->tail;
    if (list == NULL)
        return NULL;
    if (head == NULL)
        return NULL;
    if (head->next == head)
        return NULL;

    list_t *right = malloc(sizeof(list_t));
    int count = 1;
    node *p;
    for (p = head; p->next != head; p = p->next) {
        count++;
    }
    if (count%2 == 0)
        count = count/2;
    else
        count = count/2 + 1;

    int i = 1;
    for (p = head; i < count; p = p->next, i++) {
        ;
    }
    (*list)->tail = p;
    right->head = p->next;
    right->tail = tail;
    right->tail->next = right->head;
    (*list)->tail->next = (*list)->head;

    return right;
}


int cirll_insert_head(list_t **list, int x)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
        return -1;

    newnode->val = x;

    if (list == NULL)
        return -1;
    
    if ((*list)->head == NULL) {
        newnode->next = newnode;
        (*list)->head = newnode;
        (*list)->tail = newnode;
        return 0;
    }
    
    newnode->next = (*list)->head;
    (*list)->head = newnode;
    (*list)->tail->next = newnode;
    return 0;
}

void cirll_print(list_t *list)
{
    node *p;
    if (list == NULL)
        return;
    if (list->head == NULL)
        return;
    
    for (p = list->head; p != list->tail; p = p->next)
        printf("%d ", p->val);
    printf("%d\n", p->val);
}