#include <stdio.h>
#include <stdlib.h>

typedef struct Teste
{
    int c1;
    char c2;
} Teste;

int main()
{
    Teste t1;
    t1.c1 = 1;
    t1.c2 = 'c';

    Teste *p = &t1;

    // *p.c1 é errado, usamos a notação p->c1;

    printf("%d\n", p->c1);
    printf("%c\n", p->c2);
}