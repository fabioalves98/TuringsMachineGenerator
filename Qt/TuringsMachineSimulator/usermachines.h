#ifndef USERMACHINES_H
#define USERMACHINES_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QLayout>
#include <QThread>
#include <QListWidget>
#include "machine.h"
#include "machineinfo.h"

namespace Ui {
class UserMachines;
}

class UserMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMachines(QWidget *parent = 0);
    void start();
    ~UserMachines();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_addTableBt_clicked();
    void on_simBt_clicked();
    void getMachToDispay(QListWidgetItem* item);

private:
    void displayMach(MachineInfo* toDisplay);
    Ui::UserMachines *ui;
    Machine *current;
    QVector<MachineInfo*> listMach;
    bool haltSim;
};

#endif // USERMACHINES_H
