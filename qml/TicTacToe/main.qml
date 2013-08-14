import QtQuick 2.0

Rectangle {
    width: 360
    height: 360

    Grid {
        id: gameField
        rows: 3
        columns: 3
        anchors.fill: parent
        spacing: 2
        Repeater{
            model: gameModel.gameField
            delegate: Rectangle{
                width: 20
                height: width
                color: "red"
                Text{
                    anchors.centerIn: parent
                    text: modelData.cellValue == 0 ? " " : modelData.cellValue == 1 ? "X" : "O"
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: gameController.chengeCell(index)
                }
            }
        }
    }
}
