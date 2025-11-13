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
    Row {
        anchors.fill: parent
        Button {
            id: myButton
            objectName: "submitButton"  // Уникальное имя для поиска в C++
            text: "Нажать"
            x: parent.width / 8
            anchors.verticalCenter: parent.verticalCenter
            // y: (parent.height - width) / 2
            background: Rectangle {
                color: "#C0C0C0"
            }
            onClicked: {
                console.log("Received from C++:");
            }
            onPressed: {
                scale = 0.95;
                background.color = "#808080";
            }
            onReleased: {
                scale = 1.0;
                background.color = "#C0C0C0";
            }
        }
    }
}