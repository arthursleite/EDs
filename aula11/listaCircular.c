#include <stdio.h>
#include <stdlib.h>

// As structs a seguir deveriam ser incluídas no arquivo de cabecalhos (.h)

typedef struct Item
{
    int chave;
    struct Item *proximo;
} Item;

typedef struct ListaCircular
{
    Item *cabeca;
    int tamanho;
} ListaCircular;

// Implementando a funcao exibirLista()

void exibirListaCircular(ListaCircular *lista)
{
    printf("Lista: ");
    Item *atual = lista->cabeca; // De inicio, atual e o primeiro elemento da lista
    while (atual->proximo != lista->cabeca)
    {
        printf("%d ", atual->chave);
        atual = atual->proximo; // Atualizacao do ponteiro atual
    }

    printf("%d ", atual->chave);
    printf("\n");
}

// Implementando a funcao criarListaCircularVazia()

ListaCircular *criarListaCircularVazia()
{
    ListaCircular *novaLista = (ListaCircular *)malloc(sizeof(ListaCircular));
    if (novaLista == NULL)
    {
        printf("Erro ao alocar memoia para a lista.\n");
        exit(1); // ou return
    }
    novaLista->cabeca = NULL;
    novaLista->tamanho = 0;
}

// Implementando a funcao adicionarElemento(...) no final da lista

void adicionarElemento(ListaCircular *lista, Item *novoItem)
{
    if (novoItem == NULL)
    {
        printf("Item invalido.\n");
        return;
    }

    if (lista->cabeca == NULL)
    {
        novoItem->proximo = novoItem; // Aponta para si mesmo
        lista->cabeca = novoItem;
    }
    else
    {
        novoItem->proximo = lista->cabeca;
        Item *atual = lista->cabeca;
        while (atual->proximo != lista->cabeca)
        {
            atual = atual->proximo;
        }
        atual->proximo = novoItem;
    }
    lista->tamanho++;
}

int numeroDeOcorrencias(ListaCircular *lista, int temp)
{
    if (lista == NULL || lista->cabeca == NULL)
    {
        printf("Lista vazia ou invalida.\n");
        return 0;
    }

    int contador = 0;
    Item *atual = lista->cabeca;

    do
    {
        if (atual->chave == temp)
        {
            contador++;
        }
        atual = atual->proximo;
    } while (atual != lista->cabeca);

    return contador;
}


int main()
{
    ListaCircular *lista = criarListaCircularVazia();
    Item *i1 = (Item *)malloc(sizeof(Item));
    Item *i2 = (Item *)malloc(sizeof(Item));
    Item *i3 = (Item *)malloc(sizeof(Item));
    Item *i4 = (Item *)malloc(sizeof(Item));

    i1->chave = 12;
    i2->chave = 4;
    i3->chave = 10;
    i4->chave = 8;

    adicionarElemento(lista, i1);
    adicionarElemento(lista, i2);
    adicionarElemento(lista, i3);
    adicionarElemento(lista, i4);

    Item *temp = (Item *)malloc(sizeof(Item));
    temp->chave = 15;

    int t = numeroDeOcorrencias(lista, temp); // Deve ser igual a 2

    exibirListaCircular(lista);
}
