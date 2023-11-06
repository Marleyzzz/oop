#include <iostream>
#include <cmath>

// Structura pentru numere complexe
struct NumarComplex {
    double real; // Partea reală a numărului complex
    double imaginar; // Partea imaginară a numărului complex
};

// Funcție pentru citirea părții reale a unui număr complex
void setReal(NumarComplex &num, double parteReala) {
    num.real = parteReala;
}

// Funcție pentru citirea părții imaginară a unui număr complex
void setImaginar(NumarComplex &num, double parteImaginara) {
    num.imaginar = parteImaginara;
}

// Funcție pentru adunarea a două numere complexe
NumarComplex adunare(const NumarComplex &num1, const NumarComplex &num2) {
    NumarComplex rezultat;
    rezultat.real = num1.real + num2.real;
    rezultat.imaginar = num1.imaginar + num2.imaginar;
    return rezultat;
}

// Funcție pentru scăderea a două numere complexe
NumarComplex scadere(const NumarComplex &num1, const NumarComplex &num2) {
    NumarComplex rezultat;
    rezultat.real = num1.real - num2.real;
    rezultat.imaginar = num1.imaginar - num2.imaginar;
    return rezultat;
}

// Funcție pentru înmulțirea a două numere complexe
NumarComplex inmultire(const NumarComplex &num1, const NumarComplex &num2) {
    NumarComplex rezultat;
    rezultat.real = num1.real * num2.real - num1.imaginar * num2.imaginar;
    rezultat.imaginar = num1.real * num2.imaginar + num1.imaginar * num2.real;
    return rezultat;
}

// Funcție pentru împărțirea a două numere complexe
NumarComplex impartire(const NumarComplex &num1, const NumarComplex &num2) {
    NumarComplex rezultat;
    double numitor = num2.real * num2.real + num2.imaginar * num2.imaginar;
    rezultat.real = (num1.real * num2.real + num1.imaginar * num2.imaginar) / numitor;
    rezultat.imaginar = (num1.imaginar * num2.real - num1.real * num2.imaginar) / numitor;
    return rezultat;
}

// Funcție pentru calculul modulului unui număr complex
double modul(const NumarComplex &num) {
    return std::sqrt(num.real * num.real + num.imaginar * num.imaginar);
}

// Funcție pentru comparația a două numere complexe în funcție de modul
int comparare(const NumarComplex &num1, const NumarComplex &num2) {
    if (modul(num1) < modul(num2)) {
        return -1; // Primul număr are modulul mai mic
    } else if (modul(num1) > modul(num2)) {
        return 1; // Al doilea număr are modulul mai mic
    }
    return 0; // Numerele au același modul
}

int main() {
    NumarComplex numar1, numar2;
    
    setReal(numar1, 2.0);
    setImaginar(numar1, 3.0);
    
    setReal(numar2, 1.0);
    setImaginar(numar2, 2.0);
    
    NumarComplex suma = adunare(numar1, numar2);
    NumarComplex diferenta = scadere(numar1, numar2);
    NumarComplex produs = inmultire(numar1, numar2);
    NumarComplex cat = impartire(numar1, numar2);
    
    std::cout << "Suma: " << suma.real << " + " << suma.imaginar << "i" << std::endl;
    std::cout << "Diferenta: " << diferenta.real << " + " << diferenta.imaginar << "i" << std::endl;
    std::cout << "Produs: " << produs.real << " + " << produs.imaginar << "i" << std::endl;
    std::cout << "Cat: " << cat.real << " + " << cat.imaginar << "i" << std::endl;
    
    int comparatie = comparare(numar1, numar2);
    if (comparatie < 0) {
        std::cout << "Primul număr are modulul mai mic." << std::endl;
    } else if (comparatie > 0) {
        std::cout << "Al doilea număr are modulul mai mic." << std::endl;
    } else {
        std::cout << "Ambele numere au același modul." << std::endl;
    }
    
    return 0;
}
