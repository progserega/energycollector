import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: item1
    property alias button2: button2
    property alias button3: button3
    property alias image1: image1
    property alias text1: text1
    property alias button1: button1

    ColumnLayout {
        id: columnLayout1
        anchors.fill: parent

        RowLayout {
            id: rowLayout1
            width: 100
            height: 100
            Layout.fillHeight: true
            clip: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true

            Image {
                id: image1
                width: 100
                height: 100
                Layout.fillHeight: false
                Layout.fillWidth: false
                visible: true
                source: "logo_drsk.gif"
            }

            Text {
                id: text1
                text: qsTr("Внесение показаний счётчиков")
                Layout.fillHeight: false
                Layout.fillWidth: false
                font.pixelSize: 12
            }
        }

        Button {
            id: button1
            text: qsTr("По адресу")
            Layout.fillHeight: true
            autoExclusive: false
            checked: false
            checkable: false
            rotation: 0
            scale: 1
            spacing: 0
            autoRepeat: false
            highlighted: false
            clip: false
            visible: true
            transformOrigin: Item.Center
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: button2
            text: qsTr("По номеру счётчика")
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true
        }

        Button {
            id: button3
            text: qsTr("По номеру лиц. счёта")
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

    }
}
