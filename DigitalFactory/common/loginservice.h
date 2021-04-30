#ifndef LOGINSERVICE_H
#define LOGINSERVICE_H
#include <QObject>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include "QString"
#include "user.h"
class LoginService: public QObject
{
    Q_OBJECT
public:
    LoginService();
    bool login(QString userName,QString password);
private:
    QNetworkAccessManager oNetAccessManager;

};

#endif // LOGINSERVICE_H
