// triangle.cpp
#include "triangle.h"
#include <iostream>

Triangle::Triangle(Dot p1, Dot p2, Dot p3)
    : point1(p1), point2(p2), point3(p3) {}

void Triangle::printSidesLength() {
    std::cout << "Side 1: " << point1.distanceTo(point2) << std::endl;
    std::cout << "Side 2: " << point2.distanceTo(point3) << std::endl;
    std::cout << "Side 3: " << point3.distanceTo(point1) << std::endl;
}

double Triangle::calculatePerimeter() {
    double side1 = point1.distanceTo(point2);
    double side2 = point2.distanceTo(point3);
    double side3 = point3.distanceTo(point1);

    return side1 + side2 + side3;
}

double Triangle::calculateArea() {
    double side1 = point1.distanceTo(point2);
    double side2 = point2.distanceTo(point3);
    double side3 = point3.distanceTo(point1);

    double semi_perimeter = calculatePerimeter() / 2.0;
    return sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side2) * (semi_perimeter - side3));
}
