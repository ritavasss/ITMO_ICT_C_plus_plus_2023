#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {} // ����������� ������������� ������

    Time(int h, int m, int s) { // ����������� � �����������
        hours = h + m / 60 + s / 3600;
        minutes = m % 60 + s / 60;
        seconds = s % 60;
    }

    void displayTime() const { // ����� ��� ������ �������
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    Time addTime(const Time& t) const { // ����� ��� �������� �������
        Time sum;
        sum.seconds = seconds + t.seconds;
        sum.minutes = minutes + t.minutes + sum.seconds / 60;
        sum.hours = hours + t.hours + sum.minutes / 60;
        sum.minutes %= 60;
        sum.seconds %= 60;
        sum.hours %= 24;
        return sum;
    }

    // ���������� �������� �������� �������� Time
    Time operator+(const Time& t) const {
        return addTime(t);
    }

    // ���������� �������� ��������� �������� Time
    Time operator-(const Time& t) const {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diff = total1 - total2;

        // ��������� �������������� ����������
        if (diff < 0)
            diff += 24 * 3600;

        return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    // ���������� �������� �������� ������� Time � ���������� ������������� ����
    Time operator+(double secondsToAdd) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        totalSeconds += static_cast<int>(secondsToAdd);

        return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
    }

    // ���������� �������� �������� ���������� ������������� ���� � ������� Time
    friend Time operator+(double secondsToAdd, const Time& t) {
        return t + secondsToAdd;
    }

    // ���������� �������� ��������� ���� �������� Time
    bool operator==(const Time& t) const {
        return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
    }
};
