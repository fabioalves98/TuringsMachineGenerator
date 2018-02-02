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
    void setMachine(Machine* mach);
    void setTape(Tape* tape);
    Tape *getTape();
    void editTape();
    void saveTape();
    void start();
    void display();
    void displayTape();
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
    void updateUiSgn(int, int, int, QString, QString, QString);
    void changeStatusSgn(QString);
    void delayChangedSgn(int);

private slots:
    void updateUiSlt(int iter, int st, int sy, QString state, QString tape, QString status);
    void changeStatusSlt(QString status);
    void updateDelaySlt(int delay);
    void on_headPos_valueChanged(int arg1);

private:
    void selectTableCellSlt(int st, int sy);
    void insertStateSlt(QString state);
    void insertTapeSlt(QString tape);

    Ui::MachineSimulation *ui;
    bool machHalted(int iterations);
    Machine *mach;

    Tape *defTape;
    std::list<QChar> editedTape;
    std::list<QChar> tempTape;
    QChar blanckSym;
    int tempHeadPos;
    bool tapeEdited;

    QString state;
    bool haltSim;
    bool pauseSim;
    bool halts;
    double localDelayFormat;
    bool tableIsLoaded = false;

    bool uiIsReady;

    Settings *set;
    QSize maxTapeSize = QSize(1, 1);
};

#endif // MACHINESIMULATION_H
