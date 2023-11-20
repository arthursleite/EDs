#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void inicializaMatriz(Matriz *A, int nlin, int ncol)
{
    A->nlin = nlin;
    A->ncol = ncol;

    // Cria a célula cabeça
    A->cabeca = (Celula *)malloc(sizeof(Celula));
    A->cabeca->direita = A->cabeca->abaixo = A->cabeca;
    A->cabeca->linha = A->cabeca->coluna = -1;
    A->cabeca->valor = 0.0;
}

void insereElemento(Matriz *A, int linha, int coluna, float valor)
{
    if (linha < 0 || linha >= A->nlin || coluna < 0 || coluna >= A->ncol)
    {
        printf("Posição inválida!\n");
        return;
    }

    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
    novaCelula->linha = linha;
    novaCelula->coluna = coluna;
    novaCelula->valor = valor;

    // Encontrar a posição correta na linha
    Celula *atual = A->cabeca;
    while (atual->direita != A->cabeca && atual->direita->coluna < coluna)
    {
        atual = atual->direita;
    }

    novaCelula->direita = atual->direita;
    atual->direita = novaCelula;

    // Encontrar a posição correta na coluna
    atual = A->cabeca;
    while (atual->abaixo != A->cabeca && atual->abaixo->linha < linha)
    {
        atual = atual->abaixo;
    }

    novaCelula->abaixo = atual->abaixo;
    atual->abaixo = novaCelula;
}

void imprimeMatriz(Matriz A)
{
    Celula *linhaAtual, *colunaAtual;

    for (int i = 0; i < A.nlin; i++)
    {
        colunaAtual = A.cabeca->direita; // Inicia na célula cabeça da linha
        for (int j = 0; j < A.ncol; j++)
        {
            if (colunaAtual != A.cabeca && colunaAtual->coluna == j && colunaAtual->linha == i)
            {
                printf("%0.2f\t", colunaAtual->valor);
                colunaAtual = colunaAtual->direita;
            }
            else
            {
                printf("0.00\t");
            }
        }
        printf("\n");
    }
}

Matriz leMatriz()
{
    Matriz A;
    int nlin, ncol;
    float valor;

    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &nlin, &ncol);

    inicializaMatriz(&A, nlin, ncol);

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < nlin; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &valor);
            if (valor != 0.0)
            {
                insereElemento(&A, i, j, valor);
            }
        }
    }

    return A;
}
