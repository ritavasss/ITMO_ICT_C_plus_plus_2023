#include <iostream>
#include <cmath>
using namespace std;

class InvalidTriangleException {

    public:
        InvalidTriangleException() : message("Cтороны недопустимой длины") { }
        void printMessage() const { cout << message << endl; }
    private:
        string message;
    };

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) {
        if (isValidTriangle(s1, s2, s3)) {
            side1 = s1;
            side2 = s2;
            side3 = s3;
        }
        else {
            throw InvalidTriangleException();
        }
    }

    bool isValidTriangle(double s1, double s2, double s3) const {
        return (s1 + s2 > s3) && (s2 + s3 > s1) && (s1 + s3 > s2);
    }

    double calculateArea() const {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

int main() {
    system("chcp 1251");
    try {
        // Пример использования класса Triangle
        double sideA, sideB, sideC;
        cout << "Введите длины сторон треугольника: ";
        cin >> sideA >> sideB >> sideC;

        Triangle triangle(sideA, sideB, sideC);
        double area = triangle.calculateArea();
        cout << "Площадь треугольника: " << area << endl;
    }
    catch (InvalidTriangleException& e) {
            cout << "ОШИБКА: ";
            e.printMessage();
            return 1; // завершение программы при ошибке
        }
        return 0; // нормальное завершение программы
}
