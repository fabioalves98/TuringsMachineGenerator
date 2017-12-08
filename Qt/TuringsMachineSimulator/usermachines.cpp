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

    connect(ui->tablesList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(getMachToDispay(QListWidgetItem*)));
    connect(ui->splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->splitter_2, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->splitter_3, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
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
    QFile *tableFile = new QFile(QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath() + "/Mega/Bolsa/Turings-Machine-Simulator/C++/tables", "Text Files (*.txt);;All Files(*)"));
    MachineInfo *machI = new MachineInfo(tableFile);
    bool contains = false;
    foreach (MachineInfo *mach, listMach) {
        if (mach->getFileInfo()->absoluteFilePath() == machI->getFileInfo()->absoluteFilePath()) {
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
    current = machI->getMachine();
}

void UserMachines::on_simBt_clicked()
{
    if (!tableIsLoaded) return;
    haltSim = false;
    ui->simList->clear();
    current->reset();
    current->start();

    std::list<QChar> tape;
    QString tapeStr;
    while (!current->halted() && !haltSim) {
        tape = current->advance();
        int offset = current->getTapeHeadOffset();
        tapeStr = "";
        for (QChar sym : tape) {
            tapeStr.append("[");
            tapeStr.append(sym);
            tapeStr.append("]");
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
        tableText->setFont(QFont("Courier", 11, QFont::Bold));
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
        QThread::msleep(100);
        QCoreApplication::processEvents();
    }
}

void UserMachines::getMachToDispay(QListWidgetItem *item) {
    haltSim = true;
    for (int i = 0; i < listMach.size(); i++) {
        if (listMach.at(i)->getTableListItem()->text() == item->text()) {
            displayMach(listMach.at(i));
            current = listMach.at(i)->getMachine();
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
        propName->setFont(QFont("Meiryo", 10, QFont::Bold));
        layout->addWidget(propName);
        QLabel *propValue = new QLabel;
        switch(properties.indexOf(prop)) {
            case 0: {
                propValue->setText(toDisplay->getFileInfo()->baseName());
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
        layout->addWidget(propValue, Qt::AlignLeft);
        layout->setMargin(1);
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
