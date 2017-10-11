import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Button {

    id: control
    text: qsTr("Button")
    property color buttonBack: "Green"

    contentItem: Text {
         text: control.text
         font: control.font
         color: "white"
         horizontalAlignment: Text.AlignHCenter
         verticalAlignment: Text.AlignVCenter
         elide: Text.ElideRight
     }

     background: Rectangle {
         implicitWidth: 100
         implicitHeight: 40
         color: buttonBack
         border.color: buttonBack
         border.width: 1
         opacity: control.down ? 0.8 : 1.0
         radius: 20
     }

}






