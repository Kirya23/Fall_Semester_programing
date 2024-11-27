#ifndef SHAPE_H
#define SHAPE_H

#include <memory>

class Shape {
public:
  virtual ~Shape() = default;
  virtual void draw() = 0; // Чисто виртуальная функция для рисования
  virtual void save(std::ostream& stream) = 0; // Сохранение в поток
  virtual void load(std::istream& stream) = 0; // Загрузка из потока
};

using ShapePtr = std::unique_ptr<Shape>;

#endif

