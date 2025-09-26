# Visão Geral

Índice rápido
- [Objetivos](#objetivos)
- [Arquitetura (alto nível)](#arquitetura-alto-nível)
- [Fluxo de execução](#fluxo-de-execução)
- [Plataformas e build](#plataformas-e-build)
- [Testes](#testes)

Este documento apresenta uma visão geral do projeto Detective Quest, seus objetivos, arquitetura e principais módulos.

## Objetivos
- Exercitar estruturas de dados clássicas em C por meio de um jogo investigativo simples.
- Demonstrar boas práticas de organização modular, testes e UX de terminal (Windows compatível).

## Arquitetura (alto nível)

### Diagrama ASCII dos módulos
```
+---------------------------+
|           main.c          |
|  - menu/flags/roteamento  |
+-------------+-------------+
              | usa
              v
   +----------+----------+
   |        salas.*      |  Árvore binária (navegação)
   +----------+----------+
              | chama (demonstr.)
              v
   +----------+----------+
   |        pistas.*     |  BST (pistas)
   +----------+----------+
              | consulta/gera dados
              v
   +----------+----------+
   |      suspeitos.*    |  Hash (suspeitos)
   +---------------------+

Outros:
- include/* contém as APIs públicas (headers)
- tests/* compila e roda testes focados em pistas e suspeitos
```
- Executável único: main.c orquestra os modos e o menu unificado.
- Módulos de domínio:
  - Salas (Nível Novato): árvore binária para navegação em uma mansão.
  - Pistas (Nível Aventureiro): árvore binária de busca (BST) para armazenar pistas.
  - Suspeitos (Nível Mestre): tabela hash para cadastro e consulta de suspeitos.
- Headers públicos em include/ e implementações em src/.
- Testes focados em Pistas e Suspeitos na pasta tests/.

Estrutura de pastas resumida:
- src/ → main.c, salas.c, pistas.c, suspeitos.c
- include/ → salas.h, pistas.h, suspeitos.h
- tests/ → test_pistas.c, test_suspeitos.c
- docs/ → documentação técnica (este diretório)

## Fluxo de execução
- Sem argumentos: menu unificado.
- Flags diretas e ajuda:
  - -h/--help: lista de comandos e exemplos.
  - Salas: -salas (interativo), -salas-demo <script> (ou alias -demo <script>)
  - Pistas: -pistas (interativo), -pistas-demo
  - Suspeitos: -suspeitos (interativo), -suspeitos-demo

## Plataformas e build
- Desenvolvimento e testes em Windows (PowerShell) com GCC/MinGW.
- Compilação direta com gcc e opções de warning ativadas.
- Veja detalhes em docs/04-build-e-execucao.md.

## Testes
- Testes automatizados para Pistas (BST) e Suspeitos (Hash) em tests/.
- Instruções de compilação/execução dos testes em docs/04-build-e-execucao.md.