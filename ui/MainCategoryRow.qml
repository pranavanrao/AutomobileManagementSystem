import QtQuick 2.15
import MainCategories 1.0

Item {
    id: root
    anchors.fill: parent
    anchors.margins: parent.height*0.15

    AutoCategoriesData {
        id: autoCategories
    }

    Text {
        id: mainTitle
        text: "KTM VENDOR MANAGEMENT"
        color: "#212f3d"
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: parent.height*0.06
        font.bold: true
        font.family: "Monospace"
    }

    Row {
        id: mainCatRow
        width: parent.width
        height: parent.height*0.5
        spacing: parent.width*0.1
        anchors.bottom: root.bottom
        Repeater {
            model: autoCategories.parseMainCategories();
            delegate: MainCategoryRect {}
        }
    }
}
