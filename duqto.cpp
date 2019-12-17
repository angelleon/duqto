#include "duqto.hpp"

using namespace duqto;

Duqto::Duqto(int argc, char **argv):QApplication(argc, argv)
{
    setApplicationName("Duqto");
    this->w = new MainWindow();
    QString username = qEnvironmentVariable("USER", "user");
    qDebug() << "Found username: " << username;
    QString hostname = QHostInfo::localHostName();
    qDebug() << "Found hostname: " << hostname;
    QDir homeDir = QDir(
     QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0]);
    qDebug() << "Found home: " << homeDir;
    QString profilePic;
    if (homeDir.exists(".face")) {
        profilePic = homeDir.filePath(".face");
    } else {
        profilePic = "qrc://pic/flbk_profile_pic.png";
    }
    qDebug() << "Found profile picture: " << profilePic;
    connect(this, &Duqto::sgnBoot,
            this->w, &MainWindow::sltBoot);
    QList<QNetworkInterface> netIfaces = QNetworkInterface::allInterfaces();
    QList<QString> strNetIfaces = QList<QString>();
    // TODO: add loopback exclusion
    for (int i=0; i < netIfaces.length(); i++) {
        strNetIfaces.append(netIfaces[i].humanReadableName());
        qDebug() << "Found network interface: " << strNetIfaces[i];
    }
    emit sgnBoot(username, hostname, profilePic, strNetIfaces);
    this->w->show();
}
