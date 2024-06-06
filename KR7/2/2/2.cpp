#include <iostream>
#include <cmath>

// Структура для хранения корней квадратного уравнения
struct QuadraticSolution {
    double x1;
    double x2;
    bool realRoots;  // Флаг, указывающий, существуют ли вещественные корни
};

// Функция для решения квадратного уравнения
QuadraticSolution solveQuadraticEquation(double a, double b, double c) {
    QuadraticSolution result;

    // Вычисляем дискриминант
    double discriminant = b * b - 4 * a * c;

    // Проверяем условия для наличия вещественных корней
    if (discriminant > 0) {
        result.realRoots = true;
        result.x1 = (-b + sqrt(discriminant)) / (2 * a);
        result.x2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    else if (discriminant == 0) {
        result.realRoots = true;
        result.x1 = -b / (2 * a);
        result.x2 = result.x1;
    }
    else {
        result.realRoots = false;  // Вещественных корней нет
    }

    return result;
}

int main() {
    system("chcp 1251");

    double a, b, c;

    std::cout << "Введите коэффициенты a, b, c для уравнения ax^2 + bx + c = 0: ";
    std::cin >> a >> b >> c;

    QuadraticSolution solution = solveQuadraticEquation(a, b, c);

    if (solution.realRoots) {
        std::cout << "Корни уравнения: " << solution.x1 << " и " << solution.x2 << std::endl;
    }
    else {
        std::cout << "Уравнение не имеет вещественных корней." << std::endl;
    }

    return 0;
}
