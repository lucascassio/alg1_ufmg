Lucas Cassio Costa
Belo Horizonte, Minas Gerais Celular: (31) 9 71637470
Email: lccosta2604@gmail.com
GitHub: https://github.com/nicolasvondolinger?tab=repositories LinkedIn: https://www.linkedin.com/in/nicolas-von-dolinger-5a7036207/


Estudo programação desde o segundo semestre de 2022, com foco em desenvolvimento full-stack. Sou graduando em Sistemas de Informação pela UFMG e busco constantemente aprimorar meus conhecimentos na área da computação com projetos autônomos.

Experiências
Gerente de Produto
iJunior
Out 2023 - Atualmente
Como Gerente de Produto, sou responsável pela gestão de todos os outros PO’s da empresa, ter conhecimento sobre o andamento de todos os projetos e fazer a cobrança de pagamentos dos projetos.

Product Owner
iJunior
Jun 2023 - Atualmente
Como Product Owner (PO) na iJunior sou responsável pela gestão de produtos, coordenando a equipe e garantindo a entrega ágil de projetos de desenvolvimento de sites, aplicativos e protótipos para diferentes empresas.

Trainee
iJunior
Mar 2023 - Jun 2023
Como trainee na iJunior, uma empresa júnior da UFMG especializada em desenvolvimento de software, fui treinado na área de produto. Meu objetivo era integrar a equipe responsável pela administração da metodologia SCRUM, visando agilizar a entrega de projetos, incluindo criação de sites, aplicativos e protótipos, para diversas empresas.

Formação
Graduação - Universidade Federal de Minas Gerais (UFMG) - Sistemas de Informação (2º período) | Agosto de 2022 até Dezembro de 2026 (previsto)


Belo Horizonte, Janeiro de 2024




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


O programa deve calcular e exibir a pontuação mais alta possível que Diná pode alcançar com uma sequência de manobras nas seções da pista.


## Compilação e Execução


### Compilação


Para compilar o projeto, execute o comando `g++ -std=c++17 main.cpp -o radlandia` na pasta raiz do projeto. Isso irá gerar o binário `radlandia`.



