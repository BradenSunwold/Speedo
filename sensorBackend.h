#ifndef SENSORBACKEND_H
#define SENSORBACKEND_H

#include <QObject>
#include <QString>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(int wspd READ getWspd WRITE setWspd NOTIFY wspdChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);
    void setWspd(int wspd);
    int getWspd();

signals:
    void userNameChanged();
    void wspdChanged();

private:
    QString m_userName;
    int m_wspd = 40;
};

#endif // SENSORBACKEND_H
