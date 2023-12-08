#include <iostream>

// Clasa de baza
class Hartie {
public:
    Hartie(int format) : format(format) {}

    void afisareFormat() {
        std::cout << "Format: " << format << std::endl;
    }

private:
    int format;
};

// Clasa derivata
class Carte : public Hartie {
public:
    Carte(std::string titlu, int format) : Hartie(format), titlu(titlu) {}

    void afisareInfo() {
        afisareFormat();
        std::cout << "Titlu: " << titlu << std::endl;
    }

private:
    std::string titlu;
};

// Clasa derivata din Carte
class Caiet : public Carte {
public:
    Caiet(std::string titlu, int format, int numarFile) : Carte(titlu, format), numarFile(numarFile) {}

    void afisareDetalii() {
        afisareInfo();
        std::cout << "Numar de file: " << numarFile << std::endl;
    }

private:
    int numarFile;
};

// Clasa derivata din Caiet
class CaietDeNotite : public Caiet {
public:
    CaietDeNotite(std::string titlu, int format, int numarFile, std::string categorie)
        : Caiet(titlu, format, numarFile), categorie(categorie) {}

    void afisareToateDetaliile() {
        afisareDetalii();
        std::cout << "Categorie: " << categorie << std::endl;
    }

private:
    std::string categorie;
};

int main() {
    // Exemplu de utilizare
    CaietDeNotite caiet("Caiet mic", 4, 50, "Notite personale");
    caiet.afisareToateDetaliile();

    return 0;
}
