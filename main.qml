import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 320
    height: 480
    maximumHeight: 480
    maximumWidth:  320
    minimumHeight: 480
    minimumWidth:  320
    title: qsTr("RGB Supervisor 2.0")



    Page1 {




    }


    Popup {
        id: popup
        x: 0
        y: 160
        width: 320
        height: 160
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent


        Column {

            width: 200
            x: (parent.width-width) / 2

            Label {

                text: qsTr("COM Name: ")
            }

            ComboBox {

                id: comList
                width: parent.width


            }

            MyButton {

                text: qsTr("Connect")
                width: parent.width
                onClicked: {

                    popup.close()
                }

            }






        }



    }

    ColorDialog {
        id: colorDialog
        title: "Please choose a color"
        onAccepted: {
            console.log("You chose: " + colorDialog.color)

        }
        onRejected: {
            console.log("Canceled")

        }

        onCurrentColorChanged: {

            console.log("Color: "+colorDialog.color)
        }


    }







}
