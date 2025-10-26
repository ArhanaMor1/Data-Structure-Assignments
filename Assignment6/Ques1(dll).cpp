#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insert_at_begin() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;

    if(head == nullptr){
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    head = newNode;
}

void insert_at_end() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;

    if(head == nullptr){
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

void insert_after_value() {
    if(head == nullptr){
        cout << "List is empty!\n";
        return;
    }

    int value, afterValue;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Insert after which value? ";
    cin >> afterValue;

    Node* temp = head;
    do {
        if(temp->data == afterValue) break;
        temp = temp->next;
    } while(temp != head);

    if(temp->data != afterValue){
        cout << "Value not found!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void insert_before_value() {
    if(head == nullptr){
        cout << "List is empty!\n";
        return;
    }

    int value, beforeValue;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Insert before which value? ";
    cin >> beforeValue;

    Node* temp = head;
    do {
        if(temp->data == beforeValue) break;
        temp = temp->next;
    } while(temp != head);

    if(temp->data != beforeValue){
        cout << "Value not found!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;

    if(temp == head) head = newNode;
}

void delete_specific_node() {
    if(head == nullptr){
        cout << "List is empty!\n";
        return;
    }

    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    Node* temp = head;
    do {
        if(temp->data == value) break;
        temp = temp->next;
    } while(temp != head);

    if(temp->data != value){
        cout << "Value not found!\n";
        return;
    }

    if(temp->next == temp){ // only one node
        delete temp;
        head = nullptr;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if(temp == head) head = temp->next;

    delete temp;
}

void search_node() {
    if(head == nullptr){
        cout << "List is empty.\n";
        return;
    }

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    Node* temp = head;
    int pos = 0;
    do {
        if(temp->data == value){
            cout << "Value found at position " << pos << " from head.\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while(temp != head);

    cout << "Value not found!\n";
}

void display_list() {
    if(head == nullptr){
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while(temp != head);
    cout << "(head)\n";
}

void menu(int choice){
    switch(choice){
        case 1: insert_at_begin(); break;
        case 2: insert_at_end(); break;
        case 3: insert_after_value(); break;
        case 4: insert_before_value(); break;
        case 5: delete_specific_node(); break;
        case 6: search_node(); break;
        case 7: display_list(); break;
        default: cout << "Invalid choice!\n";
    }
}

int main(){
    cout << "Circular Doubly Linked List Operations Menu\n";
    cout << "1: Insert at beginning\n2: Insert at end\n3: Insert after value\n";
    cout << "4: Insert before value\n5: Delete a specific node\n6: Search a node\n7: Display list\n8: Exit\n";

    int choice;
    while(true){cout<<"Press your choice: ";
        cin >> choice;
        if(choice == 8) break;
        menu(choice);
    }

    return 0;
}
