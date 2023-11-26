#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t size;

public:
    // Constructori
    String() : data(nullptr), size(0) {}
    String(const char* str) : data(nullptr), size(0) {
        if (str) {
            size = strlen(str);
            data = new char[size + 1];
            strcpy(data, str);
        }
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Operatori de atribuire
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    String& operator=(const char* str) {
        delete[] data;
        if (str) {
            size = strlen(str);
            data = new char[size + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
            size = 0;
        }
        return *this;
    }

    // Operatori de concatenare
    String operator+(const String& other) const {
        String result;
        result.size = size + other.size;
        result.data = new char[result.size + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    String& operator+=(const String& other) {
        size_t newSize = size + other.size;
        char* newData = new char[newSize + 1];
        strcpy(newData, data);
        strcat(newData, other.data);
        delete[] data;
        data = newData;
        size = newSize;
        return *this;
    }

    // Operatori de comparare
    bool operator==(const String& other) const {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    bool operator<(const String& other) const {
        return strcmp(data, other.data) < 0;
    }

    bool operator>(const String& other) const {
        return strcmp(data, other.data) > 0;
    }

    // Operator de acces la caractere
    char operator[](size_t index) const {
        if (index < size) {
            return data[index];
        } else {
            // Aici poți să tratezi cazul în care index este mai mare decât size
            // Poți arunca o excepție sau trata în alt mod, în funcție de cerințele tale
            return '\0';  // În acest caz, returnăm caracterul nul
        }
    }

    // Operator de iesire
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    // Operator de intrare
    friend std::istream& operator>>(std::istream& is, String& str) {
        char buffer[1000];  // Alocăm un buffer temporar
        is >> buffer;  // Citim în buffer
        str = buffer;  // Folosim operatorul de atribuire pentru a actualiza String-ul
        return is;
    }
};

int main() {
    String s1 = "Hello";
    String s2 = " World";
    
    String s3 = s1 + s2;
    std::cout << "s1 + s2: " << s3 << std::endl;

    s1 += s2;
    std::cout << "s1 += s2: " << s1 << std::endl;

    if (s1 == s3) {
        std::cout << "s1 este egal cu s3" << std::endl;
    }

    String s4 = "ABC";
    if (s4 < s1) {
        std::cout << "s4 este mai putin decat s1" << std::endl;
    }

    std::cout << "Introdu un sir: ";
    String input;
    std::cin >> input;
    std::cout << "Ai introdus: " << input << std::endl;

    return 0;
}
