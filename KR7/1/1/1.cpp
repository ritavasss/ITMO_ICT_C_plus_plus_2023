#include <iostream>
#include <windows.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Функция для ввода времени
void inputTime(Time& t) {
    std::cout << "Введите часы: ";
    std::cin >> t.hours;

    std::cout << "Введите минуты: ";
    std::cin >> t.minutes;

    std::cout << "Введите секунды: ";
    std::cin >> t.seconds;
}

// Функция для вывода времени
void printTime(const Time& t) {
    std::cout << "Время: " << t.hours << " часов, " << t.minutes << " минут, " << t.seconds << " секунд\n";
}

// Функция для вычисления общего количества секунд во времени
int calculateTotalSeconds(const Time& t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

// Функция для сложения двух временных интервалов
Time addTime(const Time& t1, const Time& t2) {
    Time result;
    result.hours = t1.hours + t2.hours;
    result.minutes = t1.minutes + t2.minutes;
    result.seconds = t1.seconds + t2.seconds;

    // Обработка переполнений
    result.minutes += result.seconds / 60;
    result.seconds %= 60;

    result.hours += result.minutes / 60;
    result.minutes %= 60;

    return result;
}

// Функция для вычитания двух временных интервалов
Time subtractTime(const Time& t1, const Time& t2) {
    Time result;
    result.hours = t1.hours - t2.hours;
    result.minutes = t1.minutes - t2.minutes;
    result.seconds = t1.seconds - t2.seconds;

    // Обработка заемов
    if (result.seconds < 0) {
        result.seconds += 60;
        result.minutes--;
    }

    if (result.minutes < 0) {
        result.minutes += 60;
        result.hours--;
    }

    return result;
}

int main() {

    system("chcp 1251");
    Time time1, time2;

    std::cout << "Введите первое время:\n";
    inputTime(time1);

    std::cout << "Введите второе время:\n";
    inputTime(time2);

    std::cout << "\nВведенные времена:\n";
    printTime(time1);
    printTime(time2);

    int totalSeconds1 = calculateTotalSeconds(time1);
    int totalSeconds2 = calculateTotalSeconds(time2);

    std::cout << "\nОбщее количество секунд в первом времени: " << totalSeconds1 << " секунд\n";
    std::cout << "Общее количество секунд во втором времени: " << totalSeconds2 << " секунд\n";

    Time sum = addTime(time1, time2);
    Time difference = subtractTime(time1, time2);

    std::cout << "\nСумма временных интервалов:\n";
    printTime(sum);

    std::cout << "\nРазница временных интервалов:\n";
    printTime(difference);

    return 0;
}
