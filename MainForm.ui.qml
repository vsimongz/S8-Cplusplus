import QtQuick 2.5

Rectangle {
    id: rectangle1

    width: 480
    height: 320
    color: "#e02d2d"
    radius: 2
    border.width: 7
    border.color: "#000000"

    Text {
        id: text1
        x: 39
        y: 15
        width: 50
        height: 50
        font.pixelSize: 24
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        verticalAlignment: Text.AlignVCenter
        focus: true
        horizontalAlignment: Text.AlignHCenter
        anchors.verticalCenterOffset: -102
        font.family: "Tahoma"
        anchors.horizontalCenterOffset: -97
        text: vueObjetCpt.stat[0]

    }

    Text {
        id: text2
        x: 37
        y: 12
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: -102
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -48
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[1]
    }

    Text {
        id: text3
        x: 34
        y: 8
        width: 50
        height: 50
        focus: true
        font.pixelSize: 24
        anchors.verticalCenterOffset: -102
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 0
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[2]
    }

    Text {
        id: text4
        x: 41
        y: 11
        width: 50
        height: 50
        focus: true
        font.pixelSize: 24
        anchors.verticalCenterOffset: -102
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 50
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[3]
    }

    Text {
        id: text5
        x: 38
        y: 14
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: -52
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -97
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[4]
    }

    Text {
        id: text6
        x: 36
        y: 11
        width: 50
        height: 50
        focus: true
        font.pixelSize: 24
        anchors.verticalCenterOffset: -52
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -48
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[5]
    }

    Text {
        id: text7
        x: 33
        y: 7
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: -52
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Tahoma"
    verticalAlignment: Text.AlignVCenter
    anchors.horizontalCenterOffset: 0
    horizontalAlignment: Text.AlignHCenter
    text: vueObjetCpt.stat[6]
    }

    Text {
        id: text8
        x: 40
        y: 10
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: -52
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 50
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[7]
    }

    Text {
        id: text9
        x: 36
        y: 12
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -97
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[8]
    }

    Text {
        id: text10
        x: 34
        y: 9
        width: 50
        height: 50
        focus: true
        font.pixelSize: 24
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -48
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[9]
    }

    Text {
        id: text11
        x: 31
        y: 5
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    font.family: "Tahoma"
    verticalAlignment: Text.AlignVCenter
    anchors.horizontalCenterOffset: 0
    horizontalAlignment: Text.AlignHCenter
    text: vueObjetCpt.stat[10]
    }

    Text {
        id: text12
        x: 38
        y: 8
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 50
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[11]
    }

    Text {
        id: text13
        x: 31
        y: 7
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: 51
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -97
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[12]
    }

    Text {
        id: text14
        x: 29
        y: 4
        width: 50
        height: 50
        focus: true
        font.pixelSize: 24
        anchors.verticalCenterOffset: 51
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -48
        horizontalAlignment: Text.AlignHCenter
        text: vueObjetCpt.stat[13]
    }

    Text {
        id: text15
        x: 26
        y: 0
        width: 50
        height: 50
        font.pixelSize: 24
        focus: true
        anchors.verticalCenterOffset: 51
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    font.family: "Tahoma"
    verticalAlignment: Text.AlignVCenter
    anchors.horizontalCenterOffset: 0
    horizontalAlignment: Text.AlignHCenter
    text: vueObjetCpt.stat[14]
}

Text {
    id: text16
    x: 33
    y: 3
    width: 50
    height: 50
    font.pixelSize: 24
    focus: true
    anchors.verticalCenterOffset: 51
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
    font.family: "Tahoma"
    verticalAlignment: Text.AlignVCenter
    anchors.horizontalCenterOffset: 50
    horizontalAlignment: Text.AlignHCenter
    text: vueObjetCpt.stat[15]
}
///*
Keys.onPressed: {
          switch (event.key) {
            case Qt.Key_Up:
                vueObjetCpt.moveUp()
                vueObjetCpt.sommeUp()
                  break;
            case Qt.Key_Right:
                vueObjetCpt.moveDroit()
                vueObjetCpt.sommeDroit()
                  break;
            case Qt.Key_Left:
                vueObjetCpt.moveGauche()
                vueObjetCpt.sommeGauche()
                  break;
            case Qt.Key_Down:
                 vueObjetCpt.moveDown();
                 vueObjetCpt.sommeDown();
            break;
      }
}

}
