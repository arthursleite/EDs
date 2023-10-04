#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int chave;
    // Poderiam ser inseridos outros campos (nome, telefone, etc.)
} Item;

typedef struct
{
    Item *array;
    int tamanho;    // Número de itens inseridos na lista
    int capacidade; // Número máximo de itens que a lista suporta
} Lista;

Lista *criarLista(int capacidade)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));

    if (lista == NULL)
    {
        perror("Erro ao alocar memoria para a lista");
        exit(1);
    }

    lista->array = (Item *)malloc(capacidade * sizeof(Item));

    if (lista->array == NULL)
    {
        perror("Erro ao alocar memoria para o array da lista");
        free(lista);
        exit(1);
    }

    lista->tamanho = 0;
    lista->capacidade = capacidade;

    return lista;
}

void inserirElemento(Lista *lista, Item elemento)
{
    if (lista->tamanho >= lista->capacidade)
    {
        printf("Erro: a lista está cheia!\n");
        return;
    }
    lista->array[lista->tamanho] = elemento;
    lista->tamanho++;
}

void removerElemento(Lista *lista, int indice)
{
    if (indice < 0 || indice > lista->tamanho)
    {
        printf("Erro: indice fora dos limites.\n");
        return;
    }
    for (int i = indice; i < lista->tamanho; i++)
    {
        lista->array[i] = lista->array[i + 1];
        lista->tamanho--;
    }
}

void imprimirLista(Lista *lista)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("%d", lista->array[i]);
    }
}

int main()
{
    int capacidade = 10;

    Lista *lista = criarLista(capacidade);

    inserirElemento(lista, (Item){1});
    inserirElemento(lista, (Item){7});
    inserirElemento(lista, (Item){13});
    inserirElemento(lista, (Item){-1});
    inserirElemento(lista, (Item){10});

    printf("Memoria alocada: %d", sizeof(lista));

    free(lista->array);
    free(lista);

    return (0);
}