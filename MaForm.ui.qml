import QtQuick 2.5
import QtQuick.Controls 2.1
import QtQuick 2.6

Rectangle {
    id: rectangle1
    width: 300
    height: 400
    color: Qt.rgba(0.9,1,0.75)
    radius: 1
    border.width: 1
    border.color: "#000000"
Button {
    x: 84
    y: 139
    width: 135
    height: 40
    id: b1
    text: qsTr("PLAY")
    highlighted: true
    onClicked: vueObjetCpt.play();
    contentItem: Text {
        text: b1.text
        font: b1.font
        opacity: enabled ? 1.0 : 0.3
        color: b1.down ? "#F71020" : "#C9084C"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        border.color: b1.down ? "#F71020" : "#C9084C"
        border.width: 1
        radius: 2
    }
}
Button {
    x: 84
    y: 311
    width: 135
    height: 40
    id: b2
    text: qsTr("COULEUR")
    highlighted: true
     onClicked: vueObjetCpt.newJeu();
    contentItem: Text {
        text: b2.text
        font: b2.font
        opacity: enabled ? 1.0 : 0.3
        color: b2.down ? "#F71020" : "#C9084C"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        border.color: b2.down ? "#F71020" : "#C9084C"
        border.width: 1
        radius: 2
    }
}
Button {
    x: 84
    y: 255
    width: 135
    height: 40
    id: b3
    text: qsTr("5x5")
    highlighted: true
    onClicked: vueObjetCpt.changeSize();
    contentItem: Text {
        text: b3.text
        font: b3.font
        opacity: enabled ? 1.0 : 0.3
        color: b3.down ? "#F71020" : "#C9084C"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        border.color: b3.down ? "#F71020" : "#C9084C"
        border.width: 1
        radius: 2
    }
}
Button {
    x: 84
    y: 199
    width: 67
    height: 40
    id: b4
    text: qsTr("Mode")
    highlighted: true
    onClicked: vueObjetCpt.changeVal();
    contentItem: Text {
        text: b4.text
        font: b4.font
        opacity: enabled ? 1.0 : 0.3
        color: b4.down ? "#F71020" : "#C9084C"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        border.color: b4.down ? "#F71020" : "#C9084C"
        border.width: 1
        radius: 2
    }
}

Text {
    id: text1
    x: 84
    y: 39
    width: 133
    height: 42
    color: "#082df2"
    text: qsTr("2048 ")
    textFormat: Text.RichText
    renderType: Text.NativeRendering
    font.italic: true
    font.bold: true
    font.family: "Courier"
    styleColor: "#83f558"
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter
    font.pixelSize: 24
}

Text {
    id: text2
    x: 18
    y: 87
    width: 265
    height: 42
    color: "#082df2"
    text: qsTr("Développé par Jon et Vicente")
    styleColor: "#83f558"
    renderType: Text.NativeRendering
    font.family: "Courier"
    font.italic: true
    textFormat: Text.RichText
    font.pixelSize: 10
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.bold: true
}

Rectangle {
    id: rectangle22
    x: 169
    y: 199
    width: 50
    height: 40
    color: "#d6f7d7"
    border.color: "#e2efe4"
    border.width: 0
    Text {
        id: text22
        x: 0
        y: 33
        width: 50
        height: 34
        font.pixelSize: 24
        anchors.verticalCenterOffset: 0
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 0
        focus: true
        font.family: "Tahoma"
        horizontalAlignment: Text.AlignHCenter
        anchors.verticalCenter: parent.verticalCenter
                 text: vueObjetCpt.stat1

    }
}
}
