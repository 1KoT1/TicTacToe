#include "model.h"

const int width = 3, height = 3;
Model::Model(QObject *parent) :
	QObject(parent),
	m_gameField(QList<QObject*>())
{
	for (int i = 0; i < width * height; ++i)
		m_gameField << new Cell(this);
}

const QList<QObject *> &Model::gameField() const{
	return m_gameField;
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
