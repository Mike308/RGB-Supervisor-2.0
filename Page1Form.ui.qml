import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {

    property alias redSlider: redSlider
    property alias greenSlider: greenSlider
    property alias blueSlider: blueSlider

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top
    }

    MyButton {
        id: myButton
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
        text: qsTr("Text")
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
    }

    MySlider {
        id: greenSlider
        x: 24
        y: 186
        width: 274
        height: 38
        sliderColor: "#00ff00"
    }

    MySlider {
        id: blueSlider
        x: 24
        y: 230
        width: 274
        height: 38
        sliderColor: "#0000ff"
    }
}
