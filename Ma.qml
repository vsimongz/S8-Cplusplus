import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 300
    height: 400
    title: qsTr("Main Menu")

    MaForm {
        anchors.fill: parent
    }
}
