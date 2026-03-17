#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv.h"

bool tem(Arv A, int x)
{
    if (A == NULL) return false;
    if (item_arv(A) == x) return true;
    if (item_arv(esq_arv(A)) != x) return tem(esq_arv(A), x);
    else if (item_arv(dir_arv(A)) != x) return tem(dir_arv(A), x);
}

int main(void)
{
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)), 1, arv(NULL,3,arv(NULL, 6, NULL)));
    int x = 5;
    
    if (tem(A, x)) printf("Tem %d", x); 
    else printf("Nao tem %d", x);

    return 0;
}