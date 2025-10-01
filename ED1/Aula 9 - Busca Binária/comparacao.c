#include "lista_comp.c"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    Lista l1;
    inicializar_lista(&l1);
    Lista l2;
    inicializar_lista(&l2);

    for (int i=0; i<1000; i++)
    {
        append(&l2, i);
    }

    for (int i=0; i<1000; i++)
    {
        int random = rand() % 10000;
        append(&l1, random);
    }

    clock_t t1;
    t1 = clock();

    for (int i=0; i<10000000; i++)
    {
        int index1 = busca_binaria(&l2, i % 1000);
        // printf("%d ", i);
    }

    t1 = clock() - t1;
    double time2 = ((double)t1)/CLOCKS_PER_SEC;

    printf("Tempo para busca binaria (vetor ordenado): %f\n", time2);

    clock_t t;
    t = clock();

    for (int i=0; i<10000000; i++)
    {
        int index = busca_sentinela(&l1, i % 1000);
        // printf("%d ", i);
    }

    t = clock() - t;
    double time1 = ((double) t)/CLOCKS_PER_SEC;

    printf("Tempo busca sentinela (vetor desordenado): %f\n", time1);
}