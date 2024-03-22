#include <iostream>
#include <fstream>
#include <vector>

// Function to read matrix data from a file
void readMatrix(int **matrix, int size, std::ifstream &file)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            file >> matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and store the result in a third matrix
void addMatrices(int **matrix1, int **matrix2, int **result, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices and store the result in a third matrix
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract the second matrix from the first matrix
void subtractMatrices(int **matrix1, int **matrix2, int **result, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to update an element of the first matrix after checking validity of row and column
void updateElement(int **matrix, int size, int row, int col, int newValue)
{
    if (row < 0 || row >= size || col < 0 || col >= size)
    {
        throw std::out_of_range("Invalid row or column.");
    }

    matrix[row][col] = newValue;
}

// Function to get the max value of the first matrix
int getMaxValue(int **matrix, int size)
{
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] > maxVal)
            {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Function to transpose the first matrix
void transposeMatrix(int **matrix, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main()
{
    std::ifstream file("matrix_input.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int size;
    file >> size; // Read the size of the matrix
    int **matrix1 = new int *[size];
    int **matrix2 = new int *[size];
    int **result = new int *[size];

    for (int i = 0; i < size; i++)
    {
        matrix1[i] = new int[size];
        matrix2[i] = new int[size];
        result[i] = new int[size];
    }

    readMatrix(matrix1, size, file);
    readMatrix(matrix2, size, file);

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, size);

    std::cout << "\nMatrix 2:" << std::endl;
    printMatrix(matrix2, size);

    // Perform operations
    addMatrices(matrix1, matrix2, result, size);
    std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
    printMatrix(result, size);

    multiplyMatrices(matrix1, matrix2, result, size);
    std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
    printMatrix(result, size);

    subtractMatrices(matrix1, matrix2, result, size);
    std::cout << "\nMatrix 1 - Matrix 2:" << std::endl;
    printMatrix(result, size);

    updateElement(matrix1, size, 1, 2, 99);
    std::cout << "\nUpdated Matrix 1:" << std::endl;
    printMatrix(matrix1, size);

    int maxValue = getMaxValue(matrix1, size);
    std::cout << "\nMax value in Matrix 1: " << maxValue << std::endl;

    transposeMatrix(matrix1, size);
    std::cout << "\nTransposed Matrix 1:" << std::endl;
    printMatrix(matrix1, size);

    file.close();

    for (int i = 0; i < size; i++)
    {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] result[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] result;

    return 0;
}
