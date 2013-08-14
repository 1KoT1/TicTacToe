#include "controller.h"
#include "model.h"

Controller::Controller(Model * model, QObject *parent) :
    QObject(parent),
    m_model(model)
{
}

void Controller::chengeCell(int index){
    if(m_model->gameField().at(index)->value() == Empty){
        m_model->gameField().at(index)->setValue(m_model->gamer() == Gamer::X ? X : O);
        m_model->setGamer(m_model->gamer() == Gamer::X ? Gamer::O : Gamer::X);
    }
}
