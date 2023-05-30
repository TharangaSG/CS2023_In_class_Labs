#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> djkAlgo(const vector<vector<int>>& adjMatrix,const int src) {  // Defining the Dijkstra's algorithm function that takes an adjacency matrix
    vector<int> distances(adjMatrix.size(), INT16_MAX);


    distances[src] = 0;     // Setting the distance of the source vertex to 0

    set<int> processed;     

    
    for (int a = 0; a < adjMatrix.size(); a++) {    // Looping over all vertices
        
        int minVertex = -1;
        for (int b = 0; b < adjMatrix.size(); b++) {     // Looping over all vertices to find the minimum distance vertex
            if (!processed.count(b) && (minVertex == -1 || distances[b] < distances[minVertex])) {
                minVertex = b;
            }
        }

        // If the vertex has not been processed yet, update the distances of its neighbors.
        if (minVertex != -1) {
            processed.insert(minVertex);
            for (int b = 0; b < adjMatrix.size(); b++) {    // Add the minimum vertex to the set
                if (adjMatrix[minVertex][b] != 0) {
                    distances[b] = min(distances[b], distances[minVertex] + adjMatrix[minVertex][b]);
                }
            }
        }
    }
    return distances;
}

int main() {
    
    vector<vector<int>> adjMatrix = {    // adjacency matrix
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

   
    const int STARTING_CITY = 5;   // Setting the starting city

    vector<int> distances = djkAlgo(adjMatrix, STARTING_CITY);

    
    for (int i = 0; i < distances.size(); i++) {
        cout << "Distance from vertex "<< STARTING_CITY <<" to vertex " << i << " -> " << distances[i] << endl;  // Printing the distances from the starting city to all vertices
    }

    return 0;
}