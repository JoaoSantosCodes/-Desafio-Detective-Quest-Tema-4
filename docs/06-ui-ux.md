# Interface Gráfica (GUI) — UI/UX Guidelines

Este documento define padrões de design e UX para a interface gráfica do Detective Quest.

## Foundations (Design Tokens)
- Tipografia: Inter/Noto Sans (fallback system), tamanhos 12/14/16/20/24 px
- Espaçamento: escala 4/8/12/16/24 px
- Cores (tema claro inicial):
  - Primária: #2D6CDF
  - Texto: #1A1A1A
  - Plano de fundo: #FFFFFF
  - Superfícies: #F5F7FA
  - Borda/Divisor: #E3E7ED
  - Danger: #D92D20
  - Sucesso: #12B76A
- Raios de canto: 4/8 px
- Estados: hover, active, disabled, focus (outline visível)

## Componentes
- Botões: default, primary, danger, disabled
- Inputs: texto, com estados de validação e mensagens
- Listas/Tabelas: linhas clicáveis, estado vazio, loading
- Tabs: troca de telas (Salas, Pistas, Suspeitos)
- Modais/Diálogos: confirmação de remoção (Suspeitos)
- Toasts: feedback de ações (adicionar/atualizar/remover)
- Tooltips: ajuda contextual
- Painel lateral: navegação adicional, trilha de salas

## Padrões por Tela
- Menu Principal: botões grandes e acessíveis, atalhos de teclado (S, P, U, H)
- Salas: renderização do mapa (árvore), destaque do nó atual, trilha visual, comandos `e/d/s/r`
- Pistas: lista em ordem, campo de busca, formulário de adição/atualização, validações
- Suspeitos: listagem, busca, adicionar/atualizar, remover com confirmação

## Acessibilidade
- Contraste AA mínimo, foco visível, navegação por teclado
- Tamanhos de alvo de clique ≥ 40x40 px
- Mensagens sem ambiguidade; evitar jargões

## Interações
- Teclado: ESC fecha modais, Enter confirma, Tab navega
- Mouse: hover indica clicável; feedback imediato em ações
- Erros: mensagens claras com sugestão de correção

## Exportação de Assets
- Ícones/ilustrações em SVG
- Nomeação semântica: `icon-salas.svg`, `icon-pistas.svg`, `icon-suspeitos.svg`
- Pasta: `assets/svg/`

## Medidas de Qualidade
- FPS estável (meta 60)
- Sem vazamentos de memória
- Respostas de eventos < 16ms em ações comuns