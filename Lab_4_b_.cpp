#include <iostream>
#include <string>

// Clasa de baza: Roata
class Roata {
private:
    double raza;

public:
    // Constructor cu un parametru pentru raza
    Roata(double r) : raza(r) {}

    // Metoda de acces pentru raza
    double getRaza() const {
        return raza;
    }
};

// Clasa de baza: Automobil
class Automobil {
private:
    std::string firmaProducatoare;
    Roata roti[4];  // Automobilul are 4 roti

public:
    // Constructor cu doi parametri pentru firma producatoare si razele rotilor
    Automobil(const std::string& firma, double razaRoti)
        : firmaProducatoare(firma), roti{razaRoti, razaRoti, razaRoti, razaRoti} {}

    // Metoda de acces pentru firma producatoare
    std::string getFirmaProducatoare() const {
        return firmaProducatoare;
    }

    // Metoda de acces pentru o roata specifica
    double getRazaRoata(int index) const {
        if (index >= 0 && index < 4) {
            return roti[index].getRaza();
        } else {
            std::cerr << "Indexul roții invalid!" << std::endl;
            return -1.0;  // Valoare invalidă pentru indicarea erorii
        }
    }
};

// Clasa derivata: Autocamion
class Autocamion : public Automobil {
private:
    double tonaj;

public:
    // Constructor cu trei parametri pentru firma producatoare, razele rotilor si tonajul autocamionului
    Autocamion(const std::string& firma, double razaRoti, double t)
        : Automobil(firma, razaRoti), tonaj(t) {}

    // Destructor
    ~Autocamion() {
        std::cout << "Destructor Autocamion" << std::endl;
    }

    // Metoda de acces pentru tonaj
    double getTonaj() const {
        return tonaj;
    }
};

int main() {
    // Exemplu de utilizare
    Automobil masina("Toyota", 15.0);

    std::cout << "Firma producatoare: " << masina.getFirmaProducatoare() << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Raza roții " << i + 1 << ": " << masina.getRazaRoata(i) << std::endl;
    }

    Autocamion autocamion("Mercedes", 20.0, 5000.0);

    std::cout << "Firma producatoare autocamion: " << autocamion.getFirmaProducatoare() << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Raza roții " << i + 1 << ": " << autocamion.getRazaRoata(i) << std::endl;
    }
    std::cout << "Tonaj autocamion: " << autocamion.getTonaj() << " kg" << std::endl;

    return 0;
}
