#include<iostream>
int size;
int Array[50];
int matrix1[2][2], matrix2[2][2], result[2][2];

void display_array();
void reverse_array();
void multiply_matrices();
void transpose_matrix();

int main(){
    std::cout << "Enter size of array: ";
    std::cin >> size;
    for(int i=0;i<size;i++){
        std::cin >> Array[i];
    }
    reverse_array();
    display_array();

    std::cout << "Enter first 2x2 matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            std::cin >> matrix1[i][j];
        }
    }
    std::cout << "Enter second 2x2 matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            std::cin >> matrix2[i][j];
        }
    }
    multiply_matrices();
    transpose_matrix();
}

void display_array(){
    for(int i=0;i<size;i++){
        std::cout << Array[i] << "\n";
    }
}

void reverse_array(){
    for(int i=0;i<size/2;i++){
        int temp = Array[i];
        Array[i] = Array[size-i-1];
        Array[size-i-1] = temp;
    }
}

void multiply_matrices(){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            result[i][j]=0;
            for(int k=0;k<2;k++){
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    std::cout << "Multiplication result:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void transpose_matrix(){
    int transpose[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            transpose[j][i] = matrix1[i][j];
        }
    }
    std::cout << "Transpose of first matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            std::cout << transpose[i][j] << " ";
        }
        std::cout << "\n";
    }
}
