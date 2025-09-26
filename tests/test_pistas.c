#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../include/pistas.h"

int main(void) {
    Pista* raiz = NULL;

    // Insercoes iniciais
    raiz = pistaInserir(raiz, 10, "Mapa rasgado");
    raiz = pistaInserir(raiz, 5,  "Luvas com poeira");
    raiz = pistaInserir(raiz, 15, "Pegadas de lama");

    // Busca existentes
    const char* d10 = pistaBuscar(raiz, 10);
    const char* d5  = pistaBuscar(raiz, 5);
    const char* d15 = pistaBuscar(raiz, 15);
    assert(d10 && strcmp(d10, "Mapa rasgado") == 0);
    assert(d5 && strcmp(d5, "Luvas com poeira") == 0);
    assert(d15 && strcmp(d15, "Pegadas de lama") == 0);

    // Atualizacao (mesmo ID)
    raiz = pistaInserir(raiz, 10, "Mapa remendado");
    const char* d10b = pistaBuscar(raiz, 10);
    assert(d10b && strcmp(d10b, "Mapa remendado") == 0);

    // Busca inexistente
    const char* dX = pistaBuscar(raiz, 99);
    assert(dX == NULL);

    // Impressao para cobertura
    printf("[TEST] Pistas em-ordem (apenas cobertura):\n");
    pistaImprimirInOrder(raiz);

    pistaDestruir(raiz);
    printf("[OK] test_pistas passou.\n");
    return 0;
}