#include <stdio.h>
#include "pilha.h"

int main()
{
    Pilha p = init_pilha();

    int val, resp;

    while(1)
    {
        printf("1 - Inserir na Pilha;\n");
        printf("2 - Tirar da Pilha;\n");
        printf("3 - Tamanho da Pilha;\n");
        printf("4 - Percorrer sequencial;\n");
        printf("5 - Percorrer LIFO;\n");
        printf("6 - Reinicializar pilha;\n");
        printf("Resposta: ");

        scanf("%d", &resp);

        if (resp == 1)
        {
            printf("Valor: ");
            scanf("%d", &val);

            push(&p, val);
        }
        else if (resp == 2)
        {
            pop(&p);
        }
        else if (resp == 3)
        {
            printf("Tamanho: %d\n", len(&p));
        }
        else if (resp == 4)
        {
            printf("\nNa sequencia: \n");
            percorre(&p);
        }
        else if (resp == 5)
        {
            printf("\nNa ordem LIFO: \n");
            percorreLIFO(&p);
        }
        else if (resp == 6)
        {
            reinit(&p);
        }
        printf("\n");
    }
}