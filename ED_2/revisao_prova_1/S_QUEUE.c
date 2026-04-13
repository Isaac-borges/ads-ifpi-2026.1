#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../binary_tree/exercicios_cap_13/arv.h"
#include "S_QUEUE.h"

typedef Arv ITEM_Q;

typedef struct _static_queue
{
    ITEM_Q *data;
        long begin;
    long end;
    long capacity;
    long size;
} S_QUEUE;

S_QUEUE *s_queue_create(long capacity)
{
    S_QUEUE *Q = (S_QUEUE*) calloc(1, sizeof(S_QUEUE));
    Q->data = (ITEM_Q*) calloc(capacity, sizeof(ITEM_Q));
    Q->capacity = capacity;
    Q->begin = 0;
    Q->end = 0;
    Q->size = 0;

    return Q;
};

void s_queue_destroy(S_QUEUE **Q_REF)
{
    S_QUEUE *Q = *Q_REF;

    free(Q->data);
    free(Q);

    *Q_REF = NULL;
};

bool s_queue_is_empty(const S_QUEUE *Q)
{
    return Q->size == 0;
};

bool s_queue_is_full(const S_QUEUE *Q)
{
    return Q->size == Q->capacity;
};


void s_queue_enqueue(S_QUEUE *Q, ITEM_Q item)
{
    if (s_queue_is_full(Q))
    {
        puts("FILA CHEIA!");
        abort();
    }

    Q->data[Q->end] = item;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;
};

ITEM_Q s_queue_peek(const S_QUEUE *Q)
{
    if (s_queue_is_empty(Q))
    {
        puts("FILA VAZIA!");
        abort();
    }

    return Q->data[Q->begin];
};

ITEM_Q s_queue_dequeue(S_QUEUE *Q)
{
    if(s_queue_is_empty(Q))
    {
        puts("FILA VAZIA!");
        abort();
    }

    ITEM_Q data = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;

    return data;
};

