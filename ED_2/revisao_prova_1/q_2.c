#include <stdio.h>
#include "char_static_stack.h"

int main(void)
{
    StaticStack *S = StaticStack_create(16);

    if (!StaticStack_is_empty(S))
    {
        StaticStack_push(S);
        printf("%c\n", StaticStack_peek(S));
        StaticStack_pop(S);

        if (right_node(p) != NULL) StaticStack_push(right_node(p));
        if (left_node(p) != NULL) StaticStack_push(left_node(p));
    }

    return 0;
}
