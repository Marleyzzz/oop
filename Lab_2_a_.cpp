#include <iostream>

class Matrix {
private:
    int *data;  // pointer spre elementele matricei
    int rows;   // numărul de rânduri
    int cols;   // numărul de coloane
    int errorCode;  // codul erorii

public:
    // Constructorul implicit
    Matrix() : data(nullptr), rows(0), cols(0), errorCode(0) {}

    // Constructor pentru matrice pătrată
    Matrix(int size) : rows(size), cols(size), errorCode(0) {
        allocateMemory();
        initializeMatrix();
    }

    // Constructor pentru matrice dreptunghiulară
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0) {
        allocateMemory();
        initializeMatrix();
    }

    // Destructor pentru eliberarea memoriei
    ~Matrix() {
        delete[] data;
    }

    // Funcție pentru returnarea valorii unui element
    int getElement(int i, int j) const {
        int tempErrorCode = 0;  // variabilă temporară pentru codul de eroare
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return data[i * cols + j];
        } else {
            // Setează codul de eroare în caz de acces în afara limitelor
            tempErrorCode = 1;
            return 0;
        }
    }

    // Funcție pentru setarea valorii unui element
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            data[i * cols + j] = value;
        } else {
            // Setează codul de eroare în caz de acces în afara limitelor
            errorCode = 1;
        }
    }

    // Funcție pentru adunarea a două matrice
    Matrix add(const Matrix &other) const {
        if (rows == other.rows && cols == other.cols) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows * cols; ++i) {
                result.data[i] = data[i] + other.data[i];
            }
            return result;
        } else {
            // Setează codul de eroare în caz de dimensiuni neconforme
            Matrix result;
            result.errorCode = 2;
            return result;
        }
    }

    // Funcție pentru scăderea a două matrice
    Matrix subtract(const Matrix &other) const {
        if (rows == other.rows && cols == other.cols) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows * cols; ++i) {
                result.data[i] = data[i] - other.data[i];
            }
            return result;
        } else {
            // Setează codul de eroare în caz de dimensiuni neconforme
            Matrix result;
            result.errorCode = 2;
            return result;
        }
    }

    // Funcție pentru înmulțirea a două matrice
    Matrix multiply(const Matrix &other) const {
        if (cols == other.rows) {
            Matrix result(rows, other.cols);

            // Inițializare cu zero
            for (int i = 0; i < rows * other.cols; ++i) {
                result.data[i] = 0;
            }

            // Efectuare operații de înmulțire
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < other.cols; ++j) {
                    for (int k = 0; k < cols; ++k) {
                        result.data[i * result.cols + j] += data[i * cols + k] * other.data[k * other.cols + j];
                    }
                }
            }

            return result;
        } else {
            // Setează codul de eroare în caz de dimensiuni neconforme
            Matrix result;
            result.errorCode = 3;
            return result;
        }
    }

    // Funcție pentru înmulțirea unei matrice cu un scalar
    Matrix multiplyByScalar(int scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // Funcție pentru afișarea matricei
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i * cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    // Funcție pentru alocarea memoriei pentru matrice
    void allocateMemory() {
        data = new int[rows * cols];
    }

    // Funcție pentru inițializarea matricei cu zero
    void initializeMatrix() {
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
    }
};

int main() {
    // Testarea funcționării clasei
    Matrix mat1(2, 3);
    Matrix mat2(3, 2);

    // Inițializare matrici
    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(0, 2, 3);
    mat1.setElement(1, 0, 4);
    mat1.setElement(1, 1, 5);
    mat1.setElement(1, 2, 6);

    mat2.setElement(0, 0, 7);
    mat2.setElement(0, 1, 8);
    mat2.setElement(1, 0, 9);
    mat2.setElement(1, 1, 10);
    mat2.setElement(2, 0, 11);
    mat2.setElement(2, 1, 12);

    // Adunare
    Matrix resultAdd = mat1.add(mat2);
    std::cout << "Adunare:\n";
    resultAdd.display();

    // Scădere
    Matrix resultSubtract = mat1.subtract(mat2);
    std::cout << "\nScadere:\n";
    resultSubtract.display();

    // Înmulțire
    Matrix resultMultiply = mat1.multiply(mat2);
    std::cout << "\nInmultire:\n";
    resultMultiply.display();

    // Înmulțire cu scalar
    Matrix resultScalar = mat1.multiplyByScalar(2);
    std::cout << "\nInmultire cu scalar:\n";
    resultScalar.display();

    return 0;
}
