# Manobras Radicais em Radlândia


Este projeto implementa um algoritmo para determinar a sequência mais radical de manobras que Diná pode realizar nas pistas de Radlândia. O objetivo é maximizar a pontuação radical com base no sistema de pontuação exclusivo de Radlândia.


## Problema


A tarefa envolve encontrar a sequência ideal de manobras de skate em várias seções de uma pista. Cada seção possui um fator de bonificação e um tempo de travessia, e cada manobra tem uma pontuação base e um tempo necessário para ser executada. O desafio é calcular a sequência mais radical de manobras que pode ser realizada nas seções, levando em conta a pontuação reduzida quando a mesma manobra é realizada em seções consecutivas.


## Entrada e Saída


### Entrada


Cada caso de teste é composto por várias linhas:


1. A primeira linha contém dois inteiros, `N` e `K`, que representam, respectivamente, o número de seções de manobra da pista e o número de manobras catalogadas em Radlândia. É garantido que `1 ≤ N ≤ 100` e `1 ≤ K ≤ 10`.
2. Cada uma das `N` linhas seguintes descreve uma seção da pista com dois inteiros: `ci`, que representa o fator de bonificação da seção (`1 ≤ ci ≤ 100`), e `li`, que representa o tempo de travessia da seção (`1 ≤ li ≤ 10^6`).
3. As próximas `K` linhas descrevem as manobras, onde cada linha contém dois inteiros: `pj`, que é a pontuação base da manobra (`−10^6 ≤ pj ≤ 10^6`), e `tj`, que é o tempo necessário para executar a manobra (`1 ≤ tj ≤ 10^6`). As manobras são numeradas de `1` a `K` na ordem em que são dadas na entrada.


### Saída


O programa deve calcular e exibir a pontuação mais alta possível que Diná pode alcançar juntamente com a sequência de manobras usada nas seções da pista.


## Compilação e Execução


### Compilação


Para compilar o projeto, execute o comando `g++ -std=c++17 main.cpp -o radlandia` na pasta raiz do projeto. Isso irá gerar o binário `radlandia`.



