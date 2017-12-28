#ifndef RANDOMMACHINES_H
#define RANDOMMACHINES_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include <QtGlobal>
#include "machineinfo.h"

namespace Ui {
class RandomMachines;
}

class RandomMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit RandomMachines(QWidget *parent = 0);
    bool isReady();
    MachineInfo *getRandMach();
    ~RandomMachines();

private slots:
    void on_stSel_valueChanged(int arg1);
    void on_sySel_valueChanged(int arg1);
    void on_randBut_clicked();
    void on_saveBut_clicked();

private:
    Ui::RandomMachines *ui;
    QString abc;
    QVector<QChar> *states;
    QVector<QChar> *symbols;
    MachineInfo *randMach;
    bool ready = false;
};

#endif // RANDOMMACHINES_H
