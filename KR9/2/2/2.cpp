#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    class TimeException //класс исключений
    {
    public:
        string origin; //для имени функции
        int iValue; //для хранения ошибочного значения
        TimeException(string op , int sc)
        {
            origin = op ; //строка с именем виновника ошибки
            iValue = sc; //сохраненное неправильное значение
        }
    };

public:
    Time() : hours(0), minutes(0), seconds(0) {} // Конструктор инициализации нулями

    Time(int h, int m, int s) { // Конструктор с параметрами
        if (h < 0 || h >= 24) {
            throw TimeException("в конструкторе", h);
        }
        if (m < 0 || m >= 60) {
            throw TimeException("в конструкторе", m);
        }  
        if (s < 0 || s >= 60) {
            throw TimeException("в конструкторе", s);
        }
        hours = h + m / 60 + s / 3600;
        minutes = m % 60 + s / 60;
        seconds = s % 60;
    }

    void displayTime() const { // Метод для вывода времени
        cout << hours << ":" << minutes << ":" << seconds << endl;
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
    system("chcp 1251");
    try {
        const Time time1(26, 45, 30); // Инициализированный объект 1
        const Time time2(3, 20, 45); // Инициализированный объект 2
        Time time3; // Неинициализированный объект

        time3 = time1.addTime(time2); // Сложение временных значений
        time3.displayTime(); // Вывод результата на экран
    }
    catch (Time::TimeException& e) {
        cout << "\nОшибка инициализации " << e.origin;
        cout << "\nВведенное значение времени " << e.iValue << " является недопустимым\n";
    }
    return 0;
}
