import QtQuick 2.3
import QtQuick.Controls 2.1

Item {
    id: root
    anchors.fill: parent


    Image {
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        mirror: true
        source: PathUtils.resourcePath("images/hifi_window@2x.png");
        transformOrigin: Item.Center
        rotation: 180
    }

    Image {
        id: logo
        width: 150
        height: 150
        source: PathUtils.resourcePath("images/HiFi_Voxel.png");

        anchors {
            top: root.top
            topMargin: 48
            horizontalCenter: root.horizontalCenter
        }

         RotationAnimator {
            target: logo;
            loops: Animation.Infinite
            from: 0;
            to: 360;
            duration: 5000
            running: true
        }
    }

    Text {
        id: firstText
        width: 300
        height: 41
        font.family: "Graphik"
        font.pixelSize: 28
        text: "Setup will take a moment"
        color: "#FFFFFF"

        anchors {
            top: logo.bottom
            topMargin: 46
            horizontalCenter: logo.horizontalCenter
        }
    }

    Text {
        id: secondText
        font.family: "Graphik"
        font.pixelSize: 14
        text: "We're getting your headquaters ready"
        color: "#FFFFFF"

        anchors {
            top: firstText.bottom
            topMargin: 14
            horizontalCenter: logo.horizontalCenter
        }
    }

    ProgressBar {
        id: progressBar
        width: 394
        height: 8

        value: LauncherState.downloadProgress;

        anchors {
            top: secondText.bottom
            topMargin: 30
            horizontalCenter: logo.horizontalCenter
        }

        background: Rectangle {
            implicitWidth: progressBar.width
            implicitHeight: progressBar.height
            radius: 8
            color: "#252525"
        }

        contentItem: Item {
            implicitWidth: progressBar.width
            implicitHeight: progressBar.height * 0.85

            Rectangle {
                width: progressBar.visualPosition * parent.width
                height: parent.height
                radius: 6
                color: "#01B2ED"
            }
        }
    }


    Text {
        width: 100
        height: 17

        text: "High Fidelity"
        font.bold: true
        font.family: "Graphik"
        font.pixelSize: 24
        font.letterSpacing: -1
        color: "#FFFFFF"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        anchors {
            bottom: root.bottom
            bottomMargin: 15
            left: root.left
            leftMargin: 30
        }
    }

    Component.onCompleted: {
        root.parent.setStateInfoState("right");
        root.parent.setBuildInfoState("left");
    }
}
