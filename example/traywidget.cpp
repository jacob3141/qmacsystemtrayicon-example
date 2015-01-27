#include "traywidget.h"
#include "ui_traywidget.h"

#include <QPainter>

TrayWidget::TrayWidget(QWidget *parent) :
    QWidget(parent, Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint),
    ui(new Ui::TrayWidget)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_TranslucentBackground);

#ifdef Q_OS_MAC
    _showCounter = 0;
    _systemTrayIcon.setDarkThemePixmap(QPixmap(":/images/images/icon_dark.png"));
    _systemTrayIcon.setLightThemePixmap(QPixmap(":/images/images/icon_light.png"));
    _systemTrayIcon.setText("0");
    connect(&_systemTrayIcon, SIGNAL(trayIconToggled(QRect)), this, SLOT(trayIconToggled(QRect)));
#endif

#ifdef Q_OS_LINUX
    _systemTrayIcon.setIcon(QIcon(":/images/images/icon_dark.png"));
    connect(&_systemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));
    _systemTrayIcon.show();
#endif

    ui->webView->load(QUrl("http://www.9elements.com"));
}

TrayWidget::~TrayWidget()
{
    delete ui;
}

void TrayWidget::trayIconToggled(QRect geometry) {
#ifdef Q_OS_MAC
    _systemTrayIcon.setText(QString("%1").arg(_showCounter));

    if(isVisible()) {
        _showCounter++;
        hide();
    } else {
        move(geometry.x() - width() / 2 + geometry.width() / 2, geometry.y());
        show();
    }

#endif
}

void TrayWidget::trayIconActivated(QSystemTrayIcon::ActivationReason reason) {
#ifdef Q_OS_LINUX
    if(isVisible()) {
        hide();
    } else {
        QRect geometry = _systemTrayIcon.geometry();
        move(geometry.x() - width() / 2, geometry.y());
        show();
    }

#endif
}

void TrayWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setCompositionMode(QPainter::CompositionMode_Clear);
    p.fillRect(this->rect(), Qt::transparent);
}
