#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserMachines w;
    w.show();
    w.start();
    return a.exec();
}
