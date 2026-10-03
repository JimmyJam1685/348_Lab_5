#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using Matrix = std::vector<std::vector<int>>;

// Problem 1: File Read in
bool mat_read(Matrix& mat1, Matrix& mat2) {
    char filename[256];
    std::cout << "Enter the name of an existing text file: ";
    std::cin.getline(filename, 256);
    
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Error: Could not open file.\n";
        return false;
    }

    int n = 0;
    ifs >> n;

    mat1 = Matrix(n, std::vector<int>(n, 0));
    mat2 = Matrix(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ifs >> mat1[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ifs >> mat2[i][j];
        }
    }

    return true;
}

// Problem 2: Adding
Matrix mat_add(const Matrix& mat1, const Matrix& mat2) {
    int rows = mat1.size();
    int cols = mat1[0].size();
    Matrix final(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            final[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return final;
}

// Problem 3: Multiplying
Matrix mat_multiply(const Matrix& mat1, const Matrix& mat2) {
    int rows = mat1.size();
    int cols = mat2[0].size();
    int inner = mat1[0].size();

    Matrix final(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < inner; ++k) {
                final[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return final;
}
//Problem 4: Sums of the diagonal

int sum_diagonal(const Matrix& mat) {
    int final = 0;
    for (size_t i = 0; i < mat.size(); ++i) {
        final += mat[i][i];
    }
    return final;
}

// Problem 5: Swap two rows
void swap_rows(Matrix& mat, int row1, int row2) {
	if (row1 >= 0 && row1 < mat.size() && row2 >= 0 && row2 < mat.size()) {
		std::swap(mat[row1], mat[row2]);
	} else {
		std::cerr << "Error: Row indices out of bounds.\n";
	}
}

// Problem 6: Swap two columns
void swap_columns(Matrix& mat, int col1, int col2) {
	if (col1 >= 0 && col1 < mat[0].size() && col2 >= 0 && col2 < mat[0].size()) {
		for (auto& row : mat) {
			std::swap(row[col1], row[col2]);
		}
	} else {
		std::cerr << "Error: Column indices out of bounds.\n";
	}
}

// Problem 7: Update one element
void update_element(Matrix& mat, int row, int col, int value) {
	if (row >= 0 && row < mat.size() && col >= 0 && col < mat[0].size()) {
		mat[row][col] = value;
	} else {
		std::cerr << "Error: Element indices out of bounds.\n";
	}
}

// Print the matrix
void print_matrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            std::cout << std::setw(6) << val << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    Matrix mat1, mat2;
    if (mat_read(mat1, mat2)) {
        std::cout << "\n Matrix 1: \n";
        print_matrix(mat1);

        std::cout << "\n Matrix 2: \n";
        print_matrix(mat2);

        std::cout << "\n Matrix Addition: \n";
        print_matrix(mat_add(mat1, mat2));

        std::cout << "\n Matrix Multiplication \n";
        print_matrix(mat_multiply(mat1, mat2));
    }
    return 0;
}