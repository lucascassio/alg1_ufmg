#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>

// Estrutura para representar uma aresta
struct Edge {
    int from; // Vértice de origem
    int to; // Vértice de destino
    double angle; // Ângulo relativo
    bool visited;

    Edge(int f, int t, double a, bool vis) : from(f), to(t), angle(a), visited(vis){}
};

#endif