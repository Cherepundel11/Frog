#include <iostream>
#include <string>
#include <vector>

class Potion {
private:
    std::string name_;
    std::string base_;
    int volume_;
    std::vector<std::string> ingredients_;

public:
    //  онструкторы
    Potion();
    Potion(const std::string& name, const std::string& base, int volume, const std::vector<std::string>& ingredients);
    Potion(const Potion& other); // копирующий конструктор
    Potion(Potion&& other) noexcept; // перемещающий конструктор

    // ƒеструктор
    ~Potion();

    // ќператоры присваивани€
    Potion& operator=(const Potion& other); // копирующий
    Potion& operator=(Potion&& other) noexcept; // перемещающий

    // ѕерегруженные операторы
    Potion operator+(const Potion& other) const; // +
    Potion operator*(const Potion& other) const; // *
    //добавить оператор =+

    // ¬спомогательные методы
    void print() const;

    static std::string randomBase();
};