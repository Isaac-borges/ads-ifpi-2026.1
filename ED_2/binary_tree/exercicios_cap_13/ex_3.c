#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv.h"

int folhas(Arv A)
{
    if (A == NULL) return 0;
    if (dir_arv(A) == NULL && esq_arv(A) == NULL) return 1;

    int folha_count = 0;
    folha_count += folhas(dir_arv(A));
    folha_count += folhas(esq_arv(A));

    return folha_count;
}

int main(void)
{
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)), 1, arv(NULL,3,arv(NULL, 6, NULL)));
    int qtd_folhas = folhas(A);

    fprintf(stdout, "Quantidade de folhas Arvore A: %d\n", qtd_folhas);

    Arv B = arv(NULL, 1, NULL);
    qtd_folhas = folhas(B);

    fprintf(stdout, "Quantidade de folhas Arvore B: %d\n", qtd_folhas);

    return 0;
}
