#include <stdio.h>
#include "linked_list.c"

int main()
{
    Lista l;
    InicializarLista(&l);

    Append(&l, 1);
    Append(&l, 3);
    Append(&l, 9);
    Append(&l, 4);
    Append(&l, 3);

    Print(&l);

    Pop(&l, 4);
    Pop(&l, 1);

    Print(&l);
}