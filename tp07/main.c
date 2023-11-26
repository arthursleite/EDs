#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "pilhaPosfixa.h"
#include "pilhaPosfixa.c"

int main() {
    char expressao[] = "45 60 + 30 c *"; 
    double resultado = calcularPosfixa(expressao);
    printf("Resultado: %.2lf\n", resultado);

    return 0;
}