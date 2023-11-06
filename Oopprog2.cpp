#include <iostream>
#include <cmath>

class Vector {
private:          //Aici am folosit incapsularea
    int *data;    // Alocarea dinamică pentru stocarea elementelor vectorului
    int size;     // Dimensiunea vectorului

public:
    // Constructor pentru inițializarea vectorului cu o dimensiune dată
    Vector(int n) {
        size = n;
        data = new int[size];  // Alocă memorie pentru vectorul cu dimensiunea specificată
        for (int i = 0; i < size; i++) {
            data[i] = 0;  // Inițializează fiecare element cu 0
        }
    }

    // Destructor pentru eliminarea vectorului și eliberarea memoriei
    ~Vector() {
        delete[] data;  // Eliberează memoria alocată pentru vector
    }

    // Funcție pentru setarea/modificarea dimensiunii vectorului
    void resize(int n) {
        delete[] data;        // Șterge vectorul actual pentru a elibera memoria
        size = n;             // Actualizează dimensiunea
        data = new int[size];  // Alocă memorie pentru noul vector
        for (int i = 0; i < size; i++) {
            data[i] = 0;  // Inițializează fiecare element cu 0
        }
    }

    // Funcție pentru accesul la elementele vectorului
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index invalid");  // Aruncă o excepție dacă indexul este în afara limitei
        }
        return data[index];  // Returnează o referință la elementul specificat
    }

    // Funcție pentru calculul modulului vectorului
    double calculateMagnitude() {
        double magnitude = 0.0;
        for (int i = 0; i < size; i++) {
            magnitude += data[i] * data[i];  // Calculează suma pătratelor elementelor vectorului
        }
        return sqrt(magnitude);  // Returnează radicalul acestei sume ca modul al vectorului
    }
};

int main() {
    Vector vector1(3);  // Inițializarea primului vector cu dimensiunea 3
    vector1[0] = 1;     // Setarea elementelor vectorului
    vector1[1] = 2;
    vector1[2] = 3;

    Vector vector2(3);  // Inițializarea celui de-al doilea vector cu dimensiunea 3
    vector2[0] = 4;     // Setarea elementelor vectorului
    vector2[1] = 5;
    vector2[2] = 6;

    Vector result(3);   // Inițializarea unui vector pentru stocarea rezultatului

    for (int i = 0; i < 3; i++) {
        result[i] = vector1[i] + vector2[i];  // Adunarea elementelor corespunzătoare
    }

    std::cout << "Sum of vectors: ";
    for (int i = 0; i < 3; i++) {
        std::cout << result[i] << " ";  // Afișarea rezultatului
    }
    std::cout << std::endl;

    return 0;
}
