#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/salas.h"
#include "../include/pistas.h"
#include "../include/suspeitos.h"

// Função de ajuda (uso e flags disponíveis)
/*
 * Imprime ajuda de linha de comando e modos disponíveis.
 * Efeitos: escreve no stdout. Não altera estado global.
 * Uso: acionado por -h/--help ou como referência no menu principal.
 */
static void imprimirAjuda(void) {
    printf("Detective Quest - ajuda\n");
    printf("Uso:\n");
    printf("  detective-quest.exe                        Menu interativo\n");
    printf("  detective-quest.exe -h | --help            Mostra esta ajuda\n");
    printf("  detective-quest.exe -salas                 Salas (interativo)\n");
    printf("  detective-quest.exe -salas-demo <script>   Salas (demo - script)\n");
    printf("  detective-quest.exe -demo <script>         Alias para -salas-demo\n");
    printf("  detective-quest.exe -pistas                Pistas (interativo - BST)\n");
    printf("  detective-quest.exe -pistas-demo           Pistas (demo - BST)\n");
    printf("  detective-quest.exe -suspeitos             Suspeitos (interativo - Hash)\n");
    printf("  detective-quest.exe -suspeitos-demo        Suspeitos (demo - Hash)\n");
}

// Constrói uma configuração básica de salas (árvore binária)
/*
 * Constrói a árvore binária de salas (mansão básica) e retorna a raiz.
 * Retorno: ponteiro para a sala raiz; o chamador deve liberar com destruirSalas(raiz).
 * Efeitos: aloca memória dinâmica para os nós de Sala.
 */
static Sala* construirMansaoBasica() {
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* escritorio = criarSala("Escritorio");
    Sala* sotao = criarSala("Sotao");
    Sala* porao = criarSala("Porao");
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, escritorio, sotao);
    conectarSalas(cozinha, porao, NULL);
    return hall;
}

// Executa Salas (interativo)
/*
 * Executa o modo interativo de navegação pelas salas.
 * Fluxo: constrói a mansão, chama explorarSalas(raiz) e libera recursos ao final.
 * Entrada: sem parâmetros. Interage via stdin/stdout.
 */
static void executarModoSalasInterativo() {
    Sala* raiz = construirMansaoBasica();
    printf("Controles: e=esquerda, d=direita, s=sair (p=trilha, h=ajuda)\n");
    explorarSalas(raiz);
    destruirSalas(raiz);
}

// Executa Salas (demo) com script fornecido
/*
 * Executa o modo demonstração das salas seguindo um script de comandos, ex.: "eed".
 * Parâmetros: script — sequência de caracteres válidos (e/d/s, p/h, r).
 * Comportamento: constrói a mansão, chama explorarSalasDemo(raiz, script) e libera recursos.
 */
static void executarModoSalasDemoScript(const char* script) {
    Sala* raiz = construirMansaoBasica();
    printf("[Demo] Script: %s\n", script);
    explorarSalasDemo(raiz, script);
    destruirSalas(raiz);
}

static void executarModoPistasDemo() {
    Pista* raizP = NULL;
    raizP = pistaInserir(raizP, 10, "Mapa rasgado");
    raizP = pistaInserir(raizP, 5,  "Luvas com poeira");
    raizP = pistaInserir(raizP, 15, "Pegadas de lama");
    raizP = pistaInserir(raizP, 12, "Chave antiga");
    raizP = pistaInserir(raizP, 17, "Anotacao misteriosa");
    printf("[Pistas] Arvore em-ordem:\n");
    pistaImprimirInOrder(raizP);
    const char* d = pistaBuscar(raizP, 12);
    printf("[Pistas] Buscar ID 12: %s\n", d ? d : "(nao encontrada)");
    raizP = pistaInserir(raizP, 10, "Mapa remendado (atualizado)");
    printf("[Pistas] Atualizado ID 10. Em-ordem:\n");
    pistaImprimirInOrder(raizP);
    pistaDestruir(raizP);
}

