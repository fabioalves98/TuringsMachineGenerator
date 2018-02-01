#include "usermachines.h"
#include "ui_usermachines.h"

UserMachines::UserMachines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMachines)
{
    ui->setupUi(this);
    this->setWindowTitle("Turing's Machine Generator");
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    QThreadPool::globalInstance()->setMaxThreadCount(8);

    // Getting the global Settings Settings
    set = Settings::getInstance();
    connect(set, SIGNAL(loadPresetSgn(Machine*)), this, SLOT(loadPresetSlt(Machine*)));
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
    sizes = ui->tapeSplit->sizes();
    sizes[0] = (int)ui->tapeSplit->width()*0.70;
    sizes[1] = (int)ui->tapeSplit->width()*0.30;
    ui->tapeSplit->setSizes(sizes);

    // Setting the default display
    MachineSimulation *newMach = new MachineSimulation(nullptr, nullptr);
    ui->tableSim->insertWidget(0, newMach);
    ui->tableSim->setCurrentIndex(0);
    newMach->start();
    newMach->setEnabled(false);
    ui->delayLb->setText("--- ms");

    // Setting the icons for controlling simulation speed
    QPixmap pixS(":rec/icons/slower");
    QIcon iconS(pixS);
    ui->slowerBt->setIcon(iconS);
    ui->slowerBt->setIconSize(QSize(19, 19));
    QPixmap pixF(":rec/icons/faster");
    QIcon iconF(pixF);
    ui->fasterBt->setIcon(iconF);
    ui->fasterBt->setIconSize(QSize(19, 19));
    QPixmap pixP(":rec/icons/pauseBt");
    QIcon iconP(pixP);
    ui->pauseBt->setIcon(iconP);
    ui->pauseBt->setIconSize(QSize(19, 19));
    QPixmap pixC(":rec/icons/play");
    QIcon iconC(pixC);
    ui->contBt->setIcon(iconC);
    ui->contBt->setIconSize(QSize(19, 19));
    QPixmap pixH(":rec/icons/stop");
    QIcon iconH(pixH);
    ui->stopBt->setIcon(iconH);
    ui->stopBt->setIconSize(QSize(19, 19));

    // Settings the initial buttons
    on_buttonSelect_currentIndexChanged(0);

    // Setting the default tape item
    addTape(new Tape(new QFile));

    // Setting the possible states for the application
    states << "Init" << "TableLoaded" << "Sim" << "Pause";
    enSimButtons("Init");

    // Changing the machine view according to the table selected
    connect(ui->tablesList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(getMachToDispay(QListWidgetItem*)));
}

void UserMachines::closeEvent(QCloseEvent *event) {
    close();
    QWidget::closeEvent(event);
}

void UserMachines::loadPresetSlt(Machine* preset)
{
    if (addMachine(preset)) {
        MachineSimulation *sim = new MachineSimulation(preset, listTape.at(0));
        connect(sim, SIGNAL(delayChanged(int)), this, SLOT(delayUpdated(int)));
        ui->tableSim->insertWidget(listMach.size(), sim);
        ui->tableSim->setCurrentIndex(listMach.size());
        sim->start();
        sim->display();
        enSimButtons(sim->getState());
    }
}

void UserMachines::close() {
    for (int i = 1; i < ui->tableSim->count(); i++) {
        dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i))->stop();
    }
}

void UserMachines::on_addTableBt_clicked()
{
    if (machOrTape()) {
        // Initialize new Table, and display it
        QString fileD = QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath(), "Text Files (*.txt);;All Files(*)");
        if (!(fileD == nullptr)) {
            QFile *tableFile = new QFile(fileD);
            Machine *mach = new Machine(tableFile);
            if (addMachine(mach)) {
                MachineSimulation *sim = new MachineSimulation(mach, listTape.at(0));
                connect(sim, SIGNAL(delayChanged(int)), this, SLOT(delayUpdated(int)));
                ui->tableSim->insertWidget(listMach.size(), sim);
                ui->tableSim->setCurrentIndex(listMach.size());
                sim->start();
                sim->display();
                enSimButtons(sim->getState());
            }
        }
    }
    else {
        Tape *tape;
        QString fileD = QFileDialog::getOpenFileName(this, "Open a Text File containing a Tape's Description", QDir::homePath(), "Text Files (*.txt);;All Files(*)");
        if (!(fileD == nullptr)) {
            QFile *tapeFile = new QFile(fileD);
            tape = new Tape(tapeFile);
        }
        else return;
        addTape(tape);
    }
}

