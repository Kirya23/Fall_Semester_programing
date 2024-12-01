#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>
#include <string>
#include "primitive.h"

class Model {
public:
    void createDocument();
    void importDocument(const std::string& filename);
    void exportDocument(const std::string& filename);
    void createPrimitive(const std::string& type, int x, int y, int size);
    void deletePrimitive(int index);
    const std::vector<std::shared_ptr<Primitive>>& getPrimitives() const;

private:
    std::vector<std::shared_ptr<Primitive>> primitives;
};

#endif // MODEL_H
