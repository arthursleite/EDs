#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Celula* criaCelula(int linha, int coluna, float valor) {
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->linha = linha;
    novaCelula->coluna = coluna;
    novaCelula->valor = valor;
    novaCelula->direita = NULL;
    novaCelula->abaixo = NULL;
    return novaCelula;
}

Matriz criaMatriz(int nlin, int ncol) {
    Matriz matriz;
    matriz.nlin = nlin;
    matriz.ncol = ncol;
    matriz.cabeca = criaCelula(-1, -1, 0); // Célula cabeça
    Celula* linha_atual = matriz.cabeca;
    for (int i = 0; i < nlin; i++) {
        linha_atual->abaixo = criaCelula(-1, -1, 0); // Célula cabeça da linha
        linha_atual = linha_atual->abaixo;
    }
    Celula* coluna_atual = matriz.cabeca;
    for (int j = 0; j < ncol; j++) {
        coluna_atual->direita = criaCelula(-1, -1, 0); // Célula cabeça da coluna
        coluna_atual = coluna_atual->direita;
    }
    return matriz;
}

void insere(Matriz* A, int linha, int coluna, float valor) {
    if (linha < 0 || linha >= A->nlin || coluna < 0 || coluna >= A->ncol)
        return; // Verifique limites da matriz
    Celula* novaCelula = criaCelula(linha, coluna, valor);
    Celula* linha_atual = A->cabeca;
    while (linha_atual->linha != linha)
        linha_atual = linha_atual->abaixo;
    Celula* coluna_atual = A->cabeca;
    while (coluna_atual->coluna != coluna)
        coluna_atual = coluna_atual->direita;
    // Insere na linha
    novaCelula->direita = linha_atual->direita;
    linha_atual->direita = novaCelula;
    // Insere na coluna
    novaCelula->abaixo = coluna_atual->abaixo;
    coluna_atual->abaixo = novaCelula;
    printf("Inserido valor %.2f na linha %d, coluna %d\n", valor, linha, coluna);
}

void imprimeMatriz(Matriz A) {
    for (int i = 0; i < A.nlin; i++) {
        Celula* linha_atual = A.cabeca->abaixo;
        for (int j = 0; j < A.ncol; j++) {
            if (linha_atual->coluna == j) {
                printf("%.2f ", linha_atual->valor);
                linha_atual = linha_atual->direita;
            } else {
                printf("0.00 ");
            }
        }
        printf("\n");
    }
}

Matriz leMatriz() {
    int nlin, ncol;
    printf("Digite o nimero de linhas e colunas (nlin, ncol):\n");
    scanf("%d, %d", &nlin, &ncol);
    Matriz A = criaMatriz(nlin, ncol);
    int linha, coluna;
    float valor;
    int valoresLidos = 0;
    
    printf("Digite os elementos da matriz no formato 'linha, coluna, valor':\n");
    
    while (valoresLidos < nlin * ncol) {
        if (scanf("%d, %d, %f", &linha, &coluna, &valor) == 3) {
            insere(&A, linha, coluna, valor);
            valoresLidos++;
        } else {
            break;
        }
    }
    
    printf("Matriz lida com sucesso.\n");
    return A;
}


Matriz somaMatrizes(Matriz A, Matriz B) {
    if (A.nlin != B.nlin || A.ncol != B.ncol) {
        printf("As matrizes tem dimensoes diferentes. Nao eh possivel soma-las.\n");
        exit(1);
    }
    Matriz C = criaMatriz(A.nlin, A.ncol);
    for (int i = 0; i < A.nlin; i++) {
        Celula* linhaA = A.cabeca->abaixo->direita;
        Celula* linhaB = B.cabeca->abaixo->direita;
        while (linhaA != A.cabeca && linhaB != B.cabeca) {
            if (linhaA->coluna < linhaB->coluna) {
                insere(&C, linhaA->linha, linhaA->coluna, linhaA->valor);
                linhaA = linhaA->direita;
            } else if (linhaA->coluna > linhaB->coluna) {
                insere(&C, linhaB->linha, linhaB->coluna, linhaB->valor);
                linhaB = linhaB->direita;
            } else {
                float soma = linhaA->valor + linhaB->valor;
                if (soma != 0) {
                    insere(&C, linhaA->linha, linhaA->coluna, soma);
                }
                linhaA = linhaA->direita;
                linhaB = linhaB->direita;
            }
        }
        while (linhaA != A.cabeca) {
            insere(&C, linhaA->linha, linhaA->coluna, linhaA->valor);
            linhaA = linhaA->direita;
        }
        while (linhaB != B.cabeca) {
            insere(&C, linhaB->linha, linhaB->coluna, linhaB->valor);
            linhaB = linhaB->direita;
        }
    }
    printf("Matrizes somadas com sucesso.\n");
    return C;
}

Matriz multiplicaMatrizes(Matriz A, Matriz B) {
    if (A.ncol != B.nlin) {
        printf("O numero de colunas de A deve ser igual ao numero de linhas de B para multiplicacao de matrizes.\n");
        exit(1);
    }
    Matriz C = criaMatriz(A.nlin, B.ncol);
    for (int i = 0; i < A.nlin; i++) {
        for (int j = 0; j < B.ncol; j++) {
            float soma = 0;
            Celula* linhaA = A.cabeca->abaixo->direita;
            Celula* colunaB = B.cabeca->direita->abaixo;
            while (linhaA != A.cabeca && colunaB != B.cabeca) {
                if (linhaA->coluna == colunaB->linha) {
                    soma += linhaA->valor * colunaB->valor;
                    linhaA = linhaA->direita;
                    colunaB = colunaB->abaixo;
                } else if (linhaA->coluna < colunaB->linha) {
                    linhaA = linhaA->direita;
                } else {
                    colunaB = colunaB->abaixo;
                }
            }
            if (soma != 0) {
                insere(&C, i, j, soma);
            }
        }
    }
    printf("Matrizes multiplicadas com sucesso.\n");
    return C;
}
