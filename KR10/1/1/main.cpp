// main.cpp
/*#include "triangle.h"
#include <iostream>


int main() {
    Dot p1(0, 0);
    Dot p2(4, 0);
    Dot p3(0, 3);

    Triangle triangle(p1, p2, p3);

    triangle.printSidesLength();
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;
    std::cout << "Area: " << triangle.calculateArea() << std::endl;

    return 0;
}*/


// main.cpp - пример использования TriangleAggregation

#include "dot.h"
#include "triangle_aggregation.h"
#include <iostream>

int main() {
    Dot p1(0, 0);
    Dot p2(4, 0);
    Dot p3(0, 3);

    TriangleAggregation triangle(&p1, &p2, &p3);

    triangle.printSidesLength();
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;
    std::cout << "Area: " << triangle.calculateArea() << std::endl;

    return 0;
}
