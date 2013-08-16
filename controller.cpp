#include "controller.h"
#include "model.h"

Controller::Controller(Model * model, QObject *parent) :
    QObject(parent),
    m_model(model)
{
}

Line::LineEnum isVictory(int index, const QList<Cell*>* gameField)
{
    auto gamer = gameField->at(index)->value();
    switch (index) {
    case 0:
        if(State::Equals(gameField->at(3)->value(), gameField->at(6)->value(), gamer))
            return Line::VerticalLeft;
        else if(State::Equals(gameField->at(1)->value(), gameField->at(2)->value(), gamer))
            return Line::HorisontalTop;
        else if(State::Equals(gameField->at(4)->value(), gameField->at(8)->value(), gamer))
            return Line::Diagonal1;
        else
            return Line::NotLine;
    case 1:
        if(State::Equals(gameField->at(4)->value(), gameField->at(7)->value(), gamer))
            return Line::VerticalCenter;
        else if(State::Equals(gameField->at(0)->value(), gameField->at(2)->value(), gamer))
            return Line::HorisontalTop;
        else
            return Line::NotLine;
    case 2:
        if(State::Equals(gameField->at(5)->value(), gameField->at(8)->value(), gamer))
            return Line::VerticalRight;
        else if(State::Equals(gameField->at(0)->value(), gameField->at(1)->value(), gamer))
            return Line::HorisontalTop;
        else if(State::Equals(gameField->at(4)->value(), gameField->at(6)->value(), gamer))
            return Line::Diagonal2;
        else
            return Line::NotLine;
    case 3:
        if(State::Equals(gameField->at(0)->value(), gameField->at(6)->value(), gamer))
            return Line::VerticalLeft;
        else if(State::Equals(gameField->at(4)->value(), gameField->at(5)->value(), gamer))
            return Line::HorisontalCenter;
        else
            return Line::NotLine;
    case 4:
        if(State::Equals(gameField->at(0)->value(), gameField->at(8)->value(), gamer))
            return Line::Diagonal1;
        else if(State::Equals(gameField->at(1)->value(), gameField->at(7)->value(), gamer))
            return Line::VerticalCenter;
        else if(State::Equals(gameField->at(2)->value(), gameField->at(6)->value(), gamer))
            return Line::Diagonal2;
        else if(State::Equals(gameField->at(3)->value(), gameField->at(5)->value(), gamer))
            return Line::HorisontalCenter;
        else
            return Line::NotLine;
    case 5:
        if(State::Equals(gameField->at(3)->value(), gameField->at(4)->value(), gamer))
            return Line::HorisontalCenter;
        else if(State::Equals(gameField->at(2)->value(), gameField->at(8)->value(), gamer))
            return Line::VerticalRight;
        else
            return Line::NotLine;
    case 6:
        if(State::Equals(gameField->at(0)->value(), gameField->at(3)->value(), gamer))
            return Line::VerticalLeft;
        else if(State::Equals(gameField->at(2)->value(), gameField->at(4)->value(), gamer))
            return Line::Diagonal2;
        else if(State::Equals(gameField->at(7)->value(), gameField->at(8)->value(), gamer))
            return Line::HorisontalBottom;
        else
            return Line::NotLine;
    case 7:
        if(State::Equals(gameField->at(6)->value(), gameField->at(8)->value(), gamer))
            return Line::HorisontalBottom;
        else if(State::Equals(gameField->at(1)->value(), gameField->at(4)->value(), gamer))
            return Line::VerticalCenter;
        else
            return Line::NotLine;
    case 8:
        if(State::Equals(gameField->at(0)->value(), gameField->at(4)->value(), gamer))
            return Line::Diagonal1;
        else if(State::Equals(gameField->at(2)->value(), gameField->at(5)->value(), gamer))
            return Line::VerticalRight;
        else if(State::Equals(gameField->at(6)->value(), gameField->at(7)->value(), gamer))
            return Line::HorisontalBottom;
        else
            return Line::NotLine;
    default:
        return Line::NotLine;
    }
}

void Controller::chengeCell(int index){
    if(m_model->gameField().at(index)->value() == State::Empty){
        m_model->gameField().at(index)->setValue(m_model->gamer());
        auto isV = isVictory(index, &m_model->gameField());
        if(isV == Line::NotLine)
            m_model->setGamer(m_model->gamer() == State::X ? State::O : State::X);
        else
            m_model->setVictoryLine(isV);
    }
}
