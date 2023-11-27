#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "pilhaPosfixa.h"

void inicializar(Pilha *p)
{
    p->topo = -1;
}

int estaVazia(Pilha *p)
{
    return p->topo == -1;
}

int estaCheia(Pilha *p)
{
    return p->topo == TAMANHO_MAX - 1;
}

void empilhar(Pilha *p, double valor)
{
    if (estaCheia(p))
    {
        printf("Erro: Pilha cheia\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

double desempilhar(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    return p->itens[(p->topo)--];
}

double calcularPosfixa(char expressao[])
{
    Pilha pilha;
    inicializar(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++)
    {
        if (isdigit(expressao[i]))
        {
            double operando = 0;
            while (isdigit(expressao[i]) || expressao[i] == '.')
            {
                if (expressao[i] == '.')
                {
                    i++;
                    double decimal = 0.1;
                    while (isdigit(expressao[i]))
                    {
                        operando += (expressao[i] - '0') * decimal;
                        decimal /= 10;
                        i++;
                    }
                }
                else
                {
                    operando = operando * 10 + (expressao[i] - '0');
                    i++;
                }
            }
            i--;
            empilhar(&pilha, operando);
        }
        else if (isspace(expressao[i]))
        {
            continue;
        }
        else
        {
            double resultado, operando2 = desempilhar(&pilha), operando1;
            switch (expressao[i])
            {
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
                resultado = pow(operando2, operando1); // A ordem dos operandos afeta o resultado. No exemplo 7 e 9, a ordem está invertida.
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
        for (int j = 0; j <= pilha.topo; j++)
        {
            printf("%.2lf ", pilha.itens[j]);
        }
        printf("\n");
    }
    return desempilhar(&pilha);
}

void adicionarParenteses(char expressao[], int inicio, int fim)
{
    int comprimento = strlen(expressao);

    // Movendo os caracteres para a direita para abrir espaço para '(' e ')'
    for (int i = comprimento + 1; i >= fim; i--)
    {
        expressao[i] = expressao[i - 1];
    }

    expressao[inicio] = '(';
    expressao[fim + 2] = ')';
    expressao[comprimento + 2] = '\0';
}

void converterPosfixaParaInfixa(char expressaoPosfixa[], char expressaoInfixa[])
{
    Pilha pilha;
    inicializar(&pilha);

    int posInfixa = 0;

    for (int i = 0; expressaoPosfixa[i] != '\0'; i++)
    {
        if (isdigit(expressaoPosfixa[i]))
        {
            double operando = 0;
            while (isdigit(expressaoPosfixa[i]) || expressaoPosfixa[i] == '.')
            {
                expressaoInfixa[posInfixa++] = expressaoPosfixa[i++];
            }
            expressaoInfixa[posInfixa++] = ' '; // Adiciona um espaço entre operandos
            i--;                                // Volta um índice para corrigir o avanço extra no loop principal
        }
        else if (!isspace(expressaoPosfixa[i]))
        {
            double operando2, operando1;
            char operador[3];
            switch (expressaoPosfixa[i])
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                operando2 = desempilhar(&pilha);
                operando1 = desempilhar(&pilha);
                operador[0] = expressaoPosfixa[i];
                operador[1] = '\0';
                sprintf(expressaoInfixa + posInfixa, "%s %c ", operador, expressaoPosfixa[i]);
                posInfixa += 3; // Move o índice para a próxima posição livre
                adicionarParenteses(expressaoInfixa, posInfixa - 2, posInfixa + 1);
                empilhar(&pilha, 0); // Empilha um valor fictício para manter o algoritmo
                break;
            case 'l': // log
            case 's': // sen
            case 'c': // cos
            case 't': // tang
                operando2 = desempilhar(&pilha);
                sprintf(expressaoInfixa + posInfixa, "%c ", expressaoPosfixa[i]);
                posInfixa += 2; // Move o índice para a próxima posição livre
                adicionarParenteses(expressaoInfixa, posInfixa - 2, posInfixa);
                empilhar(&pilha, 0); // Empilha um valor fictício para manter o algoritmo
                break;
            default:
                printf("Operador inválido: %c\n", expressaoPosfixa[i]);
                exit(EXIT_FAILURE);
            }
        }
    }
}