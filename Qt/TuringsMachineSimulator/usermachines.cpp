#include "usermachines.h"
#include "ui_usermachines.h"

UserMachines::UserMachines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMachines)
{
    ui->setupUi(this);
    this->setWindowTitle("Turing's Machine Generator");
    QThreadPool::globalInstance()->setMaxThreadCount(8);

    // Seed generation for random numbers
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    // Getting the global Settings
    set = Settings::getInstance();
    connect(set, SIGNAL(loadPresetSgn(Machine*)), this, SLOT(loadPresetSlt(Machine*)));

    // Setting the possible states for the application
    states << "Init" << "TableLoaded" << "Sim" << "Pause";
    enSimButtons("Init");

    // Changing the machine view according to the table selected
    connect(ui->machList, SIGNAL(itemSelectionChanged()), this, SLOT(getMachToDispay()));
    connect(ui->machList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(getMachToDispay()));

    // Settings the initial buttons
    on_buttonSelect_currentIndexChanged(0);

    // Setting the icons for controlling simulation speed
    ui->slowerBt->setIcon(QIcon(QPixmap(":rec/icons/slower")));
    ui->slowerBt->setIconSize(QSize(19, 19));
    ui->fasterBt->setIcon(QIcon(QPixmap(":rec/icons/faster")));
    ui->fasterBt->setIconSize(QSize(19, 19));
    ui->pauseBt->setIcon(QIcon(QPixmap(":rec/icons/pauseBt")));
    ui->pauseBt->setIconSize(QSize(19, 19));
    ui->contBt->setIcon(QIcon(QPixmap(":rec/icons/play")));
    ui->contBt->setIconSize(QSize(19, 19));
    ui->stopBt->setIcon(QIcon(QPixmap(":rec/icons/stop")));
    ui->stopBt->setIconSize(QSize(19, 19));

    // Creating the Context Menus action for machine and tape deletion
    ui->machList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->machList, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showMachineContextMenu(const QPoint&)));
    ui->tapesList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tapesList, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showTapeContextMenu(const QPoint)));
}

UserMachines::~UserMachines()
{
    delete ui;
}

bool UserMachines::addMachine(Machine *toAdd)
{
    // Checking if machine already exists
    bool contains = false;
    foreach (Machine *mach, listMach)
    {
        if (mach->getFileName() == toAdd->getFileName())
        {
            contains = true;
        }
    }
    if (!contains)
    {
        // Creates machine item and adds it to the list
        listMach.append(toAdd);
        ui->machList->clearSelection();

        QListWidgetItem *machItem = new QListWidgetItem;
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

        machItem->setIcon(QIcon(":/rec/icons/table.png"));

        ui->machList->addItem(machItem);
        ui->machList->setItemWidget(machItem, widget);
        ui->machList->setIconSize(QSize(20, 20));

        ui->delayLb->setText(QString::number(set->getDelayTime()) + " ms");

        machItem->setSelected(true);
        return true;
    }
    else
    {
        return false;
    }
}

bool UserMachines::addTape(Tape *toAdd)
{
    // Checking if tape already exists
    bool contains = false;
    foreach (Tape *tape, listTape)
    {
        if (tape->getName() == toAdd->getName())
        {
            contains = true;
        }
    }
    if (!contains)
    {
        // Creates new tape item and adds it to the list
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
        QSignalMapper *sigMap = new QSignalMapper;
        connect(radio, SIGNAL(clicked(bool)), sigMap, SLOT(map()));
        sigMap->setMapping(radio, toAdd->getName());
        connect(sigMap, SIGNAL(mapped(QString)), SLOT(selTapeButtons(QString)));
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
    else
    {
        return false;
    }
}

void UserMachines::closeEvent(QCloseEvent *event)
{
    for (int i = 1; i < ui->tableSim->count(); i++)
    {
        dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i))->stop();
    }
    QWidget::closeEvent(event);
}

void UserMachines::delayUpdatedSlt(int delay)
{
    if (dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->getState() != "Sim")
    {
        ui->delayLb->setText(QString::number(delay*10) + " ms");
    }
}

