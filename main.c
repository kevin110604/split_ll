#include "cirll.h"

int main()
{
    list_t *list = malloc(sizeof(list_t));
    int i;

    for (i = 5; i > 0; i--) {
        cirll_insert_head(&list, i);
    }
    cirll_print(list);

    list_t *rlist = cirll_split(&list);
    cirll_print(list);
    cirll_print(rlist);

    return 0;
}