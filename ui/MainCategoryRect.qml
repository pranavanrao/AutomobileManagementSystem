import QtQuick 2.15

Rectangle {
    id: mainCatRect
    width: mainCatRow.width*0.27
    height: mainCatRow.height*0.8
    radius: 10
    Image {
        id: mainCatImg
        anchors.fill: parent
        anchors.margins: 20
        source: modelData.image
    }

    Text {
        id: mainCatText
        text: modelData.title
        font.pixelSize: parent.height*0.25
        font.bold: true
        color: "#212f3d"
        opacity: 0.8
        anchors.top: mainCatImg.top
        anchors.horizontalCenter: mainCatImg.horizontalCenter
    }
}
