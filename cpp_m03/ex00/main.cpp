#include "ClapTrap.hpp"

int main() {
    // 1. Создание робота
    ClapTrap robot("WALL-E");

    // 2. Атака (Тратит 1 энергию)
    robot.attack("Target Dummy");

    // 3. Получение урона (Не тратит энергию, тратит HP)
    robot.takeDamage(5);  // Останется 5 HP

    // 4. Починка (Тратит 1 энергию, восстанавливает HP)
    robot.beRepaired(3);  // Станет 8 HP

    // 5. Получение смертельного урона
    robot.takeDamage(10);  // HP должно стать 0 (не уйти в минус)

    // 6. Попытка действия мертвым
    robot.attack("Eva");  // Должен отказать]
    robot.beRepaired(5);  // Должен отказать

    // 7. Тест энергии (создадим нового)
    std::cout << "\n--- Energy Test ---" << std::endl;
    ClapTrap robot2("BatteryBot");

    // Тратим всю энергию (у него 10 очков, делаем 10 атак)
    for (int i = 0; i < 10; i++) {
        robot2.attack("SpamTarget");
    }

    // 11-я попытка (энергии нет)
    robot2.attack("SpamTarget");  // Должен отказать

    // Деструкторы вызовутся автоматически в конце
    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}