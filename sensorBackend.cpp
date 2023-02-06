#include "sensorBackend.h"

#include <QCoreApplication>

BackEnd::BackEnd(QObject *parent, QString portName, int baud) :
    QObject(parent),
    m_portName(portName),
    m_baud(baud)
{
    m_serial.setPortName(m_portName);
    m_serial.setBaudRate(m_baud);
    if(!m_serial.open(QIODevice::ReadWrite)) {
        qDebug("Could not open IO device");
    }
    connect(&m_serial, &QSerialPort::readyRead, this, &BackEnd::handleReadyRead);
}

void BackEnd::setWspd(float wspd) {
    if (wspd == m_wspd)
        return;
    m_wspd = wspd;
    emit wspdChanged();
}

float BackEnd::getWspd() {
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

void BackEnd::handleReadyRead() {
    QByteArray m_readData = m_serial.readAll();
    char *ptrWspd = (char*) &m_wspd;         // pointer to first byte of wspd float
    char *ptrTrip = (char *) &m_trip;        // pointer to first byte of trip int
    char *ptrOdom = (char *) &m_odom;        // pointer to first byte of odom int
    for(int i = 0; i < sizeof(m_wspd); i++) {
        *ptrWspd = m_readData[i];            // Loop over four bytes from readData that make up wspd float
        ptrWspd++;
        qDebug() << "WSPD BYTE: " << m_readData[i] << "\n";

        *ptrTrip = m_readData[i + 4];   // Second four bytes of data should be trip int
        ptrTrip++;
        qDebug() << "TRIP BYTE: " << m_readData[i+4] << "\n";

        *ptrOdom = m_readData[i+8];     // Last four bytes of data should be odometer int
        ptrOdom++;
        qDebug() << "ODOM BYTE: " << m_readData[i+8] << "\n";
    }
    qDebug() << "Wsp: " << m_wspd;
    qDebug() << "Trip: " << m_trip;
    qDebug() << "Odom: " << m_odom;

    // data members changed
    emit wspdChanged();
    emit tripChanged();
    emit odomChanged();
}
