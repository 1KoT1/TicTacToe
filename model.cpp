#include "model.h"

const int width = 3, height = 3;
Model::Model(QObject *parent) :
    QObject(parent),
    m_gameField(QList<Cell*>()),
    m_gamer(Gamer::X)
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

Gamer::Gamer Model::gamer() const{
    return m_gamer;
}

void Model::setGamer(Gamer::Gamer gamer){
    m_gamer = gamer;
}

bool Model::hasError(){
    return false;
}

QString Model::errorText(){
    return "";
}


Cell::Cell(QObject *parent) :
    QObject(parent),
    m_value(Empty)
{
}

State Cell::value() const{
    return m_value;
}

void Cell::setValue(State v){
    if(m_value != v){
        m_value = v;
        emit valueChange();
    }
}
