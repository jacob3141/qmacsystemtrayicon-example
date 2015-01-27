#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _showCounter = 0;
    _systemTrayIcon.setDarkThemePixmap(QPixmap(":/images/images/icon_dark.png"));
    _systemTrayIcon.setLightThemePixmap(QPixmap(":/images/images/icon_light.png"));

    connect(&_systemTrayIcon, SIGNAL(trayIconToggled(QRect)), this, SLOT(trayIconToggled(QRect)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::trayIconToggled(QRect geometry) {
    _systemTrayIcon.setText(QString("%1").arg(_showCounter));

    if(isVisible()) {
        hide();
    } else {
        move(geometry.x() - width() / 2, geometry.y());
        _showCounter++;
        show();
    }
}

