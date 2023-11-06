#include <iostream>
#include <cstring>
struct Firma {
    char* denumire;
    char* formaDeOrganizare;
    char* adresa;
    int anulFondarii;
};
// Funcție pentru a crea o firmă
Firma* CreareFirma(const char* denumire, const char* formaDeOrganizare, const char* adresa, int anulFondarii) {
    Firma* firma = new Firma;
    firma->denumire = new char[strlen(denumire) + 1];
    strcpy(firma->denumire, denumire);
    firma->formaDeOrganizare = new char[strlen(formaDeOrganizare) + 1];
    strcpy(firma->formaDeOrganizare, formaDeOrganizare);
    firma->adresa = new char[strlen(adresa) + 1];
    strcpy(firma->adresa, adresa);
    firma->anulFondarii = anulFondarii;
    return firma;
}

// Funcție pentru a modifica denumirea firmei
void ModificaDenumire(Firma* firma, const char* nouaDenumire) {
    delete[] firma->denumire;
    firma->denumire = new char[strlen(nouaDenumire) + 1];
    strcpy(firma->denumire, nouaDenumire);
}

// Funcție pentru a compara două firme
bool ComparaFirme(const Firma* firma1, const Firma* firma2) {
    return strcmp(firma1->denumire, firma2->denumire) == 0;
}

// Funcție pentru a elibera memoria alocată pentru o firmă
void ElibereazaFirma(Firma* firma) {
    delete[] firma->denumire;
    delete[] firma->formaDeOrganizare;
    delete[] firma->adresa;
    delete firma;
}

int main() {
    // Exemplu de creare a unei firme
    Firma* firma1 = CreareFirma("ABC Company", "SRL", "Str. Primaverii 123", 2000);

    // Exemplu de modificare a denumirii firmei
    ModificaDenumire(firma1, "XYZ Corporation");

    // Exemplu de comparare a două firme
    Firma* firma2 = CreareFirma("XYZ Corporation", "SA", "Str. Libertatii 456", 1995);
    if (ComparaFirme(firma1, firma2)) {
        std::cout << "Cele două firme sunt identice." << std::endl;
    } else {
        std::cout << "Cele două firme sunt diferite." << std::endl;
    }

    // Eliberarea memoriei alocate pentru firme
    ElibereazaFirma(firma1);
    ElibereazaFirma(firma2);

    return 0;
}