#ifndef RANDOMTAPES_H
#define RANDOMTAPES_H

#include <QMainWindow>
#include <QTime>
#include <QDebug>
#include <QtMath>
#include "tape.h"
#include "settings.h"

namespace Ui {
class RandomTapes;
}

class RandomTapes : public QMainWindow
{
    Q_OBJECT

public:
    explicit RandomTapes(QWidget *parent = 0);
    void quick();
    bool isReady();
    Tape *getTape();
    ~RandomTapes();

private slots:
    void on_symSBox_valueChanged(int arg1);
    void on_sizeSBox_valueChanged(int arg1);
    void on_randBt_clicked();
    void on_saveBt_clicked();

private:
    void clearSymLayout();
    void changeButState();
    // Class variables
    Ui::RandomTapes *ui;
    Settings *set;
    // Tape variables
    Tape *rand;
    bool generated = false;
    bool ready = false;
};

#endif // RANDOMTAPES_H
