#include <stdio.h>

struct Funcionario {
    char nome[20];
    double salario;
    char cargo[15];
};

int main()
{
    struct Funcionario funcionario[4];
    for (int i = 0; i < 4; i++) {
        printf("Digite o nome do %dº funcionario: \n", i + 1);
        scanf("%s", funcionario[i].nome);
        printf("Digite o salario do %dº funcionario: \n", i + 1);
        scanf("%lf", &funcionario[i].salario);
        printf("Digite o cargo do %dº funcionario: \n", i + 1);
        scanf("%s", funcionario[i].cargo);
    }
    
    printf("\nDados dos usuarios: \n\n");
    for (int i = 0; i < 4; i++) {
        printf("Usuario %d\n", i + 1);
        printf("Nome: %s\n", funcionario[i].nome);
        printf("Salario: %.2lf\n", funcionario[i].salario);
        printf("Cargo: %s\n\n", funcionario[i].cargo);
    }

    return 0;
}
