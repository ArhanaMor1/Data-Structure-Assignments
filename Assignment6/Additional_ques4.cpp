#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void append(int x) {
    Node* n = new Node{x, NULL, NULL};
    if(head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void displayReverse() {
    if(head == NULL) return;
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

void correctPointers() {
    if(head == NULL) return;
    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->next->prev != temp)
            temp->next->prev = temp;
        temp = temp->next;
    }
}

int main() {
    head = new Node{1, NULL, NULL};
    head->next = new Node{2, NULL, head};
    head->next->next = new Node{3, NULL, head}; // wrong prev
    head->next->next->next = new Node{4, NULL, head->next->next};
    head->next->next->next->prev = head->next->next;

    cout << "Incorrect List (Forward): ";
    display();
    cout << "Incorrect List (Reverse): ";
    displayReverse();

    correctPointers();

    cout << "\nCorrected List (Forward): ";
    display();
    cout << "Corrected List (Reverse): ";
    displayReverse();
}
