#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100

typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

// Criando um novo nó
No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Inserindo novo nó na árvore
No* inserir(No* raiz, int dado) {
    if (raiz == NULL) {
        return criarNo(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, dado);
    } else {
        raiz->direita = inserir(raiz->direita, dado);
    }
    return raiz;
}

// Percorrendo a árvore em ordem
void percursoEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percursoEmOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        percursoEmOrdem(raiz->direita);
    }
}

// Função do Selection Sort
void ordenacaoPorSelecao(int vetor[], int n, int* comparacoes) {
    for (int i = 0; i < n - 1; i++) {
        int indiceMinimo = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (vetor[j] < vetor[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        // Troca
        int temp = vetor[indiceMinimo];
        vetor[indiceMinimo] = vetor[i];
        vetor[i] = temp;
    }
}

void imprimirAlunos() {
    printf("Alunos:\n");
    printf("Nome: Gabriel Reis, Matrícula: 202302374867\n");
    printf("Nome: Lucas Fernande, Matrícula: 202303522738\n");
    printf("Nome: Mateus Cristovam, Matrícula: 202302374328\n");
    printf("Nome: Pedro Honorato, Matrícula: 202302904866\n");
    printf("Nome: Samuel Cordeiro, Matrícula: 202302373852\n");
}

int main() {
    srand(time(NULL));
    
    imprimirAlunos();
    
    printf("O módulo da operação é igual a 1 e o algoritmo é do tipo Selection Sort.\n");

    // Gerador de números aleátorios
    int vetor[TAMANHO];
    int comparacoes = 0;

    for (int i = 0; i < TAMANHO; ) {
        int num = rand() % 1000 + 1;
        int Unico = 1;
        for (int j = 0; j < i; j++) {
            if (vetor[j] == num) {
                Unico = 0;
                break;
            }
        }
        if (Unico) {
            vetor[i] = num;
            i++;
        }
    }

    // Ordenando e contando o tempo
    clock_t inicio = clock();
    ordenacaoPorSelecao(vetor, TAMANHO, &comparacoes);
    clock_t fim = clock();
    
    double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Imprimindo a árvore
    printf("Vetor ordenado: ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\nQuantidade de comparações: %d\n", comparacoes);
    printf("Tempo gasto na execução da ordenação: %.6f segundos\n", tempoGasto);
    
    // Criado a árvore
    No* raiz = NULL;
    for (int i = 0; i < TAMANHO; i++) {
        raiz = inserir(raiz, vetor[i]);
    }
    
    // Impressão da árvore em ordem
    printf("Árvore Binária (em ordem): ");
    percursoEmOrdem(raiz);
    printf("\n");

    return 0;
}