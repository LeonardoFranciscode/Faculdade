#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcson()

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 50
#define TAM_STRING 100

// --- Definição da Estrutura (Struct) ---
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para sim, 0 para não.
};

// ---Struct para armazenar informações do empréstimo ---
struct Emprestimo {
    int indiceLivro; // Para saber qual livro do array 'biblioteca' foi emprestado.
    char nomeUsuario[TAM_STRING];
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// --- Função Principal (main) ---
int main() {
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    //CALLOC para o array de livros (inicializa toda a memória com zeros).
    biblioteca = (struct Livro*) calloc(MAX_LIVROS, sizeof(struct Livro));

    //MALLOC para o array de empréstimos.
    emprestimos = (struct Emprestimo*) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    //VERIFICAÇÃO: para saber se a memória foi alocada corretamente
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro: Falha ao alocar memoria.\n");
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    // --- Laço Principal do Menu ---
    do {

        // Exibe o menu de opções
        printf("===================================\n");
        printf("      BIBLIOTECA - PARTE 2\n");
        printf("===================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar emprestimo\n");
        printf("4 - Listar emprestimos\n");
        printf("0 - Sair\n");
        printf("-----------------------------------\n");
        printf(">>>>");

        // Lê a opção do usuário
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '/n' deixado pelo scanf

        // --- Processamento da Opção ---
        switch (opcao) {
            case 1: // CADASTRO DE LIVRO
                printf("\n--- Cadastro de Novo Livro ---\n\n");

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

                    biblioteca[totalLivros].disponivel = 1; // Para tornar disponível

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
                printf("\n--- Lista de Livros Cadastrados ---\n\n");

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

            case 3: //REALIZAR EMPRESTIMO
                printf("\n--- Realizar Emprestimo ---\n\n");

                if (totalEmprestimos >= MAX_EMPRESTIMOS) {
                    printf("Limite de emprestimos atingido!\n");
                } 

                else {
                    printf("Livros disponiveis:\n");
                    int disponiveis = 0;
                    for (int i = 0; i < totalLivros; i++) {
                        if (biblioteca[i].disponivel) {
                            printf("%d - %s\n", i + 1, biblioteca[i].nome);
                            disponiveis++;
                        }
                    }

                        if (disponiveis == 0) {
                        printf("Nenhum livro disponivel para emprestimo. \n");
                        }

                    else {
                        printf("Digite o número do livro que deseja emprestar: ");
                        int numLivro;
                        scanf("%d", &numLivro);
                        limparBufferEntrada();

                        int indice = numLivro - 1; //Converte para o índice do array

                        // Validação da escolha do usuário
                        if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
                            printf("Digite o nome do usuario que está locando o livro: ");
                            fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                            emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario,"\n")] = '\0';

                            // Registra o empréstimo
                            emprestimos[totalEmprestimos].indiceLivro = indice;

                            // Atualiza o status do livro para indisponivel
                            biblioteca[indice].disponivel = 0;

                            totalEmprestimos++;
                            printf("\nEmprestimo realizado com sucesso!\n");
                        } 

                        else {
                            printf("\nNumero de livro invalido ou livro indisponivel. \n");
                        }
                    }
                }
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;

            case 4: // LISTAR EMPRÉSTIMOS
                printf("\n--- Listas de Emprestimos ---\n\n");
                if (totalEmprestimos == 0) {
                    printf("Nenhum emprestimo realizado. \n");
                }
                
                else {
                    for (int i = 0; i < totalEmprestimos; i++) {
                        // Usa o índice armazenado no empréstimo para buscar o nome do livro.
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("-------------------------------------\n");
                        printf("EMPRESTIMO %d\n", i + 1);
                        printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
                    }
                    printf("-------------------------------------\n");
                }
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;

            case 0: //SAIR
                printf("\nSaindo do sistema...\n");
                break;

            default: //OPÇÃO INVÁLIDA
                printf("\nOpcao invalida! Tente Novamente.\n");
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;
                }
        
    } while (opcao != 0);

    //LIBERAÇÃO DA MEMÓRIA: para evitar "memory leaks".
    free(biblioteca);
    free(emprestimos);
    printf("\nMemória liberada com sucesso.\n");


    printf("\nPrograma encerrado. Até logo!\n");


    return 0;
}