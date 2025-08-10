
#include<iostream>
void create();
void display();
void duplicate_remove();
int size;
int Array[50];

int main(){
    create();
    duplicate_remove();
    std::cout<<"The array is:\t";
    display();
}




void create(){
    std::cout << "Enter number of elements\n";
    std::cin >> size;
    for(int i = 0; i < size; i++) {
        std::cout << "Enter element" << i+1<<"\n";
        std::cin >> Array[i];
    }
}
    
    void display(){
    for(int i = 0; i < size; i++) {
        std::cout << Array[i] << "\n";
    }
}


void duplicate_remove(){
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(Array[i] == Array[j]) {
                for(int k = j; k < size - 1; k++) {
                    Array[k] = Array[k + 1];
                }
                size--;
                j--;
            }
        }
    }
}
