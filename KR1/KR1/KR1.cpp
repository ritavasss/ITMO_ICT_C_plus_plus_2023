#include <iostream>
#include <cmath>

using namespace std;

int main() {

    system("chcp 1251");

    double vertices[5][2];

    // Ввод координат вершин от пользователя
    for (int i = 0; i < 5; ++i) {
        cout << "Введите координаты вершины " << i + 1 << " (x y): ";
        cin >> vertices[i][0] >> vertices[i][1];
    }

    // Вычисление площади по формуле Гаусса
    double area = 0.0;
    for (int i = 0; i < 4; ++i) {
        area += vertices[i][0] * vertices[i + 1][1] - vertices[i + 1][0] * vertices[i][1];
    }
    area += vertices[4][0] * vertices[0][1] - vertices[0][0] * vertices[4][1];
    area /= 2.0;
    area = abs(area);

    // Вывод площади
    cout << "Площадь пятиугольника: " << area << endl;

    return 0;
}
