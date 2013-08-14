#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "model.h"
#include <QQmlContext>
#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //		qmlRegisterType<State>("TicTacToeComponents", 1, 0, "State");
    QtQuick2ApplicationViewer viewer;
    auto model = new Model(&app);
    viewer.rootContext()->setContextProperty("gameModel", model);
    viewer.rootContext()->setContextProperty("gameController", new Controller(model, &app));
    viewer.setMainQmlFile(QStringLiteral("qml/TicTacToe/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
