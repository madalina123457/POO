#include <iostream>

// Clasa de baza
class Carte {
public:
    Carte(std::string titlu) : titlu(titlu) {}

    void afisareTitlu() {
        std::cout << "Titlu: " << titlu << std::endl;
    }

private:
    std::string titlu;
};

// Clasa derivata
class Caiet : public Carte {
public:
    Caiet(std::string titlu, int numarFile) : Carte(titlu), numarFile(numarFile) {}

    void afisareInfo() {
        afisareTitlu();
        std::cout << "Numar de file: " << numarFile << std::endl;
    }

private:
    int numarFile;
};

// Clasa derivata din Caiet
class CaietDeNotite : public Caiet {
public:
    CaietDeNotite(std::string titlu, int numarFile, std::string categorie)
        : Caiet(titlu, numarFile), categorie(categorie) {}

    void afisareDetalii() {
        afisareInfo();
        std::cout << "Categorie: " << categorie << std::endl;
    }

private:
    std::string categorie;
};

int main() {
    // Exemplu de utilizare
    CaietDeNotite caiet("Caiet mic", 50, "Notite personale");
    caiet.afisareDetalii();

    return 0;
}
