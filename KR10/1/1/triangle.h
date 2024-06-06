// triangle.h
#pragma once
#include "dot.h"

class Triangle {
private:
    Dot point1;
    Dot point2;
    Dot point3;

public:
    Triangle(Dot p1, Dot p2, Dot p3);
    void printSidesLength();
    double calculatePerimeter();
    double calculateArea();
};
