#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 50 //tamanho máximo de cada string
#define TAM_MAX 3 //define o máximo de itens da lista

//Parte 01: LISTA ESTÁTICA
typedef struct {
    char dados [TAM_MAX][MAX_STR_LEN];
    int quantidade;
}  ListaEstatica;

//Funções da lista estática
void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);


//Parte 02: LISTA ENCADEADA
typedef struct No {
    char* dado;
    struct No *proximo;
} No;

typedef No* ListaEncadeada;

//Funções da lista encadeada
void inicializarListaEncadeada(ListaEncadeada *lista);

void inserirListaEncadeada(ListaEncadeada *lista, const char *texto);
void removerListaEncadeada(ListaEncadeada *lista, const char *texto);
void listarListaEncadeada(const ListaEncadeada *lista);
void liberarListaEncadeada(ListaEncadeada *lista);

// Funções de Menu's
void menuListaEstatica();
void menuListaEncadeada();


int main () {
    int opcao;
    do {
        printf("\n--- MANIPULAÇÃO DE LISTAS (TEXTO) ---\n");
        printf("[1] Lista Estática\n");
        printf("[2] Lista Encadeada\n");
        printf("[0] Sair do Programa\n");
        printf("Escolha um opcao >>> ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
            menuListaEstatica();
            break;

            case 2:
            menuListaEncadeada();
            break;

            case 0:
            printf("Saindo do programa...");
            break;

            default:
            printf("Escolha uma opção válida!\n\n");

        }
    } while (opcao != 0);


    printf("Programa encerrado.\n");

    return 0;
}


//IMPLEMENTAÇÃO DAS FUNÇOES DE MENU
void menuListaEstatica(){
    ListaEstatica lista;
    inicializarListaEstatica(&lista);

    int opc;
    do {
        printf("\n\n--- Menu Lista Estática ---\n");
        printf("[1] - Inserir item\n");
        printf("[2] - Remover item\n");
        printf("[3] - Listar itens\n");
        printf("[0] - Voltar ao menu principal\n");
        printf(">>>");
        scanf("%d", &opc);
        getchar();

        switch (opc){
            case 1: {
                char item[MAX_STR_LEN];
                printf("Insira o nome do item: ");
                fgets(item, MAX_STR_LEN, stdin);
                item[strcspn(item, "\n")] = '\0'; // remove o \n que o fgets adiciona

                inserirListaEstatica(&lista, item);
                break;
            }
            
            case 2: {
                char item[MAX_STR_LEN];
                printf("Digite o nome do item a ser removido: ");
                fgets(item, MAX_STR_LEN, stdin);
                item[strcspn(item, "\n")] = '\0'; // remove o \n que o fgets adiciona

                removerListaEstatica(&lista, item);
                break;
            }

            case 3:
                listarListaEstatica(&lista);
                break;

            case 0:
                printf("Retornando ao menu principal...\n\n");
                break;

            default:
                printf("ERRO: Digite uma opção válida!");

        }
    } while (opc != 0);
    
}


void menuListaEncadeada(){
    ListaEncadeada lista;
    inicializarListaEncadeada(&lista);
    int opc;
    do {
        printf("\n\n--- Menu Lista Encadeada ---\n\n");
        printf("[1] - Inserir item\n");
        printf("[2] - Remover item\n");
        printf("[3] - Listar itens\n");
        printf("[0] - Voltar ao menu principal\n");
        printf(">>>");
        scanf("%d", &opc);
        getchar();

        switch (opc){
            case 1: {
                char item[MAX_STR_LEN];
                printf("Digite o nome do item: ");
                fgets(item, MAX_STR_LEN, stdin);
                item[strcspn(item, "\n")] = '\0'; // remove o \n que o fgets adiciona

                inserirListaEncadeada(&lista, item);
                break;
            }
            
            case 2: {
                char item[MAX_STR_LEN];
                printf("Digite o nome do item a ser removido: ");
                fgets(item, MAX_STR_LEN, stdin);
                item[strcspn(item, "\n")] = '\0'; // remove o \n que o fgets adiciona

                removerListaEncadeada(&lista, item);
                break;
            }

            case 3:
                listarListaEncadeada(&lista);
                break;

            case 0:
                printf("Retornando ao menu principal...\n");
                break;

            default:
                printf("ERRO: Digite uma opção válida!\n");
        }
    } while (opc != 0);
}
//IMPLEMENTAÇÃO DAS FUNÇÕES: LISTA ESTÁTICA

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0;
}


void inserirListaEstatica(ListaEstatica *lista, const char *texto) {
    if (lista->quantidade == TAM_MAX) {
        printf("ERRO: Lista cheia! Não é possível inserir.\n");
        return;
    }

    strcpy(lista->dados[lista->quantidade], texto);

    lista->quantidade++;
    printf("Item \"%s\" incluído com sucesso\n",texto);
}


void removerListaEstatica(ListaEstatica *lista, const char *texto) {
    int i, pos = -1;

    for (int i = 0; i < lista->quantidade; i++){
        if (strcmp(lista->dados[i], texto) == 0){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        printf("ERRO: Texto \"%s\" não encontrado na lista.\n", texto);
        return;
    }
     // Deslocar os elementos posteriores para a esquerda
    for (i = pos; i < lista->quantidade - 1; i++){
        strcpy(lista->dados[i], lista->dados[i+1]);
    }

    lista->quantidade--;
    printf("Item \"%s\" removido com sucesso.\n", texto);
}


void listarListaEstatica(const ListaEstatica *lista){
    printf("Itens da Lista Estática:\n");
    for (int i = 0; i < lista->quantidade; i++){
        printf("- %s\n", lista->dados[i]);
    }
}

//IMPLEMENTAÇÃO DAS FUNÇÕES: LISTA ENCADEADA
void inicializarListaEncadeada(ListaEncadeada *lista){
    *lista = NULL;
}


void inserirListaEncadeada(ListaEncadeada *lista, const char* texto){
    //Alocar memória para novo Nó
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL){
        printf("ERRO: Falha na alocação de memória.\n");
        return;
    }

    //Alocar memória para a STRING DENTRO DO NÓ
    novo->dado = (char*) malloc(strlen(texto) + 1);

    if (novo->dado == NULL) {
        printf("ERRO: Falha na alocação de memória.\n");
        free(novo);
        return;
    }

    strcpy(novo->dado, texto);

    //O ponteiro proximo do novo nó passa a apontar para o era o antigo primeiro.
    novo->proximo = *lista;

    //A cabeça da lista (*lista) é atualizada para apontar para o novo.
    *lista = novo;

    printf("Item \"%s\" incluído com sucesso.\n", texto);
}

void removerListaEncadeada(ListaEncadeada *lista, const char* texto){
    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && strcmp(atual->dado, texto) != 0){
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL){
        printf("Erro: Texto \"%s\" não encontrado na lista. \n", texto);
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    //Liberar a memória
    free(atual->dado);
    free(atual);
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}


void listarListaEncadeada(const ListaEncadeada *lista){
    No *temp = *lista;
    if (temp == NULL) {
        printf("A lista encadeada está vazia.\n");
        return;
    }
    printf("Itens da Lista Encadeada: \n");
    while (temp != NULL){
        printf("- %s\n", temp->dado);
        temp = temp->proximo;
    }
}

void liberarListaEncadeada(ListaEncadeada *lista){
    No *atual = *lista;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual->dado); //Libera a string
        free(atual); //Libera Nó
        atual = proximo;
    }
    *lista = NULL;
    printf("Memória liberada com sucesso.\n");
}