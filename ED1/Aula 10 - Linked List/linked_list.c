#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int ELEMENTO;

typedef struct Node
{
    ELEMENTO Valor;
    ELEMENTO* Proximo;
} Node;

typedef struct Lista
{
    ELEMENTO* Inicio;
} Lista;

void InicializarLista(Lista *lista)
{
    lista->Inicio = NULL;
}

int TamanhoLista(Lista* lista)
{
    Node* aux = lista->Inicio;
    int count = 0;
    while (aux != NULL)
    {
        count++;
        aux = aux->Proximo;
    }
    return count;
}

void ExibirLista(Lista* lista)
{
    printf("Lista: ");
    for (Node* aux = lista->Inicio; aux != NULL; aux = aux->Proximo)
    {
        print("%d ", aux->Valor);
    }
    print("\n");
}

Node* BuscaSequencial(Lista *lista, ELEMENTO valor)
{
    Node* aux = lista->Inicio;
    while (aux != NULL)
    {
        if (aux->Valor == valor)
        {
            return aux;
        }  
        aux = aux->Proximo;
    }
    return NULL;
}

Node* BuscaSequencialOrdenada(Lista* lista, ELEMENTO valor)
{
    Node* aux = lista->Inicio;
    while (aux != NULL && aux->Valor < valor)
    {
        aux = aux->Proximo;
    }

    if (aux != NULL && aux->Valor == valor)
    {
        return aux;
    }
    return NULL;
}

Node* BuscaPosicaoInserir(Lista* lista, ELEMENTO valor, Node** anterior)
{
    Node* aux = lista->Inicio;
    *anterior = NULL;

    while (aux != NULL && aux->Valor < valor)
    {
        *anterior = aux;
        aux = aux->Proximo;
    }

    if (aux != NULL && aux->Valor == valor)
    {
        return aux;
    }  
    return NULL;
}

bool InserirOrdenadoLista(Lista* lista, ELEMENTO valor)
{
    Node* anterior;
    Node* i = BuscaPosicaoInserir(lista, valor, &anterior);

    if (i != NULL)
    {
        return false;
    }

    i = (Node*)malloc(sizeof(Node));

    if (anterior == NULL)
    {
        i->Proximo = lista->Inicio;
        lista->Inicio = i;
    }
    else
    {
        i->Proximo = anterior->Proximo;
        anterior->Proximo = i;
    }
    return true;
}

bool ExcluiLista(Lista* lista, ELEMENTO valor)
{
    Node* anterior;
    Node* i = BuscaPosicaoInserir(lista, valor, &anterior);

    if (i == NULL)
    {
        return false;
    }

    if (anterior == NULL)
    {
        lista->Inicio = i->Proximo;
    }
    else
    {
        anterior->Proximo = i->Proximo;
    }

    free(i);

    return true;
}

void ReinicializarLista(Lista* lista)
{
    Node* aux = lista->Inicio;

    while (aux != NULL)
    {
        Node* c = aux;
        aux = aux->Proximo;
        free(c);
    }

    lista->Inicio = NULL;
}