#include <stdio.h>
int
main ()
{
  
    int numeros[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Preencha a linha %d, coluna %d: ", i + 1, j + 1);
            scanf("%d", &numeros[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d  ", numeros[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
