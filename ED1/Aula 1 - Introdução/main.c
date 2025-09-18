#include <stdio.h>

int main()
{
    printf("Escreva as notas: ");

    float nota1, nota2, nota3, nota4;

    scanf("%f%f%f%f", &nota1, &nota2, &nota3, &nota4);

    printf("As notas sao: %f, %f, %f, %f\n", nota1, nota2, nota3, nota4);

    float media = (nota1 + nota2 + nota3 + nota4) / 4;

    printf("A media eh %f", media); 

    if (media >= 7) 
    {
        printf("\nAprovado");
    }
    else
    {
        printf("\nReprovado");
    }

    return 0;
}