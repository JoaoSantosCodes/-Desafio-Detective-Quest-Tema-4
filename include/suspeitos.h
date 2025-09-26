#ifndef SUSPEITOS_H
#define SUSPEITOS_H

#include <stddef.h>

// Tabela hash simples (encadeamento) para suspeitos
// - Chave: nome (string ASCII)
// - Valor: descricao (string ASCII)
// - Colisoes resolvidas por lista encadeada
// - Todas as strings sao copiadas dinamicamente

typedef struct Suspeito {
    char* nome;
    char* descricao;
    struct Suspeito* prox;
} Suspeito;

typedef struct {
    Suspeito** buckets;
    size_t nBuckets;
} TabelaSuspeitos;

// Cria tabela com "nBuckets" baldes.
TabelaSuspeitos* suspeitosCriar(size_t nBuckets);

// Insere ou atualiza um suspeito pelo nome. Retorna 1 se inseriu novo, 0 se atualizou existente.
int suspeitosInserirOuAtualizar(TabelaSuspeitos* t, const char* nome, const char* descricao);

// Busca por nome. Retorna ponteiro para descricao (nao copiar), ou NULL se nao encontrar.
const char* suspeitosBuscar(const TabelaSuspeitos* t, const char* nome);

// Remove por nome. Retorna 1 se removeu, 0 se nao encontrado.
int suspeitosRemover(TabelaSuspeitos* t, const char* nome);

// Lista todos os suspeitos (ordem por buckets)
void suspeitosListar(const TabelaSuspeitos* t);

// Libera toda a memoria
void suspeitosDestruir(TabelaSuspeitos* t);

#endif // SUSPEITOS_H