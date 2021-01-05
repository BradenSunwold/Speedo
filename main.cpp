#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "sensorBackend.h"
//#include <fstream>
//#include <iostream>
//#include <Qstring>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <QDebug>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    BackEnd backend;        // create instance of sensor backend
    engine.rootContext()->setContextProperty("backend", &backend); // connect sensor backend to qml

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    // Set up remote processor communication
    int fd;
    char buf[50];
    char* s = "/sys/kernel/debug/remoteProc/remoteProc0/trace0";
    snprintf(buf, 47, "%s\n", s);
    fd = open(buf, O_RDONLY);
    if(fd < 0) {
        qDebug("Failed to open sys file");
    }

    char* buf1;
    read(fd, buf1, 2);
    qDebug("Read attempted");
    qDebug(buf1);
    //backend.setUserName(buf1);
    close(fd);

    //backend.setUserName(val);

//    backend.setWspd(90);
//    for(int i; i < 100000; i++);
//    backend.setWspd(0);
//    for(int i; i < 100000; i++);
//    backend.setWspd(200);

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
