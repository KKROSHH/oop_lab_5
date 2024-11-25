#include <iostream>
#include <string>
#include <limits>

class Employee {
private:
    std::string name;
    int age;
    std::string position;

public:
    // Конструктор за замовчуванням
    Employee() {
        for (;;) {
            std::cout << "Enter employee's name: " << std::endl;
            getline(std::cin, name);

            if (name.empty()) {
                std::cout << "Error: Name cannot be empty. Please try again.\n";
                continue;
            }

            std::cout << "Enter employee's age: " << std::endl;
            std::cin >> age;

            if (std::cin.fail() || age < 18 || age > 65) {
                std::cout << "Error: Invalid age. Age must be between 18 and 65. Please try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter employee's position: " << std::endl;
            getline(std::cin, position);

            if (position.empty()) {
                std::cout << "Error: Position cannot be empty. Please try again.\n";
                continue;
            }

            std::cout << "Employee created (default constructor)" << std::endl;
            break;
        }
    }

    // Деструктор
    ~Employee() {
        std::cout << "Employee " << name << " destroyed.\n";
    }

    // Метод для введення даних
    void setData(std::string newName, int newAge, std::string newPosition) {
        if (newAge < 18 || newAge > 65) {
            std::cout << "Error: Invalid age. Age must be between 18 and 65.\n";
        } else if (newName.empty() || newPosition.empty()) {
            std::cout << "Error: Name and position cannot be empty.\n";
        } else {
            name = newName;
            age = newAge;
            position = newPosition;
        }
    }

    // Метод для виведення даних
    void print() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Position: " << position << std::endl;
    }

    // Гетери для полів класу
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getPosition() const { return position; }

    // Метод для фільтрації співробітників
    static void filterEmployees(Employee employees[], int size, const std::string& filterPosition = "", int ageLimit = -1, bool older = true) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            bool matchesPosition = filterPosition.empty() || employees[i].getPosition() == filterPosition;
            bool matchesAge = (ageLimit == -1) || (older ? employees[i].getAge() > ageLimit : employees[i].getAge() < ageLimit);

            if (matchesPosition && matchesAge) {
                employees[i].print();
                found = true;
            }
        }

        if (!found) {
            std::cout << "No employees match the filter criteria.\n";
        }
    }
};

int main() {
    // Створення екземплярів класу
    Employee adam;
    Employee john;
    Employee leah;

    // Виведення інформації про співробітників
    std::cout << "\nEmployee Information:\n";
    adam.print();
    std::cout << std::endl;
    john.print();
    std::cout << std::endl;
    leah.print();
    std::cout << std::endl;

    // Створення масиву об'єктів Employee
    Employee employees[] = { adam, john, leah };
    int size = sizeof(employees) / sizeof(employees[0]);  // Визначення кількості елементів у масиві

    // Фільтрація за віком старших за 25 років
    std::cout << "\nEmployees older than 25:\n";
    Employee::filterEmployees(employees, size, "", 25, true);

    // Фільтрація за посадою
    std::cout << "\nEmployees with position 'Manager':\n";
    Employee::filterEmployees(employees, size, "Manager");

    // Фільтрація за віком молодших за 30 років
    std::cout << "\nEmployees younger than 30:\n";
    Employee::filterEmployees(employees, size, "", 30, false);

    return 0;
}
