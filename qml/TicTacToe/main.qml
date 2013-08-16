import QtQuick 2.0

Rectangle {
    width: 360
    height: 360

    Grid {
        id: gameField
        rows: 3
        columns: 3
//        anchors.fill: parent
        spacing: 2
        Repeater{
            model: gameModel.gameField
            delegate: Rectangle{
                width: 20
                height: 20
                color: "red"
                Text{
                    anchors.centerIn: parent
                    text: modelData.cellValue ==  0 ? " " : modelData.cellValue ==  1 ? "X" : "O"
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: gameController.chengeCell(index)
                }
            }
        }
    }
    Rectangle {
        id: l
        property alias x1: l.x
        property alias y1: l.y

        property real x2: l.x
        property real y2: l.y

        color: "black"
        height: 2
        smooth: true;

        transformOrigin: Item.TopLeft;

        width: getWidth(x1,y1,x2,y2);
        rotation: getSlope(x1,y1,x2,y2);

        function getWidth(sx1,sy1,sx2,sy2)
        {
            var w=Math.sqrt(Math.pow((sx2-sx1),2)+Math.pow((sy2-sy1),2));
            console.debug("W: "+w);
            return w;
        }

        function getSlope(sx1,sy1,sx2,sy2)
        {
            var a,m,d;
            var b=sx2-sx1;
            if (b===0)
                return 0;
            a=sy2-sy1;
            m=a/b;
            d=Math.atan(m)*180/Math.PI;

            if (a<0 && b<0)
                return d+180;
            else if (a>=0 && b>=0)
                return d;
            else if (a<0 && b>=0)
                return d;
            else if (a>=0 && b<0)
                return d+180;
            else
                return 0;
        }
    }
    Line{
        id: victoryLine
        visible: false
        color: "white"
        state: gameModel.victoryLine

        states: [
            State {
                name: "HorisontalTop"
                PropertyChanges {
                    target: victoryLine
                    visible: true
                    x1: gameField.x
                    y1: gameField.y + 10
                    x2: gameField.x + gameField.width
                    y2: gameField.y + 10
                }
            },
            State {
                name: "HorisontalCenter"
                PropertyChanges {
                    target: victoryLine
                    visible: true
                    x1: gameField.x
                    y1: gameField.y + 30
                    x2: gameField.x + gameField.width
                    y2: gameField.y + 30
                }
            },
            State {
                name: "HorisontalBottom"
                PropertyChanges {
                    target: victoryLine
                    visible: true
                    x1: gameField.x
                    y1: gameField.y + 50
                    x2: gameField.x + gameField.width
                    y2: gameField.y + 50
                }
            },
            State {
                name: "VerticalLeft"
                PropertyChanges {
                    target: victoryLine
                    visible: true
                    x1: gameField.x + 10
                    y1: gameField.y
                    x2: gameField.x + 10
                    y2: gameField.y + gameField.height
                }
            },
            State {
                name: "VerticalCenter"
                PropertyChanges {
                    target: victoryLine
                    visible: true
                    x1: gameField.x + 30
                    y1: gameField.y
                    x2: gameField.x + 30
                    y2: gameField.y + gameField.height
                }
            },
            State {
                name: "VerticalRight"
                PropertyChanges {
                    target: victoryLine
                    visible: true
                    x1: gameField.x + 50
                    y1: gameField.y
                    x2: gameField.x + 50
                    y2: gameField.y + gameField.height
                }
            },
            State {
                name: "Diagonal1"
                PropertyChanges {
                    target: victoryLine
                    visible: true
                    x1: gameField.x
                    y1: gameField.y
                    x2: gameField.x + gameField.width
                    y2: gameField.y + gameField.height
                }
            },
            State {
                name: "Diagonal2"
                PropertyChanges {
                    target: victoryLine
                    visible: true
                    x1: gameField.x
                    y1: gameField.y + gameField.height
                    x2: gameField.x + gameField.width
                    y2: gameField.y
                }
            },
            State {
                name: "NotLine"
                PropertyChanges {
                    target: victoryLine
                    visible: false
                }
            }
        ]
    }
}
