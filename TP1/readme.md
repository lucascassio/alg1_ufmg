# Problema

Neste trabalho, trabalharemos com um problema em uma classe de grafos conhecida como grafos planares.

O problema em questão é o seguinte:

Como podemos definir o conjunto de faces de um grafo planar? 

## Por exemplo: 

![image](https://github.com/lucascassio/alg1_ufmg/assets/99884897/622d147f-76b6-4c59-b1cc-4ebe280baba1)

F1, F2 ... F5 são as faces do grafo.

# Entrada e Saída

## Entrada:
Cada caso de teste é composto por várias linhas. A primeira linha contém dois inteiros, N e M, que representam, respectivamente, o número de vértices e arestas do grafo de entrada G. É garantido que G é conexo, que 1 ≤ N, M ≤ 105, e que V (G) = {1, 2, . . . , N}. A i-ésima linha da entrada começacom dois números reais xi, yi, que representam as coordenadas do vértice i no plano cartesiano; é garantido que−104 ≤ xi, yi ≤ 104. Na mesma linha, temos um inteiro positivo di, que representa o grau do vértice i. Ainda na mesma linha, temos diinteiros entre 1 e N, cada um correspondendo a um vizinho de i; é garantido que um vértice não é vizinho de si mesmo.

## Saída:
A primeira linha da saída contém um inteiro F, que deve ser igual ao número de faces deG. As próximas F linhas devem corresponder às F faces de G; cada linha começa com um inteiro Si , que representao tamanho da i-ésima face de G; em seguida, existem si inteiros, representando o circuito que corresponde à bordada face. A ordem das faces não é importante, mas vértices consecutivos na borda da face devem ser adjacentes.

## Por exemplo:

![image](https://github.com/lucascassio/alg1_ufmg/assets/99884897/386ca3df-efb9-40ad-85af-2708a69784a9)


