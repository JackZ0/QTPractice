import QtQuick 2.0
import QtQuick.Controls 1.1
Item {
    Rectangle{
        x:50;
        y:100;
    width: 300;
    height: 500;
    gradient: Gradient{
    GradientStop{position: 0.0;color: "#202020";}
    GradientStop{position:0.33;color: "blue";}
    GradientStop{position: 0.5;color: "#ffffff";}
    }
    color: "yellow";
    z:0.5;
    }
    Rectangle{
        x:20;
        y:50;
    width: 300;
    height: 500;
    color: "yellow";
    z:0.5;
    }
    Text {
        anchors.centerIn: parent;
        id: name
        color: "red";
        font.pixelSize: 35;
        text: qsTr("text")
    }
}
