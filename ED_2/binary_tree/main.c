
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"

int main(void) {
    NODEPTR p = binary_tree_create(12);
    set_left(p, 11);
    set_right(p, 13);


    printf("Raiz: %d\n", node_info(p));
    printf("Raiz->Esquerda: %d\n", node_info(left_node(p)));
    printf("Raiz->Direita: %d\n", node_info(right_node(p)));

    remove_node(right_node(p));

    printf("Raiz: %d\n", node_info(p));
    printf("Raiz->Esquerda: %d\n", node_info(left_node(p)));
    printf("Raiz->Direita: %d\n", node_info(right_node(p)));

    return 0;
}
