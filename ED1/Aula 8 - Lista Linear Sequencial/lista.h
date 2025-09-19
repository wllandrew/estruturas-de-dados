#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef int REGISTRO;

typedef struct Lista
{
    REGISTRO lista[MAX_SIZE];
    int qtd;
} Lista;

void inicializar_lista(Lista *l)
{
    l->qtd = 0;
}

void reinicializar_lista(Lista *l)
{
    for (int i=0; i<l->qtd; i++)
    {
        l->lista[i] = 0;
    }
    l->qtd = 0;
}

int tamanho_lista(Lista *l)
{
    return l->qtd;
}

bool lista_vazia(Lista *l)
{
    if (l->qtd == 0)
    {
        return true;
    }
    return false;
}

bool lista_cheia(Lista *l)
{
    if (l->qtd == MAX_SIZE)
    {
        return true;
    }
    return false;
}

void exibir_elementos(Lista *l)
{
    for (int i=0; i<l->qtd; i++)
    {
        printf("%d : %d\n", i, l->lista[i]);
    }
}

int busca(Lista *l, REGISTRO r)
{
    for (int i = 0; i < l->qtd; i++)
    {
        if (l->lista[i] == r)
        {
            return i + 1;
        }
    }
    return -1;
}

bool append(Lista *l, REGISTRO r)
{
    if (lista_cheia(l))
    {
        return false;
    }
    l->lista[l->qtd] = r;
    l->qtd++;
    return true; 
}

bool inserir(Lista *l, int pos, REGISTRO r)
{
    if (lista_cheia(l) || pos > MAX_SIZE)
    {
        return false;
    }
    for (int i=l->qtd; i >= pos; i--)
    {
        l->lista[i] = l->lista[i-1];
    }
    l->lista[pos] = r;
    l->qtd++;
    return true;
}

bool pop(Lista *l, REGISTRO *r)
{
    if (lista_vazia(l))
    {
        return false;
    }
    l->qtd--;
    *r = l->lista[l->qtd];
    l->lista[l->qtd] = 0;
    return true;
}

bool retirar(Lista *l, int pos, REGISTRO *r)
{
    if (lista_vazia(l) || pos < 0)
    {
        return false;
    }
    for (int i=pos; i<l->qtd; i++)
    {
        l->lista[i] = l->lista[i+1];
    }
    l->lista[l->qtd] = 0;
    l->qtd--;
    return true;
}

int busca_binaria(Lista *l, REGISTRO r)
{
    if (lista_vazia(l))
    {
        return -1;
    }

    int low = 0, high = l->qtd - 1, middle;
    
    while (low <= high)
    {
        middle = (high + low) / 2;

        if (l->lista[middle] == r)
        {
            return middle;
        }
        else if (l->lista[middle] < r)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    return -1;
}

bool insercao_em_ordem(Lista *l, REGISTRO r)
{
    if (lista_vazia(l))
    {
        return append(l, r);
    }
    
    int low = 0, high = l->qtd - 1, position;

    while (low <= high)
    {
        position = (high + low) / 2;

        if (l->lista[position] == r)
        {
            break;
        }
        else if (l->lista[position] < r)
        {
            low = position + 1;
        }
        else
        {
            high = position - 1;
        }
    }

    return inserir(l, position, r);
}

void bubble_sort(Lista *l)
{
    int swaps, temp;
    for (int i=0; i<l->qtd; i++)
    {
        swaps = 0;
        for (int j=0; j<l->qtd - 1; j++)
        {
            if (l->lista[j] > l->lista[j+1])
            {
                temp = l->lista[j+1];
                l->lista[j+1] = l->lista[j];
                l->lista[j] = temp;
                swaps++;
            }
        }
        if (swaps == 0)
        {
            break;
        }
    }
}