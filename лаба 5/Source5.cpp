#include <iostream>
#include <vector>
#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;

public:
    // Конструктор за замовчуванням
    Car() : brand(""), model(""), year(0) {}

    // Конструктор з параметрами
    Car(std::string b, std::string m, int y) : brand(b), model(m), year(y) {
        if (y < 1886 || y > 2024) {
            std::cerr << "Некоректний рік випуску! Рік встановлено на 0.\n";
            year = 0;
        }
    }

    // Методи введення даних
    void setBrand(const std::string& b) { brand = b; }
    void setModel(const std::string& m) { model = m; }
    void setYear(int y) {
        if (y >= 1886 && y <= 2024) {
            year = y;
        }
        else {
            std::cerr << "Некоректний рік випуску!\n";
        }
    }

    // Методи виведення інформації
    void displayInfo() const {
        std::cout << "Марка: " << brand << ", Модель: " << model
            << ", Рік випуску: " << year << "\n";
    }

    // Геттери
    int getYear() const { return year; }
};

// Функція пошуку автомобілів за критерієм
void findCarsByYear(const std::vector<Car>& cars, int year) {
    bool found = false;
    for (const auto& car : cars) {
        if (car.getYear() == year) {
            car.displayInfo();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Автомобілів " << year << " року немає.\n";
    }
}

int main() {
    // Створення екземплярів класу
    Car car1("Toyota", "Camry", 2020);
    Car car2("BMW", "X5", 2018);
    Car car3("Ford", "Focus", 2020);

    // Збереження у вектор
    std::vector<Car> cars = { car1, car2, car3 };

    // Виведення інформації про всі автомобілі
    std::cout << "Список автомобілів:\n";
    for (const auto& car : cars) {
        car.displayInfo();
    }

    // Пошук автомобілів за роком
    int searchYear = 2020;
    std::cout << "\nПошук автомобілів " << searchYear << " року:\n";
    findCarsByYear(cars, searchYear);

    return 0;
}