void UserMachines::enSimButtons(QString state)
{
    switch(states.indexOf(state))
    {
        // Initial Case (No machines loaded)
        case 0:
        {
            ui->editBt->setEnabled(false);
            ui->saveBt->setEnabled(false);
            ui->simBt->setEnabled(false);
            ui->loadTapeBt->setEnabled(false);
            ui->selAllBt->setEnabled(false);
            ui->uSelAllBt->setEnabled(false);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(false);
            break;
        }
        // Machine is loaded
        case 1:
        {
            ui->editBt->setEnabled(true);
            ui->saveBt->setEnabled(true);
            ui->simBt->setEnabled(true);
            ui->loadTapeBt->setEnabled(true);
            ui->selAllBt->setEnabled(true);
            ui->uSelAllBt->setEnabled(true);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(false);
            break;
        }
        // Machine is simulating
        case 2:
        {
            ui->editBt->setEnabled(false);
            ui->saveBt->setEnabled(false);
            ui->simBt->setEnabled(true);
            ui->loadTapeBt->setEnabled(true);
            ui->selAllBt->setEnabled(true);
            ui->uSelAllBt->setEnabled(true);
            ui->pauseBt->setEnabled(true);
            ui->contBt->setEnabled(false);
            ui->stopBt->setEnabled(true);
            break;
        }
        // Machine is paused
        case 3:
        {
            ui->editBt->setEnabled(false);
            ui->saveBt->setEnabled(false);
            ui->simBt->setEnabled(true);
            ui->loadTapeBt->setEnabled(true);
            ui->selAllBt->setEnabled(true);
            ui->uSelAllBt->setEnabled(true);
            ui->pauseBt->setEnabled(false);
            ui->contBt->setEnabled(true);
            ui->stopBt->setEnabled(true);
            break;
        }
    }
}

void UserMachines::finishSim(QString tableName)
{
    for (int i = 0; i < listMach.size(); i++)
    {
        if (listMach.at(i)->getFileName() == tableName)
        {
            dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(3)->widget())->setEnabled(true);
            delete dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(4)->widget())->movie();
            QPixmap icon;
            if (dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i+1))->halted())
            {
                icon.load(":/rec/icons/check");
            }
            else
            {
                icon.load(":/rec/icons/question");
            }
            icon = icon.scaled(20, 20);
            dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(4)->widget())->clear();
            dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(4)->widget())->setPixmap(icon);
            break;
        }
    }
    if (selected == tableName)
    {
        enSimButtons("TableLoaded");
    }
}

void UserMachines::getMachToDispay()
{
    for (int i = 0; i < ui->machList->count(); i++)
    {
        if (ui->machList->item(i)->isSelected())
        {
            ui->tableSim->setCurrentIndex(i + 1);
            dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->resizeTable();
            enSimButtons(dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->getState());
            ui->delayLb->setText(QString::number(dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->getLocalDelay()*10) + " ms");
            break;
        }
    }
}

void UserMachines::loadPresetSlt(Machine* preset)
{
    if (addMachine(preset))
    {
        MachineSimulation *sim = new MachineSimulation(preset, listTape.at(0));
        connect(sim, SIGNAL(delayChangedSgn(int)), this, SLOT(delayUpdatedSlt(int)));
        ui->tableSim->insertWidget(listMach.size(), sim);
        ui->tableSim->setCurrentIndex(listMach.size());
        sim->start();
        sim->display();
        enSimButtons(sim->getState());
    }
}

bool UserMachines::machOrTape()
{
    return ui->buttonSelect->currentIndex() == 0;
}

