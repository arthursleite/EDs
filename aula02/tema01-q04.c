#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int numeros[10];
    int soma = 0;
    
    srand(time(NULL));
    
    for(int i = 0 ; i < 10 ; i++) {
        numeros[i] = rand() % 9 + 1;
    }
    
    int maior = numeros[0];
    for(int i = 0 ; i < 10 ; i++) {
        if(numeros[i] > maior) {
            maior = numeros[i];
            soma = 1;
        } else if (numeros[i] == maior) {
            soma++;
        }
    }
    printf("O maior valor no vetor é: %d e está %d vez(es) no vetor\n", maior, soma);


    return 0;

}