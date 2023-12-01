#include <iostream>
#include <string>

class Senzor {
public:
    Senzor(const std::string& unitateMasura) : unitateMasura_(unitateMasura) {}

    virtual void citireDate() {
        std::cout << "Introduceti date pentru senzor " << unitateMasura_ << ": ";
        std::cin >> valoare_;
    }

    virtual void afisareDate() const {
        std::cout << "Valoare senzor " << unitateMasura_ << ": " << valoare_ << " " << unitateMasura_ << "\n";
    }

    virtual std::ostream& afisare(std::ostream& out) const {
        out << "Valoare senzor " << unitateMasura_ << ": " << valoare_ << " " << unitateMasura_;
        return out;
    }

    virtual std::istream& citire(std::istream& in) {
        std::cout << "Introduceti date pentru senzor " << unitateMasura_ << ": ";
        in >> valoare_;
        return in;
    }

    Senzor(const Senzor& other) : unitateMasura_(other.unitateMasura_), valoare_(other.valoare_) {}

    Senzor& operator=(const Senzor& other) {
        if (this != &other) {
            unitateMasura_ = other.unitateMasura_;
            valoare_ = other.valoare_;
        }
        return *this;
    }

    virtual ~Senzor() {}

protected:
    std::string unitateMasura_;
    double valoare_;
};

class SenzorTemperatura : public Senzor {
public:
    SenzorTemperatura() : Senzor("Grade Celsius") {}

    void citireDate() override {
        Senzor::citireDate(); // Apelăm metoda din clasa de bază
        // Putem adăuga logica specifică pentru senzorul de temperatură dacă este necesar
    }

    void afisareDate() const override {
        Senzor::afisareDate(); // Apelăm metoda din clasa de bază
    }
};

class SenzorUmiditate : public Senzor {
public:
    SenzorUmiditate() : Senzor("%") {}

    void citireDate() override {
        Senzor::citireDate(); // Apelăm metoda din clasa de bază
        // Putem adăuga logica specifică pentru senzorul de umiditate dacă este necesar
    }

    void afisareDate() const override {
        Senzor::afisareDate(); // Apelăm metoda din clasa de bază
    }
};

class SenzorVitezaVant : public Senzor {
public:
    SenzorVitezaVant() : Senzor("m/s") {}

    void citireDate() override {
        Senzor::citireDate(); // Apelăm metoda din clasa de bază
        // Putem adăuga logica specifică pentru senzorul de viteză a vântului dacă este necesar
    }

    void afisareDate() const override {
        Senzor::afisareDate(); // Apelăm metoda din clasa de bază
    }
};

int main() {
    SenzorTemperatura tempSenzor;
    SenzorUmiditate umiditateSenzor;
    SenzorVitezaVant vantSenzor;

    tempSenzor.citireDate();
    tempSenzor.afisareDate();

    umiditateSenzor.citireDate();
    umiditateSenzor.afisareDate();

    vantSenzor.citireDate();
    vantSenzor.afisareDate();

    return 0;
}