void UserMachines::on_addBt_clicked()
{
    if (machOrTape())
    {
        // Initialize new Machine from file
        QString fileD = QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath(), "Text Files (*.txt);;All Files(*)");
        if (!(fileD == nullptr))
        {
            QFile *tableFile = new QFile(fileD);
            Machine *mach = new Machine(tableFile);
            if (addMachine(mach))
            {
                MachineSimulation *sim = new MachineSimulation(mach, listTape.at(0));
                connect(sim, SIGNAL(delayChangedSgn(int)), this, SLOT(delayUpdatedSlt(int)));
                ui->tableSim->insertWidget(listMach.size(), sim);
                ui->tableSim->setCurrentIndex(listMach.size());
                sim->start();
                sim->display();
                enSimButtons(sim->getState());
            }
        }
    }
    else
    {
        // Initailize new Tape from file
        Tape *tape;
        QString fileD = QFileDialog::getOpenFileName(this, "Open a Text File containing a Tape's Description", QDir::homePath(), "Text Files (*.txt);;All Files(*)");
        if (!(fileD == nullptr))
        {
            QFile *tapeFile = new QFile(fileD);
            tape = new Tape(tapeFile);
        }
        else return;
        addTape(tape);
    }
}

void UserMachines::on_buttonSelect_currentIndexChanged(int index)
{
    QString mOrT = (index == 0) ? "Machine" : "Tape";
    ui->addBt->setText("Add " + mOrT + " File");
    ui->editBt->setText("Edit " + mOrT);
    ui->saveBt->setText("Save " + mOrT);
    ui->qRandBt->setText("Add Quick Random " + mOrT);
    ui->cRandBt->setText("Add Custom Random " + mOrT);
}

void UserMachines::on_contBt_clicked()
{
    MachineSimulation *toCont = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toCont->cont();
    int index = ui->tableSim->currentIndex() - 1;
    QMovie *loading = new QMovie(":/rec/icons/spinner.gif");
    dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(index))->layout()->itemAt(4)->widget())->clear();
    dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(index))->layout()->itemAt(4)->widget())->setMovie(loading);
    loading->setScaledSize(QSize(20, 20));
    loading->start();
    enSimButtons(toCont->getState());
}

void UserMachines::on_cRandBt_clicked()
{
    if (machOrTape())
    {
        // Creates custom random machine
        RandomMachines *rand = new RandomMachines;
        rand->show();
        while (!rand->isReady())
        {
                QThread::msleep(10);
                QCoreApplication::processEvents();
                if (!rand->isVisible())
                {
                    return;
                }
        }
        Machine *randMach = rand->getRandMach();
        rand->close();
        addMachine(randMach);
        MachineSimulation *sim = new MachineSimulation(randMach, listTape.at(0));
        connect(sim, SIGNAL(delayChangedSgn(int)), this, SLOT(delayUpdatedSlt(int)));
        ui->tableSim->insertWidget(listMach.size(), sim);
        ui->tableSim->setCurrentIndex(listMach.size());
        sim->start();
        sim->display();
        enSimButtons(sim->getState());
    }
    else
    {
        // Creates custom random tape
        RandomTapes *rand = new RandomTapes;
        rand->show();
        while (!rand->isReady())
        {
                QThread::msleep(10);
                QCoreApplication::processEvents();
                if (!rand->isVisible())
                {
                    return;
                }
        }
        Tape *randTape = rand->getTape();
        rand->close();
        addTape(randTape);
    }
}

void UserMachines::on_editBt_clicked()
{
    if (machOrTape())
    {
        // Edits the selected machine
        EditMachines *edit = new EditMachines(listMach.at(ui->tableSim->currentIndex() - 1));
        edit->show();
        edit->loadTable();
        while (!edit->isReady())
        {
                QThread::msleep(10);
                QCoreApplication::processEvents();
                if (!edit->isVisible())
                {
                    return;
                }
        }
        Machine *edited = edit->getEditMach();
        for (int i = 0; i < listMach.size(); i++)
        {
            if (listMach.at(i)->getFileName() == edited->getFileName())
            {
                listMach.replace(i, edited);
            }
        }
        edit->close();
        dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->setMachine(edited);
        dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->display();
    }
    else
    {
        // Edits the selected machine's tape
        dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->editTape();
    }
}

void UserMachines::on_fasterBt_clicked()
{
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->increaseSpeed();
}

