#include "Document.h"
#include "Line.h"
#include "Circle.h"
#include "View.h"
#include <iostream>
#include <fstream>

int main() {
  Document doc;
  View view(doc);

  // Пример создания и добавления фигур:
  doc.addShape(std::make_unique<Line>(10, 10, 100, 100));
  doc.addShape(std::make_unique<Circle>(50, 50, 25));

  // Пример сохранения:
  doc.saveToFile("mydrawing.txt");

  // Пример загрузки:
  doc.loadFromFile("mydrawing.txt");

  view.draw(); // Рисуем фигуры (простая заглушка)

  return 0;
}

