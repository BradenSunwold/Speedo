
import QtQuick 2.0

Item {

    id: id_root
    property int value

    //to creating data for demonstration purpose
    property int count: 0
    property int randNum: 0

    width: 512
    height: 472
    visible: true

    Timer {
        id: id_timer
        repeat: true
        interval: 1000
        running: true

        onTriggered: {
//            if(id_gear.value == 6) id_gear.value = 0;
//            else id_gear.value++;

            if(id_root.count % 5 == 0){
//                id_speed.value = backend.speedValue
                if(id_root.value === 0) id_root.value = 220
                else id_root.value = 0

//                if(id_info.fuelValue == 0) id_info.fuelValue = 4
//                else id_info.fuelValue = 0
            }
            id_root.count++;

//            if(count % 2 == 0){
//                id_turnLeft.isActive = true
//                id_turnRight.isActive = false
//            }else{
//                id_turnLeft.isActive = false
//                id_turnRight.isActive = true
//            }
        }
    }

    Image {
        id: id_speed
        x: -14
        y: 135
        width: 512
        height: 472
        fillMode: Image.PreserveAspectFit
        source: "layer_1_219_3_219_3.png"
    }

    Item {
        id: id_needle

        property int value: id_root.value
        property int startAngle : 0
        // account for 20 km/hr not having even spacing like the rest of the speedometer
        property double angleLength: (value < 20) ? .75 : 15 + ((value - 20) * 1.15)
        property int maxSpeed: 220


        x: 208
        y: 337
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
            SmoothedAnimation { velocity: 50 }
        }
    }

}


