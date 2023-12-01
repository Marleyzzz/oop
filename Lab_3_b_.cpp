#include <iostream>
#include <algorithm>  // Pentru std::sort

class Set {
private:
    int* elemente;  // Vector dinamic pentru stocarea elementelor
    int dimensiune;  // Dimensiunea actuală a mulțimii

public:
    // Constructorul clasei
    Set() : elemente(nullptr), dimensiune(0) {}

    // Destructorul clasei pentru eliberarea memoriei
    ~Set() {
        delete[] elemente;
    }

    // Supraincarcarea operatorului de adaugare a unui element in multime
    void operator+=(int elem) {
        if (!contineElement(elem)) {
            dimensiune++;
            int* temp = new int[dimensiune];
            std::copy(elemente, elemente + dimensiune - 1, temp);
            temp[dimensiune - 1] = elem;
            delete[] elemente;
            elemente = temp;
        }
    }

    // Supraincarcarea operatorului de comparare la egalitate
    bool operator==(const Set& other) const {
        if (dimensiune != other.dimensiune) {
            return false;
        }
        for (int i = 0; i < dimensiune; ++i) {
            if (!other.contineElement(elemente[i])) {
                return false;
            }
        }
        return true;
    }

    // Supraincarcarea operatorului de unire a doua multimi
    friend Set operator+(const Set& set1, const Set& set2);

    // Supraincarcarea operatorului de intersectie a doua multimi
    friend Set operator*(const Set& set1, const Set& set2);

    // Supraincarcarea operatorului de scadere a doua multimi
    friend Set operator-(const Set& set1, const Set& set2);

    // Supraincarcarea operatorului de afisare
    friend std::ostream& operator<<(std::ostream& os, const Set& set);

    // Supraincarcarea operatorului de citire
    friend std::istream& operator>>(std::istream& is, Set& set);

    // Functia de verificare a apartenentei unui element la multime
    bool contineElement(int elem) const {
        return std::find(elemente, elemente + dimensiune, elem) != elemente + dimensiune;
    }
};

// Definirea operatorului de unire a doua multimi
Set operator+(const Set& set1, const Set& set2) {
    Set rezultat = set1;
    for (int i = 0; i < set2.dimensiune; ++i) {
        rezultat += set2.elemente[i];
    }
    return rezultat;
}

// Definirea operatorului de intersectie a doua multimi
Set operator*(const Set& set1, const Set& set2) {
    Set rezultat;
    for (int i = 0; i < set1.dimensiune; ++i) {
        if (set2.contineElement(set1.elemente[i])) {
            rezultat += set1.elemente[i];
        }
    }
    return rezultat;
}

// Definirea operatorului de scadere a doua multimi
Set operator-(const Set& set1, const Set& set2) {
    Set rezultat = set1;
    for (int i = 0; i < set2.dimensiune; ++i) {
        rezultat.elemente = std::remove(rezultat.elemente, rezultat.elemente + rezultat.dimensiune, set2.elemente[i]);
        rezultat.dimensiune = std::distance(rezultat.elemente, rezultat.elemente + rezultat.dimensiune);
    }
    return rezultat;
}

// Definirea operatorului de afisare
std::ostream& operator<<(std::ostream& os, const Set& set) {
    os << "{ ";
    for (int i = 0; i < set.dimensiune; ++i) {
        os << set.elemente[i];
        if (i < set.dimensiune - 1) {
            os << ", ";
        }
    }
    os << " }";
    return os;
}

// Definirea operatorului de citire
std::istream& operator>>(std::istream& is, Set& set) {
    int elem;
    is >> elem;
    set += elem;
    return is;
}

int main() {
    Set set1, set2;

    std::cout << "Introduceti elementele pentru prima multime (terminati cu -1): ";
    while (true) {
        int elem;
        std::cin >> elem;
        if (elem == -1) {
            break;
        }
        set1 += elem;
    }

    std::cout << "Introduceti elementele pentru a doua multime (terminati cu -1): ";
    while (true) {
        int elem;
        std::cin >> elem;
        if (elem == -1) {
            break;
        }
        set2 += elem;
    }

    Set reunire = set1 + set2;
    Set intersectie = set1 * set2;
    Set diferenta = set1 - set2;

    std::cout << "Reunirea: " << reunire << std::endl;
    std::cout << "Intersectia: " << intersectie << std::endl;
    std::cout << "Diferenta: " << diferenta << std::endl;

    return 0;
}
