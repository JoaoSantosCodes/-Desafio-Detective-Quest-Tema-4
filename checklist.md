# Checklist do Projeto: Detective Quest

Este checklist acompanha o progresso, qualidade de código e próximos passos do projeto em C.

## 1) Estado atual (validado)
- [x] Estrutura modular: `src/`, `include/` e `tests/` criados
- [x] Sistema de build: `Makefile` (GCC/MinGW) com `-Wall -Wextra -Wpedantic -std=c11`
- [x] Nível Novato implementado (árvore binária de salas)
  - Funções: `criarSala`, `conectarSalas`, `explorarSalas`, `explorarSalasDemo`, `destruirSalas`
  - Trilha do caminho (registro e impressão), opções `e/d/s` e extras `p/h`
  - Reinício em folha com `r/s` (mensagem usa o nome da raiz dinamicamente)
  - Mensagens padronizadas em ASCII para compatibilidade no Windows
- [x] Nível Aventureiro implementado e validado (BST de pistas) — modos `-pistas-demo` e `-pistas`
- [x] Nível Mestre implementado e integrado (Hash de suspeitos) — modos `-suspeitos-demo` e `-suspeitos`
- [x] Compilação e execução validadas (build limpo, sem warnings)
- [x] Testes automatizados (Pistas e Suspeitos) — compilados e executados com sucesso
- [x] Documentação técnica inicial em `docs/` (visão geral, estruturas, complexidade, build/execução, guia)
- [x] Verificações finais de release executadas (ajuda `-h`, smoke tests Salas/Pistas/Suspeitos em modo demo, testes automatizados OK)
- [x] Tag de versão criada: `v1.0.0` (Git)
- [x] Pacote final `.zip` gerado: `dist/detective-quest-v1.0.0.zip`

## 2) Estrutura atual de pastas
- `src/` — `main.c`, `salas.c`, `pistas.c`, `suspeitos.c`
- `include/` — `salas.h`, `pistas.h`, `suspeitos.h`
- `Makefile` — alvo principal para build com GCC/MinGW
- `.gitignore` — criado
- `docs/` — esqueleto criado (visao geral, estruturas de dados, complexidade, build/execucao, guia de contribuicao) e conteúdos iniciais concluídos
- `examples/` — arquivo `algoritmos_avancados.c` movido para exemplos (não faz parte do build principal)
- `dist/` — pacote `detective-quest-v1.0.0.zip`

## 3) Ações concluídas
- [x] Implementação do módulo `salas` (Nível Novato):
  - Criação e conexão de salas como nós de árvore binária
  - Exploração interativa com ajuda (`h`) e trilha (`p`)
  - Modo demonstração via `-demo <script>`
  - Reinício ao atingir folha (r/s)
- [x] Refinamentos de UX e robustez:
  - Mensagens sem acentuação e prompts claros
  - Exibição dos nomes das salas filhas
  - Tratamento de entradas inválidas e limpeza de buffer
  - Aviso no modo demo para comandos desconhecidos
- [x] Implementação do módulo `pistas` (Nível Aventureiro - BST):
  - API: `pistaInserir`, `pistaBuscar`, `pistaImprimirInOrder`, `pistaDestruir`
  - Modos no executável: `-pistas-demo` (exercita inserção, busca e atualização) e `-pistas` (interativo: a=adicionar, b=buscar, l=listar, q=sair)
  - Build integrado (`src/pistas.c` e `include/pistas.h`)
- [x] Implementação e integração do módulo `suspeitos` (Nível Mestre - Hash):
  - API: `suspeitosCriar`, `suspeitosInserirOuAtualizar`, `suspeitosBuscar`, `suspeitosRemover`, `suspeitosListar`, `suspeitosDestruir`
  - Modos no executável: `-suspeitos-demo` e `-suspeitos` (interativo: a=adicionar/atualizar, b=buscar, r=remover, l=listar, q=sair)
  - Build integrado (`src/suspeitos.c` e `include/suspeitos.h`)
