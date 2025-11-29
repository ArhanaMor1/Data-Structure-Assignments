#include <iostream>
using namespace std;

int main() {
    int vertices;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int matrix[100][100];

    cout << "\nEnter adjacency matrix values (0 or 1):\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
