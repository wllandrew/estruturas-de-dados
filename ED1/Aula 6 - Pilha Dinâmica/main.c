#include <stdio.h>
#include "pilha_dinamica.h"

typedef int REGISTRO;

int main()
{
    Pilha p;
    init_pilha(&p);

    int val, resp;

    while(1)
    {
        printf("1 - Inserir na Pilha;\n");
        printf("2 - Tirar da Pilha;\n");
        printf("3 - Tamanho da Pilha;\n");
        printf("4 - Percorrer FIFO;\n");
        printf("5 - Reinicializar pilha;\n");
        printf("6 - Sair\n");
        printf("Resposta: ");

        scanf("%d", &resp);

        if (resp == 6)
        {
            excluir_pilha(&p);
            break;
        }

        if (resp == 1)
        {
            printf("Valor a ser inserido: ");
            scanf("%d", &val);
            inserir(&p, val);
        }
        else if (resp == 2)
        {
            val = retirar(&p);
            printf("Valor no topo: %d\n", val);
        }
        else if (resp == 3)
        {
            val = tamanho_pilha(&p);
            printf("Tamanho: %d\n", val);
        }
        else if (resp == 4)
        {
            percorreFIFO(&p);
        }
        else if (resp == 5)
        {
            excluir_pilha(&p);
        }
    }
}