void UserMachines::on_loadTapeBt_clicked()
{
    Tape *toLoad;
    int tapeListIndex = 0;
    for (int i = 0; i < ui->tapesList->count(); i++)
    {
        if (dynamic_cast<QRadioButton*>(ui->tapesList->itemWidget(ui->tapesList->item(i))->layout()->itemAt(2)->widget())->isChecked())
        {
            toLoad = listTape.at(i);
            tapeListIndex = i;
            break;
        }
    }
    for (int i = 0; i < ui->machList->count(); i++)
    {
        if (dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(3)->widget())->isChecked())
        {
            QPixmap pix(*dynamic_cast<QLabel*>(ui->tapesList->itemWidget(ui->tapesList->item(tapeListIndex))->layout()->itemAt(3)->widget())->pixmap());
            dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(1)->widget())->setPixmap(pix);
            dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i + 1))->setTape(toLoad);
        }
    }
}

void UserMachines::on_pauseBt_clicked()
{
    MachineSimulation *toPause = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toPause->pause();
    int index = ui->tableSim->currentIndex() - 1;
    delete dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(index))->layout()->itemAt(4)->widget())->movie();
    QPixmap icon(":/rec/icons/pause");
    icon = icon.scaled(20, 20);
    dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(index))->layout()->itemAt(4)->widget())->clear();
    dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(index))->layout()->itemAt(4)->widget())->setPixmap(icon);
    enSimButtons(toPause->getState());
}

void UserMachines::on_qRandBt_clicked()
{
    if (machOrTape())
    {
        // Creates a quick random machine
        RandomMachines *rand = new RandomMachines;
        rand->quick();
        Machine *quick = rand->getRandMach();
        addMachine(quick);
        MachineSimulation *sim = new MachineSimulation(quick, listTape.at(0));
        connect(sim, SIGNAL(delayChangedSgn(int)), this, SLOT(delayUpdatedSlt(int)));
        ui->tableSim->insertWidget(listMach.size(), sim);
        ui->tableSim->setCurrentIndex(listMach.size());
        sim->start();
        sim->display();
        enSimButtons(sim->getState());
    }
    else
    {
        // Creates a quick random tape
        RandomTapes *rand = new RandomTapes;
        rand->quick();
        Tape *quick = rand->getTape();
        addTape(quick);
    }
}

void UserMachines::on_saveBt_clicked()
{
    if (machOrTape())
    {
        // Saves the selected machine
        QString fileName = QFileDialog::getSaveFileName(this, "Save Turing's Machine", QDir::homePath(), "Text Files (*.txt);;All Files(*)");
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
                qDebug() << "Error saving file";
                return;
        }
        QTextStream out(&file);
        Machine *toSave = listMach.at(ui->tableSim->currentIndex() - 1);
        out << "is: " << toSave->getInitState() << endl;
        out << "fs: " << toSave->getHaltState() << endl;
        QVector<QChar> *states = toSave->getStates();
        QVector<QChar> *symbols = toSave->getSymbols();
        out << "  *  ";
        for (int i = - 1; i < symbols->size(); i++)
        {
            if (i >= 0)
            {
                out << "  " << symbols->at(i) << "  ";
            }
            for (int j = 0; j < states->size(); j++)
            {
                if (i < 0)
                {
                    out << "  " << states->at(j) << "  ";
                }
                else {
                    out << " " << toSave->funct(states->at(j), symbols->at(i)) << " ";
                }
            }
            out << endl;
        }
        file.flush();
        file.close();
    }
    else
    {
        // Saves the selected machine's tape
        dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->saveTape();
    }
}

void UserMachines::on_selAllBt_clicked()
{
    for (int i = 0; i < ui->machList->count(); i++)
    {
        if (dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(3)->widget())->isEnabled())
        {
            dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(3)->widget())->setChecked(true);
        }
    }
}

void UserMachines::on_settingsBt_clicked()
{
    set->show();
}

