#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    system("chcp 1251");
    
    srand(time(0)); // Инициализируем генератор случайных чисел

    const int numShots = 5; // Задаем количество выстрелов
    int totalScore = 0;
    const int targetRadius = 2;

    cout << "Стрельба по мишени" << endl;
    cout << "У вас " << numShots << " выстрелов." << endl;

    for (int i = 1; i <= numShots; ++i) {
        double targetX = (rand() % (2 * targetRadius + 1)) - targetRadius; // Случайная координата x в диапазоне [-2, 2]
        double targetY = (rand() % (2 * targetRadius + 1)) - targetRadius; // Случайная координата y в диапазоне [-2, 2]

        double shotX, shotY;
        cout << "Введите координаты выстрела #" << i << " (x y): ";
        cin >> shotX >> shotY;

        // Генерируем случайную помеху от -0.5 до 0.5 в координатах x и y
        double noiseX = (rand() % 1000 - 500) / 1000.0;
        double noiseY = (rand() % 1000 - 500) / 1000.0;

        // Добавляем случайную помеху к координатам выстрела
        shotX += noiseX;
        shotY += noiseY;

        // Вычисляем расстояние от выстрела до мишени
        double distance = sqrt(pow(targetX - shotX, 2) + pow(targetY - shotY, 2));

        // Оцениваем результат выстрела
        int score = 0;
        if (distance <= 1.0) {
            score = 10;
        }
        else if (distance <= 2.0) {
            score = 5;
        }

        totalScore += score;
        cout << "Вы заработали " << score << " баллов на этом выстреле." << endl;
    }

    // Определяем уровень стрелка
    string shooterLevel;
    if (totalScore >= 40) {
        shooterLevel = "Снайпер";
    }
    else if (totalScore >= 20) {
        shooterLevel = "Просто стрелок";
    }
    else {
        shooterLevel = "Новичок";
    }

    cout << "Итоговый счет: " << totalScore << " баллов." << endl;
    cout << "Ваш уровень как стрелка: " << shooterLevel << endl;

    return 0;
}
