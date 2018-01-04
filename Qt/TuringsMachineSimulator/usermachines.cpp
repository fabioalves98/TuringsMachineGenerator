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

    states << "Init" << "TableLoaded" << "Sim" << "Pause";
    enSimButtons("Init");

    connect(ui->tablesList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(getMachToDispay(QListWidgetItem*)));
}

void UserMachines::closeEvent(QCloseEvent *event) {
    close();
    QWidget::closeEvent(event);
}

void UserMachines::close() {
    for (int i = 1; i < ui->tableSim->count(); i++) {
        dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i))->stop();
    }
}

void UserMachines::on_addTableBt_clicked()
{
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
    enSimButtons("Sim");
    toSim->simulate();
    enSimButtons(toSim->getState());
}

void UserMachines::getMachToDispay(QListWidgetItem *item) {
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
            ui->addTableBt->setEnabled(true);
            ui->editTableBt->setEnabled(false);
            ui->randTableBt->setEnabled(true);
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
    MachineSimulation *toStop = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toStop->stop();
    enSimButtons(toStop->getState());
}

void UserMachines::on_pauseBt_clicked()
{
    MachineSimulation *toPause = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toPause->pause();
    enSimButtons(toPause->getState());
}

void UserMachines::on_contBt_clicked()
{
    MachineSimulation *toCont = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toCont->cont();
    enSimButtons(toCont->getState());
}

void UserMachines::on_randTableBt_clicked()
{
    //this->setEnabled(false);
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
    addMachine(randMach);
    MachineSimulation *sim = new MachineSimulation(randMach);
    ui->tableSim->insertWidget(listMach.size(), sim);
    ui->tableSim->setCurrentIndex(listMach.size());
    sim->start();
    sim->display();
    enSimButtons(sim->getState());
}

void UserMachines::on_editTableBt_clicked()
{
    //this->setEnabled(false);
    EditMachines *edit = new EditMachines(listMach.at(ui->tableSim->currentIndex() - 1));
    edit->show();
    edit->loadTable();
    while (!edit->isReady()) {
            QThread::msleep(10);
            QCoreApplication::processEvents();
            if (!edit->isVisible()) {
                return;
            }
    }
    Machine *edited = edit->getEditMach();
    for (int i = 0; i < listMach.size(); i++) {
        if (listMach.at(i)->getFileName() == edited->getFileName()) {
            listMach.replace(i, edited);
        }
    }
    edit->close();
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->setMachine(edited);
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->display();
    enSimButtons("TableLoaded");
}
