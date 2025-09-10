#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    struct Node* proximo;
    int valor;
} Node;

typedef struct Pilha
{
    Node* topo;
    int tamanho;
} Pilha;

void init_pilha(Pilha *p)
{
    p->topo = NULL;
    p->tamanho = 0;
}

void inserir(Pilha *p, int val)
{
    Node *n = (Node*)malloc(sizeof(Node));

    if (n == NULL)
    {
        return;
    }

    n->valor = val;
    n->proximo = p->topo;
    p->topo = n;
    p->tamanho++;
}

int retirar(Pilha *p)
{
    Node *n = p->topo;

    if (n == NULL)
    {
        return 0;
    }

    p->topo = p->topo->proximo;
    p->tamanho--;

    int v = n->valor;
    free(n);
    
    return v;
}

void percorreFIFO(Pilha *p)
{
    Node *n = p->topo;

    while (n != NULL)
    {
        printf("%d\n", n->valor);
        n = n->proximo;
    }
}

void excluir_pilha(Pilha *p)
{
    Node* n = p->topo;
    
    while (p->topo != NULL)
    {
        p->topo = p->topo->proximo;
        free(n);
        n = p->topo;
    }

    p->tamanho = 0;
}

int tamanho_pilha(Pilha* p)
{
    int tam = 0;

    for (Node* i = p->topo; i != NULL; i = i->proximo)
    {
        tam++;
    }

    return tam;
}