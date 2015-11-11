import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import clicker 1.0

ApplicationWindow {
    visible: true
    title: 'Clicker'
    width: 250
    height: 200
    minimumWidth: width
    maximumWidth: width
    minimumHeight: height
    maximumHeight: height

    property bool x2Enabled: false
    property bool autoClickEnabled: false
    property string _achivements : ''

    statusBar: StatusBar {
        RowLayout {
            anchors.fill: parent
            Label {
                text: 'Clicks count: ' + clicker.clicksCount
                id: gameStatus
            }
            Label {
                id: achivementsStatus
                text: ''
                color: 'red'
            }
        }
    }

    TabView {
        anchors.fill: parent

        Tab {
            title: 'Game'

            Rectangle {
                color: 'steelblue'

                Button {
                    text: 'Click me!'
                    anchors.centerIn: parent

                    onClicked: {
                        achivementsStatus.text = '';
                        clicker.increaseClicksCount();
                    }
                }
            }
        }

        Tab {
            id: shop
            title: 'Shop'

            Grid {
                anchors.fill: parent
                anchors.margins: 10
                columns: 3
                rows: 2
                columnSpacing: 10
                rowSpacing: 5

                Text {
                    text: 'x2'
                }

                Text {
                    text: '5000'
                }

                Button {
                    enabled: x2Enabled
                    text: 'Buy'
                    onClicked: {
                        clicker.setPointsPerClick(2);
                        this.enabled = false;
                    }
                }

                Text {
                    text: 'autoclick'
                }

                Text {
                    text: '10000'
                }

                Button {
                    enabled: autoClickEnabled
                    text: 'Buy'
                    onClicked: {
                        clicker.autoClick();
                        this.enabled = false;
                    }
                }
            }
        }

        Tab {
            id: achivements
            title: 'Achivements'
            anchors.margins: 10

            Text {
                text: _achivements
            }
        }

        Clicker {
            id: clicker
            onAchivementReached: {
                achivementsStatus.text =
                        'You\'ve ' + 'clicked ' +
                        clicksCount + ' times';
                _achivements += clicksCount + '\n'
            }
            onX2Unlocked: {
                x2Enabled = true
            }
            onAutoClickUnlocked: {
                autoClickEnabled = true
            }
        }
    }
}
