import QtQuick 2.7

Page1Form {

    Connections {

        target: rgbController

         onGetTemperature: {

             temperatureText.text = temperature

         }



    }


   blueSlider.onValueChanged:  {

        rgbController.setRGB(redSlider.value,greenSlider.value,blueSlider.value)
        rectangle.color = Qt.rgba(redSlider.value/255,greenSlider.value/255,blueSlider.value/255,1)




    }
    setAnimationBtn.onClicked: {

        setAnimationPopup.open()

    }
    myButton1.onClicked: {

        colorDialog.open()

    }
    myButton2.onClicked: {

        if (rgbController.getConnectionStatus()===false){

            popup.open()


        }else {

            rgbController.disconnectFromDevice()
            myButton2.text = "Connect"

        }


    }

    greenSlider.onValueChanged: {

        rgbController.setRGB(redSlider.value,greenSlider.value,blueSlider.value)
        rectangle.color = Qt.rgba(redSlider.value/255,greenSlider.value/255,blueSlider.value/255,1)




    }
    redSlider.onValueChanged: {


        rgbController.setRGB(redSlider.value,greenSlider.value,blueSlider.value)
        rectangle.color = Qt.rgba(redSlider.value/255,greenSlider.value/255,blueSlider.value/255,1)



    }




}
