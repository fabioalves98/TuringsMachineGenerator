#ifndef EDITMACHINES_H
#define EDITMACHINES_H

#include <QMainWindow>
#include <QScrollBar>
#include "machine.h"

namespace Ui {
class EditMachines;
}

class EditMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditMachines(Machine *toEdit, QWidget *parent = 0);
    void loadTable();
    bool isReady();
    Machine *getEditMach();
    ~EditMachines();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_tableView_cellClicked(int row, int column);
    void on_changeBut_clicked();
    void on_saveBut_clicked();

private:
    void fillComBoxes();
    void resizeTable();
    Ui::EditMachines *ui;
    Machine *mach;
    bool tableIsLoaded;
    bool ready;
};

#endif // EDITMACHINES_H
