#include <iostream> // input/ouput using cin/cout
#include <vector> // dynamic arrays
#include "matrix.hpp"

// Start program on terminal: .\app.exe
// RECOMPILE: g++ logic/main.cpp logic/matrix.cpp -o app.exe

// Identity matrix I_n for A in R^(n)

int main() {
    
    int n;
    std::cout << "Enter dimension of square matrix (n):";
    std::cin >> n;                                      // Set dim n

    // User input
    Matrix A(n);                                        // Identity matrix base
    Matrix L(n);                                        // Lower triangle matrix
    
    A.read_matrix();                                    // Fill user input

    std::cout << "\n===== Original matrix A =====\n";
    A.print();                                          // Output original matrix

    // LU Decomposition
    A.row_echelon(L);                                   // U stored in A, L filled by elementary ops


    std::cout << "\n===== Upper Triangular Matrix U =====\n";
    A.print();

    
    std::cout << "\n===== Lower Triangular Matrix L =====\n";
    L.print();
 
    return 0;
}

