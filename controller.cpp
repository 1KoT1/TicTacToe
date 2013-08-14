#include "controller.h"
#include "model.h"

Controller::Controller(Model * model, QObject *parent) :
    QObject(parent),
    m_model(model)
{
}

void Controller::chengeCell(int index){
    m_model->gameField().at(index)->setValue(X);
}
