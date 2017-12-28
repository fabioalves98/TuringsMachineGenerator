#ifndef EDITMACHINES_H
#define EDITMACHINES_H

#include <QMainWindow>
#include "machineinfo.h"

namespace Ui {
class EditMachines;
}

class EditMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditMachines(MachineInfo *toEdit, QWidget *parent = 0);
    void loadTable();
    ~EditMachines();

private slots:
    void on_tableView_cellClicked(int row, int column);
    void on_changeBut_clicked();

private:
    void fillComBoxes();
    Ui::EditMachines *ui;
    MachineInfo *mach;
};

#endif // EDITMACHINES_H
