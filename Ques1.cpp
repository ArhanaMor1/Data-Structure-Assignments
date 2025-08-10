#include <iostream>
int size;
int Array[50];
void create();
void display();
void insert();
void deletion();
void search();

int main() {
    int input;  
    while (1) { 
        std::cout << "Press:\n 1 to create array\n 2 to display\n 3 to insert into array\n 4 to delete from array\n 5 to search an element in array\n 6 to exit\n";
        std::cin >> input;
        std::cout << "\n";
        switch(input) {
            case 1: create();
            break;
            case 2: display();
            break;
            case 3: insert();
            break;
            case 4: deletion();
            break;
            case 5: search();
            break;
        }
        if(input == 6) break;
    }
    return 0;
}

void create(){
    std::cout << "Enter number of elements\n";
    std::cin >> size;
    for(int i = 0; i < size; i++) {
        std::cout << "Enter element\n" << i+1;
        std::cin >> Array[i];
    }
}

void display(){
    for(int i = 0; i < size; i++) {
        std::cout << Array[i] << "\n";
    }
}

void insert(){
    int pos;
    int num;
    std::cout << "At what position do you want to insert the element?";
    std::cin >> pos;
    std::cout << "What is the element?";
    std::cin >> num;
    for(int i = size - 1; i >= pos; i--) {
        Array[i + 1] = Array[i];
    }
    Array[pos] = num;
    size++;
}

void deletion(){
    int pos;
    std::cout << "At which position is the element you want to delete?";
    std::cin >> pos;
    for(int i = pos; i < size - 1; i++) {
        Array[i] = Array[i + 1];
    }
    size--;
}

void search(){
    int element;
    std::cout << "What element do you want to know the position of?";
    std::cin >> element;
    for(int i = 0; i < size; i++) {
        if(Array[i] == element) 
            std::cout << i;
    }
}
