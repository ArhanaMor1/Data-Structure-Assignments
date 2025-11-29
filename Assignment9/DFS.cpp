#include <iostream>
#include <stack>
using namespace std;

void depth_first() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    int matrix[50][50];  // adjacency matrix

    cout << "Input adjacency matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << "Enter element " << i << ", " << j << ": ";
            cin >> matrix[i][j];
        }
    }

    int start;
    cout << "Enter the vertex to start from: ";
    cin >> start;

    int visited[50] = {0};
    stack<int> s;

    s.push(start);

    cout << "\nDFS order: ";

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (visited[node] == 0) {
            cout << node << " ";
            visited[node] = 1;

          
            for (int j = vertices - 1; j >= 0; j--) {
                if (matrix[node][j] == 1 && visited[j] == 0) {
                    s.push(j);
                }
            }
        }
    }

    cout << endl;
}

int main() {
    depth_first();
    return 0;
}
