
#include <QApplication>
#include "traywidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    TrayWidget t;
    return a.exec();
}
