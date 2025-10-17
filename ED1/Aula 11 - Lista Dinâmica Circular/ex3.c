#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Tarefa
{
    int Id;
    char Descricao[100];
    int prioridade; 
} Tarefa;

typedef struct Node
{
    Tarefa tarefa;
    Node* Proximo;
} Node;

typedef struct ListaTarefas
{
    Node* Head;
} ListaTarefas;

void InicializaListaTarefas(ListaTarefas* l)
{
    l->Head = (Node*)malloc(sizeof(Node));
    l->Head->Proximo = l->Head;
}

void PrintTarefa(Tarefa* t)
{
    printf("Id : %d\n", t->Id);
    printf("Descricao: %s\n", t->Descricao);
    printf("Prioridade: %d\n", t->prioridade);
}

void ExibirListaTarefas(ListaTarefas* l)
{
    Node* aux = l->Head->Proximo;

    while (aux != l->Head)
    {
        PrintTarefa(&aux->tarefa);
    }
}

Node* BuscaInsercaoPrioridade(ListaTarefas* lista, int prioridade, Node** anterior)
{
    *anterior = lista->Head;
    Node* aux = lista->Head->Proximo;

    while (aux != lista->Head && aux->tarefa.prioridade <= prioridade)
    {
        *anterior = aux;
        aux = aux->Proximo;
    }

    return aux;
}

bool InsereTarefaOrdenada(ListaTarefas* l)
{
    Tarefa t;
    printf("Id: ");
    scanf("%d", t.Id);
    printf("Descricao: "); /// problema aqui
    scanf("%s", t.Descricao);
    printf("Prioridade: ");
    scanf("%d", t.prioridade);

    Node* anterior;
    Node* i = BuscaInsercaoPrioridade(l, t.prioridade, &anterior);

    i = (Node*)malloc(sizeof(Node));
    if (i == NULL) return false;

    if (t.prioridade > 3 || t.prioridade < 1)
    {
        free(i);
        return false;
    }

    i->tarefa.Id = t.Id;
    strcpy(i->tarefa.Descricao, t.Descricao);
    i->tarefa.prioridade = t.prioridade;

    i->Proximo = anterior->Proximo;
    anterior->Proximo = i;
    
    return true;
}

Node* BuscaRemocaoId(ListaTarefas* lista, int id, Node** anterior)
{
    *anterior = lista->Head;
    Node* aux = lista->Head->Proximo;

    while (aux != lista->Head && aux->tarefa.prioridade != id)
    {
        *anterior = aux;
        aux = aux->Proximo;
    }

    if (aux != NULL && aux->tarefa.prioridade == id)
    {
        return aux;
    }

    return NULL;
}

bool RemoveTarefaPorId(ListaTarefas* l)
{
    int id;
    printf("Id da tarefa: ");
    scanf("%d", &id);

    Node* anterior;
    Node* i = BuscaRemocaoId(l, id, &anterior);

    if (i == NULL)
    {
        return false;
    }

    anterior->Proximo = i->Proximo;
    free(i);

    return true;
}

Node* BuscaSubstring(ListaTarefas* l, char str[])
{
    Node* aux = l->Head->Proximo;

    while (aux != l->Head)
    {
        if (strstr(aux->tarefa.Descricao, str) != NULL)
        {
            return aux;
        }
    }

    return NULL;
}

bool BuscaTarefaPorDescricao(ListaTarefas* l)
{
    char sub[20];
    printf("Parte da descricao (20 carac. max): ");
    scanf("%s", &sub);

    Node* aux = BuscaSubstring(l, sub);

    if (aux == NULL)
    {
        return false;
    }

    PrintTarefa(&aux->tarefa);

    return true;
}

void EsvaziarLista(ListaTarefas* l)
{
    Node* aux = l->Head->Proximo;

    while(aux != l->Head)
    {
        Node* p = aux;
        aux = aux->Proximo;

        free(p);
    }

    l->Head->Proximo = l->Head;
}

int main()
{
    int resposta;
    bool res;
    ListaTarefas Lista;
    InicializaListaTarefas(&Lista);

    while (true)
    {
        printf("0 - Sair\n");
        printf("1 - Inserir tarefa ordenada\n");
        printf("2 - Removar tarefa por ID\n");
        printf("3 - Buscar tarefa por descricao\n");
        printf("4 - Listar tarefas\n");
        printf("5 - Esvaziar lista\n");
        printf("Resposta: ");
        scanf("%d", &resposta);

        if (resposta == 0)
        {
            break;
        }
        else if (resposta == 1)
        {
            res = InsereTarefaOrdenada(&Lista);

            if (!res)
            {
                printf("Nao foi possivel adicionar esta tarefa.\n");
            }
        }
        else if (resposta == 2)
        {
            res = RemoveTarefaPorId(&Lista);

            if (!res)
            {
                printf("Essa tarefa nao existe.");
            }
        }
        else if (resposta == 3)
        {
            res = BuscaTarefaPorDescricao(&Lista);

            if (!res)
            {
                printf("Esta tarefa nao existe");
            }
        }
        else if (resposta == 4)
        {
            ExibirListaTarefas(&Lista);
        }
        else if (resposta == 5)
        {
            EsvaziarLista(&Lista);
        }
    }

    EsvaziarLista(&Lista);

    return 0;
}