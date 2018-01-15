#include "machinesimulation.h"
#include "ui_machinesimulation.h"

MachineSimulation::MachineSimulation(Machine *mach, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MachineSimulation),
    mach(mach)
{
    ui->setupUi(this);
}

MachineSimulation::~MachineSimulation()
{
    delete ui;
}

void MachineSimulation::start() {
    // Setting the size of the simulation container
    QList<int> sizes = ui->tableSplit->sizes();
    sizes[0] = (int)ui->tableSplit->height()*0.4;
    sizes[1] = (int)ui->tableSplit->height()*0.6;
    ui->tableSplit->setSizes(sizes);
    // Setting the size of the table view container
    sizes = ui->specSplit->sizes();
    sizes[0] = (int)ui->specSplit->width()*0.6;
    sizes[1] = (int)ui->specSplit->width()*0.4;
    ui->specSplit->setSizes(sizes);
    // Setting the size of the states container
    sizes = ui->simSplit->sizes();
    sizes[0] = (int)ui->simSplit->width()*0.1;
    sizes[1] = (int)ui->simSplit->width()*0.9;
    ui->simSplit->setSizes(sizes);

    ui->tableView->verticalScrollBar()->setEnabled(false);
    ui->tableView->horizontalScrollBar()->setEnabled(false);

    ui->stateList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->simList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    connect(ui->specSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->tableSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->stateList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->simList->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->simList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->stateList->verticalScrollBar(), SLOT(setValue(int)));

    connect(this, SIGNAL(insertTapeSgn(QString)), this, SLOT(insertTapeSlt(QString)));
    connect(this, SIGNAL(insertStateSgn(QString)), this, SLOT(insertStateSlt(QString)));
    connect(this, SIGNAL(selectTableCellSgn(int,int)), this, SLOT(selectTableCellSlt(int,int)));
}

void MachineSimulation::on_loadTapeBt_clicked()
{
    QString fileD = QFileDialog::getOpenFileName(this, "Open a Text File containing a Tape's Description", QDir::homePath() + "/Mega/Bolsa/TuringsMachineGenerator/C++/tapes", "Text Files (*.txt);;All Files(*)");
    if (!(fileD == nullptr)) {
        QFile *tapeFile = new QFile(fileD);
        mach->setTape(tapeFile);
        QFileInfo *tapeInfo = new QFileInfo(*tapeFile);
        QListWidgetItem *tapeI = new QListWidgetItem;
        QWidget *tapeW = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;
        QLabel *propName = new QLabel;
        propName->setText(" Custom Tape: ");
        propName->setFont(QFont("Meiryo", 11, QFont::Bold));
        layout->addWidget(propName);
        QLabel *propValue = new QLabel;
        propValue->setText(tapeInfo->baseName());
        propValue->setFont(QFont("Meiryo", 11));
        layout->addWidget(propValue, Qt::AlignLeft);
        layout->setMargin(0);
        tapeW->setLayout(layout);
        tapeI->setSizeHint(QSize(0, 25));
        tapeI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
        ui->propList->addItem(tapeI);
        ui->propList->setItemWidget(tapeI, tapeW);
    }
}


void MachineSimulation::setMachine(Machine *mach) {
    this->mach = mach;
}

