#include <iostream>
#include <cmath>
using namespace std;

double cube_root_standard(double a) {
    return pow(a, 1.0 / 3);
}

double cube_root_iterative(double a, double epsilon = 1e-6, int max_iterations = 100) {
    double x = a;  // Исходное приближение
    for (int i = 0; i < max_iterations; ++i) {
        x = (2 * x + a / (x * x)) / 3;  // Итерационная формула
        if (abs(x * x * x - a) < epsilon) {
            return x;
        }
    }
    return x;  // Возвращаем приближенный результат, если не сошлись
}

int main() {
    system("chcp 1251");
    double number = 27.0;
    double result;
    result = cube_root_standard(number);
    cout << "Вариант 1: кубический корень числа " << number << " равен " << result << endl;
    result = cube_root_iterative(number);
    cout << "Вариант 2: кубический корень числа " << number << " равен " << result << endl;
}