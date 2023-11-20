#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "matriz.c"

int main()
{
    Matriz A = leMatriz();

    printf("\nMatriz inserida:\n");
    imprimeMatriz(A);

    return 0;
}