void MachineSimulation::display() {
    ui->tableView->clear();
    // Get the states, symbols and instructions, fill a table with them
    QVector<QChar> *symbols = mach->getSymbols();
    QVector<QChar> *states = mach->getStates();
    ui->tableView->setRowCount(symbols->size());
    ui->tableView->setColumnCount(states->size());
    for (int i = 0, k = 0; i < symbols->size(); i++) {
        QTableWidgetItem *vHeader = new QTableWidgetItem(symbols->at(i));
        vHeader->setFont(QFont("Meiryo", 11));
        ui->tableView->setVerticalHeaderItem(i, vHeader);
        for (int j = 0; j < states->size(); j++, k++) {
            if (i == 0) {
                QTableWidgetItem *hHeader = new QTableWidgetItem(states->at(j));
                hHeader->setFont(QFont("Meiryo", 11));
                ui->tableView->setHorizontalHeaderItem(j, hHeader);
            }
            QTableWidgetItem *tableItem = new QTableWidgetItem(mach->funct(states->value(j), symbols->value(i)));
            tableItem->setFont(QFont("Meiryo", 15));
            tableItem->setTextColor(QColor(Qt::white));
            tableItem->setTextAlignment(Qt::AlignCenter);
            tableItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            ui->tableView->setItem(i, j, tableItem);
        }
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->propList->clear();
    // Get the remaining properties, and fill the PropertiesList
    QStringList properties;
    properties << " Name: " << " Symbols: " << " States: " << " Blanck Symbol: " << " Inicial State: " << " Halt State: ";
    for (QString prop : properties) {
        QListWidgetItem *newProI = new QListWidgetItem;
        QWidget *newProW = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;
        QLabel *propName = new QLabel;
        propName->setText(prop);
        propName->setFont(QFont("Meiryo", 11, QFont::Bold));
        layout->addWidget(propName);
        QLabel *propValue = new QLabel;
        switch(properties.indexOf(prop)) {
            case 0: {
                propValue->setText(mach->getFileName());
                break;
            }
            case 1: {
                QString *symbolsStr = new QString;
                for (QChar symbol : *mach->getSymbols()) {
                    symbolsStr->append(symbol);
                    symbolsStr->append((" "));
                }
                propValue->setText(*symbolsStr);
                break;
            }
            case 2: {
                QString *statesStr = new QString;
                for (QChar state : *mach->getStates()) {
                    statesStr->append(state);
                    statesStr->append((" "));
                }
                propValue->setText(*statesStr);
                break;
            }
            case 3: {
                QString bSym(mach->getBlanckSym());
                propValue->setText(bSym);
                break;
            }
            case 4: {
                QString iSt(mach->getInitState());
                propValue->setText(iSt);
                break;
            }
            case 5: {
                QString hSt(mach->getHaltState());
                propValue->setText(hSt);
                break;
            }
        }
        propValue->setFont(QFont("Meiryo", 11));
        layout->addWidget(propValue, Qt::AlignLeft);
        layout->setMargin(0);
        newProW->setLayout(layout);
        newProI->setSizeHint(QSize(0, 25));
        newProI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
        ui->propList->addItem(newProI);
        ui->propList->setItemWidget(newProI, newProW);
    }
    tableIsLoaded = true;
    resizeTable();
    state = "TableLoaded";
}

void MachineSimulation::resizeEvent(QResizeEvent *event)
{
    resizeTable();
    update();
    QWidget::resizeEvent(event);
}

void MachineSimulation::resizeTable() {
    if (tableIsLoaded) {
        int rowHeigth = (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/ui->tableView->rowCount();
        int columnWidth = (ui->tableView->width() - ui->tableView->verticalHeader()->width())/ui->tableView->columnCount();
        int horExccess = (ui->tableView->width() - ui->tableView->verticalHeader()->width()) - ui->tableView->columnCount()*columnWidth;
        int verExccess = (ui->tableView->height() - ui->tableView->horizontalHeader()->height()) - ui->tableView->rowCount()*rowHeigth;
        for (int i = 0; i < ui->tableView->rowCount(); i++) {
            if (verExccess > 1) {
                ui->tableView->setRowHeight(i, rowHeigth + 1);
                verExccess--;
            }
            else {
                ui->tableView->setRowHeight(i, rowHeigth);
            }

        }
        for (int i = 0; i < ui->tableView->columnCount(); i++) {
            if (horExccess > 1) {
                ui->tableView->setColumnWidth(i, columnWidth + 1);
                horExccess--;
            }
            else {
                ui->tableView->setColumnWidth(i, columnWidth);
            }
        }
    }
}

void MachineSimulation::simulate() {
    if (!tableIsLoaded) return;
    state = "Sim";
    haltSim = false;
    pauseSim = false;
    halts = false;
    ui->simList->clear();
    ui->stateList->clear();
    mach->reset();
    mach->start();

    std::list<QChar> tape;
    QString tapeStr;
    do {
        if (pauseSim) {
            QThread::msleep(10);
            QCoreApplication::processEvents();
            if (haltSim) {
                break;
            }
            else {
                continue;
            }
        }
        tape = mach->getTape();
        int offset = mach->getTapeHeadOffset();
        tapeStr = "";
        int spacing = tape.size()/2 - offset;
        for (QChar sym : tape) {
            if (spacing == 0) tapeStr.append(" ");
            tapeStr.append("|");
            tapeStr.append(sym);
            tapeStr.append("|");
            if (spacing == 0) tapeStr.append(" ");
            spacing--;
        }
        if (tape.size() % 2 == 0) {
            tapeStr.append("   ");
        }
        if (offset > 0) {
            for (int i = 0; i < abs(offset); i++) {
                tapeStr.prepend("      ");
            }
        }
        else if (offset < 0) {
            for (int i = 0; i < abs(offset); i++) {
                tapeStr.append("      ");
            }
        }
        int st = mach->getStates()->indexOf(mach->getCurrentState());
        int sy = mach->getSymbols()->indexOf(mach->getCurrentSymbol());

        emit selectTableCellSgn(st, sy);
        emit insertStateSgn(mach->getCurrentState());
        emit insertTapeSgn(tapeStr);

        for (int i = 0; i < 20; i++) {
            QThread::msleep(10);
            QCoreApplication::processEvents();
            if (mach->halted()) {
                state = "TableLoaded";
                halts = true;
                return;
            }
            if (haltSim) {
                state = "TableLoaded";
                return;
            }
        }
        mach->advance();
    }
    while (true);
}

void MachineSimulation::selectTableCellSlt(int st, int sy) {
    if (st >= 0) {
        ui->tableView->clearSelection();
        QModelIndex model = ui->tableView->model()->index(sy, st);
        ui->tableView->selectionModel()->select(model, QItemSelectionModel::Select);
    }
}

void MachineSimulation::insertStateSlt(QString state) {
    QListWidgetItem *newStateI = new QListWidgetItem;
    QLabel *stateText = new QLabel;
    stateText->setText(state);
    stateText->setFont(QFont("Monospace", 12));
    stateText->setAlignment(Qt::AlignCenter);
    newStateI->setSizeHint(stateText->sizeHint());
    newStateI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
    ui->stateList->addItem(newStateI);
    ui->stateList->setItemWidget(newStateI, stateText);
    ui->stateList->scrollToBottom();
    QScrollBar *bar = ui->stateList->horizontalScrollBar();
    bar->setValue((bar->maximum() + bar->minimum())/2);
    bar->update();
}

void MachineSimulation::insertTapeSlt(QString toUpdate) {
    QListWidgetItem *newTapeI = new QListWidgetItem;
    QLabel *tableText = new QLabel;
    tableText->setText(toUpdate);
    tableText->setFont(QFont("Monospace", 12));
    tableText->setAlignment(Qt::AlignCenter);
    newTapeI->setSizeHint(tableText->sizeHint());
    newTapeI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
    ui->simList->addItem(newTapeI);
    ui->simList->setItemWidget(newTapeI, tableText);
    ui->simList->scrollToBottom();
    QScrollBar *bar = ui->simList->horizontalScrollBar();
    bar->setValue((bar->maximum() + bar->minimum())/2);
    bar->update();
    ui->simList->update();
}

void MachineSimulation::pause() {
    state = "Pause";
    pauseSim = true;
}

void MachineSimulation::cont() {
    state = "Sim";
    pauseSim = false;
}

void MachineSimulation::stop() {
    state = "TableLoaded";
    haltSim = true;
}

bool MachineSimulation::halted() {
    return halts;
}

QString MachineSimulation::getState() {
    return state;
}
