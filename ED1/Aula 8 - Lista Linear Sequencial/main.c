#include <stdio.h>

#define MAX_SIZE 100

typedef int REGISTRO;

typedef struct Fila
{
    REGISTRO fila[MAX_SIZE];
    int qtd;
} Fila;