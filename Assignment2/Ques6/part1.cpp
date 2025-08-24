#include <iostream>
int rows, cols, nonZero;
int mat[50][3];
int transpose[50][3];

void matrix_input() {
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    std::cout << "Enter number of non-zero elements: ";
    std::cin >> nonZero;

    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = nonZero;

    for (int i = 1; i <= nonZero; i++) {
        std::cout << "Enter row index: ";
        std::cin >> mat[i][0];
        std::cout << "Enter col index: ";
        std::cin >> mat[i][1];
        std::cout << "Enter value: ";
        std::cin >> mat[i][2];
    }
}

void transpose_matrix() {
    transpose[0][0] = mat[0][1];
    transpose[0][1] = mat[0][0];
    transpose[0][2] = mat[0][2];

    int k = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= nonZero; i++) {
            if (mat[i][1] == col) {
                transpose[k][0] = mat[i][1]; 
                transpose[k][1] = mat[i][0]; 
                transpose[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

void display_matrix(int arr[50][3]) {
    int total = arr[0][2];
    for (int i = 0; i <= total; i++) {
        std::cout << arr[i][0] << " "
                  << arr[i][1] << " "
                  << arr[i][2] << "\n";
    }
}

int main() {
    matrix_input();
    display_matrix(mat);
    transpose_matrix();
    display_matrix(transpose);
}
