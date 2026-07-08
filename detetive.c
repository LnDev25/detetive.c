// Nível novato - Começo //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Cômodo
typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

// Protótipos
Sala* criarSala(char* nome);
void explorarSalas(Sala* salaAtual);

// Cria um nó da árvore dinamicamente
Sala* criarSala(char* nome) {
    Sala* novaSala = (Sala*) malloc(sizeof(Sala));
    strcpy(novaSala->nome, nome);
    novaSala->esq = NULL;
    novaSala->dir = NULL;
    return novaSala;
}

// Exploração recursiva
void explorarSalas(Sala* salaAtual) {
    if (salaAtual == NULL) return;
    printf("\n--- Você está no: %s ---\n", salaAtual->nome);

    if (salaAtual->esq == NULL && salaAtual->dir == NULL) {
        printf("Este cômodo não tem mais caminhos. Fim da exploração!\n");
        return;
    }

    char opcao;
    printf("Escolha: (e)squerda, (d)ireita ou (s)air: ");
    scanf(" %c", &opcao);

    if (opcao == 'e' || opcao == 'E') {
        if (salaAtual->esq != NULL) explorarSalas(salaAtual->esq);
        else printf("Caminho inexistente!\n");
    } else if (opcao == 'd' || opcao == 'D') {
        if (salaAtual->dir != NULL) explorarSalas(salaAtual->dir);
        else printf("Caminho inexistente!\n");
    } else {
        printf("Saindo...\n");
    }
}

int main() {
    // Montagem da Mansão
    Sala* hall = criarSala("Hall de Entrada");
    
    // Nível 1
    hall->esq = criarSala("Sala de Estar");
    hall->dir = criarSala("Biblioteca");
    
    // Nível 2 (Filhos da Sala de Estar)
    hall->esq->esq = criarSala("Cozinha");
    hall->esq->dir = criarSala("Jardim");
    
    // Nível 2 (Filhos da Biblioteca)
    hall->dir->esq = criarSala("Escritório");
    hall->dir->dir = criarSala("Sótão");

    // Início do Jogo
    printf("Bem-vindo ao Detective Quest!");
    explorarSalas(hall);

    return 0;
}

// Nível novato - Fim //