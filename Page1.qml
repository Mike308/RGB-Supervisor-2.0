import QtQuick 2.7

Page1Form {
    myButton1.onClicked: {

        colorDialog.open()

    }
    myButton2.onClicked: {

        popup.open()

    }

    greenSlider.onValueChanged: {




    }
    redSlider.onValueChanged: {


        console.log("Val red slider: "+redSlider.value)


    }




}
