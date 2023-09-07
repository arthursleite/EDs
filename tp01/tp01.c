#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arquivoIn;
    FILE *arquivoOut;
    char nome[75];
    char telefone[15];
    char curso[40];
    double nota1;
    double nota2;

    arquivoIn = fopen("../DadosEntrada.csv", "r");
    arquivoOut = fopen("../SituacaoFinal.csv", "w");
    if (arquivoIn == NULL || arquivoOut == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fscanf(arquivoIn, "%*[^\n]\n");
    while (fscanf(arquivoIn, "%[^,],%[^,],%[^,],%lf,%lf", nome, telefone, curso, &nota1, &nota2) == 5)
    {
        double media = (nota1 + nota2) / 2.0;
        char situacao[10];
        if (media < 7) {
            strcpy(situacao, "REPROVADO");
        } else {
            strcpy(situacao, "APROVADO");
        }
        fprintf(arquivoOut,"%s, %.2lf, %s", nome, media, situacao);
    }

    fclose(arquivoIn);
    fclose(arquivoOut);
    return 0;
}