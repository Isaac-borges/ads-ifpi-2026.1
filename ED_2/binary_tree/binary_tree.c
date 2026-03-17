#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

struct nodetype {
    int info;
    struct nodetype* left;
    struct nodetype* right;
    struct nodetype* father;
};

typedef struct nodetype* NODEPTR;

NODEPTR getnode()
{
    NODEPTR p = (NODEPTR) calloc(1, sizeof(struct nodetype));

    return p;
}

NODEPTR binary_tree_create(int x)
{
    NODEPTR p;

    p = getnode();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    p->father = NULL;

    return p;
}

void set_left(NODEPTR p, int x)
{
    if (p == NULL) puts("Inserção vazia\n");
    else if (p->left != NULL) puts("Inserção incorreta\n");
    else
    {
        p->left = binary_tree_create(x);
        p->left->father = p;
    }
}

void set_right(NODEPTR p, int x)
{
    if (p == NULL) puts("Inserção vazia\n");
    else if (p->right != NULL) puts("Inserção incorreta\n");
    else
    {
        p->right = binary_tree_create(x);
        p->right->father = p;
    }
}

int node_info(const NODEPTR p)
{
    if (p == NULL)
    {
        fprintf(stderr, "Nó vazio!");
        exit(EXIT_FAILURE);
    }
    return p->info;
}

NODEPTR left_node(const NODEPTR p)
{
    if (p->left == NULL || p == NULL)
    {
        fprintf(stderr, "Nó vazio");
        exit(EXIT_FAILURE);
    }
    return p->left;
}

NODEPTR right_node(const NODEPTR p)
{
    if (p->right == NULL || p == NULL)
    {
        fprintf(stderr, "Nó vazio");
        exit(EXIT_FAILURE);
    }
    return p->right;
}

NODEPTR father_node(const NODEPTR p)
{
    if (p->father == NULL || p == NULL)
    {
        fprintf(stderr, "Não há nó pai!");
        exit(EXIT_FAILURE);
    }
    return p->father;
}

bool is_brother(const NODEPTR p)
{
    if (p->father == NULL || p == NULL) return false;

    NODEPTR f = p->father;

    if (f->right == p && f->left != NULL) return true;
    if (f->left == p && f->right != NULL) return true;

    return false;
}

bool is_leaf(const NODEPTR p)
{
    if (p->left == NULL && p->right == NULL) return true;

    return false;
}

bool has_one_son(const NODEPTR p)
{
    if (
        (p->left == NULL && p->right != NULL) ||
        (p->left != NULL && p->right == NULL)
    ) return true;

    return false;
}

void remove_node(NODEPTR p)
{
    if (p->father == NULL)
    {

    }
    if (is_leaf(p)) // PRIMEIRO CASO: É FOLHA
    {
        if (p->father->right == p) p->father->right = NULL;
        else if (p->father->left == p) p->father->left = NULL;

        free(p);
    } // SEGUNDO CASO: TEM UM FILHO
    // PRA VERIFICAR SE TEM UM FILHO:
    else if (p->left == NULL && p->right != NULL) // TEM FILHO À DIREITA
    {
        if (p->father->right == p) // SE O NÓ P FOR FILHO DA DIREITA
        {
            p->father->right = p->right;
            p->father->right->father = p->father;
        }
        else if (p->father->left == p) // SE O NÓ P FOR FILHO DA ESQUERDA
        {
            p->father->left = p->right;
            p->father->left->father = p->father;
        }

        free(p);
    }
    else if (p->left != NULL && p->right == NULL) // TEM FILHO À ESQUERDA
    {
        if (p->father->right == p) // SE O NÓ P FOR FILHO DA DIREITA
        {
            p->father->right = p->left;
            p->father->right->father = p->father;
        }
        else if (p->father->left == p) // SE O NÓ P FOR FILHO DA DIREITA
        {
            p->father->left = p->left;
            p->father->left->father = p->father;
        }

        free(p);
    }
    else // TERCEIRO CASO: TEM DOIS FILHOS
         // IDEIA: COLOCAR O DA DIREITA PARA SUBSTITUIR O NÓ, VAMOS CONSIDERAR QUE ELE É O MAIOR
    {

    }


}
