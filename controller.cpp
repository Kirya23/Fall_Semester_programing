#include "controller.h"
#include "model.h"
#include "primitive.h"
#include <iostream>

// const std::vector<std::shared_ptr<Primitive>>& Controller::getPrimitives() const {
//     return primitives;
// }
Controller::Controller() 
    : model(std::make_shared<Model>()),view(std::make_shared<View>()){}

void Controller::createDocument(const std::string& filename) {
   model ->createDocument(filename);
}

void Controller::importDocument(const std::string& filename) {
    model->importDocument(filename);
    
}

void Controller::exportDocument(const std::string& filename) {
    model->exportDocument(filename);
}

void Controller::createPrimitive(const std::string& nameprimitive,const std::string& type, int x, int y, int size) {
    model->createPrimitive(nameprimitive,type,x,y,size);
}

void Controller::deletePrimitive(int index) {
    model->deletePrimitive(index);
}

void Controller::Viewprimitives()
{
    view->displayPrimitives(model->getPrimitives());
};