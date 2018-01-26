#ifndef MACHINESIMULATION_H
#define MACHINESIMULATION_H

#include <QMainWindow>
#include <QThread>
#include <QScrollBar>
#include <QtConcurrent>
#include <QFileDialog>
#include "machine.h"
#include "tape.h"

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

private:
    Ui::MachineSimulation *ui;
    Machine *mach;
    Tape *inTape;
    QString state;
    bool haltSim;
    bool pauseSim;
    bool halts;
    bool tableIsLoaded = false;
};

#endif // MACHINESIMULATION_H
