#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double x, double y, double radius);
    void draw() override;
    void save(std::ostream& stream) override;
    void load(std::istream& stream) override;

private:
    double x, y, radius;
};

#endif
