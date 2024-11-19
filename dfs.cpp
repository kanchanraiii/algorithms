#include<iostream>
using namespace std;

void dfs(int n, int adj[10][10], int start) {
    int visited[10] = {0};
    int stack[10];
    int top = -1;

    stack[++top] = start;
    visited[start] = 1;

    cout << "DFS traversal: ";

    while (top != -1) {
        int current = stack[top--];  
        cout << current << " ";

       
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                stack[++top] = i;  
            }
        }
    }
}

int main() {
    int n, adj[10][10], start;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> start;

    dfs(n, adj, start);

    return 0;
}
