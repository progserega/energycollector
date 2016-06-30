import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    width: 400
    height: 400
    property alias listViewCitySearchId: listViewCitySearchId
    //property alias listModelCitySearchId: listModelCitySearchId
    property alias buttonCitySearch: buttonCitySearch
    property alias textFieldCityName: textFieldCityName

    ColumnLayout {
        id: columnLayout1
        anchors.fill: parent

        Text {
            id: text1
            text: qsTr("Введите имя населённого пункта")
            font.pixelSize: 15
        }

        RowLayout {
            id: rowLayout1
            width: 100
            height: 100

            TextField {
                id: textFieldCityName
                text: qsTr("Имя населённого пункта...")
                Layout.fillWidth: true
            }

            Button {
                id: buttonCitySearch
                x: 197
                y: 8
                text: qsTr("Поиск")
            }
        }

        ColumnLayout {
            id: columnLayout2
            x: 68
            y: 232
            width: 100
            height: 100

            ListView {
                id: listViewCitySearchId
                //model: listViewCitySearchModel
                x: 0
                y: 0
                width: 110
                height: 160
                Layout.fillHeight: true
                Layout.fillWidth: true
                model: listModelCitySearchId
   delegate: Rectangle {
        height: 25
        width: 100
        Text { text: modelData }
    }
                /*delegate: Item {
                    x: 5
                    width: 80
                    height: 40
                    Row {
                        id: row1
                        spacing: 10
                        Rectangle {
                            width: 40
                            height: 40
                            color: colorCode
                        }

                        Text {
                            text: name
                            font.bold: true
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }*/
   /*             model: ListModel {
                    id: listModelCitySearchId
                    ListElement {
                        name: "Владивосток"
                        colorCode: "red"
                    }

                    ListElement {
                        name: "Артём"
                        colorCode: "blue"
                    }

                    ListElement {
                        name: "Находка"
                        colorCode: "green"
                    }
                }*/
            }
        }
    }
}
