#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "pilhaPosfixa.h"
#include "pilhaPosfixa.c"

int main() {
    char expressaoPosfixa[] = "9 5 2 8 * 4 + * +";
    char expressaoInfixa[100];

    double resultado = calcularPosfixa(expressaoPosfixa);
    printf("Resultado: %.2lf\n", resultado);

    converterPosfixaParaInfixa(expressaoPosfixa, expressaoInfixa);
    printf("Expressão Infixa: %s\n", expressaoInfixa);



    return 0;
}