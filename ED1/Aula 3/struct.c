#include <stdio.h>

struct Aluno
{
    int matricula;
    float notas[2];
};

int main()
{
    struct Aluno alunos[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Aluno %d\nMatricula: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Nota1: ");
        scanf("%f", &alunos[i].notas[0]);

        printf("Nota1: ");
        scanf("%f", &alunos[i].notas[1]);

        printf("\n");
    }

    printf("\n");
    float media;

    for (int i = 0; i < 5; i++)
    {
        media = (alunos[i].notas[1] + alunos[i].notas[0]) / 2;
        printf("Matricula: %d, Media: %.2f\n", alunos[i].matricula, media);
    }
}