#include <stdio.h>
#include "ponto.h"
#include "ponto.c"

int main()
{
    int numVertices;
    float area;
    float x, y;

    FILE *arquivo;

    arquivo = fopen("../poligono.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    if (fscanf(arquivo, "%d", &numVertices) != 1)
    {
        printf("Nao foi possivel ler a quantidade de vertices.\n");
        fclose(arquivo);
        return 1;
    }

    Ponto coordenadas[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        if (fscanf(arquivo, "%f %f", &x, &y) != 2)
        {
            printf("Nao foi possivel ler as coordenadas %d.\n", i + 1);
            fclose(arquivo);
            return 1;
        }
        coordenadas[i] = criarPonto(x, y);
    }

    area = calcularAreaPoligono(coordenadas, numVertices);
    printf("A area do poligono eh: %.2f\n", area);

    fclose(arquivo);

    return 0;
}