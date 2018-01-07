#include "usermachines.h"
#include "ui_usermachines.h"

UserMachines::UserMachines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMachines)
{
    ui->setupUi(this);
    QThreadPool::globalInstance()->setMaxThreadCount(8);
}

UserMachines::~UserMachines()
{
    delete ui;
}

void UserMachines::start()
{
    // Setting the size of the table list container
    QList<int> sizes = ui->listSplit->sizes();
    sizes[0] = (int)ui->listSplit->width()*0.25;
    sizes[1] = (int)ui->listSplit->width()*0.75;
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
        if (addMachine(mach)) {
            MachineSimulation *sim = new MachineSimulation(mach);
            ui->tableSim->insertWidget(listMach.size(), sim);
            ui->tableSim->setCurrentIndex(listMach.size());
            sim->start();
            sim->display();
            enSimButtons(sim->getState());
        }
    }
}

void UserMachines::on_uselAllBt_clicked()
{
    for (int i = 0; i < ui->tablesList->count(); i++) {
        dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(2)->widget())->setChecked(true);
    }
}

void UserMachines::on_selAllBt_clicked()
{
    for (int i = 0; i < ui->tablesList->count(); i++) {
        dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(2)->widget())->setChecked(false);
    }
}

void UserMachines::on_simBt_clicked()
{
    int index = ui->tableSim->currentIndex() - 1;
    if (dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(2)->widget())->isChecked()) {
        enSimButtons("Sim");
    }
    for (int i = 0; i < ui->tablesList->count(); i++) {
        if (dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(2)->widget())->isChecked()) {
            dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(2)->widget())->setChecked(false);
            dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(2)->widget())->setEnabled(false);
            dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i+1))->stop();
            QThread::msleep(20);
            QCoreApplication::processEvents();

            QMovie *loading = new QMovie(":/rec/icons/spinner.gif");
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->clear();
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->setMovie(loading);
            loading->setScaledSize(QSize(20, 20));
            loading->start();

            MachineSimulation *toSim = dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i+1));

            QFutureWatcher<void> *watcher = new QFutureWatcher<void>;
            QFuture<void> fut = QtConcurrent::run(toSim, &MachineSimulation::simulate);
            watcher->setFuture(fut);

            QSignalMapper *sigMap = new QSignalMapper(this);
            connect(watcher, SIGNAL(finished()), sigMap, SLOT(map()));
            QString tableName = dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(0)->widget())->text();
            sigMap->setMapping(watcher, tableName);
            connect(sigMap, SIGNAL(mapped(QString)), this, SLOT(finishSim(QString)));
        }
    }
}

void UserMachines::finishSim(QString tableName) {    
    for (int i = 0; i < listMach.size(); i++) {
        if (listMach.at(i)->getFileName() == tableName) {
            dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(2)->widget())->setEnabled(true);
            delete dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->movie();
            QPixmap icon;
            if (dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i+1))->halted()) {
                icon.load(":/rec/icons/check");
            }
            else {
                icon.load(":/rec/icons/question");
            }
            icon = icon.scaled(20, 20);
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->clear();
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->setPixmap(icon);
            break;
        }
    }
    if (selected == tableName) {
        enSimButtons("TableLoaded");
    }
}

void UserMachines::getMachToDispay(QListWidgetItem *item) {
    for (int i = 0; i < listMach.size(); i++) {
        if (listMach.at(i)->getFileName() == dynamic_cast<QLabel*>(ui->tablesList->itemWidget(item)->layout()->itemAt(0)->widget())->text()) {
            selected = dynamic_cast<QLabel*>(ui->tablesList->itemWidget(item)->layout()->itemAt(0)->widget())->text();
            ui->tableSim->setCurrentIndex(i + 1);
            dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->resizeTable();
            enSimButtons(dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->getState());
            break;
        }
    }
}

