#include <iostream>

class NumarIntreg {
private:
    int valoare;

public:
    // Constructorul clasei
    NumarIntreg(int val) : valoare(val) {}

    // Supraincarcarea operatorului de incrementare (++x)
    NumarIntreg& operator++() {
        ++valoare;
        return *this;
    }

    // Supraincarcarea operatorului de adunare (x + y)
    NumarIntreg operator+(const NumarIntreg& other) const {
        return NumarIntreg(valoare + other.valoare);
    }

    // Getter pentru valoare
    int getValoare() const {
        return valoare;
    }

    // Declarație a funcției prietene pentru operatorul de decrementare
    friend NumarIntreg operator--(NumarIntreg& numar, int);

    // Declarație a funcției prietene pentru operatorul de scădere
    friend NumarIntreg operator-(const NumarIntreg& numar1, const NumarIntreg& numar2);
};

// Definirea funcției prietene pentru operatorul de decrementare
NumarIntreg operator--(NumarIntreg& numar, int) {
    NumarIntreg temp(numar);  // Creăm o copie a obiectului original
    --numar.valoare;
    return temp;  // Returnăm copia originalului în starea inițială
}

// Definirea funcției prietene pentru operatorul de scădere
NumarIntreg operator-(const NumarIntreg& numar1, const NumarIntreg& numar2) {
    return NumarIntreg(numar1.getValoare() - numar2.getValoare());
}

int main() {
    // Exemplu de utilizare
    NumarIntreg x(5);
    NumarIntreg y(3);

    // Utilizarea operatorului de incrementare
    ++x;
    std::cout << "x dupa incrementare: " << x.getValoare() << std::endl;

    // Utilizarea operatorului de adunare
    NumarIntreg rezultat = x + y;
    std::cout << "Rezultatul adunarii: " << rezultat.getValoare() << std::endl;

    // Utilizarea operatorului de decrementare
    NumarIntreg z = y--;
    std::cout << "y dupa decrementare: " << y.getValoare() << std::endl;
    std::cout << "z: " << z.getValoare() << std::endl;

    // Utilizarea operatorului de scădere
    NumarIntreg rezultatScadere = x - y;
    std::cout << "Rezultatul scaderii: " << rezultatScadere.getValoare() << std::endl;

    return 0;
}
