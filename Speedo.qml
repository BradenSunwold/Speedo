
import QtQuick 2.6
import QtQuick.Controls 2.0
//import io.qt.examples.backend 1.0

Item {

    id: id_root
    property int value

    //to creating data for demonstration purpose
    property int count: 0
    property int randNum: 0

    width: 512
    height: 472
    visible: true

//    BackEnd {
//        id: backend
//    }

//    Timer {           // For simulated wheel speed readings
//        id: id_timer
//        repeat: true
//        interval: 1000
//        running: true

//        onTriggered: {

//            if(id_root.count % 5 == 0){
//                if(id_root.value === 0) id_root.value = 220
//                else id_root.value = 0
//            }
//            id_root.count++;
//        }
//    }

    Image {
        id: id_speed
        x: -14
        y: 135
        width: 512
        height: 472
        fillMode: Image.PreserveAspectFit
        source: "layer_1_219_3_219_3.png"
    }

    ScrollingDigits {
        id: trip
        anchors.verticalCenterOffset: 63
        anchors.horizontalCenterOffset: -3
        anchors.centerIn: id_speed

        positions: 4                    // Number of digits to display linked to ScrollingDigits
        widthScaler: 2.5
        heightScaler: 2.0
        colorFlag: 1                    // want last digit to be black instead of white

        number: backend.trip            // Link Cpp trip member to qml trip digits
//        NumberAnimation on number {
//            from: 0; to: 100
//            duration: 50000
//        }
    }

    ScrollingDigits {
        id: odometer
        anchors.verticalCenterOffset: -61
        anchors.horizontalCenterOffset: -2
        anchors.centerIn: id_speed

        positions: 6
        widthScaler: 1.7
        heightScaler: 2.0

        number: backend.odom        // Link Cpp member odom to odometer
        // Run odometer animation slower than trip
//        NumberAnimation on number {
//            from: 0; to: 75
//            duration: 500000
//        }
    }

    Item {
        id: id_needle

        property int value: backend.wspd // connect backend wspd sensor reading to qml speedo//id_root.value
        property int startAngle : 0
        // account for 20 km/hr not having even spacing like the rest of the speedometer
        property double angleLength: (value < 20) ? .75 : 15 + ((value - 20) * 1.15)
        property int maxSpeed: 220

        anchors.horizontalCenter: id_speed.horizontalCenter   //  x: 208
        anchors.verticalCenter: id_speed.verticalCenter   // y: 337
        width: 68
        height: 68

        Image {
            id: id_image_needle
            x: -147
            y: -1
            width: 220
            height: 156
            fillMode: Image.PreserveAspectFit
            source: "layer_2_219_4_219_4.png"
        }

        rotation: angleLength

        antialiasing: true

        Behavior on rotation {
            SmoothedAnimation { velocity: 100 }
        }
    }
}


