#include <iostream>
#include <string>

// Clasa de baza: Joc
class Joc {
protected:
    std::string nume;

public:
    // Constructor implicit
    Joc() : nume("Necunoscut") {
        std::cout << "Constructor Joc implicit" << std::endl;
    }

    // Constructor cu un parametru
    Joc(const std::string& numeJoc) : nume(numeJoc) {
        std::cout << "Constructor Joc cu un parametru" << std::endl;
    }

    // Destructor virtual
    virtual ~Joc() {
        std::cout << "Destructor Joc" << std::endl;
    }

    // Operatorul de atribuire
    Joc& operator=(const Joc& other) {
        if (this != &other) {
            nume = other.nume;
        }
        return *this;
    }

    // Functie virtuala pura pentru a fi implementata in clasele derivate
    virtual void desfasurareJoc() const = 0;

    // Functie non-virtuala pentru a fi apelata in clasele derivate
    void anuntareCastigator(const std::string& castigator) const {
        std::cout << "Echipa castigatoare in jocul de " << nume << ": " << castigator << std::endl;
    }
};

// Clasa derivata: JocSportiv
class JocSportiv : public Joc {
protected:
    std::string locatie;

public:
    // Constructor implicit
    JocSportiv() : locatie("Necunoscuta") {
        std::cout << "Constructor JocSportiv implicit" << std::endl;
    }

    // Constructor cu doi parametri
    JocSportiv(const std::string& numeJoc, const std::string& locatieJoc)
        : Joc(numeJoc), locatie(locatieJoc) {
        std::cout << "Constructor JocSportiv cu doi parametri" << std::endl;
    }

    // Destructor
    ~JocSportiv() override {
        std::cout << "Destructor JocSportiv" << std::endl;
    }

    // Operatorul de atribuire
    JocSportiv& operator=(const JocSportiv& other) {
        if (this != &other) {
            Joc::operator=(other);
            locatie = other.locatie;
        }
        return *this;
    }

    // Functie specifica clasei JocSportiv
    void afisareLocatie() const {
        std::cout << "Locatia jocului de " << nume << ": " << locatie << std::endl;
    }

    // Functie virtuala pura
    virtual void desfasurareJoc() const override {
        std::cout << "Desfasurare joc de " << nume << " la " << locatie << std::endl;
    }
};

// Clasa finala derivata: Volei
class Volei : public JocSportiv {
private:
    int durataSet;

public:
    // Constructor cu trei parametri
    Volei(const std::string& numeJoc, const std::string& locatieJoc, int durataSet)
        : JocSportiv(numeJoc, locatieJoc), durataSet(durataSet) {
        std::cout << "Constructor Volei cu trei parametri" << std::endl;
    }

    // Destructor
    ~Volei() override {
        std::cout << "Destructor Volei" << std::endl;
    }

    // Operatorul de atribuire
    Volei& operator=(const Volei& other) {
        if (this != &other) {
            JocSportiv::operator=(other);
            durataSet = other.durataSet;
        }
        return *this;
    }

    // Functie specifica clasei Volei
    void afisareDurataSet() const {
        std::cout << "Durata unui set in jocul de volei: " << durataSet << " minute" << std::endl;
    }

    // Functie suprascrisa pentru desfasurarea jocului de volei
    void desfasurareJoc() const override {
        std::cout << "Desfasurare joc de volei la " << locatie << " cu seturi de " << durataSet << " minute" << std::endl;
    }
};

int main() {
    // Exemplu de utilizare
    JocSportiv jocSportiv("Fotbal", "Stadion");
    jocSportiv.desfasurareJoc();
    jocSportiv.afisareLocatie();

    Volei volei("Volei", "Sala polivalenta", 25);
    volei.desfasurareJoc();
    volei.afisareLocatie();
    volei.afisareDurataSet();

    return 0;
}
