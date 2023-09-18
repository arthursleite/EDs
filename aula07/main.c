#include <stdio.h>
#include <stdlib.h>

#include "fracao.h"
#include "fracao.c"

int main()
{

    Fracao f1 = criarFracao(1, 2);
    Fracao f2 = criarFracao(3, 4);

    Fracao soma = somarFracao(f1, f2);
    Fracao subtracao = subtrairFracao(f1, f2);
    Fracao multiplicacao = multiplicarFracao(f1, f2);
    Fracao divisao = dividirFracao(f1, f2);

    soma = simplificarFracao(soma);
    subtracao = simplificarFracao(subtracao);
    multiplicacao = simplificarFracao(multiplicacao);
    divisao = simplificarFracao(divisao);

    printf("Soma: ");
    imprimirFracao(soma);
    printf("Subtração: ");
    imprimirFracao(subtracao);
    printf("Multiplicação: ");
    imprimirFracao(multiplicacao);
    printf("Divisão: ");
    imprimirFracao(divisao);

    return 0;
}