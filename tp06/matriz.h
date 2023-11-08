#ifndef MATRIZ_H
#define MATRIZ_H

// Definição das estruturas de dados
typedef struct Celula {
    struct Celula* direita;
    struct Celula* abaixo;
    int linha;
    int coluna;
    float valor;
} Celula;

typedef struct {
    Celula* cabeca;
    int nlin;
    int ncol;
} Matriz;

// Declarações das funções
void imprimeMatriz(Matriz A);
Matriz leMatriz();
Matriz somaMatrizes(Matriz A, Matriz B);
Matriz multiplicaMatrizes(Matriz A, Matriz B);

#endif