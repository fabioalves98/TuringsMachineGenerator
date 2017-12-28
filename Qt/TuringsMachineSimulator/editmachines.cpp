#include "editmachines.h"
#include "ui_editmachines.h"

EditMachines::EditMachines(MachineInfo *toEdit, QWidget *parent) :
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
    ui->tableView->setRowCount(mach->getVTableHeader()->size());
    ui->tableView->setColumnCount(mach->getHTableHeader()->size());
    for (int i = 0, k = 0; i < mach->getVTableHeader()->size(); i++) {
        ui->tableView->setRowHeight(i, (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/mach->getVTableHeader()->size());
        QTableWidgetItem *vHeader = new QTableWidgetItem(*mach->getVTableHeader()->at(i));
        ui->tableView->setVerticalHeaderItem(i, vHeader);
        for (int j = 0; j < mach->getHTableHeader()->size(); j++, k++) {
            if (i == 0) {
                ui->tableView->setColumnWidth(j, (ui->tableView->width() - ui->tableView->verticalHeader()->width())/mach->getHTableHeader()->size());
                QTableWidgetItem *hHeader = new QTableWidgetItem(*mach->getHTableHeader()->at(j));
                ui->tableView->setHorizontalHeaderItem(j, hHeader);
            }
            QTableWidgetItem *tableItem = new QTableWidgetItem(*mach->getTableElems()->at(k));
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
    QVector<QChar> *states = mach->getMachine()->getStates();
    QVector<QChar> *symbols = mach->getMachine()->getSymbols();
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
    ui->writeCBox->clear();
    ui->moveCBox->clear();
    ui->nextCBox->clear();
    foreach (QChar sym, *mach->getMachine()->getSymbols()) {
        ui->writeCBox->addItem(sym);
    }
    ui->moveCBox->addItem("Left");
    ui->moveCBox->addItem("Right");
    foreach (QChar st, *mach->getMachine()->getStates()) {
        ui->nextCBox->addItem(st);
    }
    ui->nextCBox->addItem(QChar('H'));
}

void EditMachines::on_saveBut_clicked()
{
    QMap<QString, QString> tFunct;
    QVector<QChar> *states = mach->getMachine()->getStates();
    QVector<QChar> *symbols = mach->getMachine()->getSymbols();
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

MachineInfo *EditMachines::getEditMach() {
    return mach;
}
