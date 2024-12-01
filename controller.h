#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <vector>
#include "model.h"
#include "view.h"

class Controller {
public:
    Controller();
    void createDocument();
    void importDocument(const std::string& filename);
    void exportDocument(const std::string& filename);
    void createPrimitive(const std::string& type, int x, int y, int size);
    void deletePrimitive(int index);

private:
    std::shared_ptr<Model> model;
    std::shared_ptr<View> view;
};

#endif // CONTROLLER_H