void UserMachines::on_uselAllBt_clicked()
{
    for (int i = 0; i < ui->tablesList->count(); i++) {
        dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->setChecked(true);
    }
}

void UserMachines::on_selAllBt_clicked()
{
    for (int i = 0; i < ui->tablesList->count(); i++) {
        dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->setChecked(false);
    }
}

void UserMachines::on_simBt_clicked()
{
    int index = ui->tableSim->currentIndex() - 1;
    if (dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(3)->widget())->isChecked()) {
        enSimButtons("Sim");
    }
    for (int i = 0; i < ui->tablesList->count(); i++) {
        if (dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->isChecked()) {
            dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->setChecked(false);
            dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->setEnabled(false);
            dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i+1))->stop();
            QThread::msleep(20);
            QCoreApplication::processEvents();

            QMovie *loading = new QMovie(":/rec/icons/spinner.gif");
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(4)->widget())->clear();
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(4)->widget())->setMovie(loading);
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
            dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->setEnabled(true);
            delete dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(4)->widget())->movie();
            QPixmap icon;
            if (dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i+1))->halted()) {
                icon.load(":/rec/icons/check");
            }
            else {
                icon.load(":/rec/icons/question");
            }
            icon = icon.scaled(20, 20);
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(4)->widget())->clear();
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(4)->widget())->setPixmap(icon);
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
            ui->delayLb->setText(QString::number(dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->getLocalDelay()*10) + " ms");
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

        QPixmap pix(*dynamic_cast<QLabel*>(ui->tapesList->itemWidget(ui->tapesList->item(0))->layout()->itemAt(3)->widget())->pixmap());
        QLabel *tapeIcon = new QLabel;
        tapeIcon->setPixmap(pix);
        layout->addWidget(tapeIcon);

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

        ui->delayLb->setText(QString::number(set->getDelayTime()) + " ms");

        tableItem->setSelected(true);
        return true;
    }
    else {
        return false;
    }
}

bool UserMachines::addTape(Tape *toAdd)
{
    bool contains = false;
    foreach (Tape *tape, listTape) {
        if (tape->getName() == toAdd->getName()) {
            contains = true;
        }
    }
    if (!contains) {
        listTape.append(toAdd);
        ui->tapesList->clearSelection();
        QListWidgetItem *tapeItem = new QListWidgetItem;

        QWidget *widget = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;

        QLabel *tapeName = new QLabel(toAdd->getName());
        tapeName->setFont(QFont("Meiryo", 11));
        layout->addWidget(tapeName);

        layout->addStretch();

        QRadioButton *radio = new QRadioButton();
        QSignalMapper *sigMap = new QSignalMapper(this);
        connect(radio, SIGNAL(clicked(bool)), sigMap, SLOT(map()));
        sigMap->setMapping(radio, ui->tapesList->count());
        connect(sigMap, SIGNAL(mapped(int)), SLOT(selTapeButtons(int)));
        layout->addWidget(radio);
        radio->click();

        QPixmap myPix(QSize(20,20));
        myPix.fill(QColor(0, 0, 0, 0));
        QPainter painter(&myPix);
        int r = qrand() % 255;
        int g = qrand() % 255;
        int b = qrand() % 255;
        painter.setBrush(QColor(r, g, b));
        painter.drawEllipse(QPoint(10, 9), 7, 7);
        QLabel *label = new QLabel;
        label->setPixmap(myPix);
        layout->addWidget(label);

        layout->setMargin(0);
        widget->setLayout(layout);

        tapeItem->setIcon(QIcon(":rec/icons/tape.png"));
        tapeItem->setFlags(Qt::ItemIsEnabled);

        ui->tapesList->addItem(tapeItem);
        ui->tapesList->setItemWidget(tapeItem, widget);
        ui->tapesList->setIconSize(QSize(20, 20));
        return true;
    }
    else {
        return false;
    }
}

