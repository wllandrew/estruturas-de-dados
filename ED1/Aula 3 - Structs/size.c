#include <stdio.h>
#include <stdbool.h>

struct Teste1
{
    bool v1;
    long v2;
    bool v3;
};

struct Teste2
{
    long v1;
    bool v2;
    bool v3;
};

int main()
{
    struct Teste1 t1;
    int size1 = sizeof(t1);

    struct Teste2 t2;
    int size2 = sizeof(t2);

    printf("%d\n", size1);

    printf("%d\n", size2);

    return 0;
}