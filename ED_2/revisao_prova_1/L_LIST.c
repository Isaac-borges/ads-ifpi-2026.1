#include <stdio.h>
#include <stdlib.h>

typedef int L_ITEM;

typedef struct _list_node {
    L_ITEM data;
    struct _list_node* next;
} L_NODE;


typedef struct _linked_list {
    L_NODE* begin;
    L_NODE* end;
} L_LIST;

L_LIST* l_list_create()
{
    L_LIST *L = (L_LIST *) calloc(1, sizeof(L_LIST));

    L->begin = NULL;
    L->end = NULL;

    return L;
}

L_NODE* l_node_create(L_ITEM data)
{
    L_NODE* N = (L_NODE *) calloc(1, sizeof(L_NODE));

    N->next = NULL;
    N->data = data;

    return N;
}

void l_node_insert_last(L_LIST* L, L_ITEM data)
{
    L_NODE* NEW = l_node_create(data);

    if (L->begin == NULL)
    {
        b
    }
}

int main(void)
{
    return 0;
}
