#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

// Estrutura para representar uma aresta no grafo
struct Edge {
  long long v, a, l, c; // vértice destino, ano de construção, tempo de travessia, custo de construção
};

/**
 * Função para executar o algoritmo de Dijkstra.
 * @param x Vértice inicial.
 * @param cost Vetor de custos mínimos para alcançar cada vértice.
 * @param maxYear Vetor com o ano máximo de construção das vias usadas para alcançar cada vértice.
 * @param G Grafo representado como uma lista de adjacências.
 */
void dijkstra(long long x, vector<long long>& cost, vector<long long>& maxYear, vector<vector<Edge>>& G) {
  // Fila de prioridade para armazenar os vértices a serem processados
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
  pq.push({0, x});
  cost[x] = 0;
  maxYear[x] = 0;
  
  while (!pq.empty()) {
      pair<long long, long long> front = pq.top();
      long long t = front.first; // custo acumulado
      long long u = front.second; // vértice atual
      pq.pop();
      
      if (t > cost[u]) continue; // verifica se o custo é superior ao custo armazenado
      
      for (Edge e : G[u]) {
          long long w = t + e.l; // novo custo acumulado
          if (w < cost[e.v]) {
              cost[e.v] = w;
              maxYear[e.v] = max(maxYear[u], e.a);
              pq.push({w, e.v});
          }
      }
  }
}

/**
 * Função para calcular o custo mínimo para conectar todo o grafo (similar ao algoritmo de Prim).
 * @param x Vértice inicial.
 * @param n Número total de vértices.
 * @param totalCost Referência para armazenar o custo total da MST.
 * @param G Grafo representado como uma lista de adjacências.
 */
void MinCost(long long x, long long n, long long& totalCost, vector<vector<Edge>>& G) {
  // Fila de prioridade para armazenar os vértices a serem processados
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
  vector<long long> key(n, numeric_limits<long long>::max()); // Vetor de custos mínimos
  vector<bool> inMST(n, false); // Vetor para verificar se o vértice está na MST
  pq.push({0, x});
  key[x] = 0;
  
  while (!pq.empty()) {
      long long u = pq.top().second;
      pq.pop();
      
      if (inMST[u]) continue; // Se o vértice já está na MST, continue
      
      inMST[u] = true;
      totalCost += key[u]; // Adiciona o custo do vértice à MST
      
      for (auto& e : G[u]) {
          long long v = e.v;
          long long weight = e.c;
          if (!inMST[v] && weight < key[v]) {
              key[v] = weight;
              pq.push({weight, v});
          }
      }
  }
}

/**
 * Função para executar uma busca em profundidade (DFS).
 * @param x Vértice inicial.
 * @param vis Vetor de vértices visitados.
 * @param maxYear Ano máximo considerado para a construção da via.
 * @param G Grafo representado como uma lista de adjacências.
 */
void dfs(long long x, vector<bool>& vis, long long maxYear, vector<vector<Edge>>& G) {
  vis[x] = true;
  for (auto& e : G[x]) {
      if (!vis[e.v] && e.a <= maxYear) {
          dfs(e.v, vis, maxYear, G);
      }
  }
}

/**
 * Função para verificar se todos os vértices foram visitados.
 * @param vis Vetor de vértices visitados.
 * @return Verdadeiro se todos os vértices foram visitados, falso caso contrário.
 */
bool allVisited(const vector<bool>& vis) {
  return all_of(vis.begin(), vis.end(), [](bool v) { return v; });
}

/**
 * Função para determinar o menor ano em que todas as cidades estão conectadas.
 * @param x Vértice inicial.
 * @param n Número total de vértices.
 * @param G Grafo representado como uma lista de adjacências.
 * @return O menor ano em que todas as cidades estão conectadas.
 */
long long MinYear(long long x, long long n, long long maxYear, vector<vector<Edge>>& G) {
  long long low = 0, high = maxYear; // Define high como um valor suficientemente grande
  vector<bool> vis(n, false);
  
  while (low < high) {
      long long mid = low + (high - low) / 2;
      fill(vis.begin(), vis.end(), false); // Reinicializa vis para cada iteração
      dfs(x, vis, mid, G);
      
      if (allVisited(vis)) {
          high = mid; // Se todos foram visitados, tenta um valor menor
      } else {
          low = mid + 1; // Caso contrário, tenta um valor maior
      }
  }
  return low; // Ou retorna high, ambos devem ser iguais aqui
}

int main() {
  long long n, m;
  cin >> n >> m;
  
  vector<vector<Edge>> G(n); // Grafo representado como uma lista de adjacências
  vector<long long> cost(n, numeric_limits<long long>::max()); // Vetor de custos mínimos
  vector<long long> maxYear(n, 0); // Vetor de anos máximos
  
  // Leitura das arestas do grafo
  for (long long i = 0; i < m; i++) {
      long long u, v, a, l, c;
      cin >> u >> v >> a >> l >> c;
      u--, v--; // Ajusta índices para começar de 0
      G[u].push_back({v, a, l, c});
      G[v].push_back({u, a, l, c});
  }
  
  // Calcular o tempo mínimo necessário para chegar à vila i
  dijkstra(0, cost, maxYear, G);
  for (long long i = 0; i < n; i++) {
      cout << cost[i] << endl;
  }
  
  // Calcular o primeiro ano em que as distâncias são mutuamente realizáveis
  long long A1 = *max_element(maxYear.begin(), maxYear.end());
  cout << A1 << endl;
  
  // Calcular o primeiro ano a partir do qual é possível chegar em qualquer vila do reino
  long long A2 = MinYear(0, n, A1, G);
  cout << A2 << endl;
  
  // Calcular o menor custo necessário para conectar todo o reino
  long long A3 = 0;
  MinCost(0, n, A3, G);
  cout << A3 << endl;
  
  return 0;
}
