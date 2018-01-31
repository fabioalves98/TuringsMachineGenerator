#ifndef RANDOMTAPES_H
#define RANDOMTAPES_H

#include <QMainWindow>
#include <QTime>
#include <QDebug>
#include "tape.h"

namespace Ui {
class RandomTapes;
}

class RandomTapes : public QMainWindow
{
    Q_OBJECT

public:
    explicit RandomTapes(QWidget *parent = 0);
    bool isReady();
    Tape *getTape();
    ~RandomTapes();

private slots:
    void on_symSBox_valueChanged(int arg1);
    void on_sizeSBox_valueChanged(int arg1);
    void on_randBt_clicked();
    void on_saveBt_clicked();

private:
    Ui::RandomTapes *ui;
    void clearSymLayout();
    void changeButState();
    Tape *rand;
    bool generated;
    bool ready;
};

#endif // RANDOMTAPES_H
