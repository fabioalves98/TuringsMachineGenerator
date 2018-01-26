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
#include <QCheckBox>
#include <QRadioButton>
#include <QMovie>
#include <QPainter>
#include <QPixmap>
#include "machine.h"
#include "tape.h"
#include "randommachines.h"
#include "editmachines.h"
#include "machinesimulation.h"

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
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_addTableBt_clicked();
    void on_simBt_clicked();
    void on_uselAllBt_clicked();
    void on_selAllBt_clicked();
    void finishSim(QString tableName);
    void getMachToDispay(QListWidgetItem* item);
    void on_stopBt_clicked();
    void on_pauseBt_clicked();
    void on_contBt_clicked();
    void on_cRandTableBt_clicked();
    void on_editTableBt_clicked();
    void on_qRandTableBt_clicked();
    void on_addTapeBt_clicked();
    void selTapeButtons(int item);
    void on_loadTapeBt_clicked();

    void on_saveTableBt_clicked();

private:
    bool addMachine(Machine* toAdd);
    void addTape(QString mode);
    void enSimButtons(QString state);
    Ui::UserMachines *ui;
    QStringList states;
    QString selected;
    QVector<Machine*> listMach;
    QVector<Tape*> listTape;
};

#endif // USERMACHINES_H
