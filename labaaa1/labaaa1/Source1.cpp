#include <iostream>
#include "Potion.h"
#include <algorithm>
#include <random>

// Статический генератор случайной основы
std::string Potion::randomBase() {
    static const char* bases[] = { "вода", "масло", "спирт", "кровь", "эфир" };
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(0, 4);
    return bases[dist(rng)];
}

// Конструктор по умолчанию
Potion::Potion() : name_("Unknown"), base_("вода"), volume_(0) {}

// Параметризованный конструктор
Potion::Potion(const std::string& name, const std::string& base, int volume, const std::vector<std::string>& ingredients)
{
    name_ = name;
    base_ = base;
    volume_ = volume;
    ingredients_ = ingredients;
}

// Копирующий конструктор
Potion::Potion(const Potion& other)
{
    std::cout << "Potion скопирован (конструктор копирования)\n";
    name_ = other.name_;
    base_ = other.base_;
    volume_ = other.volume_;
    ingredients_ = other.ingredients_;
}

// Перемещающий конструктор
Potion::Potion(Potion&& other) noexcept
{
    other.volume_ = 0;
    std::cout << "Potion перемещён (конструктор перемещения)\n";
    name_ = other.name_;
    base_ = other.base_;
    volume_ = other.volume_;
    ingredients_ = other.ingredients_;
}

// Деструктор
Potion::~Potion() {
    if (!ingredients_.empty()) {
        ingredients_.clear(); 
    }
    std::cout << "Potion \"" << name_ << "\" уничтожен, вектор очищен\n";
}

// Копирующее присваивание
Potion& Potion::operator=(const Potion& other) {
    std::cout << "Potion operator= (копирование)\n";
    if (this == &other) return *this;
    name_ = other.name_;
    base_ = other.base_;
    volume_ = other.volume_;
    ingredients_ = other.ingredients_;
    return *this;
}

// Перемещающее присваивание
Potion& Potion::operator=(Potion&& other) noexcept {
    std::cout << "Potion operator= (перемещение)\n";
    if (this == &other) return *this;
    name_ = std::move(other.name_);
    base_ = std::move(other.base_);
    volume_ = other.volume_;
    ingredients_ = std::move(other.ingredients_);
    other.volume_ = 0;
    return *this;
}

// Оператор +
Potion Potion::operator+(const Potion& other) const { // название не от обьема
    std::string newName = (volume_ > other.volume_) ? name_ + "+обн." : other.name_ + "+обн.";
    if (volume_ == other.volume_) newName = name_ + "+" + other.name_; 

    std::string newBase = (volume_ >= other.volume_) ? base_ : other.base_;

    int newVolume = volume_ + other.volume_;
    //Обн. только для +=, в случае + имя любое
    std::vector<std::string> newIngredients = ingredients_;
    for (const auto& ing : other.ingredients_) {
        if (std::find(newIngredients.begin(), newIngredients.end(), ing) != newIngredients.end()) {
            newIngredients.push_back(ing + " доп");
        }
        else {
            newIngredients.push_back(ing);
        }
    }

    return Potion(newName, newBase, newVolume, newIngredients);
}

// Оператор *
Potion Potion::operator*(const Potion& other) const {
    std::string newBase = randomBase();
    int newVolume = static_cast<int>((volume_ + other.volume_) * 0.8);

    std::vector<std::string> common;
    for (const auto& ing1 : ingredients_) {
        for (const auto& ing2 : other.ingredients_) {
            if (ing1 == ing2) {
                common.push_back(ing1);
                break;
            }
        }
    }
    common.push_back("хвост");
    common.push_back("вода");

    return Potion("K", newBase, newVolume, common);
}

// Печать
void Potion::print() const {
    std::cout << "Название: " << name_ << "\nОснова: " << base_ << "\nОбъём: " << volume_ << " мл\nИнгредиенты: ";
    for (size_t i = 0; i < ingredients_.size(); ++i) {
        std::cout << ingredients_[i];
        if (i != ingredients_.size() - 1) std::cout << ", ";
    }
    std::cout << "\n\n";
}