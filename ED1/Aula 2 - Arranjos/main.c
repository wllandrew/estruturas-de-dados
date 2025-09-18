#include <stdio.h>

int main()
{
    int nota1, nota2, nota3, nota4;
    float media;
    
    int qtd;
    printf("Quantidade de Alunos: ");
    scanf("%d", &qtd);

    float soma = 0;

    for (int i = 0; i < qtd; i++)
    {
        printf("Notas: ");
        scanf("%d%d%d%d", &nota1, &nota2, &nota3, &nota4);

        media = (nota1 + nota2 + nota3 + nota4) / 4;

        soma += media;

        printf("\nMedia deste alunos (%d): %f\n", i + 1, media);
    }

    soma /= qtd;

    printf("\nMedia geral: %f", soma);

    return 0;
}