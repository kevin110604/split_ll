#include "cirll.h"
#include "dcirll.h"

#define NUM_OF_NODE 55

int main(int argc, char *argv[])
{
    int num_of_node;
    if (argc < 2) {
        num_of_node = NUM_OF_NODE;
    }
    else {
        num_of_node = atoi(argv[1]);
    }

    int i;
    list_t *list, *rlist;
    dcir_list_t *dclist, *rdclist;

    puts("circular linked list");
    list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    for (i = num_of_node; i > 0; i--) {
        cirll_insert_head(&list, i);
    }
    cirll_print(list);
    rlist = cirll_split(&list);
    cirll_print(list);
    cirll_print(rlist);

    cirll_delete_list(list);
    cirll_delete_list(rlist);

    puts("doubly circular linked list");
    dclist = malloc(sizeof(dcir_list_t));
    dclist->head = NULL;
    dclist->tail = NULL;
    for (i = num_of_node; i > 0; i--) {
        dcirll_insert_head(&dclist, i);
    }
    dcirll_print(dclist);
    rdclist = dcirll_split(&dclist);
    dcirll_print(dclist);
    dcirll_print(rdclist);    

    dcirll_delete_list(dclist);
    dcirll_delete_list(rdclist);

    return 0;
}
