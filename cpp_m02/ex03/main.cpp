#include <iostream>
#include <string>

#include "Point.hpp"

// Цвета
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

// Прототип
bool bsp(Point const a, Point const b, Point const c, Point const point);

// Глобальные счетчики
int g_passed = 0;
int g_total = 0;

// Функция-помощник для красивого вывода
void run_test(std::string testName, Point a, Point b, Point c, Point p, bool expected) {
    g_total++;
    bool result = bsp(a, b, c, p);

    std::cout << "Test " << g_total << ": " << testName;

    // Выравнивание пробелами для красоты
    int padding = 50 - testName.length();
    for (int i = 0; i < padding; i++) std::cout << " ";

    if (result == expected) {
        std::cout << GREEN << "[ OK ]" << RESET << std::endl;
        g_passed++;
    } else {
        std::cout << RED << "[ KO ]" << RESET << std::endl;
        std::cout << "   -> Expected: " << (expected ? "TRUE (Inside)" : "FALSE (Outside)") << std::endl;
        std::cout << "   -> Got:      " << (result ? "TRUE" : "FALSE") << std::endl;
    }
}

int main(void) {
    std::cout << CYAN << "=== STARTING BSP STRESS TEST ===" << RESET << std::endl << std::endl;

    // ---------------------------------------------------------
    // СЦЕНАРИЙ 1: Классический треугольник
    // (0,0) -> (10,0) -> (0,10)
    // ---------------------------------------------------------
    Point a1(0, 0);
    Point b1(10, 0);
    Point c1(0, 10);

    run_test("Center (Inside)", a1, b1, c1, Point(2, 2), true);
    run_test("Far Outside", a1, b1, c1, Point(20, 20), false);
    run_test("Vertex A (Corner)", a1, b1, c1, Point(0, 0), false);
    run_test("Vertex B (Corner)", a1, b1, c1, Point(10, 0), false);
    run_test("On Edge AB", a1, b1, c1, Point(5, 0), false);
    run_test("On Edge BC (Hypotenuse)", a1, b1, c1, Point(5, 5), false);

    // ---------------------------------------------------------
    // СЦЕНАРИЙ 2: Тест на точность (Precision Test)
    // Fixed point имеет шаг ~0.0039. Проверяем микро-сдвиги.
    // ---------------------------------------------------------
    std::cout << std::endl << CYAN << "--- PRECISION CHECKS ---" << RESET << std::endl;

    // Чуть-чуть внутри (0.1 > 0)
    run_test("Slightly Inside", a1, b1, c1, Point(0.1f, 0.1f), true);

    // Чуть-чуть снаружи (-0.1 < 0)
    run_test("Slightly Outside", a1, b1, c1, Point(-0.1f, -0.1f), false);

    // Очень близко к грани, но внутри
    // Грань идет по линии Y = 10 - X. Точка (4.9, 5.0) -> Сумма 9.9 < 10. Внутри.
    run_test("Near Hypotenuse (Inside)", a1, b1, c1, Point(4.9f, 5.0f), true);

    // Очень близко к грани, но снаружи
    // Точка (5.1, 5.0) -> Сумма 10.1 > 10. Снаружи.
    run_test("Near Hypotenuse (Outside)", a1, b1, c1, Point(5.1f, 5.0f), false);

    // ---------------------------------------------------------
    // СЦЕНАРИЙ 3: Отрицательные координаты
    // Треугольник полностью в минусовой зоне
    // A(-5, -5), B(-1, -5), C(-3, -1)
    // ---------------------------------------------------------
    std::cout << std::endl << CYAN << "--- NEGATIVE COORDINATES ---" << RESET << std::endl;
    Point a2(-5, -5);
    Point b2(-1, -5);
    Point c2(-3, -1);

    run_test("Negative Center (Inside)", a2, b2, c2, Point(-3, -3), true);
    run_test("Negative Outside", a2, b2, c2, Point(-6, -6), false);
    run_test("Negative Vertex", a2, b2, c2, Point(-5, -5), false);

    // ---------------------------------------------------------
    // СЦЕНАРИЙ 4: Дробные координаты (Float conversion check)
    // ---------------------------------------------------------
    std::cout << std::endl << CYAN << "--- FLOAT CONVERSION ---" << RESET << std::endl;
    Point a3(0.5f, 0.5f);
    Point b3(5.5f, 0.5f);
    Point c3(3.0f, 4.5f);  // Вершина посередине сверху

    // Центр примерно (3, 2)
    run_test("Float Vertices (Inside)", a3, b3, c3, Point(3.0f, 2.0f), true);
    run_test("Float Vertices (Outside)", a3, b3, c3, Point(3.0f, 5.0f), false);

    // ---------------------------------------------------------
    // ИТОГИ
    // ---------------------------------------------------------
    std::cout << std::endl << "========================================" << std::endl;
    if (g_passed == g_total) {
        std::cout << GREEN << "ALL TESTS PASSED (" << g_passed << "/" << g_total << ")" << RESET << std::endl;
        std::cout << "Your Fixed class is working perfectly!" << std::endl;
    } else {
        std::cout << RED << "SOME TESTS FAILED (" << g_passed << "/" << g_total << ")" << RESET << std::endl;
        std::cout << "Check your arithmetic or bsp logic." << std::endl;
    }

    return 0;
}