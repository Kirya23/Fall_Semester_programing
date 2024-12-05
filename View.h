#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <memory>
#include "primitive.h"

class View {
public:
    void displayPrimitives(const std::vector<std::shared_ptr<Primitive>>& primitives);
};

#endif 
