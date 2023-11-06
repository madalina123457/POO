#include <iostream>

struct Vector {
    int* data; // Pointer la elementele vectorului
    int size;  // Numărul de elemente din vector

    // Inițializarea vectorului
    void initialize(int initialSize) {
        size = initialSize;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0; // Inițializăm toate elementele cu 0
        }
    }

    // Eliminarea vectorului
    void destroy() {
        delete[] data;
        size = 0;
    }

    // Setarea dimensiunii vectorului
    void resize(int newSize) {
        int* newData = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            if (i < size) {
                newData[i] = data[i];
            } else {
                newData[i] = 0; // Inițializăm noile elemente cu 0
            }
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

    // Acces la elementul de la indexul specificat
    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            std::cout << "Index invalid\n";
            exit(1);
        }
    }

    // Calculul sumei elementelor pare din vector
    int sumOfEvenElements() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (data[i] % 2 == 0) {
                sum += data[i];
            }
        }
        return sum;
    }
};

int main() {
    int size;
    std::cout << "Introduceți dimensiunea vectorului: ";
    std::cin >> size;

    Vector vector1;
    vector1.initialize(size);

    Vector vector2;
    vector2.initialize(size);

    // Umplem vectorii cu date de exemplu
    for (int i = 0; i < size; i++) {
        vector1[i] = i * 2;
        vector2[i] = i * 3;
    }

    // Calculăm suma elementelor pare din primul vector
    int sum1 = vector1.sumOfEvenElements();
    std::cout << "Suma elementelor pare din vectorul 1: " << sum1 << std::endl;

    // Adunăm cei doi vectori
    Vector sumVector;
    sumVector.initialize(size);
    for (int i = 0; i < size; i++) {
        sumVector[i] = vector1[i] + vector2[i];
    }

    // Afișăm rezultatul adunării
    std::cout << "Rezultatul adunării celor doi vectori: ";
    for (int i = 0; i < size; i++) {
        std::cout << sumVector[i] << " ";
    }
    std::cout << std::endl;

    // Eliberăm resursele
    vector1.destroy();
    vector2.destroy();
    sumVector.destroy();

    return 0;
}