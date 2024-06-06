#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {} // Конструктор инициализации нулями

    Time(int h, int m, int s) { // Конструктор с параметрами
        hours = h + m / 60 + s / 3600;
        minutes = m % 60 + s / 60;
        seconds = s % 60;
    }

    void displayTime() const { // Метод для вывода времени
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    Time addTime(const Time& t) const { // Метод для сложения времени
        Time sum;
        sum.seconds = seconds + t.seconds;
        sum.minutes = minutes + t.minutes + sum.seconds / 60;
        sum.hours = hours + t.hours + sum.minutes / 60;
        sum.minutes %= 60;
        sum.seconds %= 60;
        sum.hours %= 24;
        return sum;
    }
};

int main() {
    const Time time1(10, 45, 30); // Инициализированный объект 1
    const Time time2(3, 20, 45); // Инициализированный объект 2
    Time time3; // Неинициализированный объект

    time3 = time1.addTime(time2); // Сложение временных значений
    time3.displayTime(); // Вывод результата на экран

    return 0;
}
