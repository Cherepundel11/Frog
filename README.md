#include <iostream>
#include <string>
#include <cctype>


class Potion {
private:
    std::string name;
    std::string description;
    double price;
    std::string base;        // основа зелья ( водичка, масло и т.д.)
    double volume;           // в миллилитрах

public:
    // Конструктор по умолчанию
    Potion() : name("Неизвестно"), description("Нет описания"), price(0.0), base("Вода"), volume(100.0) {
        std::cout << "Вызван конструктор по умолчанию." << std::endl;
    }

    // Конструктор полного заполнения
    Potion(const std::string& n, const std::string& desc, double pr, const std::string& b, double vol)
        : name(n), description(desc), price(pr), base(b), volume(vol) {
        std::cout << "Вызван конструктор полного заполнения." << std::endl;
    }

    // Конструктор копирования
    Potion(const Potion& other)
        : name(other.name), description(other.description), price(other.price), base(other.base), volume(other.volume) {
        std::cout << "Вызван конструктор копирования." << std::endl;
    }

    // Деструктор
    ~Potion() {
        std::cout << "Деструктор вызван для зелья: " << name << std::endl;
    }

    // Геттеры для всех полей
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    double getPrice() const { return price; }
    std::string getBase() const { return base; }
    double getVolume() const { return volume; }

    // Сеттер для цены с проверкой (неотрицательная цена)
    void setPrice(double newPrice) {
        if (newPrice >= 0) {
            price = newPrice;
        }
        else {
            std::cout << "Цена не может быть отрицательной. Цена не изменена." << std::endl;
        }
    }

    // Вывод всей информации о зелье
    void displayInfo() const {
        setlocale(LC_ALL, "Russian");
        std::cout << "Информация о зелье:" << std::endl;
        std::cout << "  Название: " << name << std::endl;
        std::cout << "  Описание: " << description << std::endl;
        std::cout << "  Цена: " << price << " золотых" << std::endl;
        std::cout << "  Основа: " << base << std::endl;
        std::cout << "  Объем: " << volume << " мл" << std::endl;
    }

    // Сменить основу (с параметром)
    void changeBase(const std::string& newBase) {
        if (!newBase.empty()) {
            base = newBase;
            std::cout << "Основа изменена на: " << base << std::endl;
        }
        else {
            std::cout << "Новая основа не может быть пустой." << std::endl;
        }
    }

    // Сменить основу (без параметра — на водичку по умолчанию)
    void changeBase() {
        base = "Вода";
        std::cout << "Основа изменена на стандартную: Вода" << std::endl;
    }

    // Отпить зелье (фиксированный объем/порцию)
    void drink(double amount = 50.0) {
        if (amount <= 0) {
            std::cout << "Объем для употребления должен быть положительным." << std::endl;
            return;
        }
        if (amount > volume) {
            std::cout << "Нельзя выпить " << amount << " мл. Осталось только " << volume << " мл." << std::endl;
            volume = 0;
        }
        else {
            volume -= amount;
            std::cout << "Вы выпили " << amount << " мл. Осталось: " << volume << " мл." << std::endl;
        }
        if (volume == 0) {
            std::cout << "Зелье пусто!" << std::endl;
        }
    }
};

// Пример использования
int main() {
    Potion p1("Зелье лечения", "Восстанавливает 50 HP", 120.5, "Балтика 9", 200);
    p1.displayInfo();
    p1.drink(30);
    p1.changeBase("Жигулевский");
    p1.setPrice(150.75);
    p1.displayInfo();

    Potion p2;
    p2.displayInfo();

    Potion p3(p1);
    p3.displayInfo();

    return 0;
}
