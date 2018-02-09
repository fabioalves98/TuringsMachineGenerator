#include "machinesimulation.h"
#include "ui_machinesimulation.h"

MachineSimulation::MachineSimulation(Machine *mach, Tape *tape, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MachineSimulation),
    mach(mach),
    defTape(tape)
{
    ui->setupUi(this);

    // Gettings the global Settings
    set = Settings::getInstance();
    connect(set, SIGNAL(delayChangedSgn(int)), this, SLOT(updateDelaySlt(int)));
    localDelayFormat = set->getDelayTime()/10;
    if (defTape != nullptr)
    {
        setTape(defTape);
    }

    // Disabling selection in table view
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);

    // Enabling or Disabling scroll bars
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

    // Adding the single item to teh state list
    ui->stateList->addItem(new QListWidgetItem);

    // Conecting the signals for table resize
    connect(ui->specSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));
    connect(ui->tableSplit, SIGNAL(splitterMoved(int,int)), this, SLOT(resizeTable()));

    // Synchronizing scroll bars
    connect(ui->statesList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->simList->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->simList->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->statesList->verticalScrollBar(), SLOT(setValue(int)));

    // Connecting Ui signals and slots
    connect(this, SIGNAL(updateUiSgn(int,int,QString,QString,QString)), this, SLOT(updateUiSlt(int,int,QString,QString,QString)));
    connect(this, SIGNAL(changeStatusSgn(QString)), this, SLOT(changeStatusSlt(QString)));
    statusBar()->showMessage("No Status");
}

MachineSimulation::~MachineSimulation()
{
    haltSim = true;
    delete ui;    
}

void MachineSimulation::changeStatusSlt(QString status)
{
    // Changes the content of the status bar
    statusBar()->showMessage(status);
}

void MachineSimulation::clearUi()
{
    ui->simList->clear();
    ui->statesList->clear();
    ui->tapeList->clear();
    ui->stateList->setItemWidget(ui->stateList->item(0), new QLabel(""));
}

void MachineSimulation::cont()
{
    // Changes the signals to continue the simulation
    state = "Simulating";
    pauseSim = false;
}

void MachineSimulation::decreaseSpeed()
{
    // Increases the simulatin delay
    if (localDelayFormat < 5)
    {
        localDelayFormat++;
    }
    else
    {
        localDelayFormat = localDelayFormat * 1.2;
    }
    emit delayChangedSgn(localDelayFormat);
}

