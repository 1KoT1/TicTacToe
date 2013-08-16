#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QMetaEnum>

class State: QObject{
    Q_OBJECT
    Q_ENUMS(StateEnum)
public:
    enum StateEnum{
        Empty,
        X,
        O
    };

    static bool Equals(State::StateEnum value1, State::StateEnum value2, State::StateEnum value3){
        return value1 == value2 && value2 == value3;
    }
};
class Line : QObject{
    Q_OBJECT
    Q_ENUMS(LineEnum)
public:
    Line(QObject*){}

    enum LineEnum{
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
    /** Получить метаобъект перечисления. @see QMetaEnum */
    static inline const QMetaEnum m(){
        const QMetaObject &mo = Line::staticMetaObject;
        return mo.enumerator(mo.indexOfEnumerator("LineEnum"));
    }
};


class Cell : public QObject{
    Q_OBJECT
    Q_PROPERTY(int cellValue READ value NOTIFY valueChange)
public:
    explicit Cell(QObject *parent = 0);

    State::StateEnum value() const;
    void setValue(State::StateEnum value);

signals:
    void valueChange();

private:
    State::StateEnum m_value;
};
//Q_DECLARE_METATYPE(Cell)

class Model : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> gameField READ gameFieldProperty NOTIFY gameFieldChange)
    Q_PROPERTY(bool hasError READ hasError NOTIFY hasErrorChange)
    Q_PROPERTY(QString errorText READ errorText NOTIFY hasErrorChange)
    Q_PROPERTY(QString victoryLine READ victoryLine NOTIFY victoryLineChange)
public:
    explicit Model(QObject *parent = 0);

    /** Клетки игрового поля представленные в виде одного массива. */
    const QList<Cell *> &gameField() const;
    const QList<QObject *> gameFieldProperty() const;

    State::StateEnum gamer() const;
    void setGamer(State::StateEnum);

    /** Возникла ошибка.*/
    bool hasError();
    /** Текст возникшей ошибки.*/
    QString errorText();

    QString victoryLine() const;
    void setVictoryLine(Line::LineEnum value);
signals:
    void gameFieldChange();
    void hasErrorChange();
    void victoryLineChange();

private:
    QList<Cell*> m_gameField;
    State::StateEnum m_gamer;
    Line::LineEnum m_victoryLine;
};

#endif // MODEL_H
