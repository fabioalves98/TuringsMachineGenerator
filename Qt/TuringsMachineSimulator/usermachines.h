#ifndef USERMACHINES_H
#define USERMACHINES_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QLayout>
#include <QThread>
#include <QListWidget>
#include <QScrollBar>
#include <QCloseEvent>
#include "machine.h"
#include "randommachines.h"
#include "editmachines.h"

namespace Ui {
class UserMachines;
}

class UserMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMachines(QWidget *parent = 0);
    void start();
    void close();
    ~UserMachines();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_addTableBt_clicked();
    void on_simBt_clicked();
    void getMachToDispay(QListWidgetItem* item);
    void resizeTable();
    void on_stopBt_clicked();
    void on_pauseBt_clicked();
    void on_contBt_clicked();
    void on_randTableBt_clicked();
    void on_editTableBt_clicked();

private:
    void displayMach(Machine* toDisplay);
    void enSimButtons(QString state);
    QStringList states;
    Ui::UserMachines *ui;
    Machine *current;
    QVector<Machine*> listMach;
    bool haltSim;
    bool pauseSim;
    bool tableIsLoaded;
};

#endif // USERMACHINES_H
