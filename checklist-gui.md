# Checklist da Interface Gráfica (UI) — Detective Quest

Este checklist orienta a criação da interface gráfica do Detective Quest, desde a prototipagem em Figma até a implementação em C (Windows), garantindo boa UX, acessibilidade e integração com os módulos existentes (salas, pistas, suspeitos).

## 1) Objetivo e Escopo
- [ ] Definir escopo da UI: Menu principal, Salas (mapa e navegação), Pistas (listagem/busca/adição), Suspeitos (listagem/busca/adição/remoção), Ajuda/Atalhos
- [ ] Plataforma alvo inicial: Windows (DPI-aware)
- [ ] Critérios de sucesso: performance fluida, navegação por teclado, mensagens claras, zero vazamentos de memória

## 2) Prototipagem em Figma (Design System)
- [ ] Criar arquivo Figma “Detective Quest UI” com páginas: Foundations, Components, Screens, Flows
- [ ] Foundations (Design Tokens): cores, tipografia, espaçamento, raios, estados (hover/active/disabled), modo claro/escuro (opcional)
- [ ] Componentes: Botões, Inputs, Listas, Barra de Título, Tabs, Modais, Toasts, Tooltip, Painel lateral
- [ ] Padrões por tela:
  - [ ] Menu Principal: entradas (Salas, Pistas, Suspeitos, Ajuda), atalhos
  - [ ] Salas: mapa em árvore, destaque do nó atual, trilha de navegação (e/d/s/r)
  - [ ] Pistas: lista em ordem, campo de busca, formulário de adição/atualização
  - [ ] Suspeitos: listagem com contadores/associações, busca, adicionar/atualizar, remover
- [ ] Fluxos e Interações: navegação entre telas, estados vazios, erros, confirmações
- [ ] Exportação de assets: ícones e ilustrações em SVG (nomenclatura semanticamente clara; pasta `assets/svg/`)

## 3) Tecnologia e Arquitetura
- [x] Escolher biblioteca gráfica (C): Raylib (decisão registrada)
- [ ] Estrutura de projeto: `src/ui/` separado dos módulos atuais; roteador de telas; loop de eventos exclusivo
- [ ] Integração com lógica existente: adaptadores para `salas`, `pistas`, `suspeitos` (funções de render e handlers de evento)
- [ ] Gerenciamento de estado da UI: tela atual, estado de seleção, formulários, mensagens de feedback
- [ ] Acessibilidade: contraste mínimo, tamanhos de fonte, navegação por teclado, foco visível

## 4) Implementação Incremental (Sprints)
- [ ] Sprint 1: Janela inicial, loop de eventos, Menu Principal, atalhos (ex.: F1 Ajuda)
- [ ] Sprint 2: Tela de Salas — renderização da árvore, destaque do nó, comandos `e/d/s/r`, trilha visual
- [ ] Sprint 3: Tela de Pistas — lista ordenada, busca, adicionar/atualizar, mensagens de sucesso/erro
- [ ] Sprint 4: Tela de Suspeitos — listagem, buscar, adicionar/atualizar, remover, associações
- [ ] Sprint 5: Polimento — estados vazios, tooltips, transições leves, ajuda contextual
- [ ] Sprint 6: Configurações — fonte/tamanho, tema claro/escuro (opcional), redefinir atalhos

## 5) Build e Entrega
- [ ] Atualizar Makefile: alvos `gui` e `run-gui` com links para a biblioteca escolhida
- [ ] Pasta de assets: `assets/svg/` (somente SVG), `assets/fonts/` (se necessário)
- [ ] Binário: `detective-quest-gui.exe` (modo GUI) e manter `detective-quest.exe` (modo terminal)
- [ ] Pacote de release: incluir binário GUI e assets (zip separado `dist/detective-quest-gui-vX.Y.Z.zip`)

## 6) Testes e QA
- [ ] Smoke tests por tela: abrir/fechar, navegação, atalhos, feedback
- [ ] Testes de evento: validação de entradas (pistas/suspeitos), erros tratados, mensagens claras
- [ ] Perf & memória: FPS mínimo alvo (60), checagem de vazamentos, tempo de resposta de eventos
- [ ] DPI e resoluções: validar em 100%, 125%, 150%; janelas redimensionáveis (se aplicável)

## 7) Documentação
- [x] README: seção “Interface Gráfica (GUI)” com planejamento e referências
- [x] Docs: `docs/06-ui-ux.md` (guidelines e componentes), `docs/07-arquitetura-ui.md` (Raylib e build)
- [ ] Changelog e Decision Log: registrar escolhas (biblioteca, padrões de navegação)