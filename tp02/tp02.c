#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trocas = 0;      
int comparacoes = 0;

void swap(char **a, char **b);

int partition(char *arr[], int low, int high);

void quickSort(char *arr[], int low, int high);

int main()
{
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi",
        "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};

    trocas = 0;
    comparacoes = 0;

    quickSort(arr, 0, 19);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < 20; i++)
    {
        printf("(%d) %s\n", i + 1, arr[i]);
    }

    FILE *arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL)
    {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    fprintf(arquivoSaida, "Número de trocas: %d\n", trocas);
    fprintf(arquivoSaida, "Número de comparações: %d\n", comparacoes);
    fprintf(arquivoSaida, "Vetor ordenado:\n");
    for (int i = 0; i < 20; i++)
    {
        fprintf(arquivoSaida, "(%d) %s\n", i + 1, arr[i]);
    }
    fprintf(arquivoSaida, "Mediana: %s e %s\n", arr[10], arr[11]);

    fclose(arquivoSaida);

    return 0;
}

void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

int partition(char *arr[], int low, int high)
{
    char *pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (strcmp(arr[j], pivot) <= 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        comparacoes++;
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(char *arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}