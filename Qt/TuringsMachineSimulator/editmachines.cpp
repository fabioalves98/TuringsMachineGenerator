#include "editmachines.h"
#include "ui_editmachines.h"

EditMachines::EditMachines(Machine *toEdit, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditMachines),
    mach(toEdit)
{
    ui->setupUi(this);
    this->setWindowTitle("Table Edition");
    ready = false;
}

EditMachines::~EditMachines()
{
    delete ui;
}

void EditMachines::loadTable() {
    QVector<QChar> *symbols = mach->getSymbols();
    QVector<QChar> *states = mach->getStates();
    ui->tableView->setRowCount(symbols->size());
    ui->tableView->setColumnCount(states->size());
    for (int i = 0, k = 0; i < symbols->size(); i++) {
        ui->tableView->setRowHeight(i, (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/symbols->size());
        QTableWidgetItem *vHeader = new QTableWidgetItem(symbols->at(i));
        vHeader->setFont(QFont("Meiryo", 11));
        ui->tableView->setVerticalHeaderItem(i, vHeader);
        for (int j = 0; j < states->size(); j++, k++) {
            if (i == 0) {
                ui->tableView->setColumnWidth(j, (ui->tableView->width() - ui->tableView->verticalHeader()->width())/states->size());
                QTableWidgetItem *hHeader = new QTableWidgetItem(states->at(j));
                hHeader->setFont(QFont("Meiryo", 11));
                ui->tableView->setHorizontalHeaderItem(j, hHeader);
            }
            QTableWidgetItem *tableItem = new QTableWidgetItem(mach->funct(states->value(j), symbols->value(i)));
            tableItem->setFont(QFont("Meiryo", 15));
            tableItem->setTextColor(QColor(Qt::white));
            tableItem->setTextAlignment(Qt::AlignCenter);
            tableItem->setFlags(tableItem->flags() ^ Qt::ItemIsEditable);
            ui->tableView->setItem(i, j, tableItem);
        }
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    fillComBoxes();
}

void EditMachines::on_tableView_cellClicked(int row, int column)
{
    QString act = ui->tableView->item(row, column)->text();
    QVector<QChar> *states = mach->getStates();
    QVector<QChar> *symbols = mach->getSymbols();
    for (int i = 0; i < symbols->size(); i++) {
        if (act[0] == symbols->at(i)) {
            ui->writeCBox->setCurrentIndex(i);
            break;
        }
    }
    ui->moveCBox->setCurrentIndex((act[1] == 'L') ? 0 : 1);
    for (int i = 0; i < states->size(); i++) {
        if (act[2] == states->at(i)) {
            ui->nextCBox->setCurrentIndex(i);
            break;
        }
    }
}

void EditMachines::on_changeBut_clicked()
{
    QString act;
    act.append(ui->writeCBox->itemText(ui->writeCBox->currentIndex()));
    act.append(ui->moveCBox->itemText(ui->moveCBox->currentIndex()).at(0));
    act.append(ui->nextCBox->itemText(ui->nextCBox->currentIndex()));
    foreach(QTableWidgetItem *cell, ui->tableView->selectedItems()) {
        cell->setText(act);
    }
    ui->tableView->clearSelection();
}

void EditMachines::fillComBoxes() {
    foreach (QChar sym, *mach->getSymbols()) {
        ui->writeCBox->addItem(sym);
    }
    ui->moveCBox->addItem("Left");
    ui->moveCBox->addItem("Right");
    foreach (QChar st, *mach->getStates()) {
        ui->nextCBox->addItem(st);
    }
    ui->nextCBox->addItem(QChar('H'));
}

void EditMachines::on_saveBut_clicked()
{
    QMap<QString, QString> tFunct;
    QVector<QChar> *states = mach->getStates();
    QVector<QChar> *symbols = mach->getSymbols();
    for (int i = 0; i < symbols->size(); i++) {
        for (int j = 0; j < states->size(); j++) {
            QString key;
            key.append(states->at(j));
            key.append(symbols->at(i));
            tFunct.insert(key, ui->tableView->item(i, j)->text());
        }
    }
    mach->setTransFunct(&tFunct);
    ready = true;
}

bool EditMachines::isReady() {
    return ready;
}

Machine *EditMachines::getEditMach() {
    return mach;
}
