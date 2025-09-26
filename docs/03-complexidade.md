# Complexidade

Análise de complexidade temporal e espacial das operações principais.

## Salas (Árvore Binária)
- Exploração/navegação: O(h) por caminho tomado, onde h é a altura da árvore.
- Impressão da trilha: O(k), onde k é o tamanho da trilha registrada.
- Espaço: O(n) para n salas.

## Pistas (BST)
- Inserção: O(h) (média) onde h é a altura da BST; pior caso O(n) se desbalanceada.
- Busca: O(h) (média), pior O(n).
- Listagem in-order: O(n).
- Espaço: O(n).

## Suspeitos (Hash)
- Inserção/Busca/Remoção: O(1) amortizado (média), O(n) no pior caso por colisões extremas.
- Listagem: O(n).
- Espaço: O(n) para elementos + overhead de buckets.

## Observações
- Em cenários reais, considerar balanceamento (AVL/Red-Black) para a BST de pistas.
- Para a tabela hash, monitorar fator de carga e redimensionar quando necessário.