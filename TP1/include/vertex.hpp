#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "edge.hpp"
#include <vector>

// Estrutura para representar um vértice
struct Vertex {
    double x, y; // Coordenadas
    std::vector<int> neighbors; // Vizinhos
    std::vector<Edge> edges; // Arestas de saída
    bool isBridge;

    Vertex() : isBridge(false) {} // Inicializa isBridge como falso por padrão
};

#endif