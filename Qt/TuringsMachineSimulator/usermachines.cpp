#include "usermachines.h"
#include "ui_usermachines.h"

UserMachines::UserMachines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMachines)
{
    ui->setupUi(this);
}

UserMachines::~UserMachines()
{
    delete ui;
}

void UserMachines::on_fileOpener_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath(), "Text Files (*.txt);;All Files(*)");
    Machine lol(fileName);
    test = &lol;
    test->start();
}
