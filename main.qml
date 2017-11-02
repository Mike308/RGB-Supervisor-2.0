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
    property alias mainPage: mainPage



    Page1 {


        id: mainPage


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
                model: portsNameModel


            }

            MyButton {

                text: qsTr("Connect")
                width: parent.width
                onClicked: {

                    rgbController.connectToDevice(comList.currentText,9600)
                    mainPage.myButton2.text = "DISCONNECT"
                    popup.close()




                }

            }






        }



    }



    Popup {
        id: setAnimationPopup
        x: 0
        y: 160
        width: 320
        height: 250
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent


        Column {

            width: 300
            x: (parent.width-width) / 2

            Label {

                text: qsTr("Animation: ")
            }

            ComboBox {

                id: animationType
                width: parent.width
                model: ["Color wheel","Random color switching"]


            }

            Label {

                text: qsTr("Speed: ")
            }

            TextField {

                id: speedField
                validator: IntValidator {}
            }

            Label {

                text: qsTr("Step: ")
            }

            TextField {

                id: stepField
                validator: IntValidator {}

            }

            MyButton {

                text: qsTr("Set animation")
                width: parent.width
                onClicked: {

                    rgbController.setAnimation(animationType.currentIndex,speedField.text,stepField.text)
                    setAnimationPopup.close()
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


    Popup {
        id: connectingPopup
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

                width: parent.width
                text: qsTr("Connecting...");

            }

            BusyIndicator {

                width: parent.width
                id: busyIndicator


            }







        }



    }







}
