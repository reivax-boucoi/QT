import QtQuick 2.4
import QtQuick.Controls 2.3

Rectangle {
    id: rectangle
    width: 400
    height: 400
    color: "#ffffff"
    property alias label: label
    property alias button: button
    Button {
        id: button
        text: qsTr("Press Me !")
        checkable: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Label {
        id: label
        y: 117
        text: qsTr("LabelTest")
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
