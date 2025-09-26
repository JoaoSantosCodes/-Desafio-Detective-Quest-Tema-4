# Interface Gráfica (GUI) — UI/UX Guidelines

Este documento define padrões de design e UX para a interface gráfica do Detective Quest.

## Foundations (Design Tokens)
- Tipografia: Inter (fallback Segoe UI), tamanhos 14/16/20/24 px
- Espaçamento: escala 4/8/12/16/24 px
- Cores (tema escuro inicial):
  - Background: #0F1115
  - Surface: #151922
  - Text-Primary: #E6E8EE
  - Text-Secondary: #A6ADBB
  - Accent (primary): #3B82F6
  - Border/Divider: #262C36
  - Success: #22C55E
  - Danger: #EF4444
  - Focus/Outline: #93C5FD
- Raios de canto: 6/8 px
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
- Pacote de ícones: Feather (stroke 2 px, grid 24 px, stroke="currentColor")
- Nomeação semântica: `icon-salas.svg`, `icon-pistas.svg`, `icon-suspeitos.svg`
- Pasta: `assets/svg/`

## Medidas de Qualidade
- FPS estável (meta 60)
- Sem vazamentos de memória
- Respostas de eventos < 16ms em ações comuns


## Instalação da Fonte Inter (Desktop GUI)
- Local do arquivo: coloque `assets/fonts/Inter-Regular.ttf` no repositório (não versionado opcionalmente) ou no sistema.
- Comportamento: a GUI carrega automaticamente `assets/fonts/Inter-Regular.ttf` se existir; caso contrário usa a fonte padrão do sistema (fallback).
- Licença: Inter é licenciada sob SIL Open Font License 1.1; mantenha referência ao autor e à licença ao distribuir. <mcreference link="https://github.com/rsms/inter/blob/master/LICENSE.txt" index="1">1</mcreference> <mcreference link="https://openfontlicense.org/" index="2">2</mcreference>
- Alternativas: é possível usar a distribuição oficial (CDN) para web, mas para a GUI desktop use o arquivo TTF local. <mcreference link="https://github.com/rsms/inter" index="3">3</mcreference> <mcreference link="https://rsms.me/inter/" index="5">5</mcreference>