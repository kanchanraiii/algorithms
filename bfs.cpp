#include <iostream>
using namespace std;

void bfs(int n, int adj[10][10], int start) {
    int visited[10] = {0}; // Array to track visited nodes
    int queue[10];         // Queue for BFS
    int front = 0, rear = 0;

    // Mark the starting node as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS Traversal: ";

    while (front < rear) {
        // Dequeue the front element
        int current = queue[front++];
        cout << current << " "; // Process the current node

        // Check all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;        // Mark as visited
                queue[rear++] = i;     // Enqueue the adjacent node
            }
        }
    }
}

int main() {
    int n, adj[10][10], start;

    // Input the number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Input the adjacency matrix
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // Input the starting vertex
    cout << "Enter the starting vertex: ";
    cin >> start;

    // Perform BFS traversal
    bfs(n, adj, start);

    return 0;
}
