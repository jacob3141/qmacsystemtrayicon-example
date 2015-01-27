#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _showCounter = 0;
    _systemTrayIcon.setDarkThemePixmap(QPixmap(":/images/images/icon_dark.png"));
    _systemTrayIcon.setLightThemePixmap(QPixmap(":/images/images/icon_light.png"));
    _systemTrayIcon.setText("0");
    connect(&_systemTrayIcon, SIGNAL(trayIconToggled(QRect)), this, SLOT(trayIconToggled(QRect)));

    ui->webView->load(QUrl("http://www.google.de"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::trayIconToggled(QRect geometry) {
    _systemTrayIcon.setText(QString("%1").arg(_showCounter));

    if(isVisible()) {
        _showCounter++;
        hide();
    } else {
        move(geometry.x() - width() / 2 + geometry.width() / 2, geometry.y());
        show();
    }
}

