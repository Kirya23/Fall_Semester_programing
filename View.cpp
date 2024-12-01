#include "view.h"
#include <iostream>

void View::displayPrimitives(const std::vector<std::shared_ptr<Primitive>>& primitives) {
    for (const auto& primitive : primitives) {
        std::cout << "Primitive: " << primitive->getType() << std::endl;
    }
}
