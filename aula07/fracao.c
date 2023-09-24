#include <stdio.h>
#include "fracao.h"

// Forma de utilização
// Fracao x = criarFracao(3, 9);

Fracao criarFracao(int numerador, int denominador)
{
    Fracao f;
    f.numerador = numerador;
    f.denominador = denominador;
    return f;
}

// Forma de utilização
// Fracao x = simplificarFracao(criarFracao(3, 9));

Fracao simplificarFracao(Fracao f)
{
    int gcd = mdc(f.numerador, f.denominador);
    f.numerador = f.numerador / gcd;
    f.denominador = f.denominador / gcd;
    return f;
}

void imprimirFracao(Fracao f)
{
    printf("%d/%d\n", f.numerador, f.denominador);
}

Fracao somarFracao(Fracao f1, Fracao f2)
{
    Fracao fresult;
    fresult.numerador = f1.numerador * f2.denominador + f1.denominador * f2.numerador;
    fresult.denominador = f1.denominador * f2.denominador;
    fresult = simplificarFracao(fresult);
    return fresult;
}

Fracao subtrairFracao(Fracao f1, Fracao f2)
{
    Fracao fresult;
    fresult.numerador = f1.numerador * f2.denominador - f1.denominador * f2.numerador;
    fresult.denominador = f1.denominador * f2.denominador;
    fresult = simplificarFracao(fresult);
    return fresult;
}

Fracao multiplicarFracao(Fracao f1, Fracao f2)
{
    Fracao fresult;
    fresult.numerador = f1.numerador * f2.numerador;
    fresult.denominador = f1.denominador * f2.denominador;
    fresult = simplificarFracao(fresult);
    return fresult;
}

Fracao inverterFracao(Fracao f)
{
    int temp = f.numerador;
    f.numerador = f.denominador;
    f.denominador = temp;
    return f;
}

Fracao dividirFracao(Fracao f1, Fracao f2)
{
    Fracao fresult = multiplicarFracao(f1, inverterFracao(f2));
    fresult = simplificarFracao(fresult);
    return fresult;
}

int mdc(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}