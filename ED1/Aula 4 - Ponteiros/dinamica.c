#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v;
    v = (int*)malloc(10*sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        v[i] = 10 - i;
    }

    printf("%d\n", *v);
    v++;
    printf("%d\n", *v);
    v--;

    free(v);
}