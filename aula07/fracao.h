#ifndef FRACAO_H
#define FRACAO_H

typedef struct
{
    int numerador;
    int denominador;
} Fracao;

Fracao criarFracao(int numerador, int denominador);
Fracao somarFracao(Fracao f1, Fracao f2);
Fracao subtrairFracao(Fracao f1, Fracao f2);
Fracao multiplicarFracao(Fracao f1, Fracao f2);
Fracao dividirFracao(Fracao f1, Fracao f2);
Fracao simplificarFracao(Fracao f);
int mdc(int a, int b);

#endif