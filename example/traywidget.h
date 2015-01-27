#ifndef TRAYWIDGET_H
#define TRAYWIDGET_H

#include <QWidget>

#include "qmacsystemtrayiconimpl.h"

namespace Ui {
class TrayWidget;
}

class TrayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrayWidget(QWidget *parent = 0);
    ~TrayWidget();

private slots:
    void trayIconToggled(QRect geometry);

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::TrayWidget *ui;

    QMacSystemTrayIconImpl _systemTrayIcon;
    int _showCounter;
};

#endif // TRAYWIDGET_H
