#include <stdio.h>
#include <stdlib.h>

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

void empilhar(Pilha *p, int chave)
{
    Item *novoItem = criarItem(chave);
    novoItem->proximo = p->topo;
    p->topo = novoItem;
    p->tamanho = p->tamanho + 1;
}

// Retirar elemento da pilha

int desempilhar(Pilha *p)
{
    if(estaVazia(p) == SIM)
    {
        printf("Erro: a pilha está vazia.\n");
        return (ERRO);
    }
    Item *temp = p->topo;
    int chave = temp->chave;
    p->topo = temp->proximo;
    free(temp);
    p->tamanho = p->tamanho - 1;
    return chave;
}

// Destruindo a pilha

void liberarPilha(Pilha *p)
{
    while (!estaVazia(p))
    {
        desempilhar(p);
    }
    free(p);
}

// Função principal

int main()
{
    Pilha *p = criarPilha();
    empilhar(p, 10);
    empilhar(p, 20);
    empilhar(p, 30);
    empilhar(p, 40);
    printf("Desempilhando...\n");
    while (!estaVazia(p))
    {
        printf("Chave: %d\n", desempilhar(p));
    }
    liberarPilha(p);
    return 0;
}