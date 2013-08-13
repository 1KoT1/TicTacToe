#ifndef MODEL_H
#define MODEL_H

#include <QObject>

enum State{
	Empty,
	X,
	O
};

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
	Q_PROPERTY(QList<QObject*> gameField READ gameField NOTIFY gameFieldChange)
	Q_PROPERTY(bool hasError READ hasError NOTIFY hasErrorChange)
	Q_PROPERTY(QString errorText READ errorText NOTIFY hasErrorChange)
public:
	explicit Model(QObject *parent = 0);

	/** Клетки игрового поля представленные в виде одного массива. */
	const QList<QObject *> &gameField() const;
	
	/** Возникла ошибка.*/
	bool hasError();
	/** екст возникшей ошибки.*/
	QString errorText();
signals:
	void gameFieldChange();
	void hasErrorChange();

private:
	QList<QObject*> m_gameField;
};

#endif // MODEL_H
