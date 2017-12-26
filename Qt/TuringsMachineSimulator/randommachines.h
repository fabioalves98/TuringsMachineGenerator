#ifndef RANDOMMACHINES_H
#define RANDOMMACHINES_H

#include <QMainWindow>

namespace Ui {
class RandomMachines;
}

class RandomMachines : public QMainWindow
{
    Q_OBJECT

public:
    explicit RandomMachines(QWidget *parent = 0);
    ~RandomMachines();

private:
    Ui::RandomMachines *ui;
};

#endif // RANDOMMACHINES_H
