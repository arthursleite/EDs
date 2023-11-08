#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave; // Poderia ser, por exemplo, FILE *chave ou char[50] chave.
    struct Item *proximo;
} Item;

typedef struct Fila
{
    Item *inicio;
    Item *fim;
} Fila;

// Funcao criarFila()
// Observação:
// Caso os atributos de fila sejam NULL, a fila está vazia.

Fila *criarFila()
{
    Fila *fila = (Fila *)malloc(sizeof(fila));
    if (fila == NULL)
    {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// Função estaVazia(Fila *fila)
// Observação:
// Retorna 1 caso fila esteja vazia e 0 caso tenha elemento(s).

int estaVazia(Fila *fila)
{

    if (fila->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    // Outra implementação: return(fila->inicio == NULL);
}

// Função enfileirar()
void enfileirar(Fila *fila, int chave)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    if (novoItem == NULL)
    {
        printf("Erro na alocação de memória par ao item.\n");
        exit(1);
    }
    novoItem->chave = chave;
    novoItem->proximo = NULL;

    if (estaVazia(fila))
    {
        fila->inicio = novoItem;
        fila->fim = novoItem;
    }
    else
    {
        fila->fim->proximo = novoItem; // *** será necessário
        fila->fim = novoItem;
    }
}


int desenfileirar(Fila *fila) // ou retirar
{
    if (estaVazia(fila))
    {
        printf("Erro: a fila está vazia.\n");
        exit(1);
    }
    Item *temp = fila->inicio;
    int chave = temp->chave;
}