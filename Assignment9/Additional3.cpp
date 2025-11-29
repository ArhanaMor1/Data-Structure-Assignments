#include <iostream>
using namespace std;

int N; // number of nodes
int timesMatrix[50][50];
int dist[50];
bool visited[50];
int INF = 99999;

int minDistNode() {
    int minVal = INF;
    int node = -1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i] && dist[i] < minVal) {
            minVal = dist[i];
            node = i;
        }
    }
    return node;
}

int networkDelayTime(int K) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[K] = 0;

    for (int count = 1; count <= N; count++) {
        int u = minDistNode();
        if (u == -1) break;
        visited[u] = true;

        for (int v = 1; v <= N; v++) {
            if (timesMatrix[u][v] != 0 && !visited[v]) {
                if (dist[u] + timesMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + timesMatrix[u][v];
                }
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}

int main() {
    int E, K;
    cout << "Enter number of nodes N, starting node K, and number of edges E: ";
    cin >> N >> K >> E;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            timesMatrix[i][j] = 0;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        timesMatrix[u][v] = w;
    }

    int result = networkDelayTime(K);
    cout << "Network delay time: " << result << endl;

    return 0;
}
