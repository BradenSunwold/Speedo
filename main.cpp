#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "sensorBackend.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    BackEnd backend;        // create instance of sensor backend
    engine.rootContext()->setContextProperty("backend", &backend); // connect sensor backend to qml

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    backend.setWspd(90);
    for(int i; i < 100000; i++);
    backend.setWspd(0);
    for(int i; i < 100000; i++);
    backend.setWspd(200);

//    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //    const QUrl url(QStringLiteral("qrc:/main.qml"));
    //    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //                     &app, [url](QObject *obj, const QUrl &objUrl) {
    //        if (!obj && url == objUrl)
    //            QCoreApplication::exit(-1);
    //    }, Qt::QueuedConnection);
    //    engine.load(url);

    return app.exec();
}
