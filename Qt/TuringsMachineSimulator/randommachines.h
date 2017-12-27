#ifndef RANDOMMACHINES_H
#define RANDOMMACHINES_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include <QtGlobal>

namespace Ui {
class RandomMachines;
}

class RandomMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit RandomMachines(QWidget *parent = 0);
    ~RandomMachines();

private slots:
    void on_stSel_valueChanged(int arg1);
    void on_sySel_valueChanged(int arg1);
    void on_randBut_clicked();

private:
    Ui::RandomMachines *ui;
    QString abc;
    QVector<QChar> *states;
    QVector<QChar> *symbols;
};

#endif // RANDOMMACHINES_H
