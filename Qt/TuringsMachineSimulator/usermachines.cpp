#include "usermachines.h"
#include "ui_usermachines.h"

UserMachines::UserMachines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMachines)
{
    ui->setupUi(this);
    tableIsLoaded = false;
}

UserMachines::~UserMachines()
{
    delete ui;
}

void UserMachines::start()
{
    // Setting the size of the table list container
    QList<int> sizes = ui->listSplit->sizes();
    sizes[0] = (int)ui->listSplit->width()*0.2;
    ui->listSplit->setSizes(sizes);
    // Setting the size of the simulation container
    sizes = ui->tableSplit->sizes();
    sizes[1] = (int)ui->tableSplit->height()*0.7;
    ui->tableSplit->setSizes(sizes);
    // Setting the size of the table view container
    sizes = ui->specSplit->sizes();
    sizes[0] = (int)ui->specSplit->width()*0.7;
    ui->specSplit->setSizes(sizes);
    // Setting the size of the states container
    sizes = ui->simSplit->sizes();
    sizes[0] = (int)ui->simSplit->width()*0.1;
    sizes[1] = (int)ui->simSplit->width() - sizes[0];
    ui->simSplit->setSizes(sizes);

    ui->tableView->verticalScrollBar()->setEnabled(false);
    ui->tableView->horizontalScrollBar()->setEnabled(false);

    states << "Init" << "TableLoaded" << "Sim" << "Pause";
    enSimButtons("Init");

    connect(ui->tablesList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(getMachToDispay(QListWidgetItem*)));
    connect(ui->listSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->tableSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->specSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->stateList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->simList->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->simList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->stateList->verticalScrollBar(), SLOT(setValue(int)));
}

void UserMachines::close() {
    pauseSim = false;
    haltSim = true;
}

void UserMachines::resizeEvent(QResizeEvent *event)
{
    resizeTable();
    update();
    QWidget::resizeEvent(event);
}

void UserMachines::on_addTableBt_clicked()
{
    haltSim = true;
    // Initialize new Table, and display it
    QString fileD = QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath() + "/Mega/Bolsa/TuringsMachineGenerator/C++/tables", "Text Files (*.txt);;All Files(*)");
    if (!(fileD == nullptr)) {
        QFile *tableFile = new QFile(fileD);
        Machine *machI = new Machine(tableFile);
        displayMach(machI);
        tableIsLoaded = true;
        current = machI;
        enSimButtons("TableLoaded");
    }
}

void UserMachines::on_simBt_clicked()
{
    if (!tableIsLoaded) return;
    enSimButtons("Sim");
    haltSim = false;
    pauseSim = false;
    ui->simList->clear();
    ui->stateList->clear();
    current->reset();
    current->start();

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
        tape = current->getTape();
        int offset = current->getTapeHeadOffset();
        tapeStr = "";
        for (QChar sym : tape) {
            tapeStr.append("|");
            tapeStr.append(sym);
            tapeStr.append("|");
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
        // Select state and symbol in table
        int st = current->getStates()->indexOf(current->getCurrentState());
        int sy = current->getSymbols()->indexOf(current->getCurrentSymbol());
        if (st >= 0) {
            ui->tableView->clearSelection();
            QModelIndex model = ui->tableView->model()->index(sy, st);
            ui->tableView->selectionModel()->select(model, QItemSelectionModel::Select);
        }
        // Add State
        QListWidgetItem *newStateI = new QListWidgetItem;
        QLabel *stateText = new QLabel;
        stateText->setText(current->getCurrentState());
        stateText->setFont(QFont("Courier", 12, QFont::Bold));
        stateText->setAlignment(Qt::AlignCenter);
        newStateI->setSizeHint(stateText->sizeHint());
        newStateI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
        ui->stateList->addItem(newStateI);
        ui->stateList->setItemWidget(newStateI, stateText);
        ui->stateList->scrollToBottom();
        // Add Tape Value
        QListWidgetItem *newTapeI = new QListWidgetItem;
        QLabel *tableText = new QLabel;
        tableText->setText(tapeStr);
        tableText->setFont(QFont("Courier", 12, QFont::Bold));
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
        for (int i = 0; i < 10; i++) {
            QThread::msleep(10);
            QCoreApplication::processEvents();
        }
        if (current->halted() || haltSim) {
            break;
        }
        current->advance();
    }
    while (true);
    enSimButtons("TableLoaded");
}

void UserMachines::getMachToDispay(QListWidgetItem *item) {
    haltSim = true;
    for (int i = 0; i < listMach.size(); i++) {
        if (listMach.at(i)->getFileName() == item->text()) {
            displayMach(listMach.at(i));
            current = listMach.at(i);
            break;
        }
    }
}

