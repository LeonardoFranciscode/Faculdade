#include <stdio.h>

// Definindo a estrutura do tipo Aluno
typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;

int main() {
    // Criando uma variável do tipo Aluno
    Aluno aluno1 = {"João", 20, 8.5};

    // Exibindo os dados do aluno
    printf("Aluno: %s, Idade: %d, Média: %.2f\n", aluno1.nome, aluno1.idade, aluno1.media);
    

    return 0;
} 