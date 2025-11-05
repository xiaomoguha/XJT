import QtQuick 2.15

Item {
    objectName: "CommunityPage"
    width: parent ? parent.width : 0
    height: parent ? parent.height : 0
    // 接收传进来的参数
    property int index: 2
    Text {
        id: homeText
        anchors.centerIn: parent
        text: qsTr("社区（未完成)")
        font.family: "黑体"
        font.pixelSize: 20
        color: "white"
    }
}
