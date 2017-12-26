#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "usermachines.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_userWindow_clicked();

private:
    void closeEvent(QCloseEvent *event);
    Ui::MainWindow *ui;
    UserMachines usrMach;
};

#endif // MAINWINDOW_H
