#include "model.h"
#include <iostream>

void Model::createDocument() {
    // Логика создания документа
    std::cout << "New document created!" << std::endl;
}

void Model::importDocument(const std::string& filename) {
    // Логика импорта документа
    std::cout << "Document imported from " << filename << std::endl;
}

void Model::exportDocument(const std::string& filename) {
    // Логика экспорта документа
    std::cout << "Document exported to " << filename << std::endl;
}

void Model::createPrimitive(const std::string& type, int x, int y, int size) {
    if (type == "Circle") {
        primitives.push_back(std::make_shared<Circle>(x, y, size));
    } else if (type == "Rectangle") {
        primitives.push_back(std::make_shared<Rectangle>(x, y, size, size));
    }
}

void Model::deletePrimitive(int index) {
    if (index >= 0 && index < primitives.size()) {
        primitives.erase(primitives.begin() + index);
    }
}

const std::vector<std::shared_ptr<Primitive>>& Model::getPrimitives() const {
    return primitives;
}
