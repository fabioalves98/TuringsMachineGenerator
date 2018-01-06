#ifndef MACHINESIMULATION_H
#define MACHINESIMULATION_H

#include <QMainWindow>
#include <QThread>
#include <QScrollBar>
#include <QtConcurrent>
#include "machine.h"

namespace Ui {
class MachineSimulation;
}

class MachineSimulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MachineSimulation(Machine *mach, QWidget *parent = 0);
    void setMachine(Machine * mach);
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
    QString state;
    bool haltSim;
    bool pauseSim;
    bool halts;
    bool tableIsLoaded = false;
};

#endif // MACHINESIMULATION_H
