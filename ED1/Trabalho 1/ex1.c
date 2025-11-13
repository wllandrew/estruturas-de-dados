#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ELEMENTO;

typedef struct Pilha
{
    int *pilha;
    int tamanho;
    int topo;
    int aumentos;
} Pilha;

void InicializarPilha(Pilha *p)
{
    p->pilha = (int*)malloc(sizeof(int) * 10);
    p->tamanho = 10;
    p->topo = -1;
    p->aumentos = 0;
}

void PrintPilha(Pilha *p)
{
    for (int i=0; i<=p->topo; i++)
    {
        printf("%d ", p->pilha[i]);
    }
    printf("\n");
}

bool ProcuraPilha(Pilha *p, int valor, int *end)
{
    for (int i=0; i<=p->topo; i++)
    {
        if (p->pilha[i] == valor)
        {
            *end = i;
            return true;
        }
    }
    return false;
}

bool AppendPilha(Pilha *p, int valor)
{
    if (p->topo >= p->tamanho)
    {
        ResizePilha(p);
    }

    p->pilha[++p->topo] = valor;

    return true;
}

bool RemovePilha(Pilha *p, int valor)
{
    int end;
    if (!ProcuraPilha(p, valor, &end))
    {
        return false;
    }

    for (int i=end; i<=p->topo; i++)
    {
        p->pilha[i] = p->pilha[i+1];
    }

    p->topo--;
    return true;
}

bool ResizePilha(Pilha *p)
{
    int copy[p->tamanho];
    for (int i=0; i<p->tamanho; i++)
    {
        copy[i] = p->pilha[i];
    }

    int tam = p->tamanho;
    p->tamanho *= (int)1.5;

    free(p->pilha);

    p->pilha = (int*)malloc(sizeof(int) * p->tamanho);

    for (int i=0; i<tam; i++)
    {
        p->pilha[i] = copy[i];
    }
    p->aumentos++;
}

int main()
{
    Pilha A[2];
    InicializarPilha(&A[0]);
    InicializarPilha(&A[1]);

    int resp, valor, pilha, resultado;
    while (true)
    {
        printf("0-sair\n");
        printf("1-adicionar valor\n");
        printf("2-remover valor\n");
        printf("3-buscar valor\n");
        printf("4-imprime pilha\n");
        printf("5-destruir pilha\n");

        scanf("%d", &resp);

        if (resp == 0)
        {
            break;
        }
        else if (resp == 1)
        {
            printf("Valor: ");
            scanf("%d", &valor);
            printf("Pilha (1 ou 2): ");
            scanf("%d", &pilha);
            if (pilha != 1 && pilha != 2)
            {
                printf("Pilha invalida;\n");
            }
            else
            {
                resultado = AppendPilha(&A[pilha-1], valor);
                if (!resultado)
                {
                    printf("Nao foi possivel adicionar a pilha\n");
                }
            }
        }
        else if (resp == 2)
        {
            printf("Valor: ");
            scanf("%d", &valor);
            printf("Pilha (1 ou 2): ");
            scanf("%d", &pilha);
            if (pilha != 1 && pilha != 2)
            {
                printf("Pilha invalida;\n");
            }
            else
            {
                resultado = RemovePilha(&A[pilha-1], valor);
                if (!resultado)
                {
                    printf("Nao foi possivel remover da pilha\n");
                }
            }
        }
        else if (resp == 3)
        {   
            printf("Valor: ");
            scanf("%d", &valor);
            printf("Pilha (1 ou 2): ");
            scanf("%d", &pilha);
            if (pilha != 1 && pilha != 2)
            {
                printf("Pilha invalida;\n");
            }
            else
            {
                int end;
                resultado = ProcuraPilha(&A[pilha-1], valor, &end);
                if (!resultado)
                {
                    printf("Valor nao esta na pilha\n");
                }
            }
        }
        else if (resp == 4)
        {
            printf("Pilha (1 ou 2): ");
            scanf("%d", &pilha);
            if (pilha != 1 && pilha != 2)
            {
                printf("Pilha invalida;\n");
            }
            else
            {
                PrintPilha(&A[pilha-1]);
            }
        }
        else if (resp == 5)
        {
            printf("Pilha (1 ou 2): ");
            scanf("%d", &pilha);
            if (pilha != 1 && pilha != 2)
            {
                printf("Pilha invalida;\n");
            }
            else
            {
                free(&A[pilha-1]);
            }
        }

        if (A[0].aumentos == 3 || A[1].aumentos == 3)
        {
            free(&A[0]);
            free(&A[1]);
            printf("Excedeu o limite de aumentos da pilha\n");
        }
    }

    return 0;
}