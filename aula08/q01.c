/*Faça um programa que abra um arquivo HTML e elimine todas as “tags” do texto, ou seja, o programa deve gerar um novo arquivo em disco que elimine todas as tags HTML, que são caracterizadas por comandos entre “<>”. Veja abaixo um exemplo de um texto em HTML e do texto que deverá ser gerado pelo programa após eliminar as tags HTML
Q01*/

//Arthur de Souza Leite
//UC21200407

#include <stdio.h>

int main() {
    FILE *arquivoIn;
    FILE *arquivoOut;

    arquivoIn = fopen("../index.html", "r");
    arquivoOut = fopen("../index.txt", "w");

    char caractere;
    int dentroTag = 0;

    if (arquivoIn == NULL || arquivoOut == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while ((caractere = fgetc(arquivoIn)) != EOF) {
        if (caractere == '<') {
            dentroTag = 1;
        } else if (caractere == '>') {
            dentroTag = 0;
        } else if (!dentroTag) {
            fputc(caractere, arquivoOut);
        }
    }

    fclose(arquivoIn);
    fclose(arquivoOut);

    return 0;
}