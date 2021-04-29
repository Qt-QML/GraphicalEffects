/*
 * MIT License
 *
 * Copyright (C) 2021 by wangwenx190 (Yuhang Zhao)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

import QtQuick
import QtQuick.Controls
import org.wangwenx190.Qt5Compat.GraphicalEffects

Window {
    id: window
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello, world!")

    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent

        Item {
            Image {
                id: pic1
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            BrightnessContrast {
                anchors.fill: pic1
                source: pic1
                brightness: 0.5
                contrast: 0.5
            }
        }

        Item {
            Image {
                id: pic2
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            Colorize {
                anchors.fill: pic2
                source: pic2
                hue: 0.0
                saturation: 0.5
                lightness: -0.2
            }
        }

        Item {
            Image {
                id: pic3
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            ColorOverlay {
                anchors.fill: pic3
                source: pic3
                color: Qt.color("#80800000")
            }
        }

        Item {
            ConicalGradient {
                anchors.fill: parent
                angle: 0.0
                gradient: Gradient {
                    GradientStop { position: 0.0; color: Qt.color("white") }
                    GradientStop { position: 1.0; color: Qt.color("black") }
                }
            }
        }

        Item {
            Image {
                id: pic4
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            Desaturate {
                anchors.fill: pic4
                source: pic4
                desaturation: 0.8
            }
        }

        Item {
            Image {
                id: pic5
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            Rectangle {
                id: displacement
                color: Qt.rgba(0.5, 0.5, 1.0, 1.0)
                anchors.fill: parent
                visible: false
                Image {
                    anchors.centerIn: parent
                    source: "qrc:///images/glass_normal.png"
                    sourceSize: Qt.size(parent.width/2, parent.height/2)
                    smooth: true
                }
            }

            Displace {
                anchors.fill: pic5
                source: pic5
                displacementSource: displacement
                displacement: 0.1
            }
        }

        Item {
            Rectangle {
                anchors.fill: parent
            }

            Image {
                id: pic6
                source: "qrc:///images/butterfly.png"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            DropShadow {
                anchors.fill: pic6
                horizontalOffset: 3
                verticalOffset: 3
                radius: 8.0
                color: Qt.color("#80000000")
                source: pic6
            }
        }

        Item {
            Row {
                anchors.centerIn: parent
                spacing: 16

                Rectangle {
                    id: normalRect
                    width: 60
                    height: 60
                    radius: 10
                    color: Qt.color("steelblue")
                    layer.enabled: true
                    layer.effect: DropShadow {
                        transparentBorder: false
                        horizontalOffset: 8
                        verticalOffset: 8
                    }
                }

                Rectangle {
                    id: transparentBorderRect
                    width: 60
                    height: 60
                    radius: 10
                    color: Qt.color("steelblue")
                    layer.enabled: true
                    layer.effect: DropShadow {
                        transparentBorder: true
                        horizontalOffset: 8
                        verticalOffset: 8
                    }
                }
            }
        }

        Item {
            Image {
                id: pic7
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            FastBlur {
                anchors.fill: pic7
                source: pic7
                radius: 32
            }
        }

        Item {
            Image {
                id: pic8
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            GammaAdjust {
                anchors.fill: pic8
                source: pic8
                gamma: 0.45
            }
        }

        Item {
            Rectangle {
                anchors.fill: parent
                color: Qt.color("black")
            }

            Image {
                id: pic9
                source: "qrc:///images/butterfly.png"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            Glow {
                anchors.fill: pic9
                radius: 8
                color: Qt.color("white")
                source: pic9
            }
        }

        Item {
            Row {
                anchors.centerIn: parent
                spacing: 16

                Rectangle {
                    id: normalRect2
                    width: 60
                    height: 60
                    color: Qt.color("black")
                    radius: 10
                    layer.enabled: true
                    layer.effect: Glow {
                        //samples: 15
                        color: Qt.color("blue")
                        transparentBorder: false
                    }
                }

                Rectangle {
                    id: transparentBorderRect2
                    width: 60
                    height: 60
                    color: Qt.color("black")
                    radius: 10
                    layer.enabled: true
                    layer.effect: Glow {
                        //samples: 15
                        color: Qt.color("blue")
                        transparentBorder: true
                    }
                }
            }
        }

        Item {
            Image {
                id: pic10
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            HueSaturation {
                anchors.fill: pic10
                source: pic10
                hue: -0.3
                saturation: 0.5
                lightness: -0.1
            }
        }

        Item {
            Image {
                id: pic11
                source: "qrc:///images/butterfly.png"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            LevelAdjust {
                anchors.fill: pic11
                source: pic11
                minimumOutput: Qt.color("#00ffffff")
                maximumOutput: Qt.color("#ff000000")
            }
        }

        Item {
            LinearGradient {
                anchors.fill: parent
                start: Qt.point(0, 0)
                end: Qt.point(0, 300)
                gradient: Gradient {
                    GradientStop { position: 0.0; color: Qt.color("white") }
                    GradientStop { position: 1.0; color: Qt.color("black") }
                }
            }
        }

        Item {
            Image {
                id: pic12
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            Image {
                id: mask
                source: "qrc:///images/butterfly.png"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            OpacityMask {
                anchors.fill: pic12
                source: pic12
                maskSource: mask
            }
        }

        Item {
            RadialGradient {
                anchors.fill: parent
                gradient: Gradient {
                    GradientStop { position: 0.0; color: Qt.color("white") }
                    GradientStop { position: 0.5; color: Qt.color("black") }
                }
            }
        }

        Item {
            Rectangle {
                id: background
                anchors.fill: parent
                color: Qt.color("black")
            }

            RectangularGlow {
                id: effect
                anchors.fill: rect22
                glowRadius: 10
                spread: 0.2
                color: Qt.color("white")
                cornerRadius: rect22.radius + glowRadius
            }

            Rectangle {
                id: rect22
                color: Qt.color("black")
                anchors.centerIn: parent
                width: Math.round(parent.width / 1.5)
                height: Math.round(parent.height / 2)
                radius: 25
            }
        }

        Item {
            Image {
                id: background2
                anchors.fill: parent
                source: "qrc:///images/checker.png"
                smooth: true
                fillMode: Image.Tile
            }

            Image {
                id: pic13
                source: "qrc:///images/bug.jpg"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            Image {
                id: mask2
                source: "qrc:///images/fog.png"
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
            }

            ThresholdMask {
                anchors.fill: pic13
                source: pic13
                maskSource: mask2
                threshold: 0.4
                spread: 0.2
            }
        }
    }

    PageIndicator {
        id: indicator
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: view.bottom
        }
        count: view.count
        currentIndex: view.currentIndex
    }
}
