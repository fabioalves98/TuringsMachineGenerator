#include "usermachines.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserMachines *w = new UserMachines;
    w->show();
    w->start();
    return a.exec();
}
