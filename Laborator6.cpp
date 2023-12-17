#include <iostream>

// Clasa abstractă pentru dirijare
class Direction {
public:
    virtual void steeringRoots() = 0;
};

// Clasa derivată pentru dirijare liniară
class LinearDirection : public Direction {
public:
    void steeringRoots() override {
        std::cout << "Implementare pentru dirijare liniara\n";
    }
};

// Clasa derivată pentru dirijare pătratică
class QuadraticDirection : public Direction {
public:
    void steeringRoots() override {
        std::cout << "Implementare pentru dirijare patratica\n";
    }
};

int main() {
    // Exemplu de utilizare a clasei abstracte și claselor derivate
    Direction* linear = new LinearDirection();
    Direction* quadratic = new QuadraticDirection();

    std::cout << "Dirijare liniara: ";
    linear->steeringRoots();

    std::cout << "Dirijare patratica: ";
    quadratic->steeringRoots();

    // Eliberarea memoriei alocată dinamic
    delete linear;
    delete quadratic;

    return 0;
}
