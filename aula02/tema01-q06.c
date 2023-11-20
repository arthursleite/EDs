/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

struct Livro {
    char titulo[20];
    char autor[20];
    int ano;
};

int main()
{
    struct Livro livros[5];
    for (int i = 0; i < 5; i++) {
        printf("Digite o titulo do %dº livro: \n", i + 1);
        scanf("%s", livros[i].titulo);
        printf("Digite o autor do %dº livro: \n", i + 1);
        scanf("%s", livros[i].autor);
        printf("Digite o ano do %dº livro: \n", i + 1);
        scanf("%d", &livros[i].ano);
    }
    
    printf("\nDados dos livros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano: %d\n\n", livros[i].ano);
    }

    return 0;
}
