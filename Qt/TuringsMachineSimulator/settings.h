#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QDebug>
#include <QSignalMapper>
#include "machine.h"

namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    static Settings* getInstance();
    // Random Machine Settings
    QString getRandTableName();
    int getRandTableSuffix();
    int getTableMinSt();
    int getTableMaxSt();
    int getTableMinSy();
    int getTableMaxSy();
    QVector<QChar> *getTableStates();
    QVector<QChar> *getTableSymbols();
    bool getRandInState();
    QChar getInState();
    QChar getHaltState();
    // Random Tape Settings
    QString getRandTapeName();
    int getRandTapeSuffix();
    int getTapeMaxSize();
    int getTapeMinSize();
    QVector<QChar> *getTapeSymbols();
    bool getRandBSym();
    QChar getBlanckSymbol();
    // Simulation Settings
    int getConcurrentSim();
    int getDelayTime();
    bool getHaltInXIt();
    int getIterTilHalt();
    int getSimHistory();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    loadPresetSgn(Machine*);
    delayChangedSgn(int);
    concurrentSimSgn();

private slots:
    void on_maxStSpinBox_valueChanged(int arg1);
    void on_minStSpinBox_valueChanged(int arg1);
    void on_rInStCheck_stateChanged(int arg1);
    void on_maxSySpinBox_valueChanged(int arg1);
    void on_minSySpinBox_valueChanged(int arg1);
    void on_haltSimCheck_stateChanged(int arg1);
    void on_tapeSySBox_valueChanged(int arg1);
    void on_rBSyCheck_stateChanged(int arg1);
    void on_loadPresetBt_clicked();
    void on_presetsCBox_currentIndexChanged(int index);
    void on_defaultSetBt_clicked();

private:
    void setDefaults();
    void loadPresets();
    void createPreset(QString name, QVector<QChar> states, QVector<QChar> symbols, QStringList cells, QChar inSt, QChar haltState);
    void fillStatesNSymbols();
    void clearStLayout();
    void clearSyLayout();
    void clearTapeSyLayout();
    static Settings* instance;
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    Ui::Settings *ui;
    // Presets
    QVector<Machine*> presets;
    // Quick Random Table Settings
    QString randTableName;
    int randTableSuffix;
    int tableMinSt, tableMaxSt;
    int tableMinSy, tableMaxSy;
    QVector<QChar> tableStates;
    QVector<QChar> tableSymbols;
    bool randInState;
    QChar inState;
    QChar haltState;
    // Quick Random Tape Settings
    QString randTapeName;
    int randTapeSuffix;
    int numTapeSymbols;
    QVector<QChar> tapeSymbols;
    int tapeMaxSize, tapeMinSize;
    bool randBSym;
    QChar blanckSym;
    // Simulation Settings
    int concurrentSim;
    int delayTime;
    bool haltInXIt;
    int iterTilHalt;
    int simHistory;
    // Settings Settings
    QString abc;
    int prevState = 0;
    int prevSymbol = 0;
};

#endif // SETTINGS_H
