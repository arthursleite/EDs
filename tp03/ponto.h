#ifndef PONTO_H
#define PONTO_H

typedef struct
{
    float x;
    float y;
} Ponto;


Ponto criarPonto(float x, float y);
float calcularAreaTriangulo(Ponto p1, Ponto p2, Ponto p3);
float calcularAreaPoligono(Ponto coordenadas[], int numVertices);

#endif