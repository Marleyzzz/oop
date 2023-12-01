#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int* elements;
    int rows;
    int cols;
    mutable int errorCode;

public:
    // Constructor implicit
    Matrix() : elements(nullptr), rows(0), cols(0), errorCode(0) {}

    // Constructor cu un parametru pentru matrice pătrată
    Matrix(int size) : rows(size), cols(size), errorCode(0) {
        try {
            elements = new int[rows * cols]();
        } catch (std::bad_alloc&) {
            errorCode = 1;  // Codul erorii pentru a indica insuficiență de memorie
        }
    }

    // Constructor cu doi parametri pentru matrice dreptunghiulară
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0) {
        try {
            elements = new int[rows * cols]();
        } catch (std::bad_alloc&) {
            errorCode = 1;
        }
    }

    // Destructor
    ~Matrix() {
        delete[] elements;
    }

    // Funcție de acces pentru a obține valoarea unui element
    int getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return elements[i * cols + j];
        } else {
            errorCode = 2;  // Codul erorii pentru a indica depășire a limitelor matricei
            return 0;       // Întoarce o valoare implicită sau altă valoare în funcție de cerințe
        }
    }

    // Funcție de acces pentru a seta valoarea unui element
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i * cols + j] = value;
        } else {
            errorCode = 2;
        }
    }

    // Funcție de adunare a două matrice
    Matrix add(const Matrix& other) const {
        if (rows == other.rows && cols == other.cols) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.setElement(i, j, getElement(i, j) + other.getElement(i, j));
                }
            }
            return result;
        } else {
            errorCode = 3;  // Codul erorii pentru a indica necorespondență a dimensiunilor matricelor
            return Matrix();  // Întoarce o matrice goală sau altă valoare în funcție de cerințe
        }
    }

    // Funcție de scădere a două matrice
    Matrix subtract(const Matrix& other) const {
        if (rows == other.rows && cols == other.cols) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.setElement(i, j, getElement(i, j) - other.getElement(i, j));
                }
            }
            return result;
        } else {
            errorCode = 3;
            return Matrix();
        }
    }

    // Funcție de înmulțire a unei matrice cu alta
    Matrix multiply(const Matrix& other) const {
        if (cols == other.rows) {
            Matrix result(rows, other.cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < other.cols; ++j) {
                    int sum = 0;
                    for (int k = 0; k < cols; ++k) {
                        sum += getElement(i, k) * other.getElement(k, j);
                    }
                    result.setElement(i, j, sum);
                }
            }
            return result;
        } else {
            errorCode = 3;
            return Matrix();
        }
    }

    // Funcție de înmulțire a unei matrice cu un număr
    Matrix multiply(int scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setElement(i, j, getElement(i, j) * scalar);
            }
        }
        return result;
    }

    // Funcție pentru obținerea codului erorii
    int getErrorCode() const {
        return errorCode;
    }
};

int main() {
    Matrix squareMatrix(3);
    squareMatrix.setElement(0, 0, 1);
    squareMatrix.setElement(1, 1, 2);
    squareMatrix.setElement(2, 2, 3);

    Matrix rectangularMatrix(3, 2);
    rectangularMatrix.setElement(0, 0, 4);
    rectangularMatrix.setElement(1, 1, 5);
    rectangularMatrix.setElement(2, 0, 6);

    Matrix resultAddition = squareMatrix.add(rectangularMatrix);
    Matrix resultSubtraction = squareMatrix.subtract(rectangularMatrix);
    Matrix resultMultiplicationMatrix = squareMatrix.multiply(rectangularMatrix);
    Matrix resultMultiplicationScalar = squareMatrix.multiply(2);

    std::cout << "Result of addition:" << std::endl;
    std::cout << resultAddition.getElement(0, 0) << "  " << resultAddition.getElement(0, 1) << std::endl;
    std::cout << resultAddition.getElement(1, 0) << "  " << resultAddition.getElement(1, 1) << std::endl;
    std::cout << resultAddition.getElement(2, 0) << "  " << resultAddition.getElement(2, 1) << std::endl;

    std::cout << "Result of subtraction:" << std::endl;
    std::cout << resultSubtraction.getElement(0, 0) << "  " << resultSubtraction.getElement(0, 1) << std::endl;
    std::cout << resultSubtraction.getElement(1, 0) << "  " << resultSubtraction.getElement(1, 1) << std::endl;
    std::cout << resultSubtraction.getElement(2, 0) << "  " << resultSubtraction.getElement(2, 1) << std::endl;

    std::cout << "Result of multiplication (matrix):" << std::endl;
    std::cout << resultMultiplicationMatrix.getElement(0, 0) << "  " << resultMultiplicationMatrix.getElement(0, 1) << std::endl;
    std::cout << resultMultiplicationMatrix.getElement(1, 0) << "  " << resultMultiplicationMatrix.getElement(1, 1) << std::endl;
    std::cout << resultMultiplicationMatrix.getElement(2, 0) << "  " << resultMultiplicationMatrix.getElement(2, 1) << std::endl;

    std::cout << "Result of multiplication (scalar):" << std::endl;
    std::cout << resultMultiplicationScalar.getElement(0, 0) << "  " << resultMultiplicationScalar.getElement(0, 1) << std::endl;
    std::cout << resultMultiplicationScalar.getElement(1, 0) << "  " << resultMultiplicationScalar.getElement(1, 1) << std::endl;
    std::cout << resultMultiplicationScalar.getElement(2, 0) << "  " << resultMultiplicationScalar.getElement(2, 1) << std::endl;

    return 0;
}
