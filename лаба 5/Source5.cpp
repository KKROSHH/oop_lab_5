#include <iostream>
#include <vector>
#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;

public:
    // ����������� �� �������������
    Car() : brand(""), model(""), year(0) {}

    // ����������� � �����������
    Car(std::string b, std::string m, int y) : brand(b), model(m), year(y) {
        if (y < 1886 || y > 2024) {
            std::cerr << "����������� �� �������! г� ����������� �� 0.\n";
            year = 0;
        }
    }

    // ������ �������� �����
    void setBrand(const std::string& b) { brand = b; }
    void setModel(const std::string& m) { model = m; }
    void setYear(int y) {
        if (y >= 1886 && y <= 2024) {
            year = y;
        }
        else {
            std::cerr << "����������� �� �������!\n";
        }
    }

    // ������ ��������� ����������
    void displayInfo() const {
        std::cout << "�����: " << brand << ", ������: " << model
            << ", г� �������: " << year << "\n";
    }

    // �������
    int getYear() const { return year; }
};

// ������� ������ ��������� �� �������
void findCarsByYear(const std::vector<Car>& cars, int year) {
    bool found = false;
    for (const auto& car : cars) {
        if (car.getYear() == year) {
            car.displayInfo();
            found = true;
        }
    }
    if (!found) {
        std::cout << "��������� " << year << " ���� ����.\n";
    }
}

int main() {
    // ��������� ���������� �����
    Car car1("Toyota", "Camry", 2020);
    Car car2("BMW", "X5", 2018);
    Car car3("Ford", "Focus", 2020);

    // ���������� � ������
    std::vector<Car> cars = { car1, car2, car3 };

    // ��������� ���������� ��� �� ��������
    std::cout << "������ ���������:\n";
    for (const auto& car : cars) {
        car.displayInfo();
    }

    // ����� ��������� �� �����
    int searchYear = 2020;
    std::cout << "\n����� ��������� " << searchYear << " ����:\n";
    findCarsByYear(cars, searchYear);

    return 0;
}