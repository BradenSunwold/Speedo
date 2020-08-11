import QtQuick 2.0


Row {
    id: scrollingDigits

    property int number: 0
    property int positions: 5
    property double heightScaler: 2.5
    property double widthScaler: 2.0
    property string colorValue: "white"
    property int colorFlag: 0               // flag if you want last digit to be a different color (black)

    Repeater {
        id: rep

        model: scrollingDigits.positions

        Digit {
            heightScaler: scrollingDigits.heightScaler
            widthScaler: scrollingDigits.widthScaler
        }
    }

    // if colorFlag is set then change the last digit to black
function colorChange() {
    if(colorFlag == 1) {
            rep.itemAt(positions - 1).colorValue = "black";
    }
}

    Component.onCompleted: {
        colorChange();
    }

    onNumberChanged: {

        var tmp = number

        for( var i = 0; i < positions; ++i ) {
            rep.itemAt( positions - i - 1).digit = tmp % 10
            tmp = Math.floor( tmp / 10 )
        }
    }
}

