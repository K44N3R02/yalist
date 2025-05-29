#include <stdio.h>
#include <stdlib.h>
#include "yalist.h"

List* new_lst(void) {
    List* new = malloc(sizeof(List));
    new->type = TYPE_LIST;
    new->len = 0;
    new->as.l = NULL;
    return new;
}

List* new_int(int i) {
    List* new = malloc(sizeof(List));
    new->type = TYPE_INT;
    new->len = 0;
    new->as.i = i;
    return new;
}

int push(List* lst, List* elem) {
    List* new ;
    if (!IS_LST(lst)) {
        return 0;
    }

    new = realloc(AS_LST(lst), (LEN(lst) + 1) * sizeof(List));
    if (!new) {
        fprintf(stderr, "Cannot allocate memory for new element.\n");
        return 0;
    }
    AS_LST(lst)[LEN(lst)]=*elem;
    LEN(lst)++;
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
    
    return copy;
}

void print(List* lst)
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
            print(&AS_LST(lst)[i]);
        }
        printf(")");
    }


    printf(")");
}

void free_lst(List* lst)
{
    if(IS_INT(lst))
    {
        free(lst);
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

