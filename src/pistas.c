#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pistas.h"

static Pista* novoNo(int id, const char* descricao) {
    Pista* n = (Pista*)malloc(sizeof(Pista));
    if (!n) { fprintf(stderr, "Erro: memoria insuficiente.\n"); exit(EXIT_FAILURE); }
    n->id = id;
    if (descricao) {
        size_t len = strlen(descricao);
        n->descricao = (char*)malloc(len + 1);
        if (!n->descricao) { fprintf(stderr, "Erro: memoria insuficiente.\n"); exit(EXIT_FAILURE); }
        memcpy(n->descricao, descricao, len + 1);
    } else {
        n->descricao = NULL;
    }
    n->esq = n->dir = NULL;
    return n;
}

Pista* pistaInserir(Pista* raiz, int id, const char* descricao) {
    if (!raiz) return novoNo(id, descricao);
    if (id < raiz->id) raiz->esq = pistaInserir(raiz->esq, id, descricao);
    else if (id > raiz->id) raiz->dir = pistaInserir(raiz->dir, id, descricao);
    else {
        // Atualiza descricao
        free(raiz->descricao);
        if (descricao) {
            size_t len = strlen(descricao);
            raiz->descricao = (char*)malloc(len + 1);
            if (!raiz->descricao) { fprintf(stderr, "Erro: memoria insuficiente.\n"); exit(EXIT_FAILURE); }
            memcpy(raiz->descricao, descricao, len + 1);
        } else {
            raiz->descricao = NULL;
        }
    }
    return raiz;
}

const char* pistaBuscar(Pista* raiz, int id) {
    Pista* atual = raiz;
    while (atual) {
        if (id < atual->id) atual = atual->esq;
        else if (id > atual->id) atual = atual->dir;
        else return atual->descricao;
    }
    return NULL;
}

static void imprimirInOrder(Pista* r) {
    if (!r) return;
    imprimirInOrder(r->esq);
    printf("[%d] %s\n", r->id, r->descricao ? r->descricao : "(sem descricao)");
    imprimirInOrder(r->dir);
}

void pistaImprimirInOrder(Pista* raiz) {
    imprimirInOrder(raiz);
}

void pistaDestruir(Pista* raiz) {
    if (!raiz) return;
    pistaDestruir(raiz->esq);
    pistaDestruir(raiz->dir);
    free(raiz->descricao);
    free(raiz);
}