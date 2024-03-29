#ifndef RANDOMMACHINES_H
#define RANDOMMACHINES_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include <QThread>
#include <QtGlobal>
#include <QLineEdit>
#include <QSignalMapper>
#include <QScrollBar>
#include "math.h"
#include "machine.h"
#include "settings.h"

namespace Ui {
class RandomMachines;
}

class RandomMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit RandomMachines(QWidget *parent = 0);
    void quick();
    bool isReady();
    Machine *getRandMach();
    ~RandomMachines();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_stSel_valueChanged(int arg1);
    void on_sySel_valueChanged(int arg1);
    void changeHorHeader(int st);
    void changeVerHeader(int sy);
    void headersChanged();
    void on_randBut_clicked();
    void on_saveBut_clicked();
    void on_nameEdit_textChanged();
    void on_haltStEdit_textChanged(const QString &arg1);

private:
    void clearStLayout();
    void clearSyLayout();
    void changeButState();
    void resizeTable();
    // Class variables
    Ui::RandomMachines *ui;
    Settings *set;
    QString abc;
    // Random Machine variables
    QVector<QChar> *states;
    QVector<QChar> *symbols;
    Machine *randMach;
    bool resizable = false;
    bool generated = false;
    bool ready = false;
    int prevState = 0;
    int prevSymbol = 0;
};

#endif // RANDOMMACHINES_H
