#ifndef PILHA_H
#define PILHA_H

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
double avaliarPosfixa(char expressao[]);

#endif