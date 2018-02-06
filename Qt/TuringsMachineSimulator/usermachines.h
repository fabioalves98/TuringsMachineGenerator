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
    ~UserMachines();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // Main functions
    void on_addBt_clicked();
    void on_editBt_clicked();
    void on_saveBt_clicked();
    void on_qRandBt_clicked();
    void on_cRandBt_clicked();
    void on_settingsBt_clicked();
    void loadPresetSlt(Machine* preset);
    void on_buttonSelect_currentIndexChanged(int index);
    void getMachToDispay();
    void selTapeButtons(QString name);
    // Machine List Functions
    void on_selAllBt_clicked();
    void on_uSelAllBt_clicked();
    // Tape List Functions
    void on_loadTapeBt_clicked();
    // Simulation Functions
    void on_simBt_clicked();
    void on_pauseBt_clicked();
    void on_contBt_clicked();
    void on_stopBt_clicked();
    void on_slowerBt_clicked();
    void on_fasterBt_clicked();
    void delayUpdatedSlt(int delay);
    void finishSim(QString tableName);
    // Machine and Tape Deletion
    void showMachineContextMenu(const QPoint &pos);
    void showTapeContextMenu(const QPoint &pos);

private:
    bool addMachine(Machine* toAdd);
    bool addTape(Tape* toAdd);
    bool machOrTape();
    void enSimButtons(QString state);
    Ui::UserMachines *ui;
    Settings *set;
    QStringList states;
    QString selected;
    QVector<Machine*> listMach;
    QVector<Tape*> listTape;
};

#endif // USERMACHINES_H
