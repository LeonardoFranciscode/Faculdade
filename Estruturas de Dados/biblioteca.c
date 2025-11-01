#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcson()

// --- Constantes Globais ---
#define MAX_LIVROS 4
#define TAM_STRING 100

// --- Definição da Estrutura (Struct) ---
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// --- Função Principal (main) ---
int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // --- Laço Principal do Menu ---
    do {

        // Exibe o menu de opções
        printf("===================================\n");
        printf("      BIBLIOTECA - PARTE 1\n");
        printf("===================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Sair\n");
        printf("-----------------------------------\n");
        printf(">>>>");

        // Lê a opçãi do usuário
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '/n' deixado pelo scanf

        // --- Processamento da Opção ---
        switch (opcao) {
            case 1: // CADASTRO DE LIVRO
                printf("--- Cadastro de Novo Livro ---\n\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o nome do autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    // Remove o '\n' que o fgets adiciona no final da string
                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite o número da edicao: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();

                    totalLivros++;

                    printf("\nLivro Cadastrado com sucesso!\n");
                }

                else {
                    printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n");
                }

                printf("\nPressione ENTER para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu.
                break;

            case 2: // LISTAGEM DE LIVROS
                printf("--- Lista de Livros Cadastrados ---\n\n");

                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado ainda.\n");
                }

                else {
                    for (int i = 0; i < totalLivros; i++) {
                        printf("----------------------------------------------\n");
                        printf("LIVRO %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                    }
                    printf("----------------------------------------------\n");
                }

                //Pausa para usuário ver a lista
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;

            case 3: //SAIR
                printf("\nSaindo do sistema...\n");
                break;

            default: //OPÇÃO INVÁLIDA
                printf("\nOpcao invalida! Tente Novamente.\n");
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;
        }
    } while (opcao != 3);

    printf("\nPrograma encerrado. Até logo!\n");


    return 0;
}