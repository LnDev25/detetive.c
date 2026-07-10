// Nível Novato/Aventureiro/Mestre - Começo //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas
typedef struct Sala {
    char nome[50];
    char pista[50] ;
    struct Sala *esq;
    struct Sala *dir;
} Sala;

typedef struct PistaNode {
    char conteudo [50] ;
    struct PistaNode *esq;
    struct PistaNode *dir;
} PistaNode ;

typedef struct HashNode {
    char pista[50];
    char suspeito[50];
    struct HashNode *proximo; 
} HashNode;

#define TAM_HASH 10
HashNode* tabelaHash[TAM_HASH] = {NULL}; 

int calcularHash(char* pista) {
    int soma = 0;
    for(int i = 0; pista[i] != '\0'; i++) soma += pista[i];
    return soma % TAM_HASH;
}

// Protótipos
void explorarSalas(Sala* salaAtual);
PistaNode* inserirPista(PistaNode* raiz, char* pista);

// Construções
Sala* criarSala(char* nome, char* pista) { 
    Sala* novaSala = (Sala*) malloc(sizeof(Sala));
    strcpy(novaSala->nome, nome);
    strcpy(novaSala->pista, pista); 
    novaSala->esq = NULL;
    novaSala->dir = NULL;
    return novaSala;
}

PistaNode* criarPistaNode (char* pista) {
    PistaNode* novoNode = (PistaNode*) malloc(sizeof(PistaNode));
    strcpy(novoNode->conteudo, pista);
    novoNode->esq = NULL;
    novoNode->dir = NULL;
    return novoNode;
}

PistaNode* inserirPista(PistaNode* raiz, char* pista) {
    if (raiz == NULL) {
        return criarPistaNode(pista);
    }
    if (strcmp(pista, raiz->conteudo) < 0) {
        raiz->esq = inserirPista(raiz->esq, pista);
    } else if (strcmp(pista, raiz->conteudo) > 0) {
        raiz->dir = inserirPista(raiz->dir, pista);
    }
    return raiz;
}

// Exploração
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

void explorarSalasComPistas(Sala* salaAtual, PistaNode** raizPistas) {
    if (salaAtual == NULL) return;
    printf("\n--- Você está no: %s ---\n", salaAtual->nome);

    if (strlen(salaAtual->pista) > 0) {
        printf("Pista encontrada: %s\n", salaAtual->pista);
        *raizPistas = inserirPista(*raizPistas, salaAtual->pista);
    }

    if (salaAtual->esq == NULL && salaAtual->dir == NULL) {
        printf("Fim da exploração nesta sala.\n");
        return;
    }

    char opcao;
    printf("Escolha: (e)squerda, (d)ireita ou (s)air: ");
    scanf(" %c", &opcao);

    if (opcao == 'e' || opcao == 'E') {
        explorarSalasComPistas(salaAtual->esq, raizPistas);
    } else if (opcao == 'd' || opcao == 'D') {
        explorarSalasComPistas(salaAtual->dir, raizPistas);
    }
}

void exibirPistas(PistaNode* raiz) {
    if (raiz == NULL) return;
    exibirPistas(raiz->esq);        // Esquerda
    printf(" - %s\n", raiz->conteudo); // Raiz
    exibirPistas(raiz->dir);        // Direita
}

void inserirNaHash(char* pista, char* suspeito) {
    int idx = calcularHash(pista);
    HashNode* novo = (HashNode*) malloc(sizeof(HashNode));
    strcpy(novo->pista, pista);
    strcpy(novo->suspeito, suspeito);
    novo->proximo = tabelaHash[idx]; 
    tabelaHash[idx] = novo;
}

char* encontrarSuspeito(char* pista) {
    int idx = calcularHash(pista);
    HashNode* atual = tabelaHash[idx];
    while(atual != NULL) {
        if(strcmp(atual->pista, pista) == 0) return atual->suspeito;
        atual = atual->proximo;
    }
    return "Desconhecido";
}

void contarPistas(PistaNode* raiz, char* suspeitoAcusado, int* contador) {
    if (raiz == NULL) return;
    
    // Verifica se a pista deste nó pertence ao suspeito acusado
    if (strcmp(encontrarSuspeito(raiz->conteudo), suspeitoAcusado) == 0) {
        (*contador)++;
    }
    
    contarPistas(raiz->esq, suspeitoAcusado, contador);
    contarPistas(raiz->dir, suspeitoAcusado, contador);
}

void verificarSuspeitoFinal(PistaNode* raizPistas) {
    char suspeito[50];
    printf("\n--- Julgamento Final ---\n");
    printf("Quem é o culpado? ");
    scanf("%s", suspeito);
    
    int totalPistas = 0;
    contarPistas(raizPistas, suspeito, &totalPistas);
    
    if (totalPistas >= 2) {
        printf("Veredito: %s é o culpado! As %d evidências não mentem.\n", suspeito, totalPistas);
    } else {
        printf("Veredito: %s é inocente. Você não tem evidências suficientes.\n", suspeito);
    }
}


int main() {
    // 1. Populando a Tabela Hash (RELACIONANDO PISTAS E SUSPEITOS)
    inserirNaHash("Castiçal", "Sr. Mostarda");
    inserirNaHash("Livro Antigo", "Dona Branca");
    inserirNaHash("Chave", "Sr. Mostarda"); 

    // 2. Montando a Mansão
    Sala* hall = criarSala("Hall de Entrada", "");
    hall->esq = criarSala("Sala de Estar", "Castiçal");
    hall->dir = criarSala("Biblioteca", "Livro Antigo");
    hall->esq->dir = criarSala("Jardim", "Chave");

    PistaNode* cadernoDePistas = NULL;

    printf("Bem-vindo ao Detective Quest!");
    explorarSalasComPistas(hall, &cadernoDePistas);

    printf("\n--- Pistas Coletadas ---");
    exibirPistas(cadernoDePistas);

    verificarSuspeitoFinal(cadernoDePistas);

    return 0;
}

// Nível Novato/Aventureiro/Mestre - Fim //