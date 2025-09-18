#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    int pilha[MAX_SIZE];
    int topo;
} Pilha;

void push(Pilha *p, int n)
{
    if (p->topo < MAX_SIZE - 1)
    {
        p->topo++;
        p->pilha[p->topo] = n;
    }
    return;
}

void pop(Pilha *p)
{
    if (p->topo > -1)
    {
        p->pilha[p->topo] = 0;
        p->topo--;
    }
}

int len(Pilha *p)
{
    return p->topo + 1;
}

void percorre(Pilha *p)
{
    for (int i = 0; i <= p->topo; i++)
    {
        printf("Indice %d: %d\n", i, p->pilha[i]);
    }
}

void percorreLIFO(Pilha *p)
{
    for (int i = p->topo; i > -1; i--)
    {
        printf("Indice %d: %d\n", i, p->pilha[i]);
    }
}

Pilha init_pilha()
{
    Pilha p;
    p.topo = -1;
    return p;
}

void reinit(Pilha *p)
{
    p->topo = -1;
}