bool UserMachines::machOrTape()
{
    return ui->buttonSelect->currentIndex() == 0;
}

void UserMachines::enSimButtons(QString state) {
    switch(states.indexOf(state)) {
        case 0: {
            ui->editTableBt->setEnabled(false);
            ui->saveTableBt->setEnabled(false);
            ui->simBt->setEnabled(false);
            ui->selAllBt->setEnabled(false);
            ui->uselAllBt->setEnabled(false);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(false);
            break;
        }
        case 1: {
            ui->editTableBt->setEnabled(true);
            ui->saveTableBt->setEnabled(true);
            ui->simBt->setEnabled(true);
            ui->selAllBt->setEnabled(true);
            ui->uselAllBt->setEnabled(true);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(false);
            break;
        }
        case 2: {
            ui->editTableBt->setEnabled(false);
            ui->saveTableBt->setEnabled(false);
            ui->simBt->setEnabled(true);
            ui->selAllBt->setEnabled(true);
            ui->uselAllBt->setEnabled(true);
            ui->pauseBt->setEnabled(true);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(true);
            break;
        }
        case 3: {
            ui->editTableBt->setEnabled(false);
            ui->saveTableBt->setEnabled(false);
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
    dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(3)->widget())->setEnabled(true);
    enSimButtons(toStop->getState());
}

void UserMachines::on_pauseBt_clicked()
{
    MachineSimulation *toPause = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toPause->pause();
    int index = ui->tableSim->currentIndex() - 1;
    delete dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(4)->widget())->movie();
    QPixmap icon(":/rec/icons/pause");
    icon = icon.scaled(20, 20);
    dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(4)->widget())->clear();
    dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(4)->widget())->setPixmap(icon);
    enSimButtons(toPause->getState());
}

void UserMachines::on_contBt_clicked()
{
    MachineSimulation *toCont = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toCont->cont();
    int index = ui->tableSim->currentIndex() - 1;
    QMovie *loading = new QMovie(":/rec/icons/spinner.gif");
    dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(4)->widget())->clear();
    dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(index))->layout()->itemAt(4)->widget())->setMovie(loading);
    loading->setScaledSize(QSize(20, 20));
    loading->start();
    enSimButtons(toCont->getState());
}

void UserMachines::on_cRandTableBt_clicked()
{
    if (machOrTape()) {
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
        MachineSimulation *sim = new MachineSimulation(randMach, listTape.at(0));
        connect(sim, SIGNAL(delayChanged(int)), this, SLOT(delayUpdated(int)));
        ui->tableSim->insertWidget(listMach.size(), sim);
        ui->tableSim->setCurrentIndex(listMach.size());
        sim->start();
        sim->display();
        enSimButtons(sim->getState());
    }
    else {
        RandomTapes *rand = new RandomTapes;
        rand->show();
        while (!rand->isReady()) {
                QThread::msleep(10);
                QCoreApplication::processEvents();
                if (!rand->isVisible()) {
                    this->setEnabled(true);
                    return;
                }
        }
        Tape *randTape = rand->getTape();
        rand->close();
        addTape(randTape);
    }
}

void UserMachines::on_qRandTableBt_clicked()
{
    if (machOrTape()) {
        RandomMachines *rand = new RandomMachines;
        rand->quick();
        Machine *quick = rand->getRandMach();
        addMachine(quick);
        MachineSimulation *sim = new MachineSimulation(quick, listTape.at(0));
        connect(sim, SIGNAL(delayChanged(int)), this, SLOT(delayUpdated(int)));
        ui->tableSim->insertWidget(listMach.size(), sim);
        ui->tableSim->setCurrentIndex(listMach.size());
        sim->start();
        sim->display();
        enSimButtons(sim->getState());
    }
    else {
        RandomTapes *rand = new RandomTapes;
        rand->quick();
        Tape *quick = rand->getTape();
        addTape(quick);
    }
}

void UserMachines::on_editTableBt_clicked()
{
    if (machOrTape()) {
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
    }
    else {
        dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->editTape();
    }
}

