#include <iostream>
using namespace std;

struct Edge {
    int u, v, weight;
};

int findParent(int parent[], int i) {
    if (parent[i] == i) return i;
    return findParent(parent, parent[i]);
}

void kruskalMST(int vertices, Edge edges[], int edgeCount) {
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    int parent[50];
    for (int i = 0; i < vertices; i++) parent[i] = i;

    cout << "\nKruskal MST edges:\n";
    int mst_weight = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u_parent = findParent(parent, edges[i].u);
        int v_parent = findParent(parent, edges[i].v);

        if (u_parent != v_parent) {
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].weight << "\n";
            mst_weight += edges[i].weight;
            parent[u_parent] = v_parent;
        }
    }

    cout << "Total weight: " << mst_weight << "\n";
}

void primMST(int vertices, int matrix[50][50]) {
    int selected[50] = {0};
    selected[0] = 1;
    int mst_weight = 0;

    cout << "\nPrim MST edges:\n";

    for (int k = 0; k < vertices - 1; k++) {
        int min = 100000, x = 0, y = 0;

        for (int i = 0; i < vertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!selected[j] && matrix[i][j]) {
                        if (matrix[i][j] < min) {
                            min = matrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << matrix[x][y] << "\n";
        mst_weight += matrix[x][y];
        selected[y] = 1;
    }

    cout << "Total weight: " << mst_weight << "\n";
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

    Edge edges[100];
    int edgeCount = 0;
    for (int i = 0; i < vertices; i++)
        for (int j = i + 1; j < vertices; j++)
            if (matrix[i][j] != 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = matrix[i][j];
                edgeCount++;
            }

    kruskalMST(vertices, edges, edgeCount);
    primMST(vertices, matrix);

    return 0;
}
