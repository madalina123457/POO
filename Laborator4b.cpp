
#include <iostream>
#include <vector>
#include <memory>

class GeneratorValori {
public:
    virtual double genereazaValoare() const = 0;
    virtual ~GeneratorValori() {}
};

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

    const std::string& getUnitateMasura() const {
        return unitateMasura_;
    }

protected:
    std::string unitateMasura_;
    double valoare_;
};

class SenzorTemperatura : public Senzor {
public:
    SenzorTemperatura() : Senzor("Grade Celsius") {}

    void citireDate() override {
        Senzor::citireDate();
    }

    void afisareDate() const override {
        Senzor::afisareDate();
    }
};

class SenzorUmiditate : public Senzor {
public:
    SenzorUmiditate() : Senzor("%") {}

    void citireDate() override {
        Senzor::citireDate();
    }

    void afisareDate() const override {
        Senzor::afisareDate();
    }
};

class SenzorVitezaVant : public Senzor {
public:
    SenzorVitezaVant() : Senzor("m/s") {}

    void citireDate() override {
        Senzor::citireDate();
    }

    void afisareDate() const override {
        Senzor::afisareDate();
    }
};

class DispozitivColectare {
public:
    DispozitivColectare() {}

    void adaugaSenzor(std::shared_ptr<Senzor> senzor, std::shared_ptr<GeneratorValori> generator) {
        senzori_.push_back(senzor);
        generatoare_.push_back(generator);
    }

    void citesteStareTimp() {
        for (size_t i = 0; i < senzori_.size(); ++i) {
            senzori_[i]->citireDate();
            double valoare = generatoare_[i]->genereazaValoare();
            std::cout << "Valoare generata pentru senzorul " << senzori_[i]->getUnitateMasura() << ": " << valoare << "\n";
        }
    }

private:
    std::vector<std::shared_ptr<Senzor>> senzori_;
    std::vector<std::shared_ptr<GeneratorValori>> generatoare_;
};

class GeneratorValoriRandom : public GeneratorValori {
public:
    double genereazaValoare() const override {
        // Simulare generare valoare aleatoare
        return rand() % 100;
    }
};

int main() {
    // Creăm senzori și generatoare de valori
    std::shared_ptr<Senzor> tempSenzor = std::make_shared<SenzorTemperatura>();
    std::shared_ptr<GeneratorValori> tempGenerator = std::make_shared<GeneratorValoriRandom>();

    std::shared_ptr<Senzor> umiditateSenzor = std::make_shared<SenzorUmiditate>();
    std::shared_ptr<GeneratorValori> umiditateGenerator = std::make_shared<GeneratorValoriRandom>();

    std::shared_ptr<Senzor> vantSenzor = std::make_shared<SenzorVitezaVant>();
    std::shared_ptr<GeneratorValori> vantGenerator = std::make_shared<GeneratorValoriRandom>();

    // Creăm dispozitivul de colectare și adăugăm senzorii și generatoarele de valori
    DispozitivColectare dispozitiv;
    dispozitiv.adaugaSenzor(tempSenzor, tempGenerator);
    dispozitiv.adaugaSenzor(umiditateSenzor, umiditateGenerator);
    dispozitiv.adaugaSenzor(vantSenzor, vantGenerator);

    // Citim și afișăm starea timpului
    dispozitiv.citesteStareTimp();

    return 0;
}
