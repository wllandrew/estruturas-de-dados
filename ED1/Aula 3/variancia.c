#include <stdio.h>
#include <math.h>

double variancia(int notas[])
{
    double media;

    for (int i = 0; i < 4; i ++)
    {
        media += notas[i];
    }

    media /= 4;

    double variancia;

    for (int i = 0; i < 4; i ++)
    {
        variancia += pow((double) notas[i] - media, 2);
    }

    return sqrt(variancia / 3);
}

int main()
{
    int qtd;
    scanf("%d", &qtd);

    int alunos[qtd][4];

    for (int i = 0; i < qtd; i ++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &alunos[i][j]);
        }
    }

    double variancias[qtd];

    for (int i = 0; i < qtd; i++)
    {
        variancias[i] = variancia(alunos[i]);
    }

    for (int i = 0; i < qtd; i++)
    {
        printf("Variancia Aluno %d: %f\n", i, variancias[i]);
    }

    return 0;
}