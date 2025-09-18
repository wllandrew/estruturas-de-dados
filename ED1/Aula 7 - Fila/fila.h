#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef int ELEMENTO;

typedef struct Fila
{
    ELEMENTO fila[MAX_SIZE];
    int inicio;
    int qtd;
} Fila;

Fila inicializar_fila(Fila *f)
{
    f->inicio = 0;
    f->qtd = 0;
}

bool filaCheia(Fila *f)
{
    if (f->qtd >= MAX_SIZE)
    {
        return true;
    }
    return false;
}

bool filaVazia(Fila *f)
{
    if (f->qtd == 0)
    {
        return true;
    }
    return false;
}

ELEMENTO pop(Fila *f)
{
    if (filaVazia(f))
    {
        return NULL;
    }
    int v = f->fila[f->inicio];
    int pos = (f->inicio + 1) % MAX_SIZE;
    f->inicio = pos;
    return v;
}

void push(Fila *f, ELEMENTO v)
{
    if (filaCheia(f))
    {
        return;
    }
    int pos = (f->inicio + f->qtd) % MAX_SIZE;
    f->fila[pos] = v;
    f->qtd++;
}

void exibir_fila(Fila *f)
{
    int index = f->qtd;

    for (int j = 0; j < f->qtd; j++)
    {
        printf("%d\n", f->fila[index]);
        index = (index + 1) % MAX_SIZE;
    }
}