#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv.h"


int nos(Arv A)
{
    if (A == NULL) return 0;
    int no_count = 1;

    no_count += nos(esq_arv(A));
    no_count += nos(dir_arv(A));

    return no_count;
}

int main(void)
{
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)), 1, arv(NULL,3, NULL));
    int contagem = nos(A);
    fprintf(stdout, "%d", nos(A));
}
