#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <memory>
#include <string>

class Primitive {
public:
    virtual ~Primitive() = default;
    virtual void draw() const = 0;
    virtual std::string getType() const = 0;
};

class Circle : public Primitive {
public:
    Circle(int x, int y, int radius);
    void draw() const override;
    std::string getType() const override;

private:
    int x, y, radius;
};

class Rectangle : public Primitive {
public:
    Rectangle(int x, int y, int width, int height);
    void draw() const override;
    std::string getType() const override;

private:
    int x, y, width, height;
};

#endif // PRIMITIVE_H
