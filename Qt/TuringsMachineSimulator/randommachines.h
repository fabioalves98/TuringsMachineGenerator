#ifndef RANDOMMACHINES_H
#define RANDOMMACHINES_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include <QtGlobal>
#include <QLineEdit>
#include <QSignalMapper>
#include "machine.h"

namespace Ui {
class RandomMachines;
}

class RandomMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit RandomMachines(QWidget *parent = 0);
    bool isReady();
    Machine *getRandMach();
    ~RandomMachines();

private slots:
    void on_stSel_valueChanged(int arg1);
    void changeHorHeader(int st);
    void changeVerHeader(int sy);
    void on_sySel_valueChanged(int arg1);
    void on_randBut_clicked();
    void on_saveBut_clicked();

private:
    void clearStLayout();
    void clearSyLayout();
    Ui::RandomMachines *ui;
    QString abc;
    QVector<QChar> *states;
    QVector<QChar> *symbols;
    Machine *randMach;
    bool ready = false;
};

#endif // RANDOMMACHINES_H
