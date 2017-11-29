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
    QString fileName = QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath() + "/Mega/Bolsa/Turings-Machine-Simulator/C++/tables", "Text Files (*.txt);;All Files(*)");
    Machine lol(fileName);
    test = &lol;
    QListWidgetItem *newTable = new QListWidgetItem;
    newTable->setText(fileName);
    newTable->setFont(QFont("Meiryo", 10));
    newTable->setIcon(QIcon(":/rec/icons/table.png"));
    ui->tableList->addItem(newTable);
    ui->tableList->setIconSize(QSize(20, 20));

    QVector<QChar> *symbols = test->getSymbols();
    QVector<QChar> *states = test->getStates();
    ui->tableView->setRowCount(symbols->size());
    ui->tableView->setColumnCount(states->size());
    for (int i = 0; i < symbols->size(); i++) {
        ui->tableView->setRowHeight(i, (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/symbols->size());
        QTableWidgetItem *item = new QTableWidgetItem(symbols->value(i));
        ui->tableView->setVerticalHeaderItem(i, item);
    }
    for (int i = 0; i < states->size(); i++) {
        ui->tableView->setColumnWidth(i, (ui->tableView->width() - ui->tableView->verticalHeader()->width())/states->size());
        QTableWidgetItem *item = new QTableWidgetItem(states->value(i));
        ui->tableView->setHorizontalHeaderItem(i, item);
    }
    for (int i = 0; i < symbols->size(); i++) {
        for (int j = 0; j < states->size(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem(test->funct(states->value(j), symbols->value(i)));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            ui->tableView->setItem(i, j, item);
        }
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //test->start();
}
