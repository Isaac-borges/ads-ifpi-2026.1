#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv.h"

int main(void)
{
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)), 1, arv(NULL,3, NULL));
    int contagem = nos(A);
    fprintf(stdout, "%d", nos(A));
}
