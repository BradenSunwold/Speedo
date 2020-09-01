import QtQml.Models 2.2
import QtQml 2.2

import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Window 2.2


Window {
    visible: true
    width: 480
    height: 800
    title: qsTr("speedoClassic")

    //    BackEnd {
    //        id: backend
    //    }

    Rectangle {
        Speedo {
            visible: true
            width: 512
            height: 472
        }

        ScrollingDigits {
            id: trip
            anchors.verticalCenterOffset: 433
            anchors.horizontalCenterOffset: 239
            anchors.centerIn: parent

            positions: 4
            widthScaler: 2.5
            heightScaler: 2.0
            colorFlag: 1                    // want last digit to be black instead of white

            NumberAnimation on number {
                from: 0; to: 100
                duration: 50000
            }
        }

        ScrollingDigits {
            id: odometer
            anchors.verticalCenterOffset: 309
            anchors.horizontalCenterOffset: 239
            anchors.centerIn: parent

            positions: 6
            widthScaler: 1.7
            heightScaler: 2.0

            // Run odometer animation slower than trip
            NumberAnimation on number {
                from: 0; to: 75

                duration: 500000
            }
        }
    }
}
