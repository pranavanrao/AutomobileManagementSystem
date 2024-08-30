import QtQuick 2.12
import QtQuick.Window 2.12

import "./ui"

Window {
    width: screen.width
    height: screen.height
    visible: true
    title: qsTr("Hello World")
    color: "#f39c12"

    MainCategoryRow {}
}
