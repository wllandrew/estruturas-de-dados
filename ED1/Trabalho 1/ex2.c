#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int ELEMENTO;

typedef struct Node
{
    ELEMENTO Valor;
    Node* Proximo;
} Node;

typedef struct Lista
{
    Node* Inicio;
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
        printf("%d ", aux->Valor);
    }
    printf("\n");
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
    i->Valor = valor;

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

void InicializaArrayDeListas(Lista arr[])
{
    for (int i = 0; i < 10; i++)
    {
        InicializarLista(&arr[i]);
    }
}

void DestroiArrayDeListas(Lista arr[])
{
    for (int i = 0; i < 10; i++)
    {
        ReinicializarLista(&arr[i]);
    }
}

int GetChaveLista(int valor)
{
    return valor % 10;
}

int main()
{
    Lista arr[10];
    InicializaArrayDeListas(arr);

    int resp, valor, chave, resultado;
    while (true)
    {
        printf("0-sair\n");
        printf("1-adicionar valor\n");
        printf("2-remover valor\n");
        printf("3-buscar valor\n");
        printf("4-imprime lista\n");
        printf("5-destruir lista\n");

        scanf("%d", &resp);

        if (resp == 0)
        {
            break;
        }
        else if (resp == 1)
        {
            printf("Valor: ");
            scanf("%d", &valor);

            chave = GetChaveLista(valor);

            resultado = InserirOrdenadoLista(&arr[chave], valor);

            if (!resultado)
            {
                printf("Nao foi possivel inserir.\n");
            }
        }
        else if (resp == 2)
        {
            printf("Valor: ");
            scanf("%d", &valor);

            chave = GetChaveLista(valor);

            resultado = ExcluiLista(&arr[chave], valor);

            if (!resultado)
            {
                printf("Nao foi possivel remover.\n");
            }
        }
        else if (resp == 3)
        {   
            printf("Valor: ");
            scanf("%d", &valor);

            chave = GetChaveLista(valor);

            if (BuscaSequencialOrdenada(&arr[chave], valor) == NULL)
            {
                printf("Nao foi possivel encontrar.\n");
            }
            else
            {
                printf("Elemento esta no array na posicao %d\n", chave);
            }
        }
        else if (resp == 4)
        {
            printf("chave a ser impressa: ");
            scanf("%d", &valor);

            if (valor >= 0 && valor <= 9)
            {
                ExibirLista(&arr[valor]);
            }
        }
        else if (resp == 5)
        {
            DestroiArrayDeListas(arr);
        }
    }
}