# Estruturas de Dados

Este documento descreve as estruturas de dados utilizadas e suas responsabilidades.

## Salas (Árvore Binária)
- Estrutura: nós do tipo Sala, cada um com ponteiros para esquerda/direita.
- Uso: navegação por escolhas do usuário (e/d/s), com recursos de ajuda (h) e trilha (p).
- Trilha: registro dos passos tomados; terminologia padronizada como "Trilha".
- Responsabilidades:
  - criarSala, conectarSalas, explorarSalas/ExplorarSalasDemo, destruirSalas.

## Pistas (BST — Binary Search Tree)
- Cada pista possui um ID inteiro (chave) e uma descrição.
- Operações:
  - inserir (pistaInserir), buscar (pistaBuscar), listar in-order (pistaImprimirInOrder), destruir (pistaDestruir).
- Uso:
  - Modo demo (-pistas-demo): insere, busca e atualiza para demonstrar o ciclo.
  - Modo interativo (-pistas): adicionar, buscar, listar, sair.

### APIs públicas (resumo)

Salas
- Tipos: `Sala`
- Principais funções: `criarSala`, `conectarSalas`, `explorarSalas`, `explorarSalasComExtras`, `explorarSalasDemo`, `destruirSalas`.

Pistas
- Tipos: `Pista`
- Principais funções: `pistaInserir`, `pistaBuscar`, `pistaImprimirInOrder`, `pistaDestruir`.

Suspeitos
- Tipos: `Suspeito`, `TabelaSuspeitos`
- Principais funções: `suspeitosCriar`, `suspeitosInserirOuAtualizar`, `suspeitosBuscar`, `suspeitosRemover`, `suspeitosListar`, `suspeitosDestruir`.

## Suspeitos (Tabela Hash)
- Estrutura: vetor de buckets com função de espalhamento para chaves (nomes de suspeitos).
- Operações:
  - criar (suspeitosCriar), inserir/atualizar, buscar, remover, listar, destruir.
- Colisões: resolvidas por encadeamento (lista por bucket).
- Uso:
  - Modo demo (-suspeitos-demo) e modo interativo (-suspeitos).

## Invariantes e Boas Práticas
- Alocação e desalocação simétricas: toda alocação deve ser liberada (destruirSalas, pistaDestruir, suspeitosDestruir).
- Mensagens de terminal sem acentuação para compatibilidade (Windows/console).
- Entradas do usuário validadas e prompts claros no modo interativo.