#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    static Settings* getInstance();
    int getDelayTime();
    void setDelayTime(int value);
    QString getNamePrefix();
    int getRandSuffix();
    int getMinSt();
    int getMaxSt();
    int getMinSy();
    int getMaxSy();
    QVector<QChar> *getStates();
    QVector<QChar> *getSymbols();
    bool getRandInState();
    QChar getInState();
    QChar getHaltState();
    bool getDecDelay();
    bool getHaltInXIt();
    int getIterTilHalt();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_maxStSpinBox_valueChanged(int arg1);
    void on_minStSpinBox_valueChanged(int arg1);
    void on_rInStCheck_stateChanged(int arg1);
    void on_maxSySpinBox_valueChanged(int arg1);
    void on_minSySpinBox_valueChanged(int arg1);
    void on_haltSimCheck_stateChanged(int arg1);

private:
    void setDefaults();
    void fillStatesNSymbols();
    void clearStLayout();
    void clearSyLayout();
    static Settings* instance;
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    Ui::Settings *ui;

    QString namePrefix;
    int randSuffix;
    int minSt, maxSt;
    int minSy, maxSy;
    QVector<QChar> states;
    QVector<QChar> symbols;
    bool randInState;
    QChar inState;
    QChar haltState;
    int delayTime;
    bool decDelay;
    bool haltInXIt;
    int iterTilHalt;

    QString abc;
    int prevState = 0;
    int prevSymbol = 0;
};

#endif // SETTINGS_H
