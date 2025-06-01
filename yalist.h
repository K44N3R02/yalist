#ifndef ylist_h
#define ylist_h

typedef enum {
    TYPE_INT,
    TYPE_CHAR,
    TYPE_LIST
} Type;

typedef struct list {
    Type type;
    int len;
    union {
        int i;
        struct list* l;
    } as;
} List;

#define AS_LST(lst) ((lst)->as.l)
#define AS_INT(lst) ((lst)->as.i)
#define IS_LST(lst) ((lst)->type == TYPE_LIST)
#define IS_INT(lst) ((lst)->type == TYPE_INT)
#define LEN(lst) ((lst)->len)

List* new_lst(void);
List* new_int(int i);
int push(List** lst, List* elem);
List* pop(List* lst);
void print(List* lst);
void free_lst(List* lst);

#endif
