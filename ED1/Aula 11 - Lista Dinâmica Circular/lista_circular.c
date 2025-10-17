#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int ELEMENTO;

typedef struct Node
{
    ELEMENTO Valor;
    Node* Proximo;
} Node;

typedef struct ListaCircular
{
    Node* Cabeca;
} ListaCircular;

void InicializaListaCircular(ListaCircular* lista)
{
    lista->Cabeca = (Node*)malloc(sizeof(Node));
    lista->Cabeca->Proximo = lista->Cabeca;
}

int TamanhoListaCircular(ListaCircular* lista)
{
    Node* aux = lista->Cabeca->Proximo;
    int count = 0;
    while (aux != lista->Cabeca)
    {
        count++;
        aux = aux->Proximo;
    }
    return count;
}

void ExibirListaCircular(ListaCircular* lista)
{
    printf("Lista: ");
    for (Node* aux = lista->Cabeca->Proximo; aux != lista->Cabeca; aux = aux->Proximo)
    {
        printf("%d ", aux->Valor);
    }
    printf("\n");
}

Node* BuscaSequencialListaCircular(ListaCircular* lista, ELEMENTO valor)
{
    Node* aux = lista->Cabeca->Proximo;

    while (aux != lista->Cabeca)
    {
        if (aux->Valor == valor)
        {
            return aux;
        }
        aux = aux->Proximo;
    }

    return NULL;
}

Node* BuscaSequencialSentinelaListaCircular(ListaCircular* lista, ELEMENTO valor)
{
    Node* aux = lista->Cabeca->Proximo;

    while (aux != lista->Cabeca && aux->Valor < valor)
    {
        aux = aux->Proximo;
    }

    if (aux != NULL && aux->Valor == valor)
    {
        return aux;
    }

    return NULL;
}

Node* BuscaPosicaoDeInsercaoListaOrdenada(ListaCircular* lista, ELEMENTO valor, Node** anterior)
{
    *anterior = lista->Cabeca;
    Node* aux = lista->Cabeca->Proximo;

    while (aux != lista->Cabeca && aux->Valor < valor)
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

bool InserirOrdenadoListaCircular(ListaCircular* lista, ELEMENTO valor)
{
    Node* anterior;
    Node* i = BuscaPosicaoDeInsercaoListaOrdenada(lista, valor, &anterior);

    if (i != NULL)
    {
        return false;
    }

    i = (Node*)malloc(sizeof(Node));
    i->Valor = valor;

    i->Proximo = anterior->Proximo;
    anterior->Proximo = i;

    return true;
}

bool ExcluirOrdenadoListaCircular(ListaCircular* lista, ELEMENTO valor)
{
    Node* anterior;
    Node* i = BuscaPosicaoDeInsercaoListaOrdenada(lista, valor, &anterior);

    if (i == NULL)
    {
        return false;
    }

    anterior->Proximo = i->Proximo;
    free(i);

    return true;
}

void ReinicializarListaCircular(ListaCircular* lista)
{
    Node* aux = lista->Cabeca->Proximo;

    while (aux != lista->Cabeca)
    {
        Node* c = aux;
        aux = aux->Proximo;
        free(c);
    }

    lista->Cabeca->Proximo = lista->Cabeca;
}