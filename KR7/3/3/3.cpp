#include <iostream>
#include <cmath>
#include <tuple>

// Функция для решения квадратного уравнения
std::tuple<bool, double, double> solveQuadraticEquation(double a, double b, double c) {
    // Вычисляем дискриминант
    double discriminant = b * b - 4 * a * c;

    // Проверяем условия для наличия вещественных корней
    if (discriminant > 0) {
        // Есть два вещественных корня
        return std::make_tuple(true, (-b + sqrt(discriminant)) / (2 * a), (-b - sqrt(discriminant)) / (2 * a));
    }
    else if (discriminant == 0) {
        // Есть один вещественный корень
        return std::make_tuple(true, -b / (2 * a), -b / (2 * a));
    }
    else {
        // Нет вещественных корней
        return std::make_tuple(false, 0.0, 0.0);
    }
}

int main() {
    system("chcp 1251");

    double a, b, c;

    std::cout << "Введите коэффициенты a, b, c для уравнения ax^2 + bx + c = 0: ";
    std::cin >> a >> b >> c;

    auto result = solveQuadraticEquation(a, b, c);

    bool hasRealRoots;
    double x1, x2;

    std::tie(hasRealRoots, x1, x2) = result;

    if (hasRealRoots) {
        std::cout << "Корни уравнения: " << x1 << " и " << x2 << std::endl;
    }
    else {
        std::cout << "Уравнение не имеет вещественных корней." << std::endl;
    }

    return 0;
}
