/* Realiza o fatorial de um número */

#include <stdio.h>

unsigned long long int fatorial(int fat);
int lerNumero(void);

int main(void)
{
    int a = lerNumero();

    printf("\nFatorial de %d: %llu", a, fatorial(a));

    return 0;
}

int lerNumero(void)
{
    int a;
    scanf("%d", &a);
    return a;
}

unsigned long long int fatorial(int fat)
{
    if (fat <= 1)
    {
        return 1ULL;
    }

    return fat * (fatorial(fat - 1));
}