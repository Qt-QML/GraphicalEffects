/****************************************************************************
**
** Copyright (C) 2016 Jolla Ltd, author: <gunnar.sletta@jollamobile.com>
** Copyright (C) 2021 Yuhang Zhao, 2546789017@qq.com
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

#pragma once

#include "fastblur_global.h"
#include <QtQuick/qquickitem.h>

QT_BEGIN_NAMESPACE

QT_FORWARD_DECLARE_CLASS(QQuickShaderEffectSource)

class FASTBLUR_API QGfxSourceProxyV2 : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY_MOVE(QGfxSourceProxyV2)
    Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

    Q_PROPERTY(QQuickItem *input READ input WRITE setInput NOTIFY inputChanged RESET resetInput)
    Q_PROPERTY(QQuickItem *output READ output NOTIFY outputChanged)
    Q_PROPERTY(QRectF sourceRect READ sourceRect WRITE setSourceRect NOTIFY sourceRectChanged)
    Q_PROPERTY(bool active READ isActive NOTIFY activeChanged)
    Q_PROPERTY(Interpolation interpolation READ interpolation WRITE setInterpolation NOTIFY interpolationChanged)

public:
    enum class Interpolation : int
    {
        Any = 0,
        Nearest,
        Linear
    };
    Q_ENUM(Interpolation)

    explicit QGfxSourceProxyV2(QQuickItem *parent = nullptr);
    ~QGfxSourceProxyV2() override;

    QQuickItem *input() const;
    void setInput(QQuickItem *input);
    void resetInput();

    QQuickItem *output() const;

    QRectF sourceRect() const;
    void setSourceRect(const QRectF &sourceRect);

    bool isActive() const;

    void setInterpolation(Interpolation i);
    Interpolation interpolation() const;

protected:
    void updatePolish() override;

private Q_SLOTS:
    void repolish();

private:
    void setOutput(QQuickItem *output);
    void useProxy();
    static QObject *findLayer(QQuickItem *item);

Q_SIGNALS:
    void inputChanged();
    void outputChanged();
    void sourceRectChanged();
    void activeChanged();
    void interpolationChanged();

private:
    QRectF m_sourceRect = {};
    QQuickItem *m_input = nullptr;
    QQuickItem *m_output = nullptr;
    QScopedPointer<QQuickShaderEffectSource> m_proxy;
    Interpolation m_interpolation = Interpolation::Any;
};

QT_END_NAMESPACE
