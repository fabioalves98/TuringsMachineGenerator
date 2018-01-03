#ifndef MACHINESIMULATION_H
#define MACHINESIMULATION_H

#include <QMainWindow>
#include <QThread>
#include <QScrollBar>
#include "machine.h"

namespace Ui {
class MachineSimulation;
}

class MachineSimulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MachineSimulation(Machine *mach, QWidget *parent = 0);
    void start();
    void display();
    void simulate();
    ~MachineSimulation();

private slots:
    void resizeTable();

private:
    Ui::MachineSimulation *ui;
    Machine *mach;
    bool haltSim;
    bool pauseSim;
    bool tableIsLoaded;
};

#endif // MACHINESIMULATION_H
