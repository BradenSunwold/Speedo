import QtQuick 2.0

Item {
    id: digitItem
    width: size * widthScaler           // width and height control main sapcing of digits
    height: size * heightScaler

    clip: true

//    opacity: 0

    property int digit: 0
    property int size: 15               // size controls scaling of digits
    property double heightScaler: 2.5
    property double widthScaler: 2.0
    property string colorValue: "white"

    onDigitChanged: { digitPath.currentIndex = digit; }

    PathView {
        id: digitPath

        width: digitItem.size
        height: digitItem.size * 25

        interactive: false

        anchors.centerIn: parent

        model: [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]

        delegate: Text {
            width: digitItem.size
            height: digitItem.size

            text: modelData;

            color: colorValue;

            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;

            font.pointSize: digitItem.size-8;       // controls size of digit fonts
        }

        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5

        path: Path {
            startX: digitPath.width / 2
            startY: 0

            PathLine { x: digitPath.width / 2; y: digitPath.height }
        }
    }
}
