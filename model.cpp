#include "model.h"

const int width = 3, height = 3;
Model::Model(QObject *parent) :
    QObject(parent),
    m_gameField(QList<Cell*>()),
    m_gamer(State::X),
    m_victoryLine(Line::NotLine)
{
    for (int i = 0; i < width * height; ++i)
        m_gameField << new Cell(this);
}

const QList<Cell *> &Model::gameField() const{
    return m_gameField;
}

const QList<QObject *> Model::gameFieldProperty() const{
    auto res = QList<QObject*>();
    foreach (auto var, m_gameField)
        res << var;

    return res;
}

State::StateEnum Model::gamer() const{
    return m_gamer;
}

void Model::setGamer(State::StateEnum gamer){
    m_gamer = gamer;
}

bool Model::hasError(){
    return false;
}

QString Model::errorText(){
    return "";
}

QString Model::victoryLine() const{
    return Line::m().valueToKey(m_victoryLine);
}

void Model::setVictoryLine(Line::LineEnum value){
    if(m_victoryLine != value){
        m_victoryLine = value;
        emit victoryLineChange();
    }
}

bool Model::gameIsActive() const{
    return m_victoryLine == Line::NotLine;
}


Cell::Cell(QObject *parent) :
    QObject(parent),
    m_value(State::Empty)
{
}

State::StateEnum Cell::value() const{
    return m_value;
}

void Cell::setValue(State::StateEnum v){
    if(m_value != v){
        m_value = v;
        emit valueChange();
    }
}
