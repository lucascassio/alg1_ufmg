# Grafos Temporais

Este projeto implementa um conjunto de algoritmos para trabalhar com grafos temporais. O objetivo é resolver problemas relacionados à conectividade, custos de construção e anos de construção de arestas em um grafo.

## Problema

Esse trabalho aborda um problema de determinação de conectividade e custos em grafos temporais.

### Descrição do Problema

Dado um grafo planar com vértices e arestas, é necessário calcular:

1. O tempo mínimo necessário para chegar a cada vértice a partir de um vértice inicial.
2. O primeiro ano em que as distâncias são mutuamente realizáveis.
3. O primeiro ano a partir do qual é possível alcançar qualquer vértice do grafo.
4. O menor custo necessário para conectar todo o grafo.

## Entrada e Saída

### Entrada

Cada caso de teste é composto por várias linhas:

1. A primeira linha contém dois inteiros, `N` e `M`, que representam, respectivamente, o número de vértices e arestas do grafo de entrada `G`. É garantido que `G` é conexo, que `1 ≤ N, M ≤ 10^6`.
2. Para cada aresta, são fornecidos os seguintes valores:
    - `u`, `v`: vértices que a aresta conecta(`u != v`).
    - `a`: ano de construção da aresta(`1 ≤ a ≤ 10ˆ8`).
    - `l`: tempo de travessia da aresta(`1 ≤ a ≤ 10ˆ5`).
    - `c`: custo de construção da aresta(`1 ≤ a ≤ 10ˆ5`).

### Saída

1. O tempo mínimo necessário para chegar a cada vértice a partir do vértice inicial.
2. O primeiro ano em que as distâncias são mutuamente realizáveis.
3. O primeiro ano a partir do qual é possível alcançar qualquer vértice do grafo.
4. O menor custo necessário para conectar todo o grafo.

## Compilação e Execução

### Compilação

Para compilar o projeto, execute o comando `g++ -std=c++17 main.cpp -o grafos_temporais` na pasta raiz do projeto. Isso irá gerar o binário `grafos_temporais`.
