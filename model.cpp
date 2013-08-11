#include "model.h"

const int width = 3, height = 3;
Model::Model(QObject *parent) :
	QObject(parent),
	m_gameField(QList<State>())
{
	for (int i = 0; i < width * height; ++i)
m_gameField << Empty;
}

const QList<State> &Model::gameField() const{
	return m_gameField;
}

bool Model::hasError(){
	return false;
}

QString Model::errorText(){
	return "";
}
