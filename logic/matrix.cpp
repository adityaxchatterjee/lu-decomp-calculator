#include "matrix.hpp"
#include <iostream>
#include <iomanip>

// Constructor
Matrix::Matrix(int size) : n(size), data(size, std::vector<double>(size, 0.0)) {
    for (int i = 0; i < n; ++i) {
        data[i][i] = 1.0; // Identity matrix
    }
} 

// Output matrix to console terminal
void Matrix::print() const {
    for (const auto& row : data) {
        for (const auto& val : row) 
            std::cout 
            << std::setw(10)
            << std::fixed
            << std::setprecision(3)
            << val;
        std::cout << "\n";
        // data is a vector of rows ; const auto& row avoids modifying row element
    }
}

// Function to read matrix input 
void Matrix::read_matrix() {
    std::cout << "Enter " << n * n << " values:" << std:: endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> data[i][j]; // compiles user matrix with i rows, j columns
        }
    }
}

// Build row echelon engine
void Matrix::row_echelon(Matrix& L) {
    //std::cout << "[DEBUG] Starting row echelon\n";
    for (int pivot = 0; pivot < n; ++pivot) {
        // Check pivot element non zero
        if (data[pivot][pivot] == 0) {          // diagonal entry zero
            for (int i = pivot + 1; i < n; ++i) {
                if (data[i][pivot] != 0) {
                    swap_rows(pivot, i);        // swaps zero diagonal with non zero entry
                    break; 
                }
            }
        } // Pivot fix loop
   
        // Gaussian elimination below pivot
        for (int i = pivot + 1; i < n; ++i) {
            if (data[i][pivot] == 0) continue;

            // Elementary row operation if there is a non-zero element under pivot
            double factor = -data[i][pivot] / data[pivot][pivot];
            L.set(i, pivot, -factor);   // public access
            gaussian_elim(pivot, i, factor);
        }
    }
} 

// Scale rows
void Matrix::scale_rows(int r1, double scalar) {
    for (double& val : data[r1]) { // & val modifies reference in matrix class; double modifies copy 
        val *= scalar;
    }
}

// Elementary operations
void Matrix::gaussian_elim(int source, int target, double factor) {
    for (int j = 0; j < data[0].size(); ++j) { 
        data[target][j] += factor * data[source][j]; // loops over every column j in matrix
    }
}
    
 // Function to swap rows
 void Matrix::swap_rows(int r1, int r2) {
    std::swap(data[r1], data[r2]);
 }


 void Matrix::set(int i, int j, double val) {
    data[i][j] = val;
 }