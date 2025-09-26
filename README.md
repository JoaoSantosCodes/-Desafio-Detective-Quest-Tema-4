# Desafio Detective Quest - Estruturas de Dados e Investigação

Bem-vindo ao desafio **Detective Quest**! Neste jogo de mistério, o jogador explora uma mansão, encontra pistas e relaciona evidências a suspeitos. Para tornar isso possível, você atuará como programador responsável por implementar toda a lógica de estruturas de dados do jogo.

A **Enigma Studios**, especializada em jogos educacionais, contratou você para criar a base de funcionamento da mansão e das investigações usando **árvore binária**, **árvore de busca** e **tabela hash**.

O desafio está dividido em três níveis: **Novato**, **Aventureiro** e **Mestre**, com cada nível adicionando mais complexidade ao anterior.  
**Você deve escolher qual desafio deseja realizar.**

🚨 **Atenção:** O nível Novato foca apenas na árvore binária de navegação de cômodos. Ideal para começar com estruturas básicas.

---

## 🎮 Nível Novato: Mapa da Mansão com Árvore Binária

No nível Novato, você criará a árvore binária que representa o **mapa da mansão**. Cada sala é um nó, e o jogador poderá explorar os caminhos à esquerda ou à direita, começando pelo "Hall de Entrada".

🚩 **Objetivo:** Criar um programa em C que:

- Construa dinamicamente uma árvore binária representando os cômodos.
- Permita que o jogador explore a mansão interativamente (esquerda, direita).
- Exiba o nome de cada cômodo visitado até alcançar um nó-folha (fim do caminho).

⚙️ **Funcionalidades do Sistema:**

- A árvore é criada automaticamente via `main()` com `criarSala()`.
- O jogador interage com o jogo usando `explorarSalas()`, escolhendo entre:
  - `e` → ir para a esquerda
  - `d` → ir para a direita
  - `s` → sair da exploração

📥 **Entrada** e 📤 **Saída de Dados:**

*   O usuário navega pela mansão com base nas opções exibidas no terminal.
*   O programa mostra o nome da sala visitada a cada passo.

**Simplificações para o Nível Novato:**

*   Apenas árvore binária (sem inserção ou remoção durante o jogo).
*   A árvore é montada estaticamente via código.
*   Estrutura imutável em tempo de execução.

---

## 🛡️ Nível Aventureiro: Organização de Pistas com Árvore de Busca

No nível Aventureiro, você expandirá o jogo incluindo uma **árvore de busca (BST)** para armazenar pistas encontradas.

🆕 **Diferença em relação ao Nível Novato:**

*   Agora, ao visitar certos cômodos, o jogador encontrará pistas.
*   Essas pistas são armazenadas ordenadamente em uma BST.

⚙️ **Funcionalidades do Sistema:**

*   Implementar inserção e busca de strings (pistas) na árvore de busca.
*   Permitir que o jogador visualize todas as pistas em ordem alfabética.
*   Adicionar novas pistas automaticamente ao visitar salas específicas.

📥 **Entrada** e 📤 **Saída de Dados:**

*   As pistas são cadastradas via `inserir()` ao serem encontradas.
*   O programa pode listar todas as pistas com `emOrdem()`.

**Simplificações para o Nível Intermediário:**

*   Nenhuma remoção é necessária.
*   Não é necessário balancear a árvore.
*   As pistas são strings simples (nomes curtos).

---

## 🏆 Nível Mestre: Suspeitos e Solução com Tabela Hash

No nível Mestre, você implementará a **tabela hash** para vincular pistas a **suspeitos**. Agora o jogador pode consultar quem está associado a cada pista e deduzir o culpado com base nas evidências coletadas.

🆕 **Diferença em relação ao Nível Aventureiro:**

*   Cada pista armazenada na BST será relacionada a um suspeito via tabela hash.
*   Ao final, o jogador poderá ver qual suspeito está mais associado às pistas e decidir quem é o culpado.

⚙️ **Funcionalidades do Sistema:**

*   Implementar uma tabela hash (array de ponteiros ou lista encadeada).
*   Função de inserção que relaciona pista → suspeito.
*   Permitir consulta de todas as pistas relacionadas a cada suspeito.
*   Mostrar o “suspeito mais citado” ao final da análise.

📥 **Entrada** e 📤 **Saída de Dados:**

*   As pistas e suspeitos são armazenados via `inserirNaHash(pista, suspeito)`.
*   O programa exibe as associações pista → suspeito.
*   Exibe o suspeito mais citado com base nas pistas armazenadas.

**Observações:**

*   Pode utilizar hashing simples com função de espalhamento baseada em primeiros caracteres ou soma ASCII.
*   O ideal é evitar colisões, mas, se ocorrerem, use encadeamento.

---

## 🏁 Conclusão

Ao concluir qualquer um dos níveis, você terá desenvolvido um sistema de investigação funcional em C, utilizando estruturas fundamentais como árvores e tabelas hash para controlar lógica de jogo.

Boa sorte, e divirta-se programando com **Detective Quest**!

Equipe de Ensino – Enigma Studios

## Documentação
- Visão Geral: [docs/01-visao-geral.md](docs/01-visao-geral.md)
- Estruturas de Dados: [docs/02-estruturas-de-dados.md](docs/02-estruturas-de-dados.md)
- Complexidade: [docs/03-complexidade.md](docs/03-complexidade.md)
- Build e Execução: [docs/04-build-e-execucao.md](docs/04-build-e-execucao.md)
- Guia de Contribuição: [docs/05-guia-de-contribuicao.md](docs/05-guia-de-contribuicao.md)

Dica: se estiver com pressa, comece por "Build e Execução".

## Exemplos
- Pasta: `examples/`
- Conteúdo: `algoritmos_avancados.c` (material didático; não faz parte do build principal)
- Como compilar rapidamente:
  - `gcc -Wall -Wextra -Wpedantic -std=c11 examples/algoritmos_avancados.c -o examples/algoritmos_avancados.exe`
- Observação: mantenha o projeto modular; use este exemplo para estudos e experimentos.

## Release v1.0.0
- Tag criada: `v1.0.0` (Git)
- Pacote de entrega: `dist/detective-quest-v1.0.0.zip`
- Conteúdo do pacote: `src/`, `include/`, `tests/`, `docs/`, `examples/`, `README.md`, `checklist.md`, `Makefile`, `.gitignore`
- Publicar no GitHub (via web):
  1) Acesse "Releases" > "Draft a new release"
  2) Escolha a tag `v1.0.0`
  3) Título: "Release v1.0.0"
  4) Descrição: build limpo (C11 + flags estritas), modos demo/integração validados, testes OK, documentação atualizada
  5) Anexe o arquivo `dist/detective-quest-v1.0.0.zip`
  6) Clique em "Publish release"

## Interface Gráfica (GUI) — Planejamento
- Biblioteca escolhida: Raylib (Windows-friendly, API simples)
- Tema inicial: Escuro (tokens definidos em docs/06-ui-ux.md)
- Tipografia: Inter (fallback Segoe UI)
- Ícones: Feather (SVG, stroke 2px, grid 24px)
- Documentos de referência:
  - UI/UX: [docs/06-ui-ux.md](docs/06-ui-ux.md)
  - Arquitetura da UI: [docs/07-arquitetura-ui.md](docs/07-arquitetura-ui.md)
- Próximos passos: preparar Makefile (`gui`/`run-gui`), criar componentes básicos, iniciar protótipo no Figma.
