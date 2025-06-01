#include "yalist.h"

int main(void) {
    List *lst, *inner, *i1, *i2, *i3;
    lst = new_lst();
    inner = new_lst();
    i1 = new_int(1);
    i2 = new_int(2);
    i3 = new_int(3);

    push(inner, i2);
    push(inner, i3);
    push(lst, i1);
    push(lst, inner);
    print(lst);
/*    free_lst(lst);*/

    return 0;
}
