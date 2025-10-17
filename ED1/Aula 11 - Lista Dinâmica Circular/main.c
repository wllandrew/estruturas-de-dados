#include <stdio.h>
#include "lista_circular.c"

int main()
{
    ListaCircular listac;
    InicializaListaCircular(&listac);

    InserirOrdenadoListaCircular(&listac, 1);
    InserirOrdenadoListaCircular(&listac, 5);
    InserirOrdenadoListaCircular(&listac, 9);
    InserirOrdenadoListaCircular(&listac, 7);
    InserirOrdenadoListaCircular(&listac, 3);

    printf("Tamanho: %d\n", TamanhoListaCircular(&listac));

    ExibirListaCircular(&listac);

    ExcluirOrdenadoListaCircular(&listac, 1);
    ExcluirOrdenadoListaCircular(&listac, 9);

    printf("Tamanho: %d\n", TamanhoListaCircular(&listac));

    ExibirListaCircular(&listac);

    ReinicializarListaCircular(&listac);

    printf("Tamanho: %d\n", TamanhoListaCircular(&listac));

    ExibirListaCircular(&listac);

    return 0;
}