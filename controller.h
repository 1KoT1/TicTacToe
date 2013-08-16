#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

enum line{
    HorisontalTop,
    HorisontalCenter,
    HorisontalBottom,
    VerticalLeft,
    VerticalCenter,
    VerticalRight,
    Diagonal1,
    Diagonal2,
    NotLine
};

class Model;
class Controller : public QObject{
    Q_OBJECT
public:
    explicit Controller(Model *model, QObject *parent = 0);

    Q_INVOKABLE void chengeCell(int index);

signals:
    
public slots:
    
private:
    Model * m_model;

    line isVictory(int index) const;
};

#endif // CONTROLLER_H
