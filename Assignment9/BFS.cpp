#include <iostream>
using namespace std;

int Queue[50];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == 49) {
        cout << "Queue overflow\n";
        return;
    }
    if (front == -1) front = 0;
    rear++;
    Queue[rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    int value = Queue[front];
    front++;
    return value;
}

void breadth_first() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    int matrix[50][50];  

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

    enqueue(start);
    visited[start] = 1;

    cout << "\nBFS order: ";

    while (front != -1 && front <= rear) {
        int node = dequeue();
        cout << node << " ";

        for (int j = 0; j < vertices; j++) {
            if (matrix[node][j] == 1 && visited[j] == 0) {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }

    cout << endl;
}

int main() {
    breadth_first();
    return 0;
}
