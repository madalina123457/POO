#include <iostream>
#include <cstring>

class Group {
private:
    char* groupCode;
    char* specialty;
    int numStudents;
    char* curator;
    int studyYear;

public:
    // Constructorul implicit
    Group() {
        groupCode = nullptr;
        specialty = nullptr;
        numStudents = 0;
        curator = nullptr;
        studyYear = 1; // Implicit, setăm anul de studii la 1
    }

    // Constructor cu parametri pentru inițializare
    Group(const char* code, const char* spec, int students, const char* cur, int year) {
        groupCode = new char[strlen(code) + 1];
        strcpy(groupCode, code);

        specialty = new char[strlen(spec) + 1];
        strcpy(specialty, spec);

        numStudents = students;

        curator = new char[strlen(cur) + 1];
        strcpy(curator, cur);

        if (year >= 1 && year <= 5) {
            studyYear = year;
        } else {
            std::cout << "Anul de studii introdus nu este valid. Setat la 1." << std::endl;
            studyYear = 1;
        }
    }

    // Destructor pentru a elibera memoria alocată dinamic
    ~Group() {
        delete[] groupCode;
        delete[] specialty;
        delete[] curator;
    }

    // Funcție pentru schimbarea curatorului
    void setCurator(const char* cur) {
        delete[] curator;
        curator = new char[strlen(cur) + 1];
        strcpy(curator, cur);
    }

    // Funcție pentru schimbarea numărului de studenți
    void setNumStudents(int students) {
        numStudents = students;
    }

    // Funcție pentru setarea anului de studii cu limita la 1-5
    void setStudyYear(int year) {
        if (year >= 1 && year <= 5) {
            studyYear = year;
        } else {
            std::cout << "Anul de studii introdus nu este valid. Rămâne neschimbat." << std::endl;
        }
    }

    // Funcție pentru afișarea informațiilor despre grupă
    void displayInfo() {
        std::cout << "Codul grupei: " << groupCode << std::endl;
        std::cout << "Specialitatea: " << specialty << std::endl;
        std::cout << "Numărul de studenți: " << numStudents << std::endl;
        std::cout << "Tutorul grupei: " << curator << std::endl;
        std::cout << "Anul de studii: " << studyYear << std::endl;
    }
};

int main() {
    // Exemplu de utilizare a clasei Group
    Group myGroup("G100", "Informatica", 25, "Rodica", 2);
    myGroup.displayInfo();

    myGroup.setCurator("Rodica");
    myGroup.setNumStudents(13);
    myGroup.setStudyYear(2);

    std::cout << "Informații actualizate:" << std::endl;
    myGroup.displayInfo();

    return 0;
}
