#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int chave;
    // Outros componentes (...)
} Item;
typedef struct
{
    Item *array;
    int tamanho;
    int capacidade;
} Lista;

Lista *criarLista(int capacidade)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista == NULL)
    {
        perror("Erro ao alocar memória para a lista");
        exit(1);
    }
    lista->array = (Item *)malloc(capacidade * sizeof(Item));
    if (lista->array == NULL)
    {
        perror("Erro ao alocar memória para o array da lista");
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
        printf("Erro: A lista está cheia e não é possível inserir mais elementos.\n");
        return;
    }
    lista->array[lista->tamanho] = elemento;
    lista->tamanho++;
}

void removerElemento(Lista *lista, int indice)
{
    if (indice < 0 || indice >= lista->tamanho)
    {
        printf("Erro: Índice fora dos limites da lista.\n");
        return;
    }
    // Movendo os elementos subsequentes uma posição para a esquerda
    for (int i = indice; i < lista->tamanho - 1; i++)
    {
        lista->array[i] = lista->array[i + 1];
    }
    lista->tamanho--;
}

Item *localizarElemento(Lista *lista, int indice)
{
    if (indice < 0 || indice >= lista->tamanho)
    {
        printf("Erro: Índice fora dos limites da lista.\n");
        return NULL;
    }
    return &(lista->array[indice]);
}

Lista *combinarListas(Lista *lista1, Lista *lista2)
{
    int novaCapacidade = lista1->capacidade + lista2->capacidade;
    Lista *novaLista = criarLista(novaCapacidade);
    // Copiando elementos da primeira lista para a nova lista
    for (int i = 0; i < lista1->tamanho; i++)
    {
        inserirElemento(novaLista, lista1->array[i]);
    }
    // Copiando elementos da segunda lista para a nova lista
    for (int i = 0; i < lista2->tamanho; i++)
    {
        inserirElemento(novaLista, lista2->array[i]);
    }
    return novaLista;
}

Lista *recortarLista(Lista *lista, int inicio, int fim)
{

    if (inicio < 0 || fim >= lista->tamanho || inicio > fim)
    {
        printf("Erro: Intervalo inválido para recorte da lista.\n");
        return NULL;
    }

    int novaCapacidade = fim - inicio + 1;
    Lista *novaLista = criarLista(novaCapacidade);
    for (int i = inicio; i <= fim; i++)
    {
        inserirElemento(novaLista, lista->array[i]);
    }

    return novaLista;
}

int main()
{
    Lista *a = criarLista(5);

    inserirElemento(a, (Item){2});
    inserirElemento(a, (Item){3});
    inserirElemento(a, (Item){5});
    inserirElemento(a, (Item){8});
    inserirElemento(a, (Item){1});

    Lista *b = criarLista(7);

    inserirElemento(b, (Item){4});
    inserirElemento(b, (Item){3});
    inserirElemento(b, (Item){7});
    inserirElemento(b, (Item){6});
    inserirElemento(b, (Item){0});
    inserirElemento(b, (Item){9});
    inserirElemento(b, (Item){1});

    Lista *c = combinarListas(a, b);

    c = recortarLista(c, 2, 6);
    for (int i = 0; i < c->tamanho; i++)
    {
        Item *elementoLocalizado = localizarElemento(c, i);
        if (elementoLocalizado != NULL)
        {
            printf("Elemento localizado: %d\n", elementoLocalizado->chave);
        }
    }

    free(a->array);
    free(b->array);
    free(c->array);
    free(a);
    free(b);
    free(c);
    return 0;
}
