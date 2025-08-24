#include <iostream>
const int size = 4;
int i, j, Array[3*size - 2];

int main() {
    std::cout << "Enter elements (upper, then main, then lower diagonals):\n";
    for (i = 0; i < 3*size - 2; i++) {
        std::cin >> Array[i];
    }

    std::cout << "The matrix is:\n";
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j) {
                std::cout << Array[(size-1) + i]<<" ";
            }
            else if (i == j+1) { 
                std::cout << Array[(2*size -1) + (j)]<<" ";
            }
            else if (i == j-1) {
                std::cout << Array[j-1]<<" ";
            }
            else {
                std::cout << "0 ";
            }
        }
        std::cout << "\n";
    }
}
