// Passando vetor como argumento: seu nome é o "próprio endereço"

#include <stdio.h>

void imprimeVetor(int vetor[], int tam)
{
    for (int i=0; i < tam; i++)
    {
        printf("%d\n", vetor[i]);
    }
}

int main()
{
    int tam;
    scanf("%d", &tam);
    
    int matriz[tam];

    for (int i=0; i < tam; i++)
    {
        scanf("%d", &matriz[i]);
    }

    imprimeVetor(matriz, tam);

    return 0;
}