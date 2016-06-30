import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        ByAddressP1 {
        }
        Page {
            Label {
                text: qsTr("TODO: выбор по счётчику")
                anchors.centerIn: parent
            }
        }
        Page {
            Label {
                text: qsTr("TODO: выбор по счёту")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Выбор поиска")
        }
        TabButton {
            text: qsTr("Город")
        }
        TabButton {
            text: qsTr("Улица")
        }
        TabButton {
            text: qsTr("Дом")
        }
        TabButton {
            text: qsTr("Точка учёта")
        }
    }
}
