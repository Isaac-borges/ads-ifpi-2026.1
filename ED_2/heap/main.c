#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 32 
#define troca(A, B, X) {X = A; A = B; B = X;}

void heapify_max(int vetor[MAX_HEAP], int indice, int tamanho)
{
    int maior = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if (esq < tamanho && vetor[maior] < vetor[esq]) maior = esq;
    if (esq < tamanho && vetor[maior] < vetor[dir]) maior = dir;

    if (maior != indice)
    {
        int X = vetor[indice];
        troca(vetor[indice], vetor[maior], X);
        heapify_max(vetor, maior, tamanho);
    }
}

void add_node(){};

void build_heap(int vetor[MAX_HEAP], int tamanho)
{
    for (int i = (tamanho/2)-1; i>= 0; i--)
    {
        heapify_max(vetor, i, tamanho);
    }
}

int main(void)
{
    int vetor[MAX_HEAP] = {10, 30, 20, 50, 40, 75, 90};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    build_heap(vetor, n);

    for (int i = 0;i < n;i++) printf("%d ", vetor[i]);

    printf("\n");

    return 0;
}