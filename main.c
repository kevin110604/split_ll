#include "cirll.h"
#include "dcirll.h"

int main()
{
    int i;
    list_t *list, *rlist;
    dcir_list_t *dclist, *rdclist;

    puts("circular");
    list = malloc(sizeof(list_t));
    for (i = 5; i > 0; i--) {
        cirll_insert_head(&list, i);
    }
    cirll_print(list);
    rlist = cirll_split(&list);
    cirll_print(list);
    cirll_print(rlist);

    puts("doubly circular");
    dclist = malloc(sizeof(dcir_list_t));
    for (i = 5; i > 0; i--) {
        dcirll_insert_head(&dclist, i);
    }
    dcirll_print(dclist);
    rdclist = dcirll_split(&dclist);
    dcirll_print(dclist);
    dcirll_print(rdclist);    

    return 0;
}
