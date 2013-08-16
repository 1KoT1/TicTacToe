#include "controller.h"
#include "model.h"

Controller::Controller(Model * model, QObject *parent) :
    QObject(parent),
    m_model(model)
{
}

void Controller::chengeCell(int index){
    if(m_model->gameField().at(index)->value() == Empty){
        m_model->gameField().at(index)->setValue(m_model->gamer());
        m_model->setGamer(m_model->gamer() == X ? O : X);
    }
}

line Controller::isVictory(int index) const
{
    auto gamer = m_model->gameField().at(index)->value();
    switch (index) {
    case 0:
        if(m_model->gameField().at(3)->value() == m_model->gameField().at(6)->value() == gamer)
            return VerticalLeft;
        else if(m_model->gameField().at(1)->value() == m_model->gameField().at(2)->value() == gamer)
            return HorisontalTop;
        else if(m_model->gameField().at(4)->value() == m_model->gameField().at(8)->value() == gamer)
            return Diagonal1;
        else
            return NotLine;
    case 1:
        if(m_model->gameField().at(4)->value() == m_model->gameField().at(7)->value() == gamer)
            return VerticalCenter;
        else if(m_model->gameField().at(0)->value() == m_model->gameField().at(2)->value() == gamer)
            return HorisontalTop;
    case 2:
        if(m_model->gameField().at(5)->value() == m_model->gameField().at(8)->value() == gamer)
            return VerticalRight;
        else if(m_model->gameField().at(0)->value() == m_model->gameField().at(1)->value() == gamer)
            return HorisontalTop;
        else if(m_model->gameField().at(4)->value() == m_model->gameField().at(6)->value() == gamer)
            return Diagonal2;
        else
            return NotLine;
    case 3:
        if(m_model->gameField().at(0)->value() == m_model->gameField().at(6)->value() == gamer)
            return VerticalLeft;
        else if(m_model->gameField().at(4)->value() == m_model->gameField().at(5)->value() == gamer)
            return HorisontalCenter;
        else
            return NotLine;
    case 4:
        if(m_model->gameField().at(0)->value() == m_model->gameField().at(8)->value() == gamer)
            return Diagonal1;
        else if(m_model->gameField().at(1)->value() == m_model->gameField().at(7)->value() == gamer)
            return VerticalCenter;
        else if(m_model->gameField().at(2)->value() == m_model->gameField().at(6)->value() == gamer)
            return Diagonal2;
        else if(m_model->gameField().at(3)->value() == m_model->gameField().at(5)->value() == gamer)
            return HorisontalCenter;
        else
            return NotLine;
    case 5:
        if(m_model->gameField().at(3)->value() == m_model->gameField().at(4)->value() == gamer)
            return HorisontalCenter;
        else if(m_model->gameField().at(2)->value() == m_model->gameField().at(8)->value() == gamer)
            return VerticalRight;
        else
            return NotLine;
    case 6:
        if(m_model->gameField().at(0)->value() == m_model->gameField().at(3)->value() == gamer)
            return VerticalLeft;
        else if(m_model->gameField().at(2)->value() == m_model->gameField().at(4)->value() == gamer)
            return Diagonal2;
        else if(m_model->gameField().at(7)->value() == m_model->gameField().at(8)->value() == gamer)
            return HorisontalBottom;
        else
            return NotLine;
    case 7:
        if(m_model->gameField().at(6)->value() == m_model->gameField().at(8)->value() == gamer)
            return HorisontalBottom;
        else if(m_model->gameField().at(1)->value() == m_model->gameField().at(4)->value() == gamer)
            return VerticalCenter;
        else
            return NotLine;
    case 8:
        if(m_model->gameField().at(0)->value() == m_model->gameField().at(4)->value() == gamer)
            return Diagonal1;
        else if(m_model->gameField().at(2)->value() == m_model->gameField().at(5)->value() == gamer)
            return VerticalRight;
        else if(m_model->gameField().at(6)->value() == m_model->gameField().at(7)->value() == gamer)
            return HorisontalBottom;
        else
            return NotLine;
    default:
        return NotLine;
    }
}
