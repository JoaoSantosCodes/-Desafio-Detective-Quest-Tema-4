# Arquitetura da Interface Gráfica (GUI)

Este documento apresenta a organização técnica da UI e sua integração com os módulos existentes.

## Estrutura de Pastas
- `src/ui/` — renderizadores e roteador
- `assets/svg/` — ícones/ilustrações (SVG)
- `assets/fonts/` — tipografias (se necessário)

## Roteamento de Telas
- Telas: `Menu`, `Salas`, `Pistas`, `Suspeitos`, `Ajuda`
- Estado global: `telaAtual`, dados de seleção, mensagens
- Transições simples; preservar estado entre telas quando aplicável

## Integração com Módulos
- Adaptadores:
  - Salas → funções de render e event handling ligadas a `salas.h`
  - Pistas → CRUD e listagem via `pistas.h`
  - Suspeitos → CRUD e associações via `suspeitos.h`

## Loop de Eventos
- Separado do modo terminal; exclusividade do binário GUI
- Processamento de teclado/mouse; timers para animações leves

## Decisão de Biblioteca
- Biblioteca escolhida: Raylib
- Motivos: onboarding simples no Windows, API direta para desenho e eventos, fácil empacotamento

## Makefile
- Alvos: `gui`, `run-gui`
- Flags: `-Wall -Wextra -Wpedantic -std=c11`
- Linkagem Raylib (Windows, exemplo MinGW): `-lraylib -lopengl32 -lgdi32 -lwinmm`
- Binário esperado: `build/detective-quest-gui.exe`

## Testes e Qualidade
- Smoke tests por tela
- Validação de entradas; mensagens de erro claras
- Perf: FPS, uso de memória, tempo de resposta

## Estrutura de Componentes (mínima)
- Button: estados hover/press/disabled
- Input: foco, cursor, validação
- List: itens com seleção
- Tab: navegação entre telas
- Modal/Toast/Tooltip: padrões de feedback

## Roadmap Técnico
- v1.1.0: Menu + Salas + Pistas + Suspeitos (GUI) em Raylib
- v1.2.0: Tema claro/escuro, configurações, polimento