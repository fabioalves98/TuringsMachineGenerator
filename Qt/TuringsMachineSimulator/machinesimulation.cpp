#include "machinesimulation.h"
#include "ui_machinesimulation.h"

MachineSimulation::MachineSimulation(Machine *mach, Tape *tape, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MachineSimulation),
    mach(mach),
    inTape(tape)
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
    // Gettings the global Settings
    set = Settings::getInstance();
    localDelayFormat = set->getDelayTime()/10;

    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);

    ui->tableView->verticalScrollBar()->setEnabled(false);
    ui->tableView->horizontalScrollBar()->setEnabled(false);
    ui->tapeList->verticalScrollBar()->setEnabled(false);

    ui->statesList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->statesList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->stateList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->simList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->simList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tapeList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tapeList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->inTape->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->stateList->addItem(new QListWidgetItem);

    connect(ui->specSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->tableSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->statesList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->simList->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->simList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->statesList->verticalScrollBar(), SLOT(setValue(int)));

    connect(this, SIGNAL(insertTapeSgn(QString)), this, SLOT(insertTapeSlt(QString)));
    connect(this, SIGNAL(insertStateSgn(QString)), this, SLOT(insertStateSlt(QString)));
    connect(this, SIGNAL(selectTableCellSgn(int,int)), this, SLOT(selectTableCellSlt(int,int)));
    connect(this, SIGNAL(changeStatusSgn(QString)), this, SLOT(changeStatusSlt(QString)));

    statusBar()->showMessage("No Status");
}

void MachineSimulation::setMachine(Machine *mach) {
    this->mach = mach;
}

