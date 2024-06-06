#include <iostream>
#include <cmath>
using namespace std;

int Myroot(double a, double b, double c, double& x1, double& x2) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // Два действительных корня
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        return 1;
    }
    else if (discriminant == 0) {
        // Один действительный корень (корни совпадают)
        x1 = -b / (2 * a);
        x2 = x1;
        return 0;
    }
    else {
        // Нет действительных корней
        return -1;
    }
}

int main() {
    system("chcp 1251");

    double a, b, c, x1, x2;

    cout << "Введите коэффициенты a, b и c: ";
    cin >> a >> b >> c;

    int result = Myroot(a, b, c, x1, x2);

    if (result == 1) {
        cout << "Корни уравнения: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (result == 0) {
        cout << "Корень уравнения один: x1 = x2 = " << x1 << endl;
    }
    else {
        cout << "Корней уравнения нет" << endl;
    }

    return 0;
}
