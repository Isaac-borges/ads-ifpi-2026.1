#include <stdio.h>
#include <stdlib.h>

typedef int ItemL;

typedef struct _no_lista {
    ItemL conteudo;
    struct _no_lista *prox;
} No;

typedef struct _lista_encadeada {
    No *inicio;
    No *fim;
} Lista;

No *criar_no(ItemL x)
{
    No *no = (No*) calloc(1, sizeof(No));
    no->conteudo = x;
    no->prox = NULL;

    return no;
}

Lista *iniciar_lista()
{
    Lista *L = (Lista *) calloc(1, sizeof(Lista));
    L->inicio = NULL;
    L->fim = NULL;

    return L;
}
