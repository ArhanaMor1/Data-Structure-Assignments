#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void addEdge(Node* adj[], int u, int v) {
    Node* newNode = new Node;
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int vertices = 5;

    Node* adj[vertices];

    for (int i = 0; i < vertices; i++) {
        adj[i] = nullptr;
    }

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);

    cout << "Adjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        Node* temp = adj[i];
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}
