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
#include <QMenu>
#include "machine.h"
#include "tape.h"
#include "settings.h"
#include "machinesimulation.h"
#include "randommachines.h"
#include "randomtapes.h"
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
    void closeEvent(QCloseEvent *event) override;

private slots:
    void loadPresetSlt(Machine* preset);
    void on_addTableBt_clicked();
    void on_simBt_clicked();
    void on_uselAllBt_clicked();
    void on_selAllBt_clicked();
    void finishSim(QString tableName);
    void getMachToDispay();
    void on_stopBt_clicked();
    void on_pauseBt_clicked();
    void on_contBt_clicked();
    void on_cRandTableBt_clicked();
    void on_editTableBt_clicked();
    void on_qRandTableBt_clicked();
    void selTapeButtons(int item);
    void on_loadTapeBt_clicked();
    void on_saveTableBt_clicked();
    void on_settingsBt_clicked();
    void on_slowerBt_clicked();
    void on_fasterBt_clicked();
    void delayUpdatedSlt(int delay);
    void on_buttonSelect_currentIndexChanged(int index);
    void showContextMenu(const QPoint &pos);
    void deleteItem();

private:
    bool addMachine(Machine* toAdd);
    bool addTape(Tape* toAdd);
    bool machOrTape();
    void enSimButtons(QString state);
    QStringList states;
    QString selected;
    QVector<Machine*> listMach;
    QVector<Tape*> listTape;

    Ui::UserMachines *ui;
    Settings *set;
};

#endif // USERMACHINES_H
