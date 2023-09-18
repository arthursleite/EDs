#include <stdio.h>

void insertionSort(int arr[], int n);

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Elemento a ser inserido na parte ordenada
        int j = i - 1;
        // Move os elementos maiores que a chave para a direita
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insere a chave na posição correta
    }
}