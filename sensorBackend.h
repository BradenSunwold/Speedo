#ifndef SENSORBACKEND_H
#define SENSORBACKEND_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class BackEnd : public QObject
{
    // Call qt Macros to link qml properties to Cpp class
    Q_OBJECT
    Q_PROPERTY(int wspd READ getWspd WRITE setWspd NOTIFY wspdChanged)
    Q_PROPERTY(int trip READ getTrip WRITE setTrip NOTIFY tripChanged)
    Q_PROPERTY(int odom READ getOdom WRITE setOdom NOTIFY odomChanged)

public:
    explicit BackEnd(QObject *parent = nullptr, QString portName = "/dev/ttyRPMSG0", int baud = 1);

    void setWspd(float wspd);     // API to set wheel speed
    float getWspd();

    void setTrip(int trip);     // API to set trip milleage
    int getTrip();

    void setOdom(int odom);     // API to set odometer value
    int getOdom();

signals:
   // Functions to let qml know signal changed
    void wspdChanged();
    void tripChanged();
    void odomChanged();

private slots:
    void handleReadyRead();     // slot to read serial data when data ready

private:
    float m_wspd = 0;
    int m_trip = 0;
    int m_odom = 0;

    // Serial port data members
    QString m_portName = "/dev/ttyRPMSG0";
    int m_baud = 1;
    QSerialPort m_serial;
    //QByteArray m_readData;
};

#endif // SENSORBACKEND_H
