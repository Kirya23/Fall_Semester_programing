#include "model.h"
#include <iostream>

 const std::vector<std::shared_ptr<Primitive>>& Model::getPrimitives() const {
     return primitives;
}

void Model::createDocument(const std::string& filename) {
    // Логика создания документа
    std::cout<<"Документ \""<< filename << "\" is креатед =)"<<std::endl;
}

void Model::importDocument(const std::string& filename) {
    // Логика импорта документа
    std::cout << "Документ импортирован из " << filename << std::endl;
}

void Model::exportDocument(const std::string& filename) {
    // Логика экспорта документа
    std::cout << "Документ экспортирован в " << filename << std::endl;
}

void Model::createPrimitive(const std::string& nameprimitive,const std::string& type, int x, int y, int size) {
    if (type == "Circle") {
        primitives.push_back(std::make_shared<Circle>(x, y, size));
        std::cout<<"Создан \""<<nameprimitive << "\" с типом \""<< type<< "\" и размером "<< size << std::endl;
    } else if (type == "Rectangle") {
        primitives.push_back(std::make_shared<Rectangle>(x, y, size, size));
        std::cout<<"Создан \""<<nameprimitive << "\" с типом \""<< type<< "\" и размером "<< size <<" на "<< size << std::endl;
    }
}

void Model::deletePrimitive(int index) {
    if (index >= 0 && index < primitives.size()) {
        primitives.erase(primitives.begin() + index);
    }
}