void UserMachines::displayMach(Machine *toDisplay) {
    // Get the name of the table, list it in the TablesList
    bool contains = false;
    foreach (Machine *mach, listMach) {
        if (mach->getFileName() == toDisplay->getFileName()) {
            contains = true;
        }
    }
    if (!contains) {
        listMach.append(toDisplay);
        QListWidgetItem *tableItem = new QListWidgetItem;
        tableItem->setText(toDisplay->getFileName());
        tableItem->setFont(QFont("Meiryo", 11));
        tableItem->setIcon(QIcon(":/rec/icons/table.png"));
        ui->tablesList->addItem(tableItem);
        ui->tablesList->setIconSize(QSize(20, 20));
    }
    // Get the states, symbols and instructions, fill a table with them
    tableIsLoaded = true;
    ui->tableView->clear();
    QVector<QChar> *symbols = toDisplay->getSymbols();
    QVector<QChar> *states = toDisplay->getStates();
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
            QTableWidgetItem *tableItem = new QTableWidgetItem(toDisplay->funct(states->value(j), symbols->value(i)));
            tableItem->setFont(QFont("Meiryo", 15));
            tableItem->setTextColor(QColor(Qt::white));
            tableItem->setTextAlignment(Qt::AlignCenter);
            tableItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            ui->tableView->setItem(i, j, tableItem);
        }
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    resizeTable();

    // Get the remaining properties, and fill the PropertiesList
    ui->propList->clear();
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
                propValue->setText(toDisplay->getFileName());
                break;
            }
            case 1: {
                QString *symbolsStr = new QString;
                for (QChar symbol : *toDisplay->getSymbols()) {
                    symbolsStr->append(symbol);
                    symbolsStr->append((" "));
                }
                propValue->setText(*symbolsStr);
                break;
            }
            case 2: {
                QString *statesStr = new QString;
                for (QChar state : *toDisplay->getStates()) {
                    statesStr->append(state);
                    statesStr->append((" "));
                }
                propValue->setText(*statesStr);
                break;
            }
            case 3: {
                QString bSym(toDisplay->getBlanckSym());
                propValue->setText(bSym);
                break;
            }
            case 4: {
                QString iSt(toDisplay->getInitState());
                propValue->setText(iSt);
                break;
            }
            case 5: {
                QString hSt(toDisplay->getHaltState());
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
    //Clear the Simulation View*/
    ui->simList->clear();
    ui->stateList->clear();
}

void UserMachines::resizeTable() {
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

void UserMachines::enSimButtons(QString state) {
    switch(states.indexOf(state)) {
        case 0: {
            ui->addTableBt->setEnabled(true);
            ui->editTableBt->setEnabled(false);
            ui->randTableBt->setEnabled(true);
            ui->simBt->setEnabled(false);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(false);
            break;
        }
        case 1: {
            ui->addTableBt->setEnabled(true);
            ui->editTableBt->setEnabled(true);
            ui->randTableBt->setEnabled(true);
            ui->simBt->setEnabled(true);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(false);
            break;
        }
        case 2: {
            ui->addTableBt->setEnabled(false);
            ui->editTableBt->setEnabled(false);
            ui->randTableBt->setEnabled(false);
            ui->simBt->setEnabled(false);
            ui->pauseBt->setEnabled(true);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(true);
            break;
        }
        case 3: {
            ui->addTableBt->setEnabled(false);
            ui->editTableBt->setEnabled(false);
            ui->randTableBt->setEnabled(false);
            ui->simBt->setEnabled(false);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(true);
            ui->stopBt->setEnabled(true);
            break;
        }
    }
}

void UserMachines::on_stopBt_clicked()
{
    enSimButtons("TableLoaded");
    haltSim = true;
}

void UserMachines::on_pauseBt_clicked()
{
    enSimButtons("Pause");
    pauseSim = true;
}

void UserMachines::on_contBt_clicked()
{
    enSimButtons("Sim");
    pauseSim = false;
}

void UserMachines::on_randTableBt_clicked()
{
    this->setEnabled(false);
    RandomMachines *rand = new RandomMachines;
    rand->show();
    while (!rand->isReady()) {
            QThread::msleep(10);
            QCoreApplication::processEvents();
            if (!rand->isVisible()) {
                this->setEnabled(true);
                return;
            }
    }
    this->setEnabled(true);
    Machine *randMach = rand->getRandMach();
    rand->close();
    displayMach(randMach);
    current = randMach;
    enSimButtons("TableLoaded");
}

void UserMachines::on_editTableBt_clicked()
{
    EditMachines *edit = new EditMachines(current);
    edit->show();
    edit->loadTable();
    while (!edit->isReady()) {
            QThread::msleep(10);
            QCoreApplication::processEvents();
            if (!edit->isVisible()) {
                return;
            }
    }
    current = edit->getEditMach();
    for (int i = 0; i < listMach.size(); i++) {
        if (listMach.at(i)->getFileName() == current->getFileName()) {
            listMach.replace(i, current);
        }
    }
    edit->close();
    displayMach(current);
    enSimButtons("TableLoaded");
}
