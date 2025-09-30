#include "lista.h"
#include <stdio.h>

int main()
{
    Lista l;
    inicializar_lista(&l);

    int val, resp, pos, confirmacao;

    while(1)
    {
        printf("1 - Inserir no final;\n");
        printf("2 - Inserir na posicao;\n");        
        printf("3 - Tirar da Lista;\n");
        printf("4 - Tamanho da Lista;\n");
        printf("5 - Percorrer Lista;\n");
        printf("6 - Inserir em ordem;\n");
        printf("7 - Buscar linear com sentinela;\n");
        printf("8 - Buscar binario;\n");
        printf("9 - Reinicializar Lista;\n");
        printf("10 - Pop;\n");
        printf("11 - Ordenar;\n");
        printf("0 - Sair\n");
        printf("Resposta: ");

        scanf("%d", &resp);

        if (resp == 0)
        {
            break;
        }

        if (resp == 1)
        {
            printf("Valor a ser inserido: ");
            scanf("%d", &val);
            confirmacao = append(&l, val);

            if (!confirmacao)
            {
                printf("Erro! Lista cheia.");
            }
        }
        else if (resp == 2)
        {
            printf("Posicao: ");
            scanf("%d", &pos);
            printf("Valor: ");
            scanf("%d", &val);

            confirmacao = inserir(&l, pos, val);

            if (!confirmacao)
            {
                printf("Erro! Lista cheia.");
            }
        }
        else if (resp == 3)
        {
            printf("Posicao: ");
            scanf("%d", &pos);
            confirmacao = retirar(&l, pos, &val);
            
            if (confirmacao)
            {
                printf("Retirado: %d\n", val);
            }
            else
            {
                printf("Erro! Lista vazia");
            }
        }
        else if (resp == 4)
        {
            printf("Tamanho: %d", tamanho_lista(&l));    
        }
        else if (resp == 5)
        {
            exibir_elementos(&l);
        }
        else if (resp == 6)
        {
            printf("Valor: ");
            scanf("%d", &val);

            confirmacao = insercao_em_ordem(&l, val);

            if (!confirmacao)
            {
                printf("Erro! Lista cheia.");
            }
        }
        else if (resp == 7)
        {
            printf("Valor a buscar: ");
            scanf("%d", &val);

            pos = busca_sentinela(&l, val);

            if (pos == -1)
            {
                printf("Elemento nao esta na lista.");
            }
            else
            {
                printf("Posicao: %d", pos);
            }
        }
        else if (resp == 8)
        {
            printf("Valor a buscar: ");
            scanf("%d", &val);

            pos = busca_binaria(&l, val);

            if (pos == -1)
            {
                printf("Elemento nao esta na lista.");
            }
            else
            {
                printf("Posicao: %d", pos);
            }
        }
        else if (resp == 9)
        {
            reinicializar_lista(&l);
        }
        else if (resp == 10)
        {
            confirmacao = pop(&l, &val);
            
            if (confirmacao)
            {
                printf("Retirado:: %d\n", val);
            }
            else
            {
                printf("Erro! Lista vazia");
            }
        }
        else if (resp == 11)
        {
            bubble_sort(&l);
        }
        
        printf("\n\n");
    }
}