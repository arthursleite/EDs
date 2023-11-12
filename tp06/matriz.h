#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Celula
{
    struct Celula *direita, *abaixo;
    int linha, coluna;
    float valor;
} Celula;

typedef struct
{
    Celula *cabeca;
    int nlin, ncol;
} Matriz;

#endif