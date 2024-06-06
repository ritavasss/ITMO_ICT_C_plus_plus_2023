// triangle_aggregation.h
#pragma once
#include "dot.h"

class TriangleAggregation {
private:
    Dot* point1;
    Dot* point2;
    Dot* point3;

public:
    TriangleAggregation(Dot* p1, Dot* p2, Dot* p3);
    void printSidesLength();
    double calculatePerimeter();
    double calculateArea();
};
