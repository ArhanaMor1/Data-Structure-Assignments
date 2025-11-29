#include <iostream>
using namespace std;

void dijkstra(int vertices, int matrix[50][50], int start) {
    int dist[50];
    int visited[50] = {0};
    int INF = 99999;  // use a large number instead of INT_MAX

    for (int i = 0; i < vertices; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (int count = 0; count < vertices; count++) {
        int minDist = INF, u = -1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;  // remaining vertices unreachable
        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (matrix[u][v] != 0 && !visited[v]) {
                if (dist[u] + matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + matrix[u][v];
                }
            }
        }
    }

    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF)
            cout << i << ": INF\n";
        else
            cout << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    int matrix[50][50];
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            cin >> matrix[i][j];

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    dijkstra(vertices, matrix, start);

    return 0;
}
