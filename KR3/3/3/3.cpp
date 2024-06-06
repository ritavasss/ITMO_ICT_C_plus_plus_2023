#include <iostream>
#include <cmath>
using namespace std;

// Функция для вычисления площади равностороннего треугольника
double calculatelArea(double a) {
    double area = (sqrt(3) / 4) * a * a;
    return area;
}

// Перезагрузка предыдущей функции для вычисления площади разностороннего треугольника
void calculatelArea(double a, double b, double c) {
    // Используем полупериметр
    double s = (a + b + c) / 2;

    // Применяем формулу Герона
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << "Площадь треугольника: " << area << endl;
}

int main() {
    system("chcp 1251");
    int choice;
    cout << "Выберите тип треугольника (1 - равносторонний, 2 - разносторонний): ";
    cin >> choice;

    if (choice == 1) {
        double side;
        cout << "Введите длину стороны равностороннего треугольника: ";
        cin >> side;
        double area = calculatelArea(side);
        cout << "Площадь треугольника: " << area << endl;
    }
    else if (choice == 2) {
        double a, b, c;
        cout << "Введите длины трех сторон разностороннего треугольника: ";
        cin >> a >> b >> c;
        calculatelArea(a, b, c);
    }
    else {
        cout << "Неверный выбор." << endl;
    }
}
