import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    objectName: "wnd1"
    visible: true
    width: 300
    height: 400
    title: qsTr("5x5")

    Main1Form {
        anchors.fill: parent
    }
}
