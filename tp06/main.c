#include <stdio.h>
#include "matriz.h"
#include "matriz.c"

int main(void) {
    Matriz A, B, C;
    printf("Digite os elementos da matriz A:\n");
    A = leMatriz();
    printf("Matriz A:\n");
    imprimeMatriz(A);

    printf("Digite os elementos da matriz B:\n");
    B = leMatriz();
    printf("Matriz B:\n");
    imprimeMatriz(B);

    C = somaMatrizes(A, B);
    printf("Soma de A e B:\n");
    imprimeMatriz(C);

    Matriz D = multiplicaMatrizes(A, B);
    printf("Produto de A e B:\n");
    imprimeMatriz(D);

    return 0;
}