static void executarModoPistasInterativo() {
    Pista* raizP = NULL;
    printf("\n=== Modo Pistas (BST) ===\n");
    printf("Comandos: a=adicionar, b=buscar, l=listar, q=sair\n");
    for (;;) {
        printf("\nDigite comando (a/b/l/q): ");
        char cmd;
        if (scanf(" %c", &cmd) != 1) {
            printf("Entrada invalida. Tente novamente.\n");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        if (cmd == 'q') {
            printf("Saindo do modo pistas...\n");
            break;
        } else if (cmd == 'l') {
            printf("\n[Pistas] Em-ordem:\n");
            pistaImprimirInOrder(raizP);
        } else if (cmd == 'b') {
            int id;
            printf("ID da pista para buscar: ");
            if (scanf(" %d", &id) != 1) {
                printf("ID invalido.\n");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
                continue;
            }
            const char* desc = pistaBuscar(raizP, id);
            if (desc) printf("Encontrada: [%d] %s\n", id, desc);
            else printf("Pista [%d] nao encontrada.\n", id);
        } else if (cmd == 'a') {
            int id; char buffer[256];
            printf("Novo ID da pista: ");
            if (scanf(" %d", &id) != 1) {
                printf("ID invalido.\n");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
                continue;
            }
            printf("Descricao (ate 255 caracteres): ");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            if (!fgets(buffer, sizeof(buffer), stdin)) { printf("Falha ao ler descricao.\n"); continue; }
            size_t len = strlen(buffer); if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
            raizP = pistaInserir(raizP, id, buffer);
            printf("Pista [%d] adicionada/atualizada.\n", id);
        } else {
            printf("Comando '%c' desconhecido. Use a, b, l ou q.\n", cmd);
        }
    }
    pistaDestruir(raizP);
}

static void executarModoSuspeitosDemo() {
    TabelaSuspeitos* tab = suspeitosCriar(32);
    suspeitosInserirOuAtualizar(tab, "Alice", "Jornalista, esteve na biblioteca");
    suspeitosInserirOuAtualizar(tab, "Bob",   "Mordomo, visto no porao");
    suspeitosInserirOuAtualizar(tab, "Clara", "Arquiteta, pegou a chave antiga");

    printf("[Suspeitos] Lista inicial:\n");
    suspeitosListar(tab);

    const char* d = suspeitosBuscar(tab, "Bob");
    printf("[Suspeitos] Buscar 'Bob': %s\n", d ? d : "(nao encontrado)");

    suspeitosInserirOuAtualizar(tab, "Alice", "Atualizado: entrevistou o detetive");
    printf("[Suspeitos] Depois de atualizar 'Alice':\n");
    suspeitosListar(tab);

    suspeitosRemover(tab, "Clara");
    printf("[Suspeitos] Depois de remover 'Clara':\n");
    suspeitosListar(tab);

    suspeitosDestruir(tab);
}

static void executarModoSuspeitosInterativo() {
    TabelaSuspeitos* tab = suspeitosCriar(32);
    printf("\n=== Modo Suspeitos (Hash) ===\n");
    printf("Comandos: a=adicionar/atualizar, b=buscar, r=remover, l=listar, q=sair\n");
    for (;;) {
        printf("\nDigite comando (a/b/r/l/q): ");
        char cmd;
        if (scanf(" %c", &cmd) != 1) {
            printf("Entrada invalida. Tente novamente.\n");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        if (cmd == 'q') {
            printf("Saindo do modo suspeitos...\n");
            break;
        } else if (cmd == 'l') {
            printf("\n[Suspeitos] Lista:\n");
            suspeitosListar(tab);
        } else if (cmd == 'b') {
            char nome[128];
            printf("Nome para buscar: ");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            if (!fgets(nome, sizeof(nome), stdin)) { printf("Falha ao ler nome.\n"); continue; }
            size_t n = strlen(nome); if (n && nome[n-1] == '\n') nome[n-1] = '\0';
            const char* d = suspeitosBuscar(tab, nome);
            if (d) printf("Encontrado: %s -> %s\n", nome, d);
            else printf("'%s' nao encontrado.\n", nome);
        } else if (cmd == 'r') {
            char nome[128];
            printf("Nome para remover: ");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            if (!fgets(nome, sizeof(nome), stdin)) { printf("Falha ao ler nome.\n"); continue; }
            size_t n = strlen(nome); if (n && nome[n-1] == '\n') nome[n-1] = '\0';
            int ok = suspeitosRemover(tab, nome);
            if (ok) printf("'%s' removido.\n", nome);
            else printf("'%s' nao encontrado.\n", nome);
        } else if (cmd == 'a') {
            char nome[128];
            char desc[256];
            printf("Nome do suspeito: ");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            if (!fgets(nome, sizeof(nome), stdin)) { printf("Falha ao ler nome.\n"); continue; }
            size_t n = strlen(nome); if (n && nome[n-1] == '\n') nome[n-1] = '\0';
            printf("Descricao (ate 255 caracteres): ");
            if (!fgets(desc, sizeof(desc), stdin)) { printf("Falha ao ler descricao.\n"); continue; }
            size_t m = strlen(desc); if (m && desc[m-1] == '\n') desc[m-1] = '\0';
            int novo = suspeitosInserirOuAtualizar(tab, nome, desc);
            printf("%s '%s'.\n", novo ? "Adicionado" : "Atualizado", nome);
        } else {
            printf("Comando '%c' desconhecido. Use a, b, r, l ou q.\n", cmd);
        }
    }
    suspeitosDestruir(tab);
}

int main(int argc, char** argv) {
    // Ajuda
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        imprimirAjuda();
        return 0;
    }

    // Menu unificado quando sem argumentos
    if (argc == 1) {
        for (;;) {
            printf("\n=== Detective Quest ===\n");
            printf("Dica: use -h/--help para ver todos os comandos\n");
            printf("1) Salas (interativo)\n");
            printf("2) Salas (demo - script)\n");
            printf("3) Pistas (interativo - BST)\n");
            printf("4) Pistas (demo - BST)\n");
            printf("5) Suspeitos (interativo - Hash)\n");
            printf("6) Suspeitos (demo - Hash)\n");
            printf("0) Sair\n");
            printf("Escolha: ");
            int opcao;
            if (scanf(" %d", &opcao) != 1) {
                printf("Entrada invalida.\n");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
                continue;
            }
            if (opcao == 0) { printf("Saindo...\n"); return 0; }
            if (opcao == 1) {
                executarModoSalasInterativo();
            } else if (opcao == 2) {
                char script[128];
                printf("Script demo (ex.: eed): ");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
                if (!fgets(script, sizeof(script), stdin)) { printf("Falha ao ler script.\n"); continue; }
                size_t n = strlen(script); if (n && script[n-1] == '\n') script[n-1] = '\0';
                executarModoSalasDemoScript(script);
            } else if (opcao == 3) {
                executarModoPistasInterativo();
            } else if (opcao == 4) {
                executarModoPistasDemo();
            } else if (opcao == 5) {
                executarModoSuspeitosInterativo();
            } else if (opcao == 6) {
                executarModoSuspeitosDemo();
            } else {
                printf("Opcao desconhecida.\n");
            }
        }
    }

    // Alias: -salas (interativo)
    if (argc >= 2 && strcmp(argv[1], "-salas") == 0) {
        executarModoSalasInterativo();
        return 0;
    }

    // Alias: -salas-demo [script]
    if (argc >= 2 && strcmp(argv[1], "-salas-demo") == 0) {
        if (argc >= 3) executarModoSalasDemoScript(argv[2]);
        else {
            char script[128];
            printf("Script demo (ex.: eed): ");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            if (!fgets(script, sizeof(script), stdin)) { printf("Falha ao ler script.\n"); return 1; }
            size_t n = strlen(script); if (n && script[n-1] == '\n') script[n-1] = '\0';
            executarModoSalasDemoScript(script);
        }
        return 0;
    }

    // Modo demo de suspeitos (Hash)
    if (argc >= 2 && strcmp(argv[1], "-suspeitos-demo") == 0) {
        executarModoSuspeitosDemo();
        return 0;
    }

    // Modo interativo de suspeitos
    if (argc >= 2 && strcmp(argv[1], "-suspeitos") == 0) {
        executarModoSuspeitosInterativo();
        return 0;
    }

    // Modo demo de pistas (BST)
    if (argc >= 2 && strcmp(argv[1], "-pistas-demo") == 0) {
        executarModoPistasDemo();
        return 0;
    }

    // Modo interativo de pistas
    if (argc >= 2 && strcmp(argv[1], "-pistas") == 0) {
        executarModoPistasInterativo();
        return 0;
    }

    // Alias para compatibilidade: -demo <script> (Salas - demo)
    if (argc >= 3 && strcmp(argv[1], "-demo") == 0) {
        executarModoSalasDemoScript(argv[2]);
        return 0;
    }

    // Padrao: Salas (interativo)
    executarModoSalasInterativo();
    return 0;
}