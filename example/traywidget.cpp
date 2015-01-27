#include "traywidget.h"
#include "ui_traywidget.h"

#include <QPainter>

TrayWidget::TrayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrayWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    _showCounter = 0;
    _systemTrayIcon.setDarkThemePixmap(QPixmap(":/images/images/icon_dark.png"));
    _systemTrayIcon.setLightThemePixmap(QPixmap(":/images/images/icon_light.png"));
    _systemTrayIcon.setText("0");
    connect(&_systemTrayIcon, SIGNAL(trayIconToggled(QRect)), this, SLOT(trayIconToggled(QRect)));

    ui->webView->load(QUrl("http://www.9elements.com"));
}

TrayWidget::~TrayWidget()
{
    delete ui;
}

void TrayWidget::trayIconToggled(QRect geometry) {
    _systemTrayIcon.setText(QString("%1").arg(_showCounter));

    if(isVisible()) {
        _showCounter++;
        hide();
    } else {
        move(geometry.x() - width() / 2 + geometry.width() / 2, geometry.y());
        show();
    }
}

void TrayWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setCompositionMode(QPainter::CompositionMode_Clear);
    p.fillRect(this->rect(), Qt::transparent);
}
