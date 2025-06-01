#include "yalist.h"

int main(void)
{
	List *lst, *inner, *i1, *i2, *i3, *i4,*i5,*popped , *innerininneri;
	lst = new_lst();
	inner = new_lst();
	i1 = new_int(1);
	i2 = new_int(2);
	i3 = new_int(3);
	i4 = new_int(4);
	i5 = new_int(5);
	innerininneri = new_lst();
	push(&innerininneri,i4);
	push(&innerininneri,i5); 

	push(&inner, i2);
	push(&inner, i3);
	push(&inner, innerininneri);
	push(&lst, i1);
	push(&lst, inner);
	print(lst);
    popped = pop(lst);
    print(lst);
    print(popped);
	free_lst(lst);
    free_lst(popped);

	return 0;
}
