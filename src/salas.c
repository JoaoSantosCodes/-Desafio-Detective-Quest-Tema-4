#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/salas.h"

// --- utilitario simples para trilha (caminho percorrido) ---
typedef struct {
    const char** nomes;
    size_t usado;
    size_t cap;
} Trilha;

static void trilha_init(Trilha* t) { t->nomes = NULL; t->usado = 0; t->cap = 0; }
static void trilha_push(Trilha* t, const char* nome) {
    if (t->usado + 1 > t->cap) {
        size_t novo = t->cap ? t->cap * 2 : 8;
        const char** tmp = (const char**)realloc(t->nomes, novo * sizeof(const char*));
        if (!tmp) { fprintf(stderr, "Erro de memoria ao registrar trilha.\n"); exit(EXIT_FAILURE);} 
        t->nomes = tmp; t->cap = novo;
    }
    t->nomes[t->usado++] = nome;
}
static void trilha_clear(Trilha* t) { free(t->nomes); t->nomes = NULL; t->usado = t->cap = 0; }
static void trilha_print(const Trilha* t) {
    if (!t->usado) { printf("(sem passos)\n"); return; }
    for (size_t i = 0; i < t->usado; ++i) {
        printf("%s%s", t->nomes[i], (i + 1 < t->usado ? " -> " : "\n"));
    }
}

Sala* criarSala(const char* nome) {
    Sala* s = (Sala*)malloc(sizeof(Sala));
    if (!s) {
        fprintf(stderr, "Erro: falha ao alocar Sala.\n");
        exit(EXIT_FAILURE);
    }
    s->nome = nome; // literal estatico neste nivel
    s->esquerda = NULL;
    s->direita = NULL;
    return s;
}

void conectarSalas(Sala* pai, Sala* esquerda, Sala* direita) {
    if (!pai) {
        fprintf(stderr, "Aviso: nao foi possivel conectar salas porque 'pai' eh NULL.\n");
        return;
    }
    pai->esquerda = esquerda;
    pai->direita = direita;
}

static void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static void explorarInterno(Sala* raiz, int modoDemo, const char* script) {
    if (!raiz) { printf("Mapa vazio.\n"); return; }
    Sala* atual = raiz;
    char opc;
    Trilha trilha; trilha_init(&trilha); trilha_push(&trilha, atual->nome);

    if (!modoDemo) printf("Bem-vindo(a) ao Detective Quest!\n");

    size_t idxScript = 0;
    int sair = 0;
    for (;;) {
        printf("\nVoce esta em: %s\n", atual->nome);
        if (!atual->esquerda && !atual->direita) {
            printf("Voce chegou ao fim do caminho.\n");
            printf("Caminho percorrido: ");
            trilha_print(&trilha);
            if (modoDemo) { break; }
            // loop de reinicio
            for (;;) {
                printf("Deseja reiniciar do inicio (%s)? (r=recomecar, s=sair): ", raiz->nome);
                if (scanf(" %c", &opc) != 1) { limparEntrada(); continue; }
                if (opc == 'r' || opc == 'R') {
                    atual = raiz; trilha_clear(&trilha); trilha_init(&trilha); trilha_push(&trilha, atual->nome);
                    break; // sai do loop de reinicio e continua exploracao
                } else if (opc == 's' || opc == 'S') {
                    sair = 1; break; // encerra
                } else {
                    printf("Opcao invalida. Use r/s.\n");
                }
            }
            if (sair) break;
            else continue;
        }

        // Mostrar opcoes com nomes das salas filhas
        printf("Opcoes: ");
        if (atual->esquerda) printf("[e=%s] ", atual->esquerda->nome); else printf("[e=sem sala] ");
        if (atual->direita) printf("[d=%s] ", atual->direita->nome); else printf("[d=sem sala] ");
        printf("[s=sair] [p=trilha] [h=ajuda]\n");

        if (modoDemo) {
            if (!script || script[idxScript] == '\0') { printf("Script finalizado.\n"); break; }
            opc = script[idxScript++];
            printf("(demo) passo: %c\n", opc);
        } else {
            printf("Escolha (e/d/s/p/h): ");
            if (scanf(" %c", &opc) != 1) { printf("Entrada invalida.\n"); limparEntrada(); continue; }
        }

        if (opc == 's' || opc == 'S') {
            printf("Saindo...\n");
            break;
        } else if (opc == 'p' || opc == 'P') {
            printf("Caminho percorrido: ");
            trilha_print(&trilha);
            continue;
        } else if (opc == 'h' || opc == 'H') {
            printf("Ajuda: e=esquerda, d=direita, s=sair, p=trilha, h=ajuda.\n");
            continue;
        } else if (opc == 'e' || opc == 'E') {
            if (atual->esquerda) { atual = atual->esquerda; trilha_push(&trilha, atual->nome);} else { printf("Nao ha sala a esquerda.\n"); }
        } else if (opc == 'd' || opc == 'D') {
            if (atual->direita) { atual = atual->direita; trilha_push(&trilha, atual->nome);} else { printf("Nao ha sala a direita.\n"); }
        } else {
            if (modoDemo) {
                printf("(demo) comando invalido: %c (ignorado)\n", opc);
            } else {
                printf("Opcao invalida. Use e/d/s/p/h.\n");
            }
        }
    }
    trilha_clear(&trilha);
}

void explorarSalas(Sala* raiz) { explorarInterno(raiz, 0, NULL); }

void explorarSalasDemo(Sala* raiz, const char* script) { explorarInterno(raiz, 1, script); }

void destruirSalas(Sala* raiz) {
    if (!raiz) return;
    destruirSalas(raiz->esquerda);
    destruirSalas(raiz->direita);
    free(raiz);
}