#ifndef PILHAPOSFIXA_H
#define PILHAPOSFIXA_H

#define TAMANHO_MAX 100

typedef struct {
    double itens[TAMANHO_MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p);
int estaVazia(Pilha *p);
int estaCheia(Pilha *p);
void empilhar(Pilha *p, double valor);
double desempilhar(Pilha *p);
double calcularPosfixa(char expressao[]);

#endif