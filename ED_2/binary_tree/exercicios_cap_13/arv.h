#ifndef ARV_H
#define ARV_H

typedef int Item;
typedef struct arv *Arv;

Arv arv(Arv e, Item x, Arv d);

Arv dir_arv(Arv A);
Arv esq_arv(Arv A);
Item item_arv(Arv A);

void emordem(Arv A);
void preordem(Arv A);
void posordem(Arv A);

void destroi(Arv *A);
void ins(Item x, Arv *A);

bool busca (Item x, Arv A);

Item remmax(Arv *A);
void rem(Item x, Arv *A);

#endif
