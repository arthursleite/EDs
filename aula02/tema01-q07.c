#include <stdio.h>

int main()
{
    int soma = 0;
    int numeros[6];
    for (int i = 0; i < 6; i++) {
        printf("Digite o %dº numero: \n", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    double media = (double) soma / 6;
    printf("A media é: %f\n", media);

    return 0;
}
