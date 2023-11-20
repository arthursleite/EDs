#include <stdio.h>

int main()
{
    int numeros[3][3];
    int maior;
    maior = numeros[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o numero da %dª linha e da %dª coluna: \n", i + 1, j + 1);
            scanf("%d", &numeros[i][j]);
            if (numeros[i][j] > maior) {
                maior = numeros[i][j];
            }
        }
    }
    printf("O maior valor da matriz é: %d\n", maior);

    return 0;
}