void UserMachines::on_simBt_clicked()
{
    int index = ui->tableSim->currentIndex() - 1;
    if (dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(index))->layout()->itemAt(3)->widget())->isChecked())
    {
        enSimButtons("Sim");
    }
    for (int i = 0; i < ui->machList->count(); i++)
    {
        if (dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(3)->widget())->isChecked())
        {
            dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(3)->widget())->setChecked(false);
            dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(3)->widget())->setEnabled(false);
            dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i+1))->stop();

            QMovie *loading = new QMovie(":/rec/icons/spinner.gif");
            dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(4)->widget())->clear();
            dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(4)->widget())->setMovie(loading);
            loading->setScaledSize(QSize(20, 20));
            loading->start();

            MachineSimulation *toSim = dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i+1));

            QFutureWatcher<void> *watcher = new QFutureWatcher<void>;
            QFuture<void> fut = QtConcurrent::run(toSim, &MachineSimulation::simulate);
            watcher->setFuture(fut);

            QSignalMapper *sigMap = new QSignalMapper(this);
            connect(watcher, SIGNAL(finished()), sigMap, SLOT(map()));
            QString tableName = dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(0)->widget())->text();
            sigMap->setMapping(watcher, tableName);
            connect(sigMap, SIGNAL(mapped(QString)), this, SLOT(finishSim(QString)));
        }
    }
}

void UserMachines::on_slowerBt_clicked()
{
    dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget())->decreaseSpeed();
}

void UserMachines::on_stopBt_clicked()
{
    MachineSimulation *toStop = dynamic_cast<MachineSimulation*>(ui->tableSim->currentWidget());
    toStop->stop();
    int index = ui->tableSim->currentIndex() - 1;
    dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(index))->layout()->itemAt(3)->widget())->setEnabled(true);
    enSimButtons(toStop->getState());
}

void UserMachines::on_uSelAllBt_clicked()
{
    for (int i = 0; i < ui->machList->count(); i++)
    {
        dynamic_cast<QCheckBox*>(ui->machList->itemWidget(ui->machList->item(i))->layout()->itemAt(3)->widget())->setChecked(false);
    }
}

void UserMachines::selTapeButtons(QString name)
{
    for (int i = 0; i < ui->tapesList->count(); i++)
    {
        if (dynamic_cast<QLabel*>(ui->tapesList->itemWidget(ui->tapesList->item(i))->layout()->itemAt(0)->widget())->text() == name)
        {
            dynamic_cast<QRadioButton*>(ui->tapesList->itemWidget(ui->tapesList->item(i))->layout()->itemAt(2)->widget())->setChecked(true);
        }
        else
        {
            dynamic_cast<QRadioButton*>(ui->tapesList->itemWidget(ui->tapesList->item(i))->layout()->itemAt(2)->widget())->setChecked(false);
        }
    }
}

void UserMachines::showMachineContextMenu(const QPoint &pos)
{
    QModelIndex index = ui->machList->indexAt(pos);
    delete ui->machList->item(index.row());
    delete ui->tableSim->widget(index.row() + 1);
    listMach.remove(index.row());
    if (ui->machList->count() == 0)
    {
        enSimButtons("Init");
    }
}

void UserMachines::showTapeContextMenu(const QPoint &pos)
{
    QModelIndex mIndex = ui->tapesList->indexAt(pos);
    int index = mIndex.row();
    Tape *toDel = listTape.at(index);
    if (toDel->getName() != "Default")
    {
        for (int i = 1; i < ui->tableSim->count(); i++)
        {
            if (dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i))->getTape()->getName() == toDel->getName())
            {
                dynamic_cast<MachineSimulation*>(ui->tableSim->widget(i))->setTape(listTape.at(0));
                QPixmap pix(*dynamic_cast<QLabel*>(ui->tapesList->itemWidget(ui->tapesList->item(0))->layout()->itemAt(3)->widget())->pixmap());
                dynamic_cast<QLabel*>(ui->machList->itemWidget(ui->machList->item(i - 1))->layout()->itemAt(1)->widget())->setPixmap(pix);
            }
        }
        if (dynamic_cast<QRadioButton*>(ui->tapesList->itemWidget(ui->tapesList->item(index))->layout()->itemAt(2)->widget())->isChecked())
        {
            dynamic_cast<QRadioButton*>(ui->tapesList->itemWidget(ui->tapesList->item(0))->layout()->itemAt(2)->widget())->setChecked(true);
        }
        listTape.remove(index);
        delete ui->tapesList->item(index);
    }
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

    // Setting the default tape item
    addTape(new Tape(new QFile));
}
