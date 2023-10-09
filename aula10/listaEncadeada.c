#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
    struct Item *proximo;
} Item;

typedef struct
{
    Item *cabeca;
    int tamanho;
} Lista;

void exibirLista(Lista *lista) // Função para exibir todos os elementos da lista
{
    printf("Lista: ");
    Item *atual = lista->cabeca; // atual seja o primeiro elemento da lista

    while (atual != NULL)
    {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}

Lista *criarListaVazia() // Função para criar uma lista vazia
{
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    if (novaLista == NULL)
    {
        // Verifique se a alocação de memória falhou
        printf("Erro ao alocar memoria para a lista.\n");
        exit(1); // ou return;
    }
    novaLista->cabeca = NULL; // Inicialmente, a cabeça aponta para NULL, indicando uma lista vazia
    novaLista->tamanho = 0;   // Inicialmente, o tamanho é zero
    return novaLista;
}

void inserirNaPosicao(Lista *lista, int posicao, Item *item) // Função para inserir um item na posição n
{
    if (posicao < 0 || posicao > lista->tamanho)
    {
        printf("Posição inválida para inserção.\n");
        return;
    }
    if (posicao == 0)
    {
        // Inserir na primeira posição
        item->proximo = lista->cabeca;
    }
    else
    {
        // Encontrar o nó na posição anterior
        Item *anterior = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++)
        {
            anterior = anterior->proximo;
        }
        item->proximo = anterior->proximo;
        anterior->proximo = item;
    }
    lista->tamanho++;
}

void removerDaPosicao(Lista *lista, int posicao) // Função para remover um item da posição n
{
    if (posicao < 0 || posicao > lista->tamanho)
    {
        printf("Posição inválida para inserção.\n");
        return;
    }
    if (posicao == 0)
    {
        Item *temp = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
        free(temp);
    }
    else
    {
        Item *anterior = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++)
        {
            anterior = anterior->proximo;
        }
        Item *temp = anterior->proximo;
        anterior->proximo = temp->proximo;
        free(temp);
    }
    lista->tamanho--;
}

int retornarTamanhoLista(Lista *lista) // Função para retornar o tamanho da lista
{
    return (lista->tamanho);
}

int determinarMaiorValor(Lista *lista) // Função para determinar o maior valor da lista
{
    Item *atual = lista->cabeca; // atual seja o primeiro elemento da lista
    int maior = atual->chave;
    while (atual != NULL)
    {
        if (maior < atual->chave)
        {
            maior = atual->chave;
            atual = atual->proximo; // similar ao i++
        }
    }
    return maior;
}

float determinarMedia(Lista *lista) // Função para determinar a média de todos os valores da lista
{
    Item *atual = lista->cabeca; // atual seja o primeiro elemento da lista
    int soma = 0;
    float media = 0.0;
    while (atual != NULL)
    {
        soma += atual->chave;
        atual = atual->proximo;
    }
    if (lista->tamanho > 0)
    {
        // media /= retornarTamanhoLista(lista);
        media = (float) soma / lista->tamanho;
    }
    return media;
}

int main()
{
    Lista *lista = criarListaVazia();

    Item *item1 = (Item *)malloc(sizeof(Item));
    item1->chave = 10;
    inserirNaPosicao(lista, 0, item1);

    Item *item2 = (Item *)malloc(sizeof(Item));
    item1->chave = 20;
    inserirNaPosicao(lista, 1, item2);

    Item *item3 = (Item *)malloc(sizeof(Item));
    item1->chave = 30;
    inserirNaPosicao(lista, 2, item3);

    exibirLista(lista);
    printf("Media: %f\n", determinarMedia(lista));
    // exibirLista(lista);
    // printf("Maior: %d\n", determinarMaiorValor(lista));
    // removerDaPosicao(lista, 1);
    // exibirLista(lista);

    return 0;
}