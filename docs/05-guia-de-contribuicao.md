# Guia de Contribuição

Boas práticas para manter consistência e qualidade no projeto.

## Estilo e Compilação
- Padrão: C11 (-std=c11) com -Wall -Wextra -Wpedantic.
- Evite warnings; trate-os como potenciais problemas.
- Mensagens em ASCII (sem acentuação) para compatibilidade no Windows/console.

## Nomenclatura e Terminologia
- Manter a terminologia padronizada: "Trilha" (não "Trilho").
- Funções e variáveis claras e coesas ao módulo.

## Gerenciamento de Memória
- Alocou? Então libere: destruirSalas, pistaDestruir, suspeitosDestruir.
- Evitar vazamentos; prefira retornos únicos com limpeza de recursos.

## Commits e Revisões
- Commits pequenos e descritivos (imperativo curto).
- Atualize docs/checklist quando alterar comportamentos ou interfaces públicas.

## Testes
- Ao alterar Pistas ou Suspeitos, atualize/adicione testes em tests/.
- Execução rápida dos testes: ver docs/04-build-e-execucao.md.