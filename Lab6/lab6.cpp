#include <iostream>
#include <fstream>

const int N = 3; // Size of the square matrices (NxN)

// Function to read matrix data from a file
void readMatrix(int matrix[N][N]) {
    std::ifstream file("matrix_input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrix[i][j];
        }
    }

    file.close();
}

// Function to print a matrix
void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and store the result in a third matrix
void addMatrices(int matrix1[N][N], int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices and store the result in a third matrix
void multiplyMatrices(int matrix1[N][N], int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract the second matrix from the first matrix
void subtractMatrices(int matrix1[N][N], int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to update an element of the first matrix
void updateElement(int matrix[N][N], int row, int col, int newValue) {
    if (row >= 0 && row < N && col >= 0 && col < N) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column." << std::endl;
    }
}

// Function to get the max value of the first matrix
int getMaxValue(int matrix[N][N]) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Function to transpose the first matrix
void transposeMatrix(int matrix[N][N]) {
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix1[N][N], matrix2[N][N], result[N][N];

    readMatrix(matrix1);
    readMatrix(matrix2);

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1);

    std::cout << "\nMatrix 2:" << std::endl;
    printMatrix(matrix2);

    // Perform operations
    addMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
    printMatrix(result);

    multiplyMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
    printMatrix(result);

    subtractMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix 1 - Matrix 2:" << std::endl;
    printMatrix(result);

    updateElement(matrix1, 1, 1, 99);
    std::cout << "\nUpdated Matrix 1:" << std::endl;
    printMatrix(matrix1);

    int maxValue = getMaxValue(matrix1);
    std::cout << "\nMax value in Matrix 1: " << maxValue << std::endl;

    transposeMatrix(matrix1);
    std::cout << "\nTransposed Matrix 1:" << std::endl;
    printMatrix(matrix1);
    system("pause");

    return 0;
}
