#ifndef PISTAS_H
#define PISTAS_H

// BST de Pistas (Nivel Aventureiro)
// - Cada pista possui um ID inteiro (chave) e uma descricao (string alocada)
// - Operacoes: inserir, buscar, imprimir (in-order) e destruir

typedef struct Pista {
    int id;                 // chave
    char* descricao;        // texto da pista (alocado dinamicamente)
    struct Pista* esq;      // filho esquerdo
    struct Pista* dir;      // filho direito
} Pista;

// Insere (ou atualiza) uma pista na BST. Retorna a nova raiz.
// - Se o ID ja existir, a descricao e atualizada (string anterior e liberada).
Pista* pistaInserir(Pista* raiz, int id, const char* descricao);

// Busca pela pista com ID. Retorna ponteiro para a descricao (ou NULL se nao encontrar).
const char* pistaBuscar(Pista* raiz, int id);

// Imprime as pistas em-ordem: IDs crescentes, com suas descricoes.
void pistaImprimirInOrder(Pista* raiz);

// Libera toda a BST e suas descricoes.
void pistaDestruir(Pista* raiz);

#endif // PISTAS_H