#include <iostream>
#include <climits>
using namespace std;

#define MAX 10

void dijkstra(int n, int adj[MAX][MAX], int start) {
    int dist[MAX];        
    bool visited[MAX];    

   
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX; 
        visited[i] = false; 
    }
    dist[start] = 0;  

    // Dijkstra's algorithm
    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the smallest distance
        int minDist = INT_MAX, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update the distances of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] != 0 && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Print the shortest distance to each node
    for (int i = 0; i < n; i++) {
        cout << "Distance from node " << start << " to node " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int n, adj[MAX][MAX], start;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> start;

    dijkstra(n, adj, start);

    return 0;
}
