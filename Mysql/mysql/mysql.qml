import QtQuick 2.0
import QtQuick.Controls 1.1
Item {
//    Rectangle{
//        x:50;
//        y:100;
//    width: 300;
//    height: 500;
//    gradient: Gradient{
//    GradientStop{position: 0.0;color: "#202020";}
//    GradientStop{position:0.33;color: "blue";}
//    GradientStop{position: 0.5;color: "#ffffff";}
//    }
//    color: "yellow";
//    z:0.5;
//    }
//    Rectangle{
//        x:20;
//        y:50;
//    width: 300;
//    height: 500;
//    color: "yellow";
//    z:0.5;
//    }
    Text {
        anchors.centerIn: parent;
        id: name
        color: "red";
        font.pixelSize: 35;
        text: qsTr("text")
    }
    Button {
        id: changebutton;
        anchors.top: name.bottom;
        anchors.topMargin: 9;
        anchors.horizontalCenter: parent.horizontalCenter;
        text:"change";
    }
    TextField {
           id: username
           x: 137
           y: 35
           width: 200
           height: 30
           placeholderText: qsTr("请输入用户名")
   }
    Text {
            id: text1
            x: 47
            y: 35
            width: 80
            height: 30
            text: qsTr("用户名：")
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 14
        }
    Text {
           id: text2
           x: 47
           y: 85
           width: 80
           height: 30
           text: qsTr("密  码：")
           verticalAlignment: Text.AlignVCenter
           font.pixelSize: 14
           horizontalAlignment: Text.AlignRight
       }


        TextField {
            id: password
            x: 137
            y: 85
            width: 200
            height: 30
            echoMode: 2
            placeholderText: qsTr("请输入密码")
        }

        Button {
            id: loginbutton
            x: 71
            y: 145
            width: 116
            height: 36
            text: qsTr("登 录")
        }

        Button {
            id: canclebutton
            x: 224
            y: 145
            width: 110
            height: 36
            text: qsTr("取 消")
        }


}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
