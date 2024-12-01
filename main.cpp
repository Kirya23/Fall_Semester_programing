#include <iostream>
#include <memory>
#include "controller.h"

int main() {
    Controller controller;

    // Создание нового документа
    controller.createDocument();

    // Импорт документа из файла
    controller.importDocument("document.txt");

    // Экспорт документа в файл
    controller.exportDocument("exported_document.txt");

    // Создание графического примитива
    controller.createPrimitive("Circle", 10, 20, 5); // Пример: Circle с координатами (10, 20) и радиусом 5
    
    // Удаление графического примитива
    controller.deletePrimitive(0); // Удаляем первый примитив

    return 0;
}
