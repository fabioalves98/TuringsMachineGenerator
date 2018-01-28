#ifndef MACHINESIMULATION_H
#define MACHINESIMULATION_H

#include <QMainWindow>
#include <QThread>
#include <QScrollBar>
#include <QtConcurrent>
#include <QFileDialog>
#include "machine.h"
#include "tape.h"
#include "settings.h"

namespace Ui {
class MachineSimulation;
}

class MachineSimulation : public QMainWindow
{
    Q_OBJECT

public:
    MachineSimulation(Machine *mach, Tape *tape, QWidget *parent = 0);
    void setMachine(Machine* mach);
    void setTape(Tape* tape);
    void start();
    void display();
    void simulate();
    void pause();
    void cont();
    void stop();
    bool halted();
    void decreaseSpeed();
    void increaseSpeed();
    QString getState();
    ~MachineSimulation();

public slots:
    void resizeTable();

protected:
    void resizeEvent(QResizeEvent *event) override;

signals:
    void selectTableCellSgn(int, int);
    void insertStateSgn(QString);
    void insertTapeSgn(QString);

private slots:
    void selectTableCellSlt(int st, int sy);
    void insertStateSlt(QString state);
    void insertTapeSlt(QString tape);
    void on_headPos_valueChanged(int arg1);

private:
    void displayTape();
    Machine *mach;
    Tape *inTape;
    QString state;
    bool haltSim;
    bool pauseSim;
    bool halts;
    int localDelayFormat;
    bool tableIsLoaded = false;

    Ui::MachineSimulation *ui;
    Settings *set;
};

#endif // MACHINESIMULATION_H
