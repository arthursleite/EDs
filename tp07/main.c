#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "pilhaPosfixa.h"
#include "pilhaPosfixa.c"

int main() {
    char expressao[] = "3 4 + 5 t *"; 
    double resultado = calcularPosfixa(expressao);
    printf("Resultado: %.2lf\n", resultado);

    return 0;
}