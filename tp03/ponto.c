#include <stdio.h>
#include "ponto.h"

Ponto criarPonto(float x, float y)
{
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}

float calcularAreaTriangulo(Ponto a, Ponto b, Ponto c)
{
    float area = (a.x * b.y * 1.0 +
                  a.y * 1.0 * c.x +
                  1.0 * b.x * c.y -
                  a.y * b.x * 1.0 -
                  a.x * 1.0 * c.y -
                  1.0 * b.y * c.x) *
                 0.5;

    return area;
}

float calcularAreaPoligono(Ponto coordenadas[], int numVertices)
{
    float area = 0.0;

    if (numVertices < 3)
    {
        printf("Um poligono deve ter pelo menos 3 vertices para calcular a area.\n");
        return area;
    }

    for (int i = 1; i < numVertices - 1; i++)
    {
        area += calcularAreaTriangulo(coordenadas[0], coordenadas[i], coordenadas[i + 1]);
    }

    if (area < 0)
    {
        area *= -1;
    }
    return area;
}