void UserMachines::selTapeButtons(int item) {
    for (int i = 0; i < ui->tapesList->count(); i++) {
        if (i == item) {
            dynamic_cast<QRadioButton*>(ui->tapesList->itemWidget(ui->tapesList->item(i))->layout()->itemAt(2)->widget())->setChecked(true);
        }
        else {
            dynamic_cast<QRadioButton*>(ui->tapesList->itemWidget(ui->tapesList->item(i))->layout()->itemAt(2)->widget())->setChecked(false);
        }
    }
}

void UserMachines::on_loadTapeBt_clicked()
{
    Tape *toLoad;
    int tapeListIndex = 0;
    for (int i = 0; i < ui->tapesList->count(); i++) {
        if (dynamic_cast<QRadioButton*>(ui->tapesList->itemWidget(ui->tapesList->item(i))->layout()->itemAt(2)->widget())->isChecked()) {
            toLoad = listTape.at(i);
            tapeListIndex = i;
            break;
        }
    }
    for (int i = 0; i < ui->tablesList->count(); i++) {
        if (dynamic_cast<QCheckBox*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(3)->widget())->isChecked()) {
            QPixmap pix(*dynamic_cast<QLabel*>(ui->tapesList->itemWidget(ui->tapesList->item(tapeListIndex))->layout()->itemAt(3)->widget())->pixmap());
            dynamic_cast<QLabel*>(ui->tablesList->itemWidget(ui->tablesList->item(i))->layout()->itemAt(1)->widget())->setPixmap(pix);
            dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i + 1))->setTape(toLoad);
        }
    }
}

void UserMachines::on_saveTableBt_clicked()
{
    if (machOrTape()) {
        QString fileName = QFileDialog::getSaveFileName(this, "Save Turing's Machine", QDir::homePath(), "Text Files (*.txt);;All Files(*)");
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
                qDebug() << "Error saving file";
                return;
        }
        QTextStream out(&file);
        Machine *toSave = listMach.at(ui->tableSim->currentIndex() - 1);
        out << "begin_info" << endl;
        out << "bs: " << toSave->getBlanckSym() << endl;
        out << "is: " << toSave->getInitState() << endl;
        out << "fs: " << toSave->getHaltState() << endl;
        out << "begin_table" << endl;
        QVector<QChar> *states = toSave->getStates();
        QVector<QChar> *symbols = toSave->getSymbols();
        out << "  *  ";
        for (int i = - 1; i < symbols->size(); i++) {
            if (i >= 0) out << "  " << symbols->at(i) << "  ";
            for (int j = 0; j < states->size(); j++) {
                if (i < 0) {
                    out << "  " << states->at(j) << "  ";
                }
                else {
                    out << " " << toSave->funct(states->at(j), symbols->at(i)) << " ";
                }
            }
            out << endl;
        }
        out << "end_table";
        file.flush();
        file.close();
    }
    else {
        dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->saveTape();
    }
}

void UserMachines::on_settingsBt_clicked()
{
    set->show();
}

void UserMachines::on_slowerBt_clicked()
{
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->decreaseSpeed();
}

void UserMachines::on_fasterBt_clicked()
{
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->increaseSpeed();
}

void UserMachines::delayUpdated(int delay)
{
    ui->delayLb->setText(QString::number(delay*10) + " ms");
}

void UserMachines::on_buttonSelect_currentIndexChanged(int index)
{
    switch(index) {
    case 0: {
        ui->addTableBt->setText("Add Machine File");
        ui->editTableBt->setText("Edit Machine");
        ui->saveTableBt->setText("Save Machine");
        ui->qRandTableBt->setText("Add Quick Random Machine");
        ui->cRandTableBt->setText("Add Custom Random Machine");
        break;
    }
    case 1: {
        ui->addTableBt->setText("Add Tape File");
        ui->editTableBt->setText("Edit Tape");
        ui->saveTableBt->setText("Save Tape");
        ui->qRandTableBt->setText("Add Quick Random Tape");
        ui->cRandTableBt->setText("Add Custom Random Tape");
        break;
    }
    }
}
