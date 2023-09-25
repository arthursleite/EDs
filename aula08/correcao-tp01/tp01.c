#include <stdio.h>

#define MAX_NOME 50
#define MAX_TELEFONE 15 // Para armazenar (DDD) DD-DDDD
#define MAX_CURSO 50
#define MAX_LINHA 1024

typedef struct
{
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char curso[MAX_CURSO];
    double nota1;
    double nota2;
} Aluno;

void getNome(char *linha, char *nome)
{
    int i = 0;
    while (linha[i] != ',' && linha[i] != '\0' && i < MAX_NOME - 1)
    {
        nome[i] = linha[i];
        i++;
    }
    nome[i] = '\0';
}

void getTelefone(char *linha, char *telefone)
{
    int i = 0;
    int count_virgula = 0; // Contador de vírgulas
    int j = 0;             // Índice para a gravação do telefone
    while (linha[i] != '\0' && count_virgula < 2 && j < MAX_TELEFONE - 1)
    {
        if (linha[i] == ',')
        {
            count_virgula++;
        }
        else if (count_virgula == 1)
        {
            telefone[j] = linha[i];
            j++;
        }
        i++;
    }
    telefone[j] = '\0';
}

void getCurso(char *linha, char *curso)
{
    int i = 0;
    int count_virgula = 0; // Contador de vírgulas
    int j = 0;             // Índice para a gravação do telefone
    while (linha[i] != '\0' && count_virgula < 3)
    {
        if (linha[i] == ',')
        {
            count_virgula++;
        }
        else if (count_virgula == 2)
        {
            curso[j] = linha[i];
            j++;
        }
        i++;
    }
    curso[j] = '\0';
}

float getNota01(char *linha)
{
    char Nota[10];
    int i = 0;
    int count_virgula = 0; // Contador de vírgulas
    int j = 0;             // Índice para a gravação do telefone
    while (linha[i] != '\0' && count_virgula < 4)
    {
        if (linha[i] == ',')
            count_virgula++;
        else if (count_virgula == 3)
        {
            Nota[j] = linha[i];
            j++;
        }
        i++;
    }
    Nota[j] = '\0';
    return (atof(Nota));
}

float getNota02(char *linha)
{
    char Nota[10];
    int i = 0;
    int count_virgula = 0; // Contador de vírgulas
    int j = 0;             // Índice para a gravação do telefone
    while (linha[i] != '\0')
    {
        if (linha[i] == ',')
            count_virgula++;
        else if (count_virgula == 4)
        {
            Nota[j] = linha[i];
            j++;
        }
        i++;
    }
    Nota[j] = '\0';
    return (atof(Nota));
}

int main()
{
    FILE *entrada = fopen("../DadosEntrada.csv", "r");
    FILE *saida = fopen("../SituacaoFinal.csv", "w");
    if (entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }
    fprintf(saida, "Nome,Nota Media,Situacao\n"); // Escreve o cabeçalho no arquivo de saída
    char linha[MAX_LINHA];
    fgets(linha, sizeof(linha), entrada);

    while (fgets(linha, sizeof(linha), entrada))
    {
        Aluno aluno;
        getNome(linha, aluno.nome);
        getTelefone(linha, aluno.telefone);
        getCurso(linha, aluno.curso);
        aluno.nota1 = getNota01(linha);
        aluno.nota2 = getNota02(linha);
        float media = (aluno.nota1 + aluno.nota2) / 2.0;
        char situacao[10];
        if (media >= 7.0)
            strcpy(situacao, "APROVADO");
        else
            strcpy(situacao, "REPROVADO");
        fprintf(saida, "%s,%.2lf,%s\n", aluno.nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}