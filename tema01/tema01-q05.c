#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL));
    
    int soma = 0;
    int numeros[4][4];
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 4 ; j++) {
            numeros[i][j] = rand() % 10;
            soma += numeros[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("L%d: %d   C%d: %d\n", i, numeros[i][j], j, numeros[j][i]);
        }
    }
    printf("A soma é %d\n", soma);


    return 0;

}