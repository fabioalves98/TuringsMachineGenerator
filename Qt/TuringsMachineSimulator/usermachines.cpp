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
    QList<int> sizes = ui->splitter->sizes();
    sizes[0] = (int)ui->splitter->width()*0.7;
    ui->splitter->setSizes(sizes);

    sizes = ui->splitter_2->sizes();
    sizes[1] = (int)ui->splitter_2->height()*0.7;
    ui->splitter_2->setSizes(sizes);

    sizes = ui->splitter_3->sizes();
    sizes[0] = (int)ui->splitter_3->width()*0.2;
    ui->splitter_3->setSizes(sizes);

    states << "Init" << "TableLoaded" << "Sim" << "Pause";
    enSimButtons("Init");

    connect(ui->tablesList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(getMachToDispay(QListWidgetItem*)));
    connect(ui->splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->splitter_2, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->splitter_3, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
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
    QFile *tableFile = new QFile(QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath() + "/Mega/Bolsa/TuringsMachineGenerator/C++/tables", "Text Files (*.txt);;All Files(*)"));
    MachineInfo *machI = new MachineInfo(tableFile);
    bool contains = false;
    foreach (MachineInfo *mach, listMach) {
        if (mach->getFileName() == machI->getFileName()) {
            contains = true;
        }
    }
    if (!contains) {
        listMach.append(machI);
        // Get the name of the table, list it in the TablesList
        ui->tablesList->addItem(listMach.back()->getTableListItem());
        ui->tablesList->setIconSize(QSize(20, 20));
    }
    displayMach(machI);
    tableIsLoaded = true;
    currentI = machI;
    currentM = currentI->getMachine();
    enSimButtons("TableLoaded");
}

void UserMachines::on_simBt_clicked()
{
    if (!tableIsLoaded) return;
    enSimButtons("Sim");
    haltSim = false;
    pauseSim = false;
    ui->simList->clear();
    currentM->reset();
    currentM->start();

    std::list<QChar> tape;
    QString tapeStr;
    do {
        if (pauseSim) {
            QCoreApplication::processEvents();
            continue;
        }
        tape = currentM->getTape();
        int offset = currentM->getTapeHeadOffset();
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
        for (int i = 0; i < 100; i++) {
            QThread::msleep(1);
            QCoreApplication::processEvents();
        }
        if (currentM->halted() || haltSim) {
            break;
        }
        currentM->advance();
    }
    while (true);
    enSimButtons("TableLoaded");
}

void UserMachines::getMachToDispay(QListWidgetItem *item) {
    haltSim = true;
    for (int i = 0; i < listMach.size(); i++) {
        if (listMach.at(i)->getTableListItem()->text() == item->text()) {
            displayMach(listMach.at(i));
            currentI = listMach.at(i);
            currentM = currentI->getMachine();
            break;
        }
    }
}

void UserMachines::displayMach(MachineInfo *toDisplay) {
    // Get the states, symbols and instructions, fill a table with them
    ui->tableView->clear();
    ui->tableView->setRowCount(toDisplay->getVTableHeader()->size());
    ui->tableView->setColumnCount(toDisplay->getHTableHeader()->size());
    for (int i = 0, k = 0; i < toDisplay->getVTableHeader()->size(); i++) {
        ui->tableView->setRowHeight(i, (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/toDisplay->getVTableHeader()->size());
        QTableWidgetItem *vHeader = new QTableWidgetItem(*toDisplay->getVTableHeader()->at(i));
        ui->tableView->setVerticalHeaderItem(i, vHeader);
        for (int j = 0; j < toDisplay->getHTableHeader()->size(); j++, k++) {
            if (i == 0) {
                ui->tableView->setColumnWidth(j, (ui->tableView->width() - ui->tableView->verticalHeader()->width())/toDisplay->getHTableHeader()->size());
                QTableWidgetItem *hHeader = new QTableWidgetItem(*toDisplay->getHTableHeader()->at(j));
                ui->tableView->setHorizontalHeaderItem(j, hHeader);
            }
            QTableWidgetItem *tableItem = new QTableWidgetItem(*toDisplay->getTableElems()->at(k));
            tableItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            ui->tableView->setItem(i, j, tableItem);
        }
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
                for (QChar symbol : *toDisplay->getMachine()->getSymbols()) {
                    symbolsStr->append(symbol);
                    symbolsStr->append((" "));
                }
                propValue->setText(*symbolsStr);
                break;
            }
            case 2: {
                QString *statesStr = new QString;
                for (QChar state : *toDisplay->getMachine()->getStates()) {
                    statesStr->append(state);
                    statesStr->append((" "));
                }
                propValue->setText(*statesStr);
                break;
            }
            case 3: {
                QString bSym(toDisplay->getMachine()->getBlanckSym());
                propValue->setText(bSym);
                break;
            }
            case 4: {
                QString iSt(toDisplay->getMachine()->getInitState());
                propValue->setText(iSt);
                break;
            }
            case 5: {
                QString hSt(toDisplay->getMachine()->getHaltState());
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
}

void UserMachines::resizeTable() {
    if (tableIsLoaded) {
        int rowHeigth = (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/ui->tableView->rowCount();
        int columnWidth = (ui->tableView->width() - ui->tableView->verticalHeader()->width())/ui->tableView->columnCount();
        for (int i = 0; i < ui->tableView->rowCount(); i++) {
            ui->tableView->setRowHeight(i, rowHeigth);
        }
        for (int i = 0; i < ui->tableView->columnCount(); i++) {
            ui->tableView->setColumnWidth(i, columnWidth);
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
    RandomMachines *rand = new RandomMachines;
    rand->show();
    while (!rand->isReady()) {
            QThread::msleep(1);
            QCoreApplication::processEvents();
    }
    MachineInfo *randMach = rand->getRandMach();
    rand->close();
    listMach.append(randMach);
    ui->tablesList->addItem(listMach.back()->getTableListItem());
    ui->tablesList->setIconSize(QSize(20, 20));
    displayMach(randMach);
    tableIsLoaded = true;
    currentI = randMach;
    currentM = currentI->getMachine();
    enSimButtons("TableLoaded");
}

void UserMachines::on_editTableBt_clicked()
{

}
