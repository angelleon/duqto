#include "mainwindow.hpp"
#include "ui_mainwindow.h"

using namespace duqto;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QCoreApplication::applicationName());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sltBoot(QString username, QString hostname, QString profilePic, QList<QString>) {

}
