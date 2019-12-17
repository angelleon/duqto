#ifndef CORE_HPP
#define CORE_HPP

#include <QApplication>
#include <QHostInfo>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QNetworkInterface>

#include "mainwindow.hpp"

namespace duqto {
class Duqto:public QApplication
{
Q_OBJECT
public:
    Duqto(int, char**);

private:
    MainWindow *w;
signals:
    void sgnBoot(QString username, QString hostname, QString profile_pic, QList<QString>);
};
}

#endif // CORE_HPP
