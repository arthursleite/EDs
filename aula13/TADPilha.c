#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERRO -1
#define SIM 1
#define NAO 0

typedef struct Item
{
    int chave;
    struct Item *proximo;
} Item;

typedef struct Pilha
{
    int tamanho;
    Item *topo;
} Pilha;

// Função para criar uma pilha vazia

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL)
    {
        printf("Erro: falha ao alocar memória para a pilha.\n");
        return (ERRO);
    }
    p->tamanho = 0;
    p->topo = NULL;
    return p;
}

// Função para verificar se a pilha está vazia

int estaVazia(Pilha *p)
{
    if (p->topo == NULL)
    {
        return SIM;
    }
    else
    {
        return NAO;
    }
}

// Função para criar Item da pilha

Item *criarItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    if (novoItem == NULL)
    {
        printf("Erro: falha ao alocar memória para o item.\n");
        return (ERRO);
    }
    novoItem->chave = x;
    novoItem->proximo = NULL;
    return novoItem;
}

// Inserir elemento na pilha

void push(Pilha *p, int chave)
{
    Item *novoItem = criarItem(chave);
    novoItem->proximo = p->topo;
    p->topo = novoItem;
    p->tamanho = p->tamanho + 1;
}

// Retirar elemento da pilha

int pop(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Erro: a pilha está vazia, não é possível desempilhar.\n");
        return (ERRO);
    }
    Item *temp = p->topo;
    int chave = temp->chave;
    p->topo = temp->proximo;
    free(temp);
    p->tamanho = p->tamanho - 1;
    return chave;
}

// Retorna a chave do item que está no topo da pilha

int topo(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Erro: Pilha vazia, não há elementos para visualizar.\n");
        exit(EXIT_FAILURE);
    }
    return p->topo->chave;
}

// Destruindo a pilha

void liberarPilha(Pilha *p)
{
    while (!estaVazia(p))
    {
        pop(p);
    }
    free(p);
}

// Função principal

int main()
{
    Pilha *p = criarPilha();
    push(p, 10);
    push(p, 20);
    push(p, 30);
    push(p, 40);

    printf("Topo da pilha: %d\n", topo(p));
    printf("Desempilhando: \n");
    while (!estaVazia(p))
    {
        printf("Chave: %d\n", desempilhar(p));
    }
    liberarPilha(p);
    return 0;
}