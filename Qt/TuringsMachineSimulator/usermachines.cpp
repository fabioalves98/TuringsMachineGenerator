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
    sizes[1] = (int)ui->listSplit->width()*0.8;
    ui->listSplit->setSizes(sizes);
    // Setting the default display
    MachineSimulation *newMach = new MachineSimulation(nullptr);
    ui->tableSim->insertWidget(0, newMach);
    ui->tableSim->setCurrentIndex(0);
    newMach->start();
    newMach->setEnabled(false);

    /*// Setting the size of the simulation container
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
    ui->tableView->horizontalScrollBar()->setEnabled(false);*/

    states << "Init" << "TableLoaded" << "Sim" << "Pause";
    enSimButtons("Init");

    connect(ui->tablesList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(getMachToDispay(QListWidgetItem*)));
    /*connect(ui->listSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->tableSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->specSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->stateList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->simList->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->simList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->stateList->verticalScrollBar(), SLOT(setValue(int)));*/
}

void UserMachines::close() {
    pauseSim = false;
    haltSim = true;
}

void UserMachines::resizeEvent(QResizeEvent *event)
{
    //resizeTable();
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
        Machine *mach = new Machine(tableFile);
        addMachine(mach);
        MachineSimulation *sim = new MachineSimulation(mach);
        ui->tableSim->insertWidget(listMach.size(), sim);
        ui->tableSim->setCurrentIndex(listMach.size());
        sim->start();
        sim->display();
        enSimButtons(sim->getState());
    }
}

void UserMachines::on_simBt_clicked()
{
    MachineSimulation *toSim = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toSim->simulate();
    qDebug() << toSim->getState();
    enSimButtons(toSim->getState());
    while (toSim->getState() == "Sim") {
        for (int i = 0; i < 10; i++) {
            QThread::msleep(10);
            QCoreApplication::processEvents();
        }
    }
    enSimButtons(toSim->getState());
}

void UserMachines::getMachToDispay(QListWidgetItem *item) {
    haltSim = true;
    for (int i = 0; i < listMach.size(); i++) {
        if (listMach.at(i)->getFileName() == item->text()) {
            ui->tableSim->setCurrentIndex(i + 1);
            enSimButtons(dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->getState());
            break;
        }
    }
}

void UserMachines::addMachine(Machine *toAdd) {
    // Get the name of the table, list it in the TablesList
    bool contains = false;
    foreach (Machine *mach, listMach) {
        if (mach->getFileName() == toAdd->getFileName()) {
            contains = true;
        }
    }
    if (!contains) {
        listMach.append(toAdd);
        QListWidgetItem *tableItem = new QListWidgetItem;
        tableItem->setText(toAdd->getFileName());
        tableItem->setFont(QFont("Meiryo", 11));
        tableItem->setIcon(QIcon(":/rec/icons/table.png"));
        ui->tablesList->addItem(tableItem);
        ui->tablesList->setIconSize(QSize(20, 20));
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
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->stop();
}

void UserMachines::on_pauseBt_clicked()
{
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->pause();
}

void UserMachines::on_contBt_clicked()
{
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->cont();
}

void UserMachines::on_randTableBt_clicked()
{
    /*this->setEnabled(false);
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
    enSimButtons("TableLoaded");*/
}

void UserMachines::on_editTableBt_clicked()
{
    /*EditMachines *edit = new EditMachines(current);
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
    enSimButtons("TableLoaded");*/
}
