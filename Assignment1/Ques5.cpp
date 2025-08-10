#include <iostream>
int rows, cols;
int Array[50][50];

void create();
void display();
void sum_rows();
void sum_cols();

int main() {
    create();
    display();
    sum_rows();
    sum_cols();
    return 0;
}

void create() {
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << "Enter element at position [" << i << "][" << j << "]: ";
            std::cin >> Array[i][j];
        }
    }
}

void display() {
    std::cout << "\nMatrix:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << Array[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void sum_rows() {
    std::cout << "\nSum of each row:\n";
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < cols; j++) {
            sum += Array[i][j];
        }
        std::cout << "Row " << i << ": " << sum << "\n";
    }
}

void sum_cols() {
    std::cout << "\nSum of each column:\n";
    for(int j = 0; j < cols; j++) {
        int sum = 0;
        for(int i = 0; i < rows; i++) {
            sum += Array[i][j];
        }
        std::cout << "Column " << j << ": " << sum << "\n";
    }
}
