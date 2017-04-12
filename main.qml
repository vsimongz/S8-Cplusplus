import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    objectName: "wnd1"
    visible: true
    width: 300
    height: 400
    title: qsTr("Jeu 2048")

    MainForm {
        anchors.fill: parent
    }
}
