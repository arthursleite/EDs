#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "pilhaPosfixa.h"

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == TAMANHO_MAX - 1;
}

void empilhar(Pilha *p, double valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

double desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    return p->itens[(p->topo)--];
}

double calcularPosfixa(char expressao[]) {
    Pilha pilha;
    inicializar(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (isdigit(expressao[i])) {
            double operando = 0;
            while (isdigit(expressao[i]) || expressao[i] == '.') {
                if (expressao[i] == '.') {
                    i++;
                    double decimal = 0.1;
                    while (isdigit(expressao[i])) {
                        operando += (expressao[i] - '0') * decimal;
                        decimal /= 10;
                        i++;
                    }
                } else {
                    operando = operando * 10 + (expressao[i] - '0');
                    i++;
                }
            }
            i--;
            empilhar(&pilha, operando);
        } else if (isspace(expressao[i])) {
            continue; 
        } else {
            double resultado, operando2 = desempilhar(&pilha), operando1;
            switch (expressao[i]) {
                case '+':
                    operando1 = desempilhar(&pilha);
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    operando1 = desempilhar(&pilha);
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    operando1 = desempilhar(&pilha);
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    operando1 = desempilhar(&pilha);
                    resultado = operando1 / operando2;
                    break;
                case '^':
                    operando1 = desempilhar(&pilha);
                    resultado = pow(operando2, operando1);
                    break;
                case 'l': // log
                    resultado = log10(operando2);
                    break;
                case 's': // sen
                    resultado = sin(operando2);
                    break;
                case 'c': // cos
                    resultado = cos(operando2);
                    break;
                case 't': // tang
                    resultado = tan(operando2);
                    break;
                default:
                    printf("Operador inválido: %c\n", expressao[i]);
                    exit(EXIT_FAILURE);
            }
            empilhar(&pilha, resultado);
        }
        printf("Pilha no momento: ");
        for (int j = 0; j <= pilha.topo; j++) {
            printf("%.2lf ", pilha.itens[j]);
        }
        printf("\n");
    }
    return desempilhar(&pilha);
}