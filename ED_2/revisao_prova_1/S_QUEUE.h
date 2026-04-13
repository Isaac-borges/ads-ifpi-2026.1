#ifndef S_QUEUE_H
#define S_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../binary_tree/exercicios_cap_13/arv.h"

typedef Arv ITEM_Q;

typedef struct _static_queue S_QUEUE;

S_QUEUE *s_queue_create(long capacity);

void s_queue_destroy(S_QUEUE **Q_REF);

bool s_queue_is_empty(const S_QUEUE *Q);
bool s_queue_is_full(const S_QUEUE *Q);
void s_queue_enqueue(S_QUEUE *Q, ITEM_Q item);

ITEM_Q s_queue_peek(const S_QUEUE *Q);
ITEM_Q s_queue_dequeue(S_QUEUE *Q);

#endif