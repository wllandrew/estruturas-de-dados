/* Calcula o enésimo fibbonaci. */

#include <stdio.h>

int main()
{
    int fat;
    unsigned long long int a, b, c;

    scanf("%d", &fat);

    a = 1ULL;
    b = 1ULL;

    for (int i = 0; i < fat; i++)
    {
        printf("\nfat(%d) %llu", i + 1, a);
        c = a + b;
        a = b;
        b = c;

        if (c < a)
        {
            break;
        }
    } 

    return 0;
}