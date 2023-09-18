#include <stdio.h>

void swap(int *a, int *b);

int particao(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

int main()
{
    int arr[20] = {25, 17, 31, 13, 2, 19, 8, 14, 7, 1, 22, 10, 3, 12, 9, 5, 6, 16, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Vetor desordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Escolhendo o último elemento como pivô
    int i = (low - 1);     // O índice do menor elemento
    for (int j = low; j <= high - 1; j++)
    {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot)
        {
            i++; // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função Quicksort principal
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Encontre a posição do pivô
        int pi = partition(arr, low, high);
        // Ordena os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}