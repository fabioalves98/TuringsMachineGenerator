#ifndef USERMACHINES_H
#define USERMACHINES_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QLayout>
#include "machine.h"

namespace Ui {
class UserMachines;
}

class UserMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMachines(QWidget *parent = 0);
    ~UserMachines();

private slots:
    void on_addTableBt_clicked();
    void on_simBt_clicked();

private:
    Ui::UserMachines *ui;
    Machine *test;
};

#endif // USERMACHINES_H
