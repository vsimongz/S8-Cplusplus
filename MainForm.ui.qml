import QtQuick 2.5
import QtQuick.Controls 2.1
import QtQuick 2.6


Rectangle {
    id: rectangle1
    width: 230
    height: 330
    color: Qt.rgba(0.9,1,0.75)
    radius: 1
    border.width: 1
    border.color: "#000000"

    function textcouleur( i) {
            var cl;
            if(vueObjetCpt.stat[i]==0)
                cl =    Qt.rgba(0.7,1,1);
            else if (vueObjetCpt.stat[i]==2)
            cl =  Qt.rgba(0.8,0.2,0.1);
            else if (vueObjetCpt.stat[i]==4)
                cl =   Qt.rgba(0.8,0,0.4);
            else if (vueObjetCpt.stat[i]==8)
             cl =    Qt.rgba(0.8,0.2,0.6);
            else if (vueObjetCpt.stat[i]==16)
                cl =     Qt.rgba(0.5,0.9,0.9);
            else if (vueObjetCpt.stat[i]==32)
                cl =    Qt.rgba(0.5,1,0.8);
            else if (vueObjetCpt.stat[i]==64)
                cl =    Qt.rgba(0.5,1,0.5);
            else if (vueObjetCpt.stat[i]==128)
                cl =   Qt.rgba(0.5,0.8,0.1);
            else if (vueObjetCpt.stat[i]==256)
                cl =    Qt.rgba(0.5,0.7,0.6);
            else if (vueObjetCpt.stat[i]==512)
                cl =    Qt.rgba(0.5,0.8,0.5);
            else if (vueObjetCpt.stat[i]==1024)
                cl =    Qt.rgba(0.5,0.9,0.9);
            else if (vueObjetCpt.stat[i]==2048)
                cl =    Qt.rgba(0.5,1,0.9);
            else
                cl =    Qt.rgba(0.7,1,1);
            return cl;
     }

    function rectcouleur(i) {
            var cl;
            if(vueObjetCpt.stat[i]==0)
            cl =    Qt.rgba(0.7,1,1);
            else if (vueObjetCpt.stat[i]==2)
            cl =    Qt.rgba(0.7,1,0.5);
            else if (vueObjetCpt.stat[i]==4)
             cl =    Qt.rgba(0.7,0.9,0.1);
            else if (vueObjetCpt.stat[i]==8)
             cl =    Qt.rgba(0.7,0.7,0.3);
            else if (vueObjetCpt.stat[i]==16)
             cl =   Qt.rgba(0.7,0.6,0.4);
            else if (vueObjetCpt.stat[i]==32)
             cl =    Qt.rgba(0.7,0.5,0.5);
            else if (vueObjetCpt.stat[i]==64)
             cl =    Qt.rgba(0.5,0.2,0.6);
            else if (vueObjetCpt.stat[0]==128)
             cl =     Qt.rgba(0.7,0.3,0.7);
            else if (vueObjetCpt.stat[i]==256)
             cl =    Qt.rgba(0.8,0.2,0.6);
            else if (vueObjetCpt.stat[0]==512)
             cl =   Qt.rgba(0.8,0,0.4);
            else if (vueObjetCpt.stat[i]==1024)
             cl =   Qt.rgba(0.8,0.2,0.1);
            else if (vueObjetCpt.stat[i]==2048)
             cl =   Qt.rgba(0.8,0,0);
             else
             cl = "green";
            return cl;
     }


    Rectangle {
        id: rectangle
        x: 10
        y: 80
        width: 210
        height: 210
        color: "#ffffff"
    }


    Rectangle {
        id: score1
        x: 16
        y: 10
        width: 104
        height: 45
        color: rgba(0.7,0.9,0.1)
        gradient: Gradient {
                GradientStop { position: 0.0; color: "#58FAAC" }
                GradientStop { position: 1.0; color: "#01DF3A" }
            }
        border.color: "black"
        border.width: 1.4
        TextEdit {
            id: textEdit
            width: 104
            height: 20
            text: qsTr("Score")
            font.family: "Verdana"
            selectionColor: "#231ffa"
            renderType: Text.QtRendering
            textFormat: Text.AutoText
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
        }

        Text {
            id: text1
            x: 0
            y: 23
            width: 104
            height: 14
            text: vueObjetCpt.stat3[0]
            horizontalAlignment: Text.AlignHCenter
            font.weight: Font.ExtraLight
            font.family: "Verdana"
            font.pixelSize: 16

        }
    }

    Rectangle {
        id: score2
        x: 140
        y: 10
        width: 104
        height: 45
        color: rgba(0.7,0.9,0.1)
        gradient: Gradient {
                GradientStop { position: 0.0; color: "#58FAAC" }
                GradientStop { position: 1.0; color: "#01DF3A" }
            }
        border.color: "black"
        border.width: 1.4
        TextEdit {
            id: textEdit2
            width: 104
            height: 20
            text: qsTr("Best")
            font.family: "Verdana"
            selectionColor: "#231ffa"
            renderType: Text.QtRendering
            textFormat: Text.AutoText
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
        }

        Text {
            id: text2
            x: 0
            y: 23
            width: 104
            height: 14
            text: vueObjetCpt.stat3[1]
            horizontalAlignment: Text.AlignHCenter
            font.weight: Font.ExtraLight
            font.family: "Verdana"
            font.pixelSize: 16

        }
}

    Rectangle {
        id: rectangle11
        x: 12
        y: 82
        width: 50
        height: 50
        color: rectangle1.rectcouleur(0)

        Text {
            id: text11
            x: 49
            y: 0
            width: 50
            height: 50
            font.pixelSize: 24
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            focus: true
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenterOffset: 0
            font.family: "Tahoma"
            anchors.horizontalCenterOffset: 0
            property string couleur
                   text: vueObjetCpt.stat[0]
                   color: rectangle1.textcouleur(0)

        }
    }





    Rectangle {
        id: rectangle12
        x: 64
        y: 82
        width: 50
        height: 50
          color: rectangle1.rectcouleur(1)
        border.width: 0

        Text {
            id: text12
            x: 247
            y: 33
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
                 text: vueObjetCpt.stat[1]
                 color: rectangle1.textcouleur(1)

        }
    }


    Connections {
        target: rectangle11
        onClicked: print("clicked")
    }


    Rectangle {
        id: rectangle13
        x: 116
        y: 82
        width: 50
        height: 50
             color: rectangle1.rectcouleur(2)
        border.width: 0
        Text {
            id: text13
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 24
            anchors.verticalCenterOffset: 0
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                   color: rectangle1.textcouleur(2)
                   text: vueObjetCpt.stat[2]


        }
    }




    Rectangle {
        id: rectangle14
        x: 168
        y: 82
        width: 50
        height: 50
           color: rectangle1.rectcouleur(3)
        border.width: 0
        Text {
            id: text14
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 24
            anchors.verticalCenterOffset: 0
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                     text: vueObjetCpt.stat[3]
                     color: rectangle1.textcouleur(3)


        }
    }




    Rectangle {
        id: rectangle21
        x: 12
        y: 134
        width: 50
        height: 50
              color: rectangle1.rectcouleur(4)
        border.width: 0
        Text {
            id: text21
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 24
            anchors.verticalCenterOffset: 0
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                     text: vueObjetCpt.stat[4]
                   color: rectangle1.textcouleur(4)


        }
    }




    Rectangle {
        id: rectangle22
        x: 64
        y: 134
        width: 50
        height: 50
                color: rectangle1.rectcouleur(5)
        border.width: 0
        Text {
            id: text22
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 24
            anchors.verticalCenterOffset: 0
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                     text: vueObjetCpt.stat[5]
                     color: rectangle1.textcouleur(5)

        }
    }



    Rectangle {
        id: rectangle23
        x: 116
        y: 134
        width: 50
        height: 50
              color: rectangle1.rectcouleur(6)
        border.width: 0
        Text {
            id: text23
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                      text: vueObjetCpt.stat[6]
                      color: rectangle1.textcouleur(6)
        }
    }



    Rectangle {
        id: rectangle24
        x: 168
        y: 134
        width: 50
        height: 50
              color: rectangle1.rectcouleur(7)
        border.width: 0
        Text {
            id: text24
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 1
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                     text: vueObjetCpt.stat[7]
                     color: rectangle1.textcouleur(7)
        }
    }



    Rectangle {
        id: rectangle31
        x: 12
        y: 186
        width: 50
        height: 50
                color: rectangle1.rectcouleur(8)
        border.width: 0
        Text {
            id: text31
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: -1
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                      text: vueObjetCpt.stat[8]
                      color: rectangle1.textcouleur(8)

        }
    }



    Rectangle {
        id: rectangle32
        x: 64
        y: 186
        width: 50
        height: 50
              color: rectangle1.rectcouleur(9)
        border.width: 0
        Text {
            id: text32
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                    text: vueObjetCpt.stat[9]
                     color: rectangle1.textcouleur(9)


        }
    }



    Rectangle {
        id: rectangle33
        x: 116
        y: 186
        width: 50
        height: 50
              color: rectangle1.rectcouleur(10)
        border.width: 0
        Text {
            id: text33
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 1
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                     text: vueObjetCpt.stat[10]
                      color: rectangle1.textcouleur(10)

        }
    }



    Rectangle {
        id: rectangle34
        x: 168
        y: 186
        width: 50
        height: 50
            color: rectangle1.rectcouleur(11)
        border.width: 0
        Text {
            id: text34
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                  text: vueObjetCpt.stat[11]
                   color: rectangle1.textcouleur(11)

        }
    }



    Rectangle {
        id: rectangle41
        x: 12
        y: 238
        width: 50
        height: 50
          color: rectangle1.rectcouleur(12)
        border.width: 0
        Text {
            id: text41
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                   text: vueObjetCpt.stat[12]
                    color: rectangle1.textcouleur(12)

        }
    }



    Rectangle {
        id: rectangle42
        x: 64
        y: 238
        width: 50
        height: 50
        color: rectangle1.rectcouleur(13)
        border.width: 0
        Text {
            id: text42
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
               text: vueObjetCpt.stat[13]
                  color: rectangle1.textcouleur(13)

        }
    }



    Rectangle {
        id: rectangle43
        x: 116
        y: 238
        width: 50
        height: 50
        color: rectangle1.rectcouleur(14)
        border.width: 0
        Text {
            id: text43
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 1
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                  text: vueObjetCpt.stat[14]
                  color: rectangle1.textcouleur(14)

        }
    }



    Rectangle {
        id: rectangle44
        x: 168
        y: 238
        width: 50
        height: 50
          color: rectangle1.rectcouleur(15)
        border.width: 0
        Text {
            id: text44
            x: 247
            y: 33
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pixelSize: 24
            anchors.horizontalCenterOffset: 0
            focus: true
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
                  text: vueObjetCpt.stat[15]
                  color: rectangle1.textcouleur(15)

        }
    }

    Text {
        id: textgagnant
        x: 14
        y: 57
        width: 208
        height: 19
        text: qsTr("2048")
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 17
    }

    Text {
        id: textperdeur
        x: 11
        y: 57
        width: 208
        height: 19
        text: rectangle1.perdant()
        font.pixelSize: 17
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
    }


    Button {
        x: 10
        y: 300
        id: control
        text: qsTr("BACK")
        onClicked: vueObjetCpt.back();
        contentItem: Text {
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: control.down ? "#17a81a" : "#21be2b"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            border.color: control.down ? "#17a81a" : "#21be2b"
            border.width: 1
            radius: 2
        }
    }

    Button {
        x: 120
        y: 300
        id: control2
        text: qsTr("AGAIN")
        onClicked: vueObjetCpt.newJeu();
        contentItem: Text {
            text: control2.text
            font: control2.font
            opacity: enabled ? 1.0 : 0.3
            color: control2.down ? "#F71020" : "#C9084C"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            border.color: control2.down ? "#F71020" : "#C9084C"
            border.width: 1
            radius: 2
        }
    }


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
            case Qt.Key_R:
                vueObjetCpt.back();
               break;
      }
    }


       Rectangle {
           id: info
           x: 16
           y: 360
           width: 250
           height: 25
           color: Qt.rgba(0.9,1,0.75)


           TextEdit {
               id: infotext
               width: 104
               height: 20
               text: vueObjetCpt.stat4
               font.family: "Verdana"
               selectionColor: "#231ffa"
               renderType: Text.QtRendering
               textFormat: Text.AutoText
               horizontalAlignment: Text.AlignHCenter
               font.pixelSize: 18
           }

       }

}
