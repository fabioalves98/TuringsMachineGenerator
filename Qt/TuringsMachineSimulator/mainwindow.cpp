#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Turring's Machine Simulator");
    ui->stackedWidget->setGeometry(0, 0, this->width(), this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_userWindow_clicked()
{
    ui->stackedWidget->insertWidget(1, &usrMach);
    ui->stackedWidget->setCurrentIndex(1);
    this->setWindowTitle("User's Machines");
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->stackedWidget->setGeometry(0, 0, this->width(), this->height());
    update();
    QWidget::resizeEvent(event);
}
