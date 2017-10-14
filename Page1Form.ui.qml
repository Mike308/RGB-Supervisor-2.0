import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias redSlider: redSlider
    property alias text1: text1
    property alias greenSlider: greenSlider
    property alias rectangle: rectangle
    property alias myButton2: myButton2
    property alias myButton1: myButton1
    property alias setAnimationBtn: setAnimationBtn




    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top
    }



    MyButton {
        id: setAnimationBtn
        x: 24
        y: 290
        width: 274
        height: 41
        text: "SET ANIMATION"
        buttonBack: "#0055ff"
    }

    MyButton {
        id: myButton1
        x: 24
        y: 337
        width: 274
        height: 41
        text: "COLOR PALETTE"
        buttonBack: "#00aa00"
    }

    MyButton {
        id: myButton2
        x: 24
        y: 384
        width: 274
        height: 41
        text: "CONNECT"
        buttonBack: "#5500ff"
    }

    Text {
        id: text1
        x: 24
        y: 8
        width: 274
        height: 57
        text: qsTr("0")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 39
    }

    Rectangle {
        id: rectangle
        x: 24
        y: 63
        width: 274
        height: 60
        color: "#ffffff"
        border.color: "#040404"
    }

    MySlider {
        id: redSlider
        x: 24
        y: 142
        width: 274
        height: 38
        to: 255
        stepSize: 1
        from: 0
        value: 1



    }

    MySlider {
        id: greenSlider
        x: 24
        y: 186
        width: 274
        height: 38
        stepSize: 1
        to: 255
        sliderColor: "#00ff00"
    }

    MySlider {
        id: blueSlider
        x: 24
        y: 230
        width: 274
        height: 38
        stepSize: 1
        to: 255
        sliderColor: "#0000ff"
    }
}
