#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../include/geo.hpp"
#include "../include/vertex.hpp"
#include "../include/edge.hpp"

using namespace std;

Geo geo;
vector<Vertex> G;

/**
 * Function to print the number of faces and their vertices.
 * @param faces Vector of vectors containing the indices of vertices forming each face.
 */
void printFaces(vector<vector<int>>& faces) {
    cout << faces.size() << endl;
    for (int i = 0; i < faces.size(); ++i) {
        cout << faces[i].size() << " ";
        for (int j = 0; j < faces[i].size(); ++j) {
            cout << faces[i][j] + 1 << " ";
        }
        cout << endl;
    }
}

/**
 * Comparator function to compare edges by angle.
 * @param e1 First edge.
 * @param e2 Second edge.
 * @return True if the angle of e1 is less than the angle of e2, false otherwise.
 */
bool compareEdgesByAngle(const Edge& e1, const Edge& e2) {
    return e1.angle < e2.angle;
}

/**
 * DFS to count connected components starting from vertex u.
 * @param adjList Adjacency list representing the graph.
 * @param visited Vector to mark visited vertices.
 * @param u Current vertex.
 */
void CountComponentsDFS(vector<vector<int>>& adjList, vector<bool>& visited, int u) {
    visited[u] = true;
    for(int v : adjList[u]) {
        if(!visited[v]) {
            CountComponentsDFS(adjList, visited, v);
        }
    }
}

/**
 * Function to find bridge edges in a graph.
 * @param adjList Adjacency list representing the graph.
 */
void findBridges(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    int time = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j : adjList[i]) {
            // Temporarily remove the edge
            int temp = i;
            adjList[i].erase(remove(adjList[i].begin(), adjList[i].end(), j), adjList[i].end());
            adjList[j].erase(remove(adjList[j].begin(), adjList[j].end(), i), adjList[j].end());

            // Call a dfs to know the number of connected components
            vector<bool> visited(n, false);
            int components = 0;
            for(int v = 0; v < n; v++) {
                if(!visited[v]) {
                    CountComponentsDFS(adjList, visited, v);
                    components++;
                }
            }

            // If the number of connected components increases, the edge is a bridge
            if (components > 1) {
                G[i].isBridge = true;
                G[j].isBridge = true;
            }

            // Restore the removed edge
            adjList[i].push_back(j);
            adjList[j].push_back(i);
        }
    }
}

/**
 * DFS to find a face in the graph starting from a given vertex.
 * @param vertex Vector of vertices representing the graph.
 * @param currentVertex Current vertex being visited.
 * @param startVertex Starting vertex of the face.
 * @param prevVertex Previous vertex visited.
 * @param face Vector to store the indices of vertices forming the face.
 */
void findFaceDFS(vector<Vertex>& vertex, int currentVertex, int startVertex, int prevVertex, vector<int>& face) {
    face.push_back(currentVertex);
    
    if (currentVertex == startVertex && face.size() > 1) {
        return;
    }

    // Check if it's the first iteration
    if (prevVertex == -1) {
        for (auto& edge : vertex[currentVertex].edges) {
            if (!edge.visited) {
                edge.visited = true;
                findFaceDFS(vertex, edge.to, startVertex, currentVertex, face);
                return;
            }
        }
    } else {
        // Find the next edge after the return edge
        int nextEdge = -1;
        bool foundPrevEdge = false;
        for (int i = 0; i < vertex[currentVertex].edges.size(); i++) {
            if (foundPrevEdge) {
                nextEdge = i;
                break;
            }
            if (vertex[currentVertex].edges[i].to == prevVertex) {
                foundPrevEdge = true;
            }
        }
        // If we didn't find the return edge, the next one will be the first
        if (nextEdge == -1) {
            nextEdge = 0;
        }

        // Visit the next edge after the return edge
        if (nextEdge != -1 && !vertex[currentVertex].edges[nextEdge].visited) {
            vertex[currentVertex].edges[nextEdge].visited = true;
            findFaceDFS(vertex, vertex[currentVertex].edges[nextEdge].to, startVertex, currentVertex, face);
            return;
        }
    }
}

/**
 * Function to find all faces in the graph.
 * @param vertex Vector of vertices representing the graph.
 * @return Vector of vectors containing the indices of vertices forming each face.
 */
vector<vector<int>> findFaces(vector<Vertex>& vertex) {
    int n = vertex.size();
    vector<vector<int>> faces;

    // Vector to store indices of non-bridge and bridge vertex
    vector<int> nonBridgevertex;
    vector<int> bridgevertex;

    // Separate vertex into non-bridge and bridge categories
    for (int i = 0; i < n; ++i) {
        if (vertex[i].isBridge) {
            bridgevertex.push_back(i);
        } else {
            nonBridgevertex.push_back(i);
        }
    }

    // Start the search for faces
    // First process non-bridge vertex
    for (int i : nonBridgevertex) {
        for (auto& edge : vertex[i].edges) {
            if (!edge.visited) {
                vector<int> face;
                findFaceDFS(vertex, edge.from, i, -1, face);
                faces.push_back(face);
            }
        }
    }

    // Then process bridge vertex
    for (int i : bridgevertex) {
        for (auto& edge : vertex[i].edges) {
            if (!edge.visited) {
                vector<int> face;
                findFaceDFS(vertex, edge.from, i, -1, face);
                faces.push_back(face);
            }
        }
    }

    return faces;
}

/**
 * Function to read the graph from input.
 * @param n Number of vertices.
 * @param m Number of edges.
 * @param adjList Adjacency list to store the graph.
 */
void readGraph(int n, int m, vector<vector<int>>& adjList) {
    // Read vertex coordinates and neighbors
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        G[i].x = x;
        G[i].y = y;
        int degree;
        cin >> degree;
        G[i].neighbors.clear(); // Clear neighbors before reading
        for (int j = 0; j < degree; ++j) {
            int neighbor;
            cin >> neighbor;
            // Adjust neighbor index for base 0
            G[i].neighbors.push_back(neighbor - 1);
            adjList[i].push_back(neighbor - 1);
        }
    }
}

/**
 * Function to calculate angles between edges and create Edge objects.
 * @param edges Vector to store the edges.
 * @param n Number of vertices.
 */
void calcAnglesAndEdges(vector<Edge>& edges, int n) {
    for (int i = 0; i < n; i++) {
        for (int j : G[i].neighbors) {
            Ponto x = {G[i].x, G[i].y};
            Ponto y = {G[j].x, G[j].y};
            double angle = geo.RelativeInclination(x, y); // Assuming RelativeInclination calculates relative angle
            edges.push_back(Edge(i, j, angle, false));
        }
    }
}

/**
 * Main function to read the graph, detect faces, and print them.
 */
int main() {
    int n, m; // Number of vertex and edges
    cin >> n >> m;

    // Initialize the vertex vector
    G.resize(n);

    // Vector to store adjacency list for bridge detection
    vector<vector<int>> adjList(n);

    // Read the Graph
    readGraph(n, m, adjList);

    // Detect bridge vertex
    findBridges(adjList);

    // Calculate angles and create edges
    vector<Edge> edges;
    calcAnglesAndEdges(edges, n);

    // Sort edges by angle
    sort(edges.begin(), edges.end(), compareEdgesByAngle);

    // Add edges to corresponding vertex
    for (int i = 0; i < edges.size(); i++) {
        edges[i].visited = false;
        G[edges[i].from].edges.push_back(edges[i]);
    } 

    vector<vector<int>> faces = findFaces(G);
    printFaces(faces);

    return 0;
}
