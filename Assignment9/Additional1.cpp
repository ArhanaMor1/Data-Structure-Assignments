#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }

    bool visited[V] = {false};
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }

    cout << "Number of connected components: " << components << endl;
    return 0;
}
