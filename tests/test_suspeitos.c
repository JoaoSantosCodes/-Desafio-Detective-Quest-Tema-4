#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../include/suspeitos.h"

int main(void) {
    TabelaSuspeitos* tab = suspeitosCriar(32);

    // Inserir e buscar
    int novo1 = suspeitosInserirOuAtualizar(tab, "Alice", "Jornalista");
    assert(novo1 == 1);
    const char* a = suspeitosBuscar(tab, "Alice");
    assert(a && strcmp(a, "Jornalista") == 0);

    // Atualizar existente
    int novo2 = suspeitosInserirOuAtualizar(tab, "Alice", "Jornalista experiente");
    assert(novo2 == 0);
    const char* a2 = suspeitosBuscar(tab, "Alice");
    assert(a2 && strcmp(a2, "Jornalista experiente") == 0);

    // Inserir outro, listar (cobertura)
    suspeitosInserirOuAtualizar(tab, "Bob", "Mordomo");
    printf("[TEST] Lista de suspeitos (apenas cobertura):\n");
    suspeitosListar(tab);

    // Remover
    int rem = suspeitosRemover(tab, "Alice");
    assert(rem == 1);
    const char* ax = suspeitosBuscar(tab, "Alice");
    assert(ax == NULL);

    // Remover inexistente
    int rem2 = suspeitosRemover(tab, "NaoExiste");
    assert(rem2 == 0);

    suspeitosDestruir(tab);
    printf("[OK] test_suspeitos passou.\n");
    return 0;
}