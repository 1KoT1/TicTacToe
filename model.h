#ifndef MODEL_H
#define MODEL_H

#include <QObject>

enum State{
    Empty,
    X,
    O
};
namespace Gamer{
enum Gamer{
    X,
    O
};
}

class Cell : public QObject{
    Q_OBJECT
    Q_PROPERTY(int cellValue READ value NOTIFY valueChange)
public:
    explicit Cell(QObject *parent = 0);

    State value() const;
    void setValue(State value);

signals:
    void valueChange();

private:
    State m_value;
};
//Q_DECLARE_METATYPE(Cell)

class Model : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> gameField READ gameFieldProperty NOTIFY gameFieldChange)
    Q_PROPERTY(bool hasError READ hasError NOTIFY hasErrorChange)
    Q_PROPERTY(QString errorText READ errorText NOTIFY hasErrorChange)
public:
    explicit Model(QObject *parent = 0);

    /** Клетки игрового поля представленные в виде одного массива. */
    const QList<Cell *> &gameField() const;
    const QList<QObject *> gameFieldProperty() const;

    Gamer::Gamer gamer() const;
    void setGamer(Gamer::Gamer);

    /** Возникла ошибка.*/
    bool hasError();
    /** екст возникшей ошибки.*/
    QString errorText();
signals:
    void gameFieldChange();
    void hasErrorChange();

private:
    QList<Cell*> m_gameField;
    Gamer::Gamer m_gamer;
};

#endif // MODEL_H
