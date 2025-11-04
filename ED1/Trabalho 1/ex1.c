#include <stdio.h>
#include <stdbool.h>

#define INITIAL_SIZE 10

typedef struct
{
    int pilha[INITIAL_SIZE];
    int topo;
    int extensions;
} Pilha;

Pilha init_pilha()
{
    Pilha p;
    p.topo = -1;
    p.extensions = 0;
    return p;
}

void push(Pilha *p, int n)
{
    if (p->topo < INITIAL_SIZE - 1)
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
    for (int i = p->topo; i > -1; i--)
    {
        printf("Indice %d: %d\n", i, p->pilha[i]);
    }
}

bool extendPilha(Pilha *p)
{
    if (p->extensions >= 3)
    {
        return false;
    }

    int size = sizeof(p->pilha) / sizeof(int);

    int copy[size];
    for (int i=0; i<size; i++)
    {
        copy[i] = p->pilha[i];
    }

    size *= 3;

    
}

void reinit(Pilha *p)
{
    p->topo = -1;
}

int main()
{
    Pilha pilhas[2];
    init_pilha(pilhas[0]);
    init_pilha(pilhas[1]);


}