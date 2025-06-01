#include <stdio.h>
#include <stdlib.h>
#include "yalist.h"

List* new_lst(void) {
    List* new = malloc(sizeof(List));
    new->type = TYPE_LIST;
    new->len = 0;
    AS_LST(new) = NULL;
    return new;
}

List* new_int(int i) {
    List* new = malloc(sizeof(List));
    new->type = TYPE_INT;
    new->len = 0;
    AS_INT(new) = i;
    return new;
}

int push(List** lst, List* elem) {
    List* new ;
    if (!IS_LST(*lst)) {
        return 0;
    }
    if(!AS_LST(*lst))
    {
        new= malloc(sizeof(List));
        if (!new) {
            fprintf(stderr, "Cannot allocate memory for new element.\n");
            return 0;
        }
    }
    else
    {
        new = realloc(AS_LST(*lst), (LEN(*lst) + 1) * sizeof(List));
        if (!new) {
            fprintf(stderr, "Cannot allocate memory for new element.\n");
            return 0;
        }
    }
    AS_LST(*lst)=new;
    AS_LST(*lst)[LEN(*lst)]=*elem;
    LEN(*lst)++;
    return 1;
}

List* pop(List* lst) {
    List* copy;
    if (!IS_LST(lst)) {
        return NULL;
    }

    if (!LEN(lst)) {
        return NULL;
    }

    copy = malloc(sizeof(List));
    *copy = AS_LST(lst)[LEN(lst) - 1];
    AS_LST(lst) = realloc(AS_LST(lst), (LEN(lst) - 1) * sizeof(List));
    LEN(lst)--;
    
    return copy;
}

static void print_rec(List* lst)
{
    if(IS_INT(lst))
    {
        printf(" %d ",AS_INT(lst));
    }
    else 
    {
        int i;
        printf("(");
        for(i=0;i<lst->len;i++)
        {
            print_rec(&AS_LST(lst)[i]);
        }
        printf(")");
    }
}

void print(List* lst)
{
    print_rec(lst);
    printf("\n");
}

void free_lst(List* lst)
{
    if(!lst) return ;
    if(IS_INT(lst))
    {
        free(lst);
        return;
    }
    else 
    {
        int i;
        for(i=0;i<lst->len;i++)
        {
            free_lst(&AS_LST(lst)[i]);
        }
        free(lst);
    }
}



