/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Graphical Effects module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "graphicaleffects.h"
#include "qgfxsourceproxyv2.h"

#define GRAPHICALEFFECTS_REGISTER_QML_TYPE(name) \
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/" #name ".qml")), __graphicaleffects_uri, 1, 0, #name)

static const char __graphicaleffects_uri[] = "org.wangwenx190.Qt5Compat.GraphicalEffects";

static inline void initGraphicalEffectsResources()
{
    Q_INIT_RESOURCE(graphicaleffects);
}

void GRAPHICALEFFECTS_PREPEND_NAMESPACE(registerModule)()
{
    initGraphicalEffectsResources();

    qmlRegisterType<QGfxSourceProxyV2>(__graphicaleffects_uri, 1, 0, "SourceProxy");

    GRAPHICALEFFECTS_REGISTER_QML_TYPE(BrightnessContrast);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(Colorize);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(ColorOverlay);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(ConicalGradient);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(Desaturate);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(Displace);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(DropShadow);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(FastBlur);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(FastGlow);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(GammaAdjust);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(Glow);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(HueSaturation);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(LevelAdjust);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(LinearGradient);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(OpacityMask);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(RadialGradient);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(RectangularGlow);
    GRAPHICALEFFECTS_REGISTER_QML_TYPE(ThresholdMask);

#if 0
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/BrightnessContrast.qml")), __graphicaleffects_uri, 1, 0, "BrightnessContrast");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/Colorize.qml")), __graphicaleffects_uri, 1, 0, "Colorize");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/ColorOverlay.qml")), __graphicaleffects_uri, 1, 0, "ColorOverlay");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/ConicalGradient.qml")), __graphicaleffects_uri, 1, 0, "ConicalGradient");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/Desaturate.qml")), __graphicaleffects_uri, 1, 0, "Desaturate");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/Displace.qml")), __graphicaleffects_uri, 1, 0, "Displace");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/DropShadow.qml")), __graphicaleffects_uri, 1, 0, "DropShadow");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/FastBlur.qml")), __graphicaleffects_uri, 1, 0, "FastBlur");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/FastGlow.qml")), __graphicaleffects_uri, 1, 0, "FastGlow");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/GammaAdjust.qml")), __graphicaleffects_uri, 1, 0, "GammaAdjust");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/Glow.qml")), __graphicaleffects_uri, 1, 0, "Glow");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/HueSaturation.qml")), __graphicaleffects_uri, 1, 0, "HueSaturation");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/LevelAdjust.qml")), __graphicaleffects_uri, 1, 0, "LevelAdjust");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/LinearGradient.qml")), __graphicaleffects_uri, 1, 0, "LinearGradient");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/OpacityMask.qml")), __graphicaleffects_uri, 1, 0, "OpacityMask");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/RadialGradient.qml")), __graphicaleffects_uri, 1, 0, "RadialGradient");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/RectangularGlow.qml")), __graphicaleffects_uri, 1, 0, "RectangularGlow");
    qmlRegisterType(QUrl(QStringLiteral("qrc:///wangwenx190/Qt5Compat/GraphicalEffects/ThresholdMask.qml")), __graphicaleffects_uri, 1, 0, "ThresholdMask");
#endif
}
