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

    // Перегрузка операции сложения объектов Time
    Time operator+(const Time& t) const {
        return addTime(t);
    }

    // Перегрузка операции вычитания объектов Time
    Time operator-(const Time& t) const {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diff = total1 - total2;

        // Обработка отрицательного результата
        if (diff < 0)
            diff += 24 * 3600;

        return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    // Перегрузка операции сложения объекта Time и переменной вещественного типа
    Time operator+(double secondsToAdd) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        totalSeconds += static_cast<int>(secondsToAdd);

        return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
    }

    // Перегрузка операции сложения переменной вещественного типа и объекта Time
    friend Time operator+(double secondsToAdd, const Time& t) {
        return t + secondsToAdd;
    }

    // Перегрузка операции сравнения двух объектов Time
    bool operator==(const Time& t) const {
        return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
    }
};
