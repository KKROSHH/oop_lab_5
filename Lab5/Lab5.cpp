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
            std::cout << "Enter employee's name: " << std::endl;
            getline(std::cin, name);

            std::cout << "Enter employee's age: " << std::endl;
            std::cin >> age;

            std::cout << "Enter employee's position: " << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(std::cin, position);

            std::cout << "Employee created (default constructor)" << std::endl;
        }

        // Конструктор з параметрами
        Employee(std::string name, int age, std::string position) : name(name), age(age), position(position) {
            
            std::cout << "Employee created (parameterized constructor)." << std::endl;
        }

        // Деструктор
        ~Employee() {
            std::cout << "Employee " << name << " destroyed.\n";
        }

        // Метод для введення даних
        void setData(std::string newName, int newAge, std::string newPosition) {
            if (newAge < 18 || newAge > 65) {
                std::cout << "Error: Invalid age. Age must be between 18 and 65.\n";
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

        // Метод для перевірки фільтрування за віком
        void filterByAge(Employee employees[], int size, int ageLimit) {
            bool found = false;
            for (int i = 0; i < size; i++) {
                if (employees[i].getAge() > ageLimit) {
                    employees[i].print();
                    found = true;
                }
            }
            if (!found) {
                std::cout << "No employees older than " << ageLimit << " found." << std::endl;
            }
        }
};

int main() {
    // Створення екземплярів класу
    Employee adam;
    Employee john("John", 28, "Manager");
    Employee bob("Bob", 34, "Accountant");
    Employee leah("Leah", 22, "Programmer");

    // Виведення інформації про співробітників
    std::cout << "\nEmployee Information:\n";
    adam.print();
    std::cout << std::endl;
    john.print();
    std::cout << std::endl;
    bob.print();
    std::cout << std::endl;
    leah.print();
    std::cout << std::endl;

    // Створення масиву об'єктів Employee
    Employee employees[] = { john, bob, leah };
    int size = sizeof(employees) / sizeof(employees[0]);  // Визначення кількості елементів у масиві

    // Фільтрація за віком
    std::cout << "\nEmployees older than 25:\n";
    john.filterByAge(employees, size, 25);
    std::cout << std::endl;

    // Зміна даних та перевірка валідності
    std::cout << "\nUpdating Leah's age to an invalid value (70):\n";
    leah.setData("Leah", 70, "Programmer");  // Спроба встановити некоректний вік
    leah.print();  // Після невдалої спроби зміни вік не буде змінено
}
