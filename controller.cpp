#include "controller.h"
#include "model.h"
#include "view.h"

Controller::Controller() 
    : model(std::make_shared<Model>()), view(std::make_shared<View>()) {}

void Controller::createDocument() {
    model->createDocument();
    view->displayPrimitives(model->getPrimitives());
}

void Controller::importDocument(const std::string& filename) {
    model->importDocument(filename);
    view->displayPrimitives(model->getPrimitives());
}

void Controller::exportDocument(const std::string& filename) {
    model->exportDocument(filename);
}

void Controller::createPrimitive(const std::string& type, int x, int y, int size) {
    model->createPrimitive(type, x, y, size);
    view->displayPrimitives(model->getPrimitives());
}

void Controller::deletePrimitive(int index) {
    model->deletePrimitive(index);
    view->displayPrimitives(model->getPrimitives());
}
