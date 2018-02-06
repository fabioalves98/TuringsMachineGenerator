#ifndef MACHINESIMULATION_H
#define MACHINESIMULATION_H

#include <QMainWindow>
#include <QThread>
#include <QScrollBar>
#include <QtConcurrent>
#include <QFileDialog>
#include <QTimer>
#include "machine.h"
#include "tape.h"
#include "settings.h"
#include "edittapes.h"

namespace Ui {
class MachineSimulation;
}

class MachineSimulation : public QMainWindow
{
    Q_OBJECT

public:
    MachineSimulation(Machine *mach, Tape *tape, QWidget *parent = 0);
    void start();
    // Main Functions
    void setMachine(Machine* mach);
    void setTape(Tape* tape);
    Tape *getTape();
    void editTape();
    void saveTape();
    void displayMachine();
    // Simulation control
    void simulate();
    void pause();
    void cont();
    void stop();
    bool halted();
    void decreaseSpeed();
    void increaseSpeed();
    int getLocalDelay();
    QString getState();
    ~MachineSimulation();

public slots:
    void resizeTable();

protected:
    void resizeEvent(QResizeEvent *event) override;

signals:
    void updateUiSgn(int, int, QString, QString, QString);
    void changeStatusSgn(QString);
    void delayChangedSgn(int);

private slots:
    void updateUiSlt(int st, int sy, QString state, QString tape, QString status);
    void changeStatusSlt(QString status);
    void updateDelaySlt(int delay);
    void on_headPos_valueChanged(int arg1);

private:
    void displayTape();
    void selectTableCellSlt(int st, int sy);
    void insertStateSlt(QString state);
    void insertTapeSlt(QString tape);
    // Class
    Ui::MachineSimulation *ui;
    bool uiIsReady;
    Settings *set;
    // Machine
    Machine *mach;
    bool machHalted(int iterations);
    // Tape
    Tape *defTape;
    std::list<QChar> editedTape;
    std::list<QChar> tempTape;
    QChar blanckSym;
    int tempHeadPos;
    bool tapeEdited;
    // Simulation
    QString state;
    bool haltSim;
    bool pauseSim;
    bool halts;
    double localDelayFormat;
    bool tableIsLoaded = false;
};

#endif // MACHINESIMULATION_H
