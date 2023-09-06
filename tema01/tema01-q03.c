#include <stdio.h>

struct Aluno {
    char nome[20];
    int nota;
};

int main () 
{
  struct Aluno aluno[3];
  for (int i = 0; i < 3; i++) {
      printf("Digite o nome do aluno %d: ", i + 1);
      scanf("%s", &aluno[i].nome);
      printf("Digite a nota do aluno %d: ", i + 1);
      scanf("%d", &aluno[i].nota);
  }
  for (int i = 0; i < 3; i++) {
      printf("Aluno: %s\n", aluno[i].nome);
      printf("Nota: %d\n", aluno[i].nota);
  }
 
 
 
return 0;

}