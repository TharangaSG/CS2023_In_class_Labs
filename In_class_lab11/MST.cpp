#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;


void addEdge(Graph& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));  // Add an edge from u to v 
    graph[v].push_back(make_pair(u, weight));  // Add an edge from v to u 
}

// using Prim's algorithm find the minimum spanning tree 
void primMST(const Graph& graph, int startVertex) {
    int numofVertices = graph.size();  // Get the number of vertices in the graph

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;  // Priority queue to store the edges with minimum weight

    vector<int> key(numofVertices, INT16_MAX);  // Key values used to pick minimum weight edge
    vector<bool> inMST(numofVertices, false);  // To track whether a vertex is included in the MST or not
    vector<int> parent(numofVertices, -1);  // Array to store the MST

    pq.push(make_pair(0, startVertex));  // Start with the given start vertex
    key[startVertex] = 0;  // Set the key value of the start vertex as 0

    while (!pq.empty()) {
        int u = pq.top().second;  // Get the vertex with the minimum key value
        pq.pop();

        inMST[u] = true;  // Include the vertex in the MST

        for (const auto& neighbor : graph[u]) {  // Explore all the adjacent vertices of the current vertex
            int v = neighbor.first;  // Get the adjacent vertex
            int weight = neighbor.second;  // Get the weight of the edge

            if (!inMST[v] && weight < key[v]) {  // If the adjacent vertex is not in the MST 
                key[v] = weight;  // Update the key value of the adjacent vertex
                parent[v] = u;  // Set the current vertex as the parent of the adjacent vertex in the MST
                pq.push(make_pair(key[v], v));  // Push the updated key value 
            }
        }
    }

    // Printing minimum spanning tree
    cout << "Edges of Minimum Spanning Tree:" << endl;
    for (int a = 1; a < numofVertices; a++) {
        cout << parent[a] << " ----- " << a << "       weight  : " << key[a] << endl;
    }
}

int main() {
    int numVertices = 6;
    Graph graph(numVertices);  // Create a graph with the given number of vertices

    // Adding edges to the graph
    addEdge(graph, 0, 5, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 4, 5, 4);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 1, 4, 10);

    int startVertex = 0;
    primMST(graph, startVertex);

    return 0;
}