void MachineSimulation::setTape(Tape *tape) {
    this->inTape = tape;
    dynamic_cast<QLabel*>(ui->propList->itemWidget(ui->propList->item(6))->layout()->itemAt(1)->widget())->setText(tape->getName());
    displayTape();
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
    properties << " Name: " << " Symbols: " << " States: " << " Blanck Symbol: " << " Inicial State: " << " Halt State: " << " Tape: ";
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
            case 6: {
                propValue->setText(inTape->getName());
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
    displayTape();
    tableIsLoaded = true;
    resizeTable();
    state = "TableLoaded";
    statusBar()->showMessage("Machine is Loaded");
}

void MachineSimulation::displayTape() {
    int headPos = inTape->getTapePos();
    ui->headPos->setValue(headPos);
    std::list<QChar> tape = inTape->getTape();
    if (headPos <= 0) {
        headPos = 1;
    }
    std::list<QChar>::iterator tapeIt = tape.begin();
    QString tapeStr;
    int offset = tape.size()/2 - headPos;
    for (int i = 0; i < tape.size(); i++) {
        if (i == headPos) tapeStr.append(" ");
        tapeStr.append("|");
        tapeStr.append(*tapeIt);
        tapeStr.append("|");
        if (i == headPos) tapeStr.append(" ");
        tapeIt++;
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
    QListWidgetItem *inTapeItem = new QListWidgetItem;
    QLabel *inTapeText = new QLabel;
    inTapeText->setText(tapeStr);
    inTapeText->setFont(QFont("Courier", 12, QFont::Bold));
    inTapeText->setAlignment(Qt::AlignCenter);
    ui->inTape->clear();
    ui->inTape->addItem(inTapeItem);
    ui->inTape->setItemWidget(inTapeItem, inTapeText);
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
    ui->statesList->clear();
    ui->tapeList->clear();
    mach->start(inTape);

    int iterations = 0;
    int maxIter = set->getIterTilHalt();
    bool haltWhenMaxIter = set->getHaltInXIt();
    //bool decDelay = set->getDecDelay();

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

        for (int i = 0; i < localDelayFormat; i++) {
            QThread::msleep(10);
            QCoreApplication::processEvents();
            if (mach->halted()) {
                emit changeStatusSgn("The machine halted after " + QString::number(iterations) + " iterations");
                state = "TableLoaded";
                halts = true;
                return;
            }
            if (haltSim) {
                emit changeStatusSgn("The machine halted by user's order");
                state = "TableLoaded";
                return;
            }
        }
        // To Fix
        /*if (decDelay && localDelayFormat > 1) {
            if (iterations % 10 == 0) {
                localDelayFormat--;
            }
        }*/
        iterations++;
        if ((iterations > maxIter) && haltWhenMaxIter) {
            emit changeStatusSgn("The machine reached maximum number of iterations");
            return;
        }
        mach->advance();
        emit changeStatusSgn("Simulating - " + QString::number(iterations) + " iterations");
    }
    while (true);
}

void MachineSimulation::selectTableCellSlt(int st, int sy) {
    //ui->tableView->setFocus();
    if (st >= 0) {
        ui->tableView->clearSelection();
        QModelIndex model = ui->tableView->model()->index(sy, st);
        ui->tableView->selectionModel()->select(model, QItemSelectionModel::Select);
    }
}

void MachineSimulation::insertStateSlt(QString state) {
    QListWidgetItem *newStateI = new QListWidgetItem;
    QLabel *statesText = new QLabel;
    statesText->setText(state);
    statesText->setFont(QFont("Courier", 12, QFont::Bold));
    statesText->setAlignment(Qt::AlignCenter);
    newStateI->setSizeHint(statesText->sizeHint());
    newStateI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
    ui->statesList->addItem(newStateI);
    ui->statesList->setItemWidget(newStateI, statesText);
    ui->statesList->scrollToBottom();

    QLabel *stateText = new QLabel;
    stateText->setText(state);
    stateText->setFont(QFont("Courier", 12, QFont::Bold));
    stateText->setAlignment(Qt::AlignCenter);
    ui->stateList->setItemWidget(ui->stateList->item(0), stateText);
}

void MachineSimulation::insertTapeSlt(QString toUpdate) {
    QListWidgetItem *tableTextI = new QListWidgetItem;
    QLabel *tableText = new QLabel;
    tableText->setText(toUpdate);
    tableText->setFont(QFont("Courier", 12, QFont::Bold));
    tableText->setAlignment(Qt::AlignCenter);
    tableTextI->setSizeHint(tableText->sizeHint());
    tableTextI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
    ui->simList->addItem(tableTextI);
    ui->simList->setItemWidget(tableTextI, tableText);
    ui->simList->scrollToBottom();

    QListWidgetItem *tapeTextI = new QListWidgetItem;
    QLabel *tapeText = new QLabel;
    tapeText->setText(toUpdate);
    tapeText->setFont(QFont("Courier", 12, QFont::Bold));
    tapeText->setAlignment(Qt::AlignCenter);
    tapeTextI->setSizeHint(tapeText->sizeHint());
    tapeTextI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
    ui->tapeList->addItem(tapeTextI);
    ui->tapeList->setItemWidget(tapeTextI, tapeText);
    ui->tapeList->scrollToBottom();

    QScrollBar *barUp = ui->simList->horizontalScrollBar();
    barUp->setValue((barUp->maximum() + barUp->minimum())/2);
    barUp->update();
    ui->simList->update();
    QScrollBar *barDown = ui->tapeList->horizontalScrollBar();
    barDown->setValue((barDown->maximum() + barDown->minimum())/2);
    barDown->update();
    ui->tapeList->update();
}

void MachineSimulation::changeStatusSlt(QString status) {
    statusBar()->showMessage(status);
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

void MachineSimulation::decreaseSpeed()
{
    localDelayFormat = localDelayFormat * 1.2;
    emit delayChanged(localDelayFormat);
}

void MachineSimulation::increaseSpeed()
{
    localDelayFormat = localDelayFormat * 0.8;
    if (localDelayFormat < 5) {
        localDelayFormat = 5;
    }
    emit delayChanged(localDelayFormat);
}

int MachineSimulation::getLocalDelay()
{
    return int(localDelayFormat);
}

QString MachineSimulation::getState() {
    return state;
}

void MachineSimulation::on_headPos_valueChanged(int arg1)
{
    inTape->setTapePos(arg1);
    displayTape();
}
