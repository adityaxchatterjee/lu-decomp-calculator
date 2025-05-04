#include <vector>
#include <iostream>

// Class declaration (Matrix)
class Matrix {
    private:
        std::vector<std::vector<double>> data; // stores 2D vector array
        int n; // dim n
        // private access to class methods only; cannot access via int main()
    
    public:
        Matrix(int size); // initialize I_n
        void print() const;
        void set(int i, int j, double val);
        void scale_rows(int r1, double scalar);
        void gaussian_elim(int source, int target, double factor);
        void read_matrix();
        void swap_rows(int r1, int r2);
        void row_echelon(Matrix& L);

    }; 
    


