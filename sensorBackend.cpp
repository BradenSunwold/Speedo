#include "sensorBackend.h"

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
}

QString BackEnd::userName()
{
    return m_userName;
}

void BackEnd::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}

void BackEnd::setWspd(int wspd) {
    if (wspd == m_wspd)
        return;
    m_wspd = wspd;
    emit wspdChanged();
}

int BackEnd::getWspd() {
    return m_wspd;
}

void BackEnd::setTrip(int trip) {
    if (trip == m_trip)
        return;
    m_trip = trip;
    emit tripChanged();     // emit signal for qml
}

int BackEnd::getTrip() {
    return m_trip;
}

void BackEnd::setOdom(int odom) {
    if (odom == m_odom)
        return;
    m_odom = odom;
    emit odomChanged();
}

int BackEnd::getOdom() {
    return m_odom;
}
