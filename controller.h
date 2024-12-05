#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <vector>
#include "model.h"
#include "view.h"
class Controller {
public:
    Controller();
    void createDocument(const std::string& filename);
    void importDocument(const std::string& filename);
    void exportDocument(const std::string& filename);

    void createPrimitive(const std::string& nameprimitive,const std::string& type, int x, int y, int size);
    void deletePrimitive(int index);
    void displayPrimitives(const std::vector<std::shared_ptr<Primitive>>& primitives);
    void Viewprimitives();

    // const std::vector<std::shared_ptr<Primitive>>& getPrimitives() const;

private:
    std::shared_ptr<Model> model;
    std::shared_ptr<View> view;
    // std::vector<std::shared_ptr<Primitive>> primitives;
};

#endif // CONTROLLER_H
