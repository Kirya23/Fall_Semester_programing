#include "primitive.h"
#include <iostream>

Circle::Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}

void Circle::draw() const {
    std::cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
}

std::string Circle::getType() const {
    return "Circle";
}

Rectangle::Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

void Rectangle::draw() const {
    std::cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << std::endl;
}

std::string Rectangle::getType() const {
    return "Rectangle";
}
