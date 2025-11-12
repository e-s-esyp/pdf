import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Hello QML"
    Label {
        text: "Привет, мир!"
        anchors.centerIn: parent
    }
}