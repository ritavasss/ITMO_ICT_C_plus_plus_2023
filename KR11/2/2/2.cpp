#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Функция для вычисления расстояния до центра координат
    double distanceToOrigin() const {
        return std::sqrt(x * x + y * y);
    }

    // Перегрузка оператора <
    bool operator<(const Point& other) const {
        return this->distanceToOrigin() < other.distanceToOrigin();
    }

    // Перегрузка оператора вывода <<
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

int main() {
    std::vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));

    std::sort(v.begin(), v.end()); // Сортировка по расстоянию до центра координат

    for (const auto& point : v)
        std::cout << point << '\n'; // Вывод отсортированных точек

    return 0;
}
