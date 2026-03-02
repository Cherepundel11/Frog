#include <iostream>
#include <string>
#include <cctype>
#include "Potion.h"

// Пример использования
int main() {
    setlocale(LC_ALL, "RUSSIAN");
    std::vector<std::string> ingredientsA = { "корень мандрагоры","корень мандрагоры", "глаз тритона", "чешуя дракона", "сера" };
    std::vector<std::string> ingredientsB = { "чешуя дракона","чешуя дракона", "сера", "крыло летучей мыши" };
    
    Potion potionA("Эликсир силы", "вода", 20, ingredientsA);
    Potion potionB("Зелье невидимости", "масло", 10, ingredientsB);
    
    std::cout << "Зелье A:" << std::endl;
    potionA.print();
    
    std::cout << "Зелье B:" << std::endl;
    potionB.print();
    
    //ТЕСТ ОПЕРАТОРА + СМЕШИВАНИЕ
    std::cout << std::endl;

    // Демонстрация оператора +
    Potion potionC = potionA + potionB;
    std::cout << "Результат potionA + potionB:" << std::endl;
    potionC.print();
    
    //ТЕСТ ОПЕРАТОРА * ТРАНСМУТАЦИЯ
    std::cout << std::endl;

    // Демонстрация оператора *
    Potion potionD = potionA * potionB;
    std::cout << "Результат potionA * potionB:" << std::endl;
    potionD.print();
    
    //ТЕСТ КОПИРОВАНИЯ
    std::cout << std::endl;
    
    // Копирующий конструктор
    std::cout << "Создаем potionE как копию potionC:" << std::endl;
    Potion potionE = potionC; // копирующий конструктор
    potionE.print();
    
    //ТЕСТ ПЕРЕМЕЩЕНИЯ
    std::cout << std::endl;
    
    // Перемещающий конструктор
    std::cout << "Создаем potionF перемещением из potionD:" << std::endl;
    Potion potionF = std::move(potionD); // перемещающий конструктор
    potionF.print();
    
    // Проверяем, что potionD теперь пустой (перемещенный)
    std::cout << "Состояние potionD после перемещения:" << std::endl;
    potionD.print();
    
    //ТЕСТ ПРИСВАИВАНИ
    std::cout << std::endl;
    
    // Копирующее присваивание
    std::cout << "Присваиваем potionA = potionB:" << std::endl;
    potionA = potionB; // копирующее присваивание
    potionA.print();
    
    // Перемещающее присваивание
    std::cout << "Присваиваем potionB = std::move(potionC):" << std::endl;
    potionB = std::move(potionC); // перемещающее присваивание
    potionB.print();
    
    //ТЕСТ ЦЕПОЧКИ ОПЕРАЦИЙ
    std::cout << std::endl;
    
    // Демонстрация сложных выражений
    Potion potionG("База", "спирт", 5, { "трава", "камень" });
    Potion potionH("Добавка", "вода", 3, { "камень", "кровь" });
    
    std::cout << "Сложное выражение: (potionG + potionH) * potionG" << std::endl;
    Potion potionI = (potionG + potionH) * potionG;
    potionI.print();
    
    //ТЕСТ САМОПРИСВАИВАНИЯ
    std::cout << std::endl;
    
    // Проверка защиты от самоприсваивания
    std::cout << "Пробуем potionG = potionG:" << std::endl;
    potionG = potionG; // должно сработать без ошибок
    potionG.print();
    

    std::cout << "Создаем временное зелье в блоке:" << std::endl;
    {
        Potion temp("Временное", "вода", 1, { "пыль", "пепел" });
        temp.print();
    }
    
    std::cout << "Завершение main() - все оставшиеся объекты будут уничтожены" << std::endl;
    
}
