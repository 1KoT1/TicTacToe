import QtQuick 2.0

Rectangle {
    width: 360
    height: 360

    Grid {
        id: gameField
        rows: 3
        columns: 3
        anchors.fill: parent
        Repeater{
            model: gameModel.gameField
            delegate: Text{
                text: modelData.cellValue
                MouseArea{
                    anchors.fill: parent
                    onClicked: gameController.chengeCell(index)
                }
            }
        }
    }
}