- [x] Integração no `main.c` dos modos de Pistas e Suspeitos (demo e interativo)
- [x] Unificação do menu principal no `main.c` (quando sem argumentos), mantendo flags diretas
- [x] Extração da construção da mansão para função auxiliar `construirMansaoBasica()`
- [x] Criação da pasta `tests/` com testes automatizados para Pistas e Suspeitos; compilação e execução bem-sucedidas
- [x] `.gitignore` criado para ignorar artefatos de build e temporários
- [x] Suporte a ajuda rápida `-h/--help` com listagem de comandos e exemplos
- [x] Padronização de terminologia: uso consistente de "Trilha" no módulo de Salas
- [x] Comentários explicativos adicionados nas funções auxiliares do `main.c`
- [x] Documentos `docs/01-05` atualizados com índice/diagrama e APIs públicas
- [x] Verificação final: build com flags validado, ajuda `-h` verificada, smoke tests dos modos demo (Salas/Pistas/Suspeitos) e testes automatizados executados com sucesso
- [x] Publicação no GitHub: branch `main` com origem `origin/main` e push concluído
- [x] Tag `v1.0.0` enviada para o GitHub

## 4) Pendências e próximos passos
- [ ] (Opcional) Publicar a Release v1.0.0 no GitHub (anexar `dist/detective-quest-v1.0.0.zip`)
- [ ] (Opcional) Adicionar diagrama(s) complementares e exemplos detalhados por módulo nos docs
- [ ] (Opcional) Refatorar `main.c` em submódulos se o arquivo crescer muito
- [ ] (Opcional) Integrar `explorarSalasComExtras` ao fluxo das salas quando houver comandos adicionais globais
- [ ] (Opcional) Adicionar licença (MIT) ao repositório

## 5) Como compilar e executar (rápido)
- Compilar com GCC (direto):
  - `gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude src/main.c src/salas.c src/pistas.c src/suspeitos.c -o detective-quest.exe`
- Executar menu (sem argumentos): `./detective-quest.exe`
- Ajuda rápida: `./detective-quest.exe -h` ou `./detective-quest.exe --help`
- Executar Salas (interativo): `./detective-quest.exe -salas`
- Executar Salas (demo): `./detective-quest.exe -salas-demo eed` (alias: `-demo eed`)
- Executar Pistas (demo): `./detective-quest.exe -pistas-demo`
- Executar Pistas (interativo): `./detective-quest.exe -pistas`
- Executar Suspeitos (demo): `./detective-quest.exe -suspeitos-demo`
- Executar Suspeitos (interativo): `./detective-quest.exe -suspeitos`
- Compilar testes (sem make):
  - `gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude tests/test_pistas.c src/pistas.c -o tests/test_pistas.exe`
  - `gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude tests/test_suspeitos.c src/suspeitos.c -o tests/test_suspeitos.exe`
- Executar testes: `tests\test_pistas.exe` e `tests\test_suspeitos.exe`

## 6) Histórico do processo (resumo)
- Revisão do escopo e confirmação do Nível Novato concluído (salas, navegação, trilha, demo)
- Criação do módulo de Pistas (BST), inclusão no build e validação via `-pistas-demo` e `-pistas`
- Criação do módulo de Suspeitos (tabela hash), inclusão no build e integração no `main.c` com `-suspeitos-demo` e `-suspeitos`
- Atualização de `salas.h` para suportar comandos extras via handler (`explorarSalasComExtras`)
- Recompilações e execuções bem-sucedidas no Windows (PowerShell) com GCC/MinGW
- Inclusão do `-h/--help` e melhora de UX no menu principal
- Padronização de terminologia no módulo de Salas ("Trilha")
- Comentários explicativos adicionados no `main.c`
- Criação e preenchimento inicial da documentação técnica em `docs/`
- Execução das verificações finais de release (ajuda `-h`, smoke tests de modos demo, testes automatizados)
- Criação e push da tag `v1.0.0`; geração do pacote `.zip` em `dist/`

Mantenha este checklist atualizado conforme concluímos cada etapa.