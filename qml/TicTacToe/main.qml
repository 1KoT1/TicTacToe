import QtQuick 2.0

Rectangle {
    width: 360
    height: 360

    GridView {
        id: game_feild_view
        anchors.fill: parent
        model: gameModel.gameField
        delegate: Text{text: modelData.cellValue}
    }
}
