/* Conta quantas vezes um elemente aparece */

#include <stdio.h>

int main()
{   
    int vetor[10], i, x, count=0;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("\nNumero a ser procurado: ");
    scanf("%d", &x);

    for (i = 0; i < 10; i++)
    {
        if (vetor[i] == x)
        {
            count++;
        }
    }

    printf("Ha %d ocorrencias deste item.", count);

    return 0;
}