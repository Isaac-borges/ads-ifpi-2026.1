#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "S_QUEUE.h"
#include "../binary_tree/exercicios_cap_13/arv.h"


int main(void)
{
    S_QUEUE *Q = s_queue_create(8);
    Arv tree = arv(arv(arv(NULL,2,NULL),10,arv(NULL,12,NULL)),13,arv(arv(NULL,20,NULL),25,arv(NULL,31,arv(NULL,29,NULL))));

    if (tree != NULL)
    {
        s_queue_enqueue(Q, tree);
        while(!s_queue_is_empty(Q))
        {
            tree = s_queue_peek(Q);
            printf("%d ", item_arv(tree));
            s_queue_dequeue(Q);

            if (esq_arv(tree) != NULL) s_queue_enqueue(Q, esq_arv(tree));
            if (dir_arv(tree) != NULL) s_queue_enqueue(Q, dir_arv(tree));
        }

    }

    return 0;
}
