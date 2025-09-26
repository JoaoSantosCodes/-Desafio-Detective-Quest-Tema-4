#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/suspeitos.h"

static size_t hashStr(const char* s, size_t mod) {
    // djb2 simples
    unsigned long h = 5381UL;
    int c;
    while ((c = (unsigned char)*s++)) {
        h = ((h << 5) + h) + (unsigned long)c;
    }
    return (size_t)(h % mod);
}

static char* dupStr(const char* s) {
    size_t n = strlen(s);
    char* p = (char*)malloc(n + 1);
    if (!p) { fprintf(stderr, "Erro: memoria insuficiente.\n"); exit(EXIT_FAILURE);}    
    memcpy(p, s, n + 1);
    return p;
}

TabelaSuspeitos* suspeitosCriar(size_t nBuckets) {
    if (nBuckets == 0) nBuckets = 16;
    TabelaSuspeitos* t = (TabelaSuspeitos*)malloc(sizeof(TabelaSuspeitos));
    if (!t) { fprintf(stderr, "Erro: memoria insuficiente.\n"); exit(EXIT_FAILURE);}    
    t->buckets = (Suspeito**)calloc(nBuckets, sizeof(Suspeito*));
    if (!t->buckets) { fprintf(stderr, "Erro: memoria insuficiente.\n"); exit(EXIT_FAILURE);}    
    t->nBuckets = nBuckets;
    return t;
}

int suspeitosInserirOuAtualizar(TabelaSuspeitos* t, const char* nome, const char* descricao) {
    if (!t || !nome || !descricao) return 0;
    size_t idx = hashStr(nome, t->nBuckets);
    Suspeito* curr = t->buckets[idx];
    while (curr) {
        if (strcmp(curr->nome, nome) == 0) {
            // atualizar
            char* nova = dupStr(descricao);
            free(curr->descricao);
            curr->descricao = nova;
            return 0;
        }
        curr = curr->prox;
    }
    // inserir
    Suspeito* novo = (Suspeito*)malloc(sizeof(Suspeito));
    if (!novo) { fprintf(stderr, "Erro: memoria insuficiente.\n"); exit(EXIT_FAILURE);}    
    novo->nome = dupStr(nome);
    novo->descricao = dupStr(descricao);
    novo->prox = t->buckets[idx];
    t->buckets[idx] = novo;
    return 1;
}

const char* suspeitosBuscar(const TabelaSuspeitos* t, const char* nome) {
    if (!t || !nome) return NULL;
    size_t idx = hashStr(nome, t->nBuckets);
    Suspeito* curr = t->buckets[idx];
    while (curr) {
        if (strcmp(curr->nome, nome) == 0) return curr->descricao;
        curr = curr->prox;
    }
    return NULL;
}

int suspeitosRemover(TabelaSuspeitos* t, const char* nome) {
    if (!t || !nome) return 0;
    size_t idx = hashStr(nome, t->nBuckets);
    Suspeito* prev = NULL;
    Suspeito* curr = t->buckets[idx];
    while (curr) {
        if (strcmp(curr->nome, nome) == 0) {
            if (prev) prev->prox = curr->prox; else t->buckets[idx] = curr->prox;
            free(curr->nome);
            free(curr->descricao);
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->prox;
    }
    return 0;
}

void suspeitosListar(const TabelaSuspeitos* t) {
    if (!t) return;
    for (size_t i = 0; i < t->nBuckets; ++i) {
        Suspeito* curr = t->buckets[i];
        while (curr) {
            printf("- %s: %s\n", curr->nome, curr->descricao);
            curr = curr->prox;
        }
    }
}

void suspeitosDestruir(TabelaSuspeitos* t) {
    if (!t) return;
    for (size_t i = 0; i < t->nBuckets; ++i) {
        Suspeito* curr = t->buckets[i];
        while (curr) {
            Suspeito* nx = curr->prox;
            free(curr->nome);
            free(curr->descricao);
            free(curr);
            curr = nx;
        }
    }
    free(t->buckets);
    free(t);
}