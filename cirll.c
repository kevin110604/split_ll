#include "cirll.h"


list_t *cirll_split(list_t **list)
{
    list_t *right;
    node_t *head, *tail, *p;
    head = (*list)->head;
    tail = (*list)->tail;
    if (!list || !head || head->next == head)
        return NULL;

    right = malloc(sizeof(list_t));
    int count = 1;
    for (p = head; p->next != head; p = p->next) {
        count++;
    }
    
    count = count % 2 ? count/2 + 1 : count/2;

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
    if (list == NULL)
        return -1;
        
    node_t *newnode = malloc(sizeof(node_t));
    if (newnode == NULL)
        return -1;

    newnode->val = x;
    
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
    node_t *p;
    if (list == NULL)
        return;
    if (list->head == NULL)
        return;
    
    for (p = list->head; p != list->tail; p = p->next)
        printf("%d ", p->val);
    printf("%d\n", p->val);
}

void cirll_delete_list(list_t *list)
{
    node_t *p, *tmp;
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