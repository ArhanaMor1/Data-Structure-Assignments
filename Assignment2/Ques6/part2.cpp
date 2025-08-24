#include <iostream>
int rows, cols, nonZero1, nonZero2;
int mat1[50][3];
int mat2[50][3];
int result[50][3];

void matrix_input(int arr[50][3], int &nonZero) {
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    std::cout << "Enter number of non-zero elements: ";
    std::cin >> nonZero;
    arr[0][0] = rows;
    arr[0][1] = cols;
    arr[0][2] = nonZero;
    for (int i = 1; i <= nonZero; i++) {
        std::cout << "Enter row index: ";
        std::cin >> arr[i][0];
        std::cout << "Enter col index: ";
        std::cin >> arr[i][1];
        std::cout << "Enter value: ";
        std::cin >> arr[i][2];
    }
}

void result_matrix(int a[50][3], int n1, int b[50][3], int n2) {
    result[0][0] = rows;
    result[0][1] = cols;
    int i=1, j=1, k=1;
    while (i <= n1 || j <= n2) {
        if (j > n2 || (i <= n1 && (a[i][0] < b[j][0] || (a[i][0]==b[j][0] && a[i][1] < b[j][1]))))
            result[k][0]=a[i][0], result[k][1]=a[i][1], result[k][2]=a[i][2], i++;
        else if (i > n1 || (b[j][0] < a[i][0] || (b[j][0]==a[i][0] && b[j][1] < a[i][1])))
            result[k][0]=b[j][0], result[k][1]=b[j][1], result[k][2]=b[j][2], j++;
        else
            result[k][0]=a[i][0], result[k][1]=a[i][1], result[k][2]=a[i][2]+b[j][2], i++, j++;
        k++;
    }
    result[0][2] = k-1;
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
    std::cout << "First matrix:\n";
    matrix_input(mat1, nonZero1);
    std::cout << "Second matrix:\n";
    matrix_input(mat2, nonZero2);
    result_matrix(mat1, nonZero1, mat2, nonZero2);
    std::cout << "Result matrix:\n";
    display_matrix(result);
}
