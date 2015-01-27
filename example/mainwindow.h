#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qmacsystemtrayiconimpl.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void trayIconToggled(QRect geometry);

private:
    Ui::MainWindow *ui;
    QMacSystemTrayIconImpl _systemTrayIcon;
    int _showCounter;
};

#endif // MAINWINDOW_H
