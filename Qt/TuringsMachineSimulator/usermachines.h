#ifndef USERMACHINES_H
#define USERMACHINES_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QLayout>
#include <QThread>
#include "machine.h"

namespace Ui {
class UserMachines;
}

class UserMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMachines(QWidget *parent = 0);
    void start();
    ~UserMachines();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_addTableBt_clicked();
    void on_simBt_clicked();

private:
    Ui::UserMachines *ui;
    Machine *test;
};

#endif // USERMACHINES_H
