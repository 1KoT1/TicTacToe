#ifndef MODEL_H
#define MODEL_H

#include <QObject>

enum State{
	Empty,
	X,
	O
};

class Model : public QObject
{
	Q_OBJECT

public:
	explicit Model(QObject *parent = 0);

	/** Клетки игрового поля представленные в виде одного массива. */
	const QList<State> & gameField() const;
	
	/** Возникла ошибка.*/
	bool hasError();
	/** екст возникшей ошибки.*/
	QString errorText();
signals:
	void gameFieldChange();
	void hasErrorChange();

private:
	QList<State> m_gameField;
};

#endif // MODEL_H
