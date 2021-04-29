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

#include <graphicaleffects.h>
#include <QtCore/qloggingcategory.h>
#include <QtGui/qguiapplication.h>
#include <QtQml/qqmlapplicationengine.h>
#include <QtQuickControls2/qquickstyle.h>
#include <QtQuick/qquickwindow.h>

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);

    QLoggingCategory::setFilterRules(QStringLiteral("qt.scenegraph.general=true\nqt.rhi.*=true"));

    QQmlApplicationEngine engine;

    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
    QQuickStyle::setStyle(QStringLiteral("Basic"));

    GRAPHICALEFFECTS_PREPEND_NAMESPACE(registerModule)();

    const QUrl homePageUrl(QStringLiteral("qrc:///qml/main.qml"));

    const QMetaObject::Connection connection = QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &application,
        [&homePageUrl, &connection](QObject *object, const QUrl &url){
            if (url != homePageUrl) {
                return;
            }
            if (object) {
                QObject::disconnect(connection);
            } else {
                QGuiApplication::exit(-1);
            }
        },
        Qt::QueuedConnection);

    engine.load(homePageUrl);

    return QGuiApplication::exec();
}
