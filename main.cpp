#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "model.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//		qmlRegisterType<State>("TicTacToeComponents", 1, 0, "State");
    QtQuick2ApplicationViewer viewer;
		viewer.rootContext()->setContextProperty("gameModel", new Model(&app));
    viewer.setMainQmlFile(QStringLiteral("qml/TicTacToe/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
