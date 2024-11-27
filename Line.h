#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
public:
  Line(double x1, double y1, double x2, double y2);
  void draw() override;
  void save(std::ostream& stream) override;
  void load(std::istream& stream) override;

private:
  double x1, y1, x2, y2;
};

#endif