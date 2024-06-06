#include "Time.cpp"
#include <iostream>

int main() {
    const Time time1(10, 45, 30); // Инициализированный объект 1
    const Time time2(3, 20, 45); // Инициализированный объект 2
    Time time3; // Неинициализированный объект

    // Сложение объектов Time
    time3 = time1 + time2;
    time3.displayTime(); // Ожидаем результат: 14:6:15

    // Вычитание объектов Time
    Time time4 = time1 - time2;
    time4.displayTime(); // Ожидаем результат: 7:24:45

    // Сложение объекта Time и переменной вещественного типа
    Time time5 = time1 + 150.5;
    time5.displayTime(); // Ожидаем результат: 10:47:0

    // Сложение переменной вещественного типа и объекта Time
    Time time6 = 75.5 + time2;
    time6.displayTime(); // Ожидаем результат: 3:22:0

    // Сравнение двух объектов Time
    if (time1 == time2) {
        std::cout << "time1 and time2 are equal." << std::endl;
    }
    else {
        std::cout << "time1 and time2 are not equal." << std::endl;
    }

    return 0;
}
