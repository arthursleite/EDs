#include <stdio.h>
int
main ()
{
  
    int numeros[5];
    int soma = 0;
    
    for (int i = 0; i < 5; i++) {
        printf("Preencha a posicao %d: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    printf("Soma de todos os elementos: %d", soma);
    
    return 0;
}