void MachineSimulation::displayMachine()
{
    // Displays the machine's description and properties
    ui->tableView->clear();
    QVector<QChar> *symbols = mach->getSymbols();
    QVector<QChar> *states = mach->getStates();
    ui->tableView->setRowCount(symbols->size());
    ui->tableView->setColumnCount(states->size());
    for (int i = 0, k = 0; i < symbols->size(); i++)
    {
        QTableWidgetItem *vHeader = new QTableWidgetItem(symbols->at(i));
        vHeader->setFont(QFont("Meiryo", 11));
        ui->tableView->setVerticalHeaderItem(i, vHeader);
        for (int j = 0; j < states->size(); j++, k++)
        {
            if (i == 0)
            {
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

    ui->machPropList->clear();
    QStringList properties;
    properties << " Name: " << " Symbols: " << " States: " << " Inicial State: " << " Halt State: ";
    for (QString prop : properties) {
        QListWidgetItem *newProI = new QListWidgetItem;
        QWidget *newProW = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;
        QLabel *propName = new QLabel;
        propName->setText(prop);
        propName->setFont(QFont("Meiryo", 11, QFont::Bold));
        layout->addWidget(propName);
        QLabel *propValue = new QLabel;
        switch(properties.indexOf(prop))
        {
            case 0:
            {
                propValue->setText(mach->getFileName());
                break;
            }
            case 1:
            {
                QString *symbolsStr = new QString;
                for (QChar symbol : *mach->getSymbols())
                {
                    symbolsStr->append(symbol);
                    symbolsStr->append((" "));
                }
                propValue->setText(*symbolsStr);
                break;
            }
            case 2:
            {
                QString *statesStr = new QString;
                for (QChar state : *mach->getStates())
                {
                    statesStr->append(state);
                    statesStr->append((" "));
                }
                propValue->setText(*statesStr);
                break;
            }
            case 3:
            {
                QString iSt(mach->getInitState());
                propValue->setText(iSt);
                break;
            }
            case 4:
            {
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
        ui->machPropList->addItem(newProI);
        ui->machPropList->setItemWidget(newProI, newProW);
    }
    displayTape();
    machIsLoaded = true;
    resizeTable();
    state = "Machine Loaded";
    changeStatusSlt("Machine is Loaded");
}

void MachineSimulation::displayTape()
{
    // Displays the tape's description and properties
    ui->headPos->setValue(tempHeadPos);
    if (tempHeadPos<= 0)
    {
        tempHeadPos = 1;
    }
    std::list<QChar>::iterator tapeIt = tempTape.begin();
    QString tapeStr;
    int offset = tempTape.size()/2 - tempHeadPos;
    for (int i = 0; i < tempTape.size(); i++)
    {
        if (i == tempHeadPos) tapeStr.append(" |");
        tapeStr.append(*tapeIt);;
        if (i == tempHeadPos) tapeStr.append("| ");
        tapeIt++;
    }
    if (tempTape.size() % 2 == 0)
    {
        tapeStr.append(" ");
    }
    if (offset > 0)
    {
        for (int i = 0; i < abs(offset); i++)
        {
            tapeStr.prepend("  ");
        }
    }
    else if (offset < 0)
    {
        for (int i = 0; i < abs(offset); i++)
        {
            tapeStr.append("  ");
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

    ui->tapePropList->clear();
    QStringList properties;
    properties << " Name: " << " Size: " << " Blanck Symbol: ";
    for (QString prop : properties)
    {
        QListWidgetItem *newProI = new QListWidgetItem;
        QWidget *newProW = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;
        QLabel *propName = new QLabel;
        propName->setText(prop);
        propName->setFont(QFont("Meiryo", 11, QFont::Bold));
        layout->addWidget(propName);
        QLabel *propValue = new QLabel;
        switch(properties.indexOf(prop))
        {
            case 0:
            {
                if (tapeEdited)
                {
                    propValue->setText(defTape->getName() + " - Edited");
                }
                else
                {
                    propValue->setText(defTape->getName());
                }
                break;
            }
            case 1:
            {
                propValue->setText(QString::number(tempTape.size()));
                break;
            }
            case 2:
            {
                propValue->setText(QString(blanckSym));
                break;
            }
        }
        propValue->setFont(QFont("Meiryo", 11));
        layout->addWidget(propValue, Qt::AlignLeft);
        layout->setMargin(0);
        newProW->setLayout(layout);
        newProI->setSizeHint(QSize(0, 25));
        newProI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
        ui->tapePropList->addItem(newProI);
        ui->tapePropList->setItemWidget(newProI, newProW);
    }
}

void MachineSimulation::editTape()
{
    // Opens the tape edition window to edit the selected machine's tape
    EditTapes *edit = new EditTapes(tempTape, blanckSym);
    edit->show();
    edit->loadTape();
    while (!edit->isReady())
    {
        QThread::msleep(10);
        QCoreApplication::processEvents();
        if (!edit->isVisible())
        {
            return;
        }
    }
    if (edit->isEdited())
    {
        tapeEdited = true;
        editedTape = edit->getTape();
        blanckSym = edit->getBlanckSym();
        on_headPos_valueChanged(editedTape.size()/2);
    }
    else
    {
        setTape(defTape);
    }
    edit->close();
}

int MachineSimulation::getLocalDelay()
{
    // Returns the custom delay value
    return int(localDelayFormat);
}

QString MachineSimulation::getState()
{
    // Returns the state of the machne
    return state;
}

Tape *MachineSimulation::getTape()
{
    // Returns the tape object
    return defTape;
}

bool MachineSimulation::halted()
{
    // Checks if the machine halted
    return halts;
}

void MachineSimulation::increaseSpeed()
{
    // Decreases the simulation delay
    if (localDelayFormat < 5 && localDelayFormat > 0)
    {
        localDelayFormat--;
    }
    else
    {
        localDelayFormat = localDelayFormat * 0.8;
    }
    emit delayChangedSgn(localDelayFormat);
}

void MachineSimulation::insertStateSlt(QString state)
{
    // Inserts the last iteration's state into the state list
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

void MachineSimulation::insertTapeSlt(QString toUpdate)
{
    // Inserts the last iteration's tape into the tape history list
    QListWidgetItem *simTextI = new QListWidgetItem;
    QLabel *simText = new QLabel;
    simText->setText(toUpdate);
    simText->setFont(QFont("Courier", 12, QFont::Bold));
    simText->setAlignment(Qt::AlignCenter);
    simTextI->setSizeHint(simText->sizeHint());
    simTextI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
    ui->simList->addItem(simTextI);
    ui->simList->setItemWidget(simTextI, simText);
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

bool MachineSimulation::machHalted(int iterations)
{
    // Checks if the mahcine halted
    if (mach->halted())
    {
        emit changeStatusSgn("The machine halted after " + QString::number(iterations) + " iterations");
        state = "Machine Loaded";
        halts = true;
        return true;
    }
    else if (haltSim)
    {
        emit changeStatusSgn("The machine halted by user's order. Iterations: " + QString::number(iterations));
        state = "Machine Loaded";
        return true;
    }
    else if ((iterations > set->getIterTilHalt()) && set->getHaltInXIt())
    {
        emit changeStatusSgn("The machine reached maximum number of iterations: " + QString::number(iterations));
        state = "Machine Loaded";
        return true;
    }
    else
    {
        return false;
    }
}

void MachineSimulation::on_headPos_valueChanged(int arg1)
{
    // Changes the position of the machine's head in the tape
    if (tapeEdited)
    {
        tempHeadPos = arg1;
        tempTape = editedTape;
        if (signed(tempHeadPos) >= signed(tempTape.size() - 1))
        {
            for (int i = tempTape.size() - 1; i <= tempHeadPos; i++)
            {
                tempTape.push_back(blanckSym);
            }
        }
        else if (tempHeadPos <= 0)
        {
            for (int i = tempHeadPos; i <= 0; i++)
            {
                tempTape.push_front(blanckSym);
            }
        }
    }
    else
    {
        tempHeadPos = arg1;
        tempTape = defTape->getTape();
        if (signed(tempHeadPos) >= signed(tempTape.size() - 1))
        {
            for (int i = tempTape.size() - 1; i <= tempHeadPos; i++)
            {
                tempTape.push_back(blanckSym);
            }
        }
        else if (tempHeadPos <= 0)
        {
            for (int i = tempHeadPos; i <= 0; i++)
            {
                tempTape.push_front(blanckSym);
            }
        }
    }
    displayTape();
}

void MachineSimulation::pause()
{
    // Pauses the simulation
    QString message = statusBar()->currentMessage();
    statusBar()->showMessage("Paused" + message.split("Simulating").at(1));
    state = "Pause";
    pauseSim = true;
}

void MachineSimulation::resizeEvent(QResizeEvent *event)
{
    // Is called whenever the window is resized
    resizeTable();
    update();
    QWidget::resizeEvent(event);
}

void MachineSimulation::resizeTable()
{
	// Resizes the table acording to the container dimenssions
    if (machIsLoaded)
    {
        int rowHeigth = (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/ui->tableView->rowCount();
        int columnWidth = (ui->tableView->width() - ui->tableView->verticalHeader()->width())/ui->tableView->columnCount();
        int horExccess = (ui->tableView->width() - ui->tableView->verticalHeader()->width()) - ui->tableView->columnCount()*columnWidth;
        int verExccess = (ui->tableView->height() - ui->tableView->horizontalHeader()->height()) - ui->tableView->rowCount()*rowHeigth;
        for (int i = 0; i < ui->tableView->rowCount(); i++)
        {
            if (verExccess > 1)
            {
                ui->tableView->setRowHeight(i, rowHeigth + 1);
                verExccess--;
            }
            else
            {
                ui->tableView->setRowHeight(i, rowHeigth);
            }

        }
        for (int i = 0; i < ui->tableView->columnCount(); i++)
        {
            if (horExccess > 1)
            {
                ui->tableView->setColumnWidth(i, columnWidth + 1);
                horExccess--;
            }
            else
            {
                ui->tableView->setColumnWidth(i, columnWidth);
            }
        }
    }
}

void MachineSimulation::saveTape()
{
	// Saves the currentky displayed machine
    QString fileName = QFileDialog::getSaveFileName(this, "Save Turing's Machine", QDir::homePath(), "Text Files (*.txt);;All Files(*)");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        return;
    }
    QTextStream out(&file);
    out << "hp: " << ui->headPos->value() << endl;
    out << "bs: " << blanckSym << endl;
    for (auto it = tempTape.begin(); it != tempTape.end(); it++)
    {
        out << *it;
    }
    out << endl;
    file.flush();
    file.close();
}

void MachineSimulation::selectTableCellSlt(int st, int sy)
{
	// Selects the table cell of the current state and current symbol
    if (st >= 0)
    {
        ui->tableView->clearSelection();
        QModelIndex model = ui->tableView->model()->index(sy, st);
        ui->tableView->selectionModel()->select(model, QItemSelectionModel::Select);
    }
}

void MachineSimulation::setMachine(Machine *mach)
{
	// Changes the machine object
    this->mach = mach;
}

void MachineSimulation::setTape(Tape *tape)
{
	// Chnages the tape object
    this->defTape = tape;
    tapeEdited = false;
    tempTape = defTape->getTape();
    tempHeadPos = defTape->getTapePos();
    blanckSym = defTape->getBlanckSym();
    on_headPos_valueChanged(tempHeadPos);
}

void MachineSimulation::simulate()
{
	// Starts the machine's simulation
    if (!machIsLoaded) return;
    state = "Simulating";
    haltSim = false;
    pauseSim = false;
    halts = false;
    ui->simList->clear();
    ui->statesList->clear();
    ui->tapeList->clear();
    mach->start(tempTape, tempHeadPos, blanckSym);

    int iterations = 0;

    std::list<QChar> tape;
    QString tapeStr;

    while (true) {
        if (pauseSim)
        {
            QThread::msleep(10);
            if (machHalted(iterations)) return;
            else continue;
        }
        tape = mach->getTape();
        int offset = mach->getTapeHeadOffset();
        tapeStr.clear();
        int spacing = tape.size()/2 - offset;
        for (auto it = tape.begin(); it != tape.end(); it++)
        {
            if (spacing == 0) tapeStr.append(" |");
            tapeStr.append(*it);
            if (spacing == 0) tapeStr.append("| ");
            spacing--;
        }
        if (tape.size() % 2 == 0)
        {
            tapeStr.append(" ");
        }
        if (offset > 0)
        {
            for (int i = 0; i < abs(offset); i++)
            {
                tapeStr.prepend("  ");
            }
        }
        else if (offset < 0)
        {
            for (int i = 0; i < abs(offset); i++)
            {
                tapeStr.append("  ");
            }
        }
        int st = mach->getStates()->indexOf(mach->getCurrentState());
        int sy = mach->getSymbols()->indexOf(mach->getCurrentSymbol());

        uiIsReady = false;
        emit updateUiSgn(st, sy, mach->getCurrentState(), tapeStr, "Simulating - " + QString::number(iterations) + " iterations");

        for (int i = 0; i < localDelayFormat; i++)
        {
            QThread::msleep(10);
            if (machHalted(iterations)) return;
        }
        while (!uiIsReady) {
            QThread::msleep(1);
            if (machHalted(iterations)) return;
        }
        iterations++;
        mach->advance();
    }
}

void MachineSimulation::start()
{
    // Setting the sizes of the containers
    QList<int> sizes = ui->tableSplit->sizes();
    sizes[0] = (int)ui->tableSplit->height()*0.45;
    sizes[1] = (int)ui->tableSplit->height()*0.55;
    ui->tableSplit->setSizes(sizes);
    sizes = ui->specSplit->sizes();
    sizes[0] = (int)ui->specSplit->width()*0.6;
    sizes[1] = (int)ui->specSplit->width()*0.4;
    ui->specSplit->setSizes(sizes);
    sizes = ui->propSplit->sizes();
    sizes[0] = (int)ui->propSplit->width()*0.58;
    sizes[1] = (int)ui->propSplit->width()*0.42;
    ui->propSplit->setSizes(sizes);
    sizes = ui->simSplit->sizes();
    sizes[0] = (int)ui->simSplit->width()*0.1;
    sizes[1] = (int)ui->simSplit->width()*0.9;
    ui->simSplit->setSizes(sizes);
}

void MachineSimulation::stop()
{
	// Stops the simulation
    state = "Machine Loaded";
    haltSim = true;
}

void MachineSimulation::updateDelaySlt(int delay)
{
	// Changes the simulation delay if the machine is not simulating
    if (state != "Simulating")
    {
        localDelayFormat = delay/10;
        emit delayChangedSgn(localDelayFormat);
    }
}

void MachineSimulation::updateUiSlt(int st, int sy, QString state, QString tape, QString status)
{
	// Updates the Ui elemtents with the information provided by the simulation
    int toClean = ui->simList->count()  - set->getSimHistory();
    for (int i = 0; i < toClean; i++)
    {
         delete ui->simList->item(0);
         delete ui->tapeList->item(0);
         delete ui->statesList->item(0);
    }
    selectTableCellSlt(st, sy);
    insertStateSlt(state);
    insertTapeSlt(tape);
    changeStatusSlt(status);
    uiIsReady = true;
}
