#ifndef VIEW_H
#define VIEW_H

#include "Document.h"

class View {
public:
    View(Document& doc);
    void draw(); // Рисует все фигуры из документа
    // ... другие методы для взаимодействия с GUI ...

private:
    Document& document;
};
#endif

