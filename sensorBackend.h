#ifndef SENSORBACKEND_H
#define SENSORBACKEND_H

#include <QObject>
#include <QString>

class BackEnd : public QObject
{
    // Call qt Macros to link qml properties to Cpp class
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(int wspd READ getWspd WRITE setWspd NOTIFY wspdChanged)
    Q_PROPERTY(int trip READ getTrip WRITE setTrip NOTIFY tripChanged)
    Q_PROPERTY(int odom READ getOdom WRITE setOdom NOTIFY odomChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

    void setWspd(int wspd);     // API to set wheel speed
    int getWspd();

    void setTrip(int trip);     // API to set trip milleage
    int getTrip();

    void setOdom(int odom);     // API to set odometer value
    int getOdom();

signals:
    void userNameChanged();     // Functions to let qml know signal changed
    void wspdChanged();
    void tripChanged();
    void odomChanged();

private:
    QString m_userName = "HELLO";
    int m_wspd = 0;
    int m_trip = 0;
    int m_odom = 0;
};

#endif // SENSORBACKEND_H
