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
    }
}
