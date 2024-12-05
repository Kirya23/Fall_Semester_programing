#include <iostream>
#include <memory>
#include "controller.h"

int main() {
    Controller controller;

    // Создание нового документа
    controller.createDocument("First document");

    //Импорт документа из файла
    controller.importDocument("top_секрет.txt");

    // Экспорт документа в файл
    controller.exportDocument("top_секрет.txt");

    // Создание графических примитивов
    controller.createPrimitive("Мой ребёнок","Circle", 10, 20, 5); // Пример: Circle с координатами (10, 20) и радиусом 5
    controller.createPrimitive("Мой второй ребёнок","Rectangle", 14, 2, 10);
    controller.createPrimitive("Мой третий ребёнок","Circle", 10, 20, 5); // Пример: Circle с координатами (10, 20) и радиусом 5

    std::cout<<"Вывод примитивов:"<< std::endl;
    controller.Viewprimitives();

    std::cout<<"После удаления:"<< std::endl;
    // Удаление графического примитива
    controller.deletePrimitive(0); // Удаляем первый примитив
    controller.Viewprimitives();
    return 0;
}
