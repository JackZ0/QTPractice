import QtQuick 2.0
import QtQuick.Controls 1.1
Item {
    Rectangle{
    width: 100;
    height: 100;
    color: "yellow";
    }
    Text {
        anchors.centerIn: parent;
        id: name
        color: "red";
        font.pixelSize: 35;
        text: qsTr("text")
    }
}
