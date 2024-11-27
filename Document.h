#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Shape.h"
#include <vector>

class Document {
public:
  void addShape(ShapePtr shape);
  void removeShape(int index);
  void saveToFile(const std::string& filename);
  void loadFromFile(const std::string& filename);
  

private:
  std::vector<ShapePtr> shapes;
};

#endif

