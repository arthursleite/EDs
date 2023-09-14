#include <stdio.h>

void swap(int *a, int *b);
int particao(int valores[], int inf, int sup);
void quickSort(int valores[], int inf, int sup);

int main()
{
    int valores[] = {3, 6, 4, 5, 1, 7, 2};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", valores[i]);
    }
    printf("\n");
    quickSort(valores, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", valores[i]);
    }
    printf("\n");
}

// Função para trocar um valor com outro
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o vetor
int particao(int valores[], int inf, int sup)
{
    int pivot = valores[sup];
    int i = inf - 1;
}

// Função para organizar usando o quickSort
void quickSort(int valores[], int inf, int sup)
{
    if (inf < sup)
    {
        int p = particao(valores, inf, sup);
        quickSort(valores, inf, p - 1);
        quickSort(valores, p + 1, sup);
    }
}