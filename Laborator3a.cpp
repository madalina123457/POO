#include <iostream>

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Metoda pentru adunarea a două obiecte Date
    Date operator+(const Date& other) const {
        Date result(*this); // Creăm o copie a obiectului curent
        result.day += other.day;
        result.month += other.month;
        result.year += other.year;

        // Verificăm și ajustăm pentru depășirea limitelor
        if (result.day > 31) {
            result.day -= 31;
            result.month++;
        }
        if (result.month > 12) {
            result.month -= 12;
            result.year++;
        }

        return result;
    }

    // Metoda pentru scăderea a două obiecte Date
    Date operator-(const Date& other) const {
        Date result(*this); // Creăm o copie a obiectului curent
        result.day -= other.day;
        result.month -= other.month;
        result.year -= other.year;

        // Verificăm și ajustăm pentru depășirea limitelor
        if (result.day < 1) {
            result.month--;
            result.day += 31;
        }
        if (result.month < 1) {
            result.year--;
            result.month += 12;
        }

        return result;
    }

    // Funcții prietene pentru operatorii "++" și "--"
    friend Date operator++(Date& date);       // Prefix
    friend Date operator++(Date& date, int);  // Postfix
    friend Date operator--(Date& date);       // Prefix
    friend Date operator--(Date& date, int);  // Postfix

    // Funcție pentru afișarea datei
    void display() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

// Implementarea funcțiilor prietene pentru operatorii "++" și "--"
Date operator++(Date& date) {
    date.day++;
    if (date.day > 31) {
        date.day = 1;
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

Date operator++(Date& date, int) {
    Date temp(date); // Salvăm starea curentă a obiectului
    ++date;          // Incrementăm obiectul curent
    return temp;     // Returnăm starea salvată anterior incrementării
}

Date operator--(Date& date) {
    date.day--;
    if (date.day < 1) {
        date.month--;
        if (date.month < 1) {
            date.month = 12;
            date.year--;
        }
        date.day = 31;
    }
    return date;
}

Date operator--(Date& date, int) {
    Date temp(date); // Salvăm starea curentă a obiectului
    --date;          // Decrementăm obiectul curent
    return temp;     // Returnăm starea salvată anterior decrementării
}

int main() {
    Date today(26, 11, 2023);
    Date tomorrow = today + Date(1, 0, 0);
    Date yesterday = today - Date(1, 0, 0);

    std::cout << "Today: ";
    today.display();

    std::cout << "Tomorrow: ";
    tomorrow.display();
    std::cout << "Yesterday: ";
    yesterday.display();
    std::cout << "Incrementing today: ";
    ++today;
    today.display();
    std::cout << "Decrementing today: ";
    --today;
    today.display();
    return 0;
}
