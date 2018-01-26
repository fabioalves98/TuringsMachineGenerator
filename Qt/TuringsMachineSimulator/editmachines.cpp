#include "editmachines.h"
#include "ui_editmachines.h"

EditMachines::EditMachines(Machine *toEdit, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditMachines),
    mach(toEdit)
{
    ui->setupUi(this);
    this->setWindowTitle("Table Edition");
    ui->tableView->verticalScrollBar()->setEnabled(false);
    ui->tableView->horizontalScrollBar()->setEnabled(false);
    tableIsLoaded = false;
    ready = false;
    ui->saveBut->setEnabled(false);
}

EditMachines::~EditMachines()
{
    delete ui;
}

void EditMachines::resizeEvent(QResizeEvent *event)
{
    resizeTable();
    update();
    QWidget::resizeEvent(event);
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
            tableItem->setTextAlignment(Qt::AlignCenter);
            tableItem->setFlags(tableItem->flags() ^ Qt::ItemIsEditable);
            ui->tableView->setItem(i, j, tableItem);
        }
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    fillComBoxes();
    tableIsLoaded = true;
    resizeTable();
}

void EditMachines::resizeTable() {
    if (tableIsLoaded) {
        int rowHeigth = (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/ui->tableView->rowCount();
        int columnWidth = (ui->tableView->width() - ui->tableView->verticalHeader()->width())/ui->tableView->columnCount();
        int horExccess = (ui->tableView->width() - ui->tableView->verticalHeader()->width()) - ui->tableView->columnCount()*columnWidth;
        int verExccess = (ui->tableView->height() - ui->tableView->horizontalHeader()->height()) - ui->tableView->rowCount()*rowHeigth;
        for (int i = 0; i < ui->tableView->rowCount(); i++) {
            if (verExccess > 2) {
                ui->tableView->setRowHeight(i, rowHeigth + 1);
                verExccess--;
            }
            else {
                ui->tableView->setRowHeight(i, rowHeigth);
            }

        }
        for (int i = 0; i < ui->tableView->columnCount(); i++) {
            if (horExccess > 2) {
                ui->tableView->setColumnWidth(i, columnWidth + 1);
                horExccess--;
            }
            else {
                ui->tableView->setColumnWidth(i, columnWidth);
            }
        }
    }
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
    ui->saveBut->setEnabled(true);
}

void EditMachines::fillComBoxes() {
    foreach (QChar sym, *mach->getSymbols()) {
        ui->writeCBox->addItem(sym);
    }
    ui->moveCBox->addItem("Left");
    ui->moveCBox->addItem("Right");
    QChar haltState = mach->getHaltState();
    QChar initState = mach->getInitState();
    bool haltInStates = false;
    int init = -1, halt = -1, i = 0;
    foreach (QChar st, *mach->getStates()) {
        if (st == haltState) {
            haltInStates = true;
            halt = i;
        }
        if (st == initState) {
            init = i;
        }
        ui->nextCBox->addItem(st);
        ui->inStateCBox->addItem(st);
        ui->hltStateCBox->addItem(st);
        i++;
    }
    if (!haltInStates) {
        ui->nextCBox->addItem(mach->getHaltState());
        ui->hltStateCBox->addItem(mach->getHaltState());
    }
    else {
        ui->nextCBox->addItem(QChar('Z'));
        ui->hltStateCBox->addItem(QChar('Z'));
    }
    ui->inStateCBox->setCurrentIndex(init);
    if (halt != -1) {
        ui->hltStateCBox->setCurrentIndex(halt);
    }
    else {
        ui->hltStateCBox->setCurrentIndex(ui->hltStateCBox->count() - 1);
    }
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
    mach->setInitState(ui->inStateCBox->currentText().at(0));
    mach->setHaltState(ui->hltStateCBox->currentText().at(0));
    ready = true;
}

bool EditMachines::isReady() {
    return ready;
}

Machine *EditMachines::getEditMach() {
    return mach;
}