bool UserMachines::addMachine(Machine *toAdd) {
    // Get the name of the table, list it in the TablesList
    bool contains = false;
    foreach (Machine *mach, listMach) {
        if (mach->getFileName() == toAdd->getFileName()) {
            contains = true;
        }
    }
    if (!contains) {
        listMach.append(toAdd);
        ui->tablesList->clearSelection();
        QListWidgetItem *tableItem = new QListWidgetItem;

        QWidget *widget = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;

        selected = toAdd->getFileName();
        QLabel *tableName = new QLabel(selected);
        tableName->setFont(QFont("Meiryo", 11));
        layout->addWidget(tableName);

        layout->addStretch();

        QCheckBox *check = new QCheckBox;
        layout->addWidget(check);

        QLabel *label = new QLabel;
        QPixmap icon(":/rec/icons/question");
        icon = icon.scaled(20, 20);
        label->setPixmap(icon);
        layout->addWidget(label);

        layout->addSpacing(3);
        layout->setMargin(0);

        widget->setLayout(layout);

        tableItem->setIcon(QIcon(":/rec/icons/table.png"));

        ui->tablesList->addItem(tableItem);
        ui->tablesList->setItemWidget(tableItem, widget);
        ui->tablesList->setIconSize(QSize(20, 20));

        tableItem->setSelected(true);
        return true;
    }
    else {
        return false;
    }
}

void UserMachines::enSimButtons(QString state) {
    switch(states.indexOf(state)) {
        case 0: {
            ui->addTableBt->setEnabled(true);
            ui->editTableBt->setEnabled(false);
            ui->cRandTableBt->setEnabled(true);
            ui->qRandTableBt->setEnabled(true);
            ui->simBt->setEnabled(false);
            ui->selAllBt->setEnabled(false);
            ui->uselAllBt->setEnabled(false);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(false);
            break;
        }
        case 1: {
            ui->addTableBt->setEnabled(true);
            ui->editTableBt->setEnabled(true);
            ui->cRandTableBt->setEnabled(true);
            ui->qRandTableBt->setEnabled(true);
            ui->simBt->setEnabled(true);
            ui->selAllBt->setEnabled(true);
            ui->uselAllBt->setEnabled(true);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(false);
            break;
        }
        case 2: {
            ui->addTableBt->setEnabled(true);
            ui->editTableBt->setEnabled(false);
            ui->cRandTableBt->setEnabled(true);
            ui->qRandTableBt->setEnabled(true);
            ui->simBt->setEnabled(true);
            ui->selAllBt->setEnabled(true);
            ui->uselAllBt->setEnabled(true);
            ui->pauseBt->setEnabled(true);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(true);
            break;
        }
        case 3: {
            ui->addTableBt->setEnabled(false);
            ui->editTableBt->setEnabled(false);
            ui->cRandTableBt->setEnabled(true);
            ui->qRandTableBt->setEnabled(true);
            ui->simBt->setEnabled(true);
            ui->selAllBt->setEnabled(true);
            ui->uselAllBt->setEnabled(true);
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
    int index = ui->tableSim->currentIndex() - 1;
    dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(2)->widget())->setEnabled(true);
    enSimButtons(toStop->getState());
}

void UserMachines::on_pauseBt_clicked()
{
    MachineSimulation *toPause = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toPause->pause();
    int index = ui->tableSim->currentIndex() - 1;
    delete dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(3)->widget())->movie();
    QPixmap icon(":/rec/icons/pause");
    icon = icon.scaled(20, 20);
    dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(3)->widget())->clear();
    dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(3)->widget())->setPixmap(icon);
    enSimButtons(toPause->getState());

}

void UserMachines::on_contBt_clicked()
{
    MachineSimulation *toCont = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toCont->cont();
    int index = ui->tableSim->currentIndex() - 1;
    QMovie *loading = new QMovie(":/rec/icons/spinner.gif");
    dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(3)->widget())->clear();
    dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(3)->widget())->setMovie(loading);
    loading->setScaledSize(QSize(20, 20));
    loading->start();
    enSimButtons(toCont->getState());

}

void UserMachines::on_cRandTableBt_clicked()
{
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

void UserMachines::on_qRandTableBt_clicked()
{
    RandomMachines *rand = new RandomMachines;
    rand->quick(2, 10, 2, 10);
    Machine *quick = rand->getRandMach();
    addMachine(quick);
    MachineSimulation *sim = new MachineSimulation(quick);
    ui->tableSim->insertWidget(listMach.size(), sim);
    ui->tableSim->setCurrentIndex(listMach.size());
    sim->start();
    sim->display();
    enSimButtons(sim->getState());
}

void UserMachines::on_editTableBt_clicked()
{
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
