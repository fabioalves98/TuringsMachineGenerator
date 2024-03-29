#include "settings.h"
#include "ui_settings.h"

Settings* Settings::instance = 0;

Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings");
    this->setWindowIcon(QIcon(QPixmap(":rec/icons/settings")));
    this->setWindowModality(Qt::ApplicationModal);

    // Initailizing class elements
    abc = "ABCDEFGIJKLMNOPQRSTUVWXYZ"; 
    ui->tabWidget->setCurrentIndex(0);
    setDefaults();
    loadPresets();
    statusBar()->showMessage("Changes will be applied automatically by closing this window.");
}

Settings::~Settings()
{
    delete ui;
}

void Settings::clearStLayout()
{
    // Deletes all previous state line edits
    QLayoutItem *item;
    while((item = ui->stLayout->takeAt(0)))
    {
        delete item->widget();
        delete item;
    }
}

void Settings::clearSyLayout()
{
    // Deletes all previous symbol line edits
    QLayoutItem *item;
    while((item = ui->syLayout->takeAt(0)))
    {
        delete item->widget();
        delete item;
    }
}

void Settings::clearTapeSyLayout()
{
    // Deletes all previous tape symbol line edits
    QLayoutItem *item;
    while((item = ui->tapeSyLayout->takeAt(0)))
    {
        delete item->widget();
        delete item;
    }
}

void Settings::closeEvent(QCloseEvent *event)
{
    // Saves quick random machine settings
    if (ui->machNameEdit->text() == nullptr)
    {
        randMachName = ui->machNameEdit->placeholderText();
    }
    else
    {
        randMachName = ui->machNameEdit->text();
    }
    randMachSuffix = ui->machRandSuffix->currentIndex() + 2;
    machMinSt = ui->minStSpinBox->value();
    machMaxSt = ui->maxStSpinBox->value();
    machStates.clear();
    machMinSy = ui->minSySpinBox->value();
    machMaxSy = ui->maxSySpinBox->value();
    machSymbols.clear();
    randInState = ui->rInStCheck->isChecked();
    inState = ui->inStCBox->currentText().at(0);
    if (ui->haltStEdit->text() == nullptr)
    {
        haltState = ui->haltStEdit->placeholderText().at(0);
    }
    else
    {
        haltState = ui->haltStEdit->text().at(0);
    }

    // Saves the quick random tape settings
    if (ui->tapeNameEdit->text() == nullptr)
    {
        randTapeName = ui->tapeNameEdit->placeholderText();
    }
    else
    {
        randTapeName = ui->tapeNameEdit->text();
    }
    randTapeSuffix = ui->tapeRandSuffix->currentIndex() + 2;
    numTapeSymbols = ui->tapeSySBox->value();
    tapeSymbols.clear();
    tapeMaxSize = ui->tapeMaxSizeSBox->value();
    tapeMinSize = ui->tapeMinSizeSBox->value();
    randBSym = ui->rBSyCheck->isChecked();
    if (ui->tapeBSymEdit->text() == nullptr)
    {
        blankSym = ui->tapeBSymEdit->placeholderText().at(0);
    }
    else
    {
        blankSym = ui->tapeBSymEdit->text().at(0);
    }

    // Saves common settings
    fillStatesNSymbols();

    // Saves simulation settings
    concurrentSim = ui->concurrentSim->value();
    emit concurrentSimSgn();
    delayTime = ui->delaySpinBox->value();
    emit delayChangedSgn(delayTime);
    haltInXIt = ui->haltSimCheck->isChecked();
    iterTilHalt = ui->haltSimSpinBox->value();
    simHistory = ui->simHistSBox->value();

    close();
    QWidget::closeEvent(event);
}

void Settings::createPreset(QString name, QVector<QChar> states, QVector<QChar> symbols, QStringList cells, QChar inSt, QChar htSt)
{
    // Creates a preset and adds it to the preset list
    QMap<QString, QString> tFunct;
    int index = 0;
    QString key;
    for (int i = 0; i < symbols.size(); i++)
    {
        for (int j = 0; j < states.size(); j++)
        {
            key.clear();
            key.append(states.at(j));
            key.append(symbols.at(i));
            tFunct.insert(key, cells.at(index));
            index++;
        }
    }
    Machine *preset = new Machine(name, states, symbols, tFunct, inSt, htSt);
    presets.append(preset);
}

void Settings::fillStatesNSymbols()
{
    // Fills the state/symbols/tape symbols containers with the ui info
    for (int i = 0; i < ui->stLayout->count(); i++)
    {
        if (dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->text() == nullptr)
        {
            machStates.append(dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->placeholderText().at(0));
        }
        else
        {
            machStates.append(dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->text().at(0));
        }
    }
    for (int i = 0; i < ui->syLayout->count(); i++)
    {
        if (dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->text() == nullptr)
        {
            machSymbols.append(dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->placeholderText().at(0));
        }
        else
        {
            machSymbols.append(dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->text().at(0));
        }
    }
    for (int i = 0; i < ui->tapeSyLayout->count(); i++)
    {
        if (dynamic_cast<QLineEdit*>(ui->tapeSyLayout->itemAt(i)->widget())->text() == nullptr)
        {
            tapeSymbols.append(dynamic_cast<QLineEdit*>(ui->tapeSyLayout->itemAt(i)->widget())->placeholderText().at(0));
        }
        else
        {
            tapeSymbols.append(dynamic_cast<QLineEdit*>(ui->tapeSyLayout->itemAt(i)->widget())->text().at(0));
        }
    }
}

QChar Settings::getBlankSymbol()
{
    // Returns the blank symbol
    return blankSym;
}

int Settings::getConcurrentSim()
{
    // Returns the number of machines that can be simulated simultaneously
    return concurrentSim;
}

int Settings::getDelayTime()
{
    // Returns the delay value
    return delayTime;
}

bool Settings::getHaltInXIt()
{
    // Checks if the simulation is suposed to halt in a number of iterations
    return haltInXIt;
}

QChar Settings::getHaltState()
{
    // Returns the halt state
    return haltState;
}

Settings* Settings::getInstance()
{
    // Returns the Setting instance
    if (instance == 0)
    {
        instance = new Settings;
    }
    return instance;
}

QChar Settings::getInState()
{
    // Returns initial state
    return inState;
}

int Settings::getIterTilHalt()
{
    // Return the maximum number of iterations
    return iterTilHalt;
}

bool Settings::getRandBSym()
{
    // Checks if the blank symbol will be randomly generated
    return randBSym;
}

bool Settings::getRandInState()
{
    // Checks if the initial state will be randomly generated
    return randInState;
}

QString Settings::getRandMachName()
{
    // Returns the random machine name
    return randMachName;
}

int Settings::getRandMachSuffix()
{
    // Returns the number of digits the random machine name will have
    return randMachSuffix;
}

QString Settings::getRandTapeName()
{
    // Returns the random tape name
    return randTapeName;
}

int Settings::getRandTapeSuffix()
{
    // Returns the number of digits the random machine name will have
    return randTapeSuffix;
}

int Settings::getSimHistory()
{
    // Returns the number of iterations that will be saved in the simulation
    return simHistory;
}

int Settings::getMachMaxSt()
{
    // Returns the maximum number of states for the random mahine creation
    return machMaxSt;
}

int Settings::getMachMaxSy()
{
    // Returns the maximum number of symbols for the random mahine creation
    return machMaxSy;
}

int Settings::getMachMinSt()
{
    // Returns the minimum number of states for the random mahine creation
    return machMinSt;
}

int Settings::getMachMinSy()
{
    // Returns the minumim number of symbols for the random mahine creation
    return machMinSy;
}

QVector<QChar>* Settings::getMachStates()
{
    // Returns a list of states for the random machine creation
    return &machStates;
}

QVector<QChar>* Settings::getMachSymbols()
{
    // Returns a list of symbols for the random machine creation
    return &machSymbols;
}

int Settings::getTapeMaxSize()
{
    // Retruns the maximum size for the random tape creation
    return tapeMaxSize;
}

int Settings::getTapeMinSize()
{
    // Retruns the minimum size for the random tape creation
    return tapeMinSize;
}

QVector<QChar> *Settings::getTapeSymbols()
{
    // Returns a list of symbols for the random tape creation
    return &tapeSymbols;
}

void Settings::loadPresets()
{
    QString name;
    QVector<QChar> states, symbols;
    QStringList cells;

    // Creating the 3 state BusyBeaver preset
    name = "3 State Busy Beaver";
    ui->presetsCBox->addItem(name);
    states.append('A'); states.append('B'); states.append('C');
    symbols.append('0'); symbols.append('1');
    cells << "1RB" << "1LA" << "1LB" << "1LC" << "1RB" << "1RH";
    createPreset(name, states, symbols, cells, 'A', 'H');

    // Creating the 4 state BusyBeaver preset
    name = "4 State Busy Beaver";
    ui->presetsCBox->addItem(name);
    states.append('D');
    cells.clear();
    cells << "1RB" << "1LA" << "1RH" << "1RD" << "1LB" << "0LC" << "1LD" << "0RA";
    createPreset(name, states, symbols, cells, 'A', 'H');

    // Creating the Turring Sequence preset
    name = "Turring's Sequence";
    ui->presetsCBox->addItem(name);
    states.clear();
    for (int i = 0; i < 16; i++)
    {
        states.append(abc.at(i));
        if (i == 6) states.append('H');
    }
    symbols.clear();
    symbols.append('.'); symbols.append('1'); symbols.append('0'); symbols.append('e'); symbols.append('x');
    cells.clear();
    cells << "eLB" << "eLC" << "0LD" << ".LE" << "0RF" << ".RG" << ".*G" << "xRI" << ".RJ" << ".RG" << "1RM" << ".LK" << ".RN" << ".RM" << "0RP" << ".RG" << ".LO";
    cells << "eLB" << "eLC" << "0LD" << "1LE" << "0RF" << "1RG" << "1LH" << "xRI" << "1RJ" << "1RG" << "1LL" << "1LK" << "1*M" << "1RM" << "1LQ" << "1RG" << "1LO";
    cells << "eLB" << "eLC" << "0LD" << "0LE" << "0RF" << "0RG" << "0*K" << "xRI" << "0RJ" << "0RG" << "0LL" << "0LK" << "0*M" << "0RM" << "0LQ" << "0RG" << "0LO";
    cells << "eLB" << "eLC" << "0LD" << "eLE" << "0RF" << "eRG" << "e*G" << "xRI" << "eRJ" << "eRG" << "eLL" << "eLK" << "eLO" << "eRM" << "eLQ" << "eRG" << "eLO";
    cells << "eLB" << "eLC" << "0LD" << "xLE" << "0RF" << "xRG" << "x*G" << "xRI" << "xRJ" << "xRG" << "xLL" << "xLK" << ".LK" << "xRM" << "xLQ" << "xRG" << "xLO";
    createPreset(name, states, symbols, cells, 'A', 'Z');

    // Creating the Binary to Decimal Converter preset
    name = "Bin2Dec Converter";
    ui->presetsCBox->addItem(name);
    states.clear();
    for (int i = 0; i < 8; i++)
    {
        states.append(abc.at(i));
        if (i == 6) states.append('H');
    }
    symbols.clear();
    symbols.append('.');
    for (int i = 0; i < 10; i++)
    {
        symbols.append(QString::number(i).at(0));
    }
    cells.clear();
    cells << ".LA" << ".RD" << ".LA" << ".LG" << ".RF" << "1LC" << ".RH" << ".RH" << ".LZ";
    cells << "0LB" << "0LB" << "0LC" << "1RD" << "0RE" << "1LC" << ".LG" << "0RI" << "0RI";
    cells << "1LB" << "1LB" << "1LC" << "0RE" << "1RE" << "2LC" << ".LG" << "1RI" << "1RI";
    cells << "2LB" << "2LB" << "2LC" << "2*D" << "2RE" << "3LC" << ".LG" << "2RI" << "2RI";
    cells << "3LB" << "3LB" << "3LC" << "3*D" << "3RE" << "4LC" << ".LG" << "3RI" << "3RI";
    cells << "4LB" << "4LB" << "4LC" << "4*D" << "4RE" << "5LC" << ".LG" << "4RI" << "4RI";
    cells << "5LB" << "5LB" << "5LC" << "5*D" << "5RE" << "6LC" << ".LG" << "5RI" << "5RI";
    cells << "6LB" << "6LB" << "6LC" << "6*D" << "6RE" << "7LC" << ".LG" << "6RI" << "6RI";
    cells << "7LB" << "7LB" << "7LC" << "7*D" << "7RE" << "8LC" << ".LG" << "7RI" << "7RI";
    cells << "8LB" << "8LB" << "8LC" << "8*D" << "8RE" << "9LC" << ".LG" << "8RI" << "8RI";
    cells << "9LB" << "9LB" << "9LC" << "9*D" << "9RE" << "0RF" << ".LG" << "9RI" << "9RI";
    createPreset(name, states, symbols, cells, 'A', 'Z');

    // Creating the Binary Addition preset
    name = "Binary Addition";
    ui->presetsCBox->addItem(name);
    states.clear();
    for (int i = 0; i < 9; i++)
    {
        states.append(abc.at(i));
        if (i == 6) states.append('H');
    }
    symbols.clear();
    symbols.append('.'); symbols.append('0'); symbols.append('1'); symbols.append('x'); symbols.append('y');
    cells.clear();
    cells << ".LB" << ".RC" << ".RJ" << ".RF" << ".RG" << "xLA" << "1*H" << ".RI" << ".*I" << ".LZ";
    cells << "0LA" << "0LB" << ".RD" << "0RD" << "0RE" << "xLA" << "1*H" << "0LH" << "xLA" << "0RJ";
    cells << "1LA" << "1LB" << ".RE" << "1RD" << "1RE" << "yLA" << "0RG" << "1LH" << "yLA" << "1RJ";
    cells << "xLA" << "xLB" << "x*C" << "xRD" << "xRE" << "xRF" << "xRG" << "xRI" << "x*I" << "0RJ";
    cells << "yLA" << "yLB" << "y*C" << "yRD" << "yRE" << "yRF" << "yRG" << "yRI" << "y*I" << "1RJ";
    createPreset(name, states, symbols, cells, 'A', 'Z');
}

void Settings::on_defaultSetBt_clicked()
{
    // Changes all variables to the default state
    setDefaults();
}

void Settings::on_haltSimCheck_stateChanged(int arg1)
{
    // Enables or disables the halt state choice
    if (arg1 > 1)
    {
        ui->haltSimSpinBox->setEnabled(true);
    }
    else
    {
        ui->haltSimSpinBox->setEnabled(false);
    }
}

void Settings::on_loadPresetBt_clicked()
{
    emit loadPresetSgn(presets.at(ui->presetsCBox->currentIndex()));
}

void Settings::on_maxStSpinBox_valueChanged(int arg1)
{
    // Creates line edits to insert custom states
    ui->inStCBox->clear();
    QString previous;
    for (int i = 0; i < ui->stLayout->count(); i++)
    {
        QString state = dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->text();
        if (state == nullptr)
        {
            previous.append(dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->placeholderText());
        }
        else
        {
            previous.append(state);
        }
    }
    clearStLayout();
    if (arg1 != 0)
    {
        for (int i = 0; i < arg1; i++)
        {
            QString st;
            if (i > prevState || prevState == 0)
            {
                st.append(abc.at(i));
            }
            else
            {
                st.append(previous.at(i));
            }
            ui->inStCBox->addItem(st);

            QLineEdit *lEdit = new QLineEdit;
            lEdit->setMaximumSize(QSize(50, ui->maxStSpinBox->height()));
            lEdit->setAlignment(Qt::AlignCenter);
            lEdit->setPlaceholderText(st);
            lEdit->setMaxLength(1);
            ui->stLayout->addWidget(lEdit);
        }
    }
    if (arg1 < ui->minStSpinBox->value())
    {
        ui->minStSpinBox->setValue(arg1);
    }
    prevState = arg1 - 1;
}

void Settings::on_maxSySpinBox_valueChanged(int arg1)
{
    // Creates line edits to insert custom symbols
    QString previous;
    for (int i = 0; i < ui->syLayout->count(); i++)
    {
        QString state = dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->text();
        if (state == nullptr)
        {
            previous.append(dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->placeholderText());
        }
        else
        {
            previous.append(state);
        }
    }
    clearSyLayout();
    if (arg1 != 0) {
        for (int i = 0; i < arg1; i++)
        {
            QString sy;
            if (i > prevSymbol || prevSymbol == 0)
            {
                sy.append(QString::number(i));
            }
            else
            {
                sy.append(previous.at(i));
            }

            QLineEdit *lEdit = new QLineEdit;
            lEdit->setMaximumSize(QSize(50, ui->maxSySpinBox->height()));
            lEdit->setAlignment(Qt::AlignCenter);
            lEdit->setPlaceholderText(sy);
            lEdit->setMaxLength(1);
            ui->syLayout->addWidget(lEdit);
        }
    }
    if (arg1 < ui->minSySpinBox->value())
    {
        ui->minSySpinBox->setValue(arg1);
    }
    prevSymbol = arg1 - 1;
}

void Settings::on_minStSpinBox_valueChanged(int arg1)
{
    // Checks is the minimum value is above the maximum and fixes it
    if (arg1 > ui->maxStSpinBox->value())
    {
        ui->maxStSpinBox->setValue(arg1);
    }
}

void Settings::on_minSySpinBox_valueChanged(int arg1)
{
    // Checks is the minimum value is above the maximum and fixes it
    if (arg1 > ui->maxSySpinBox->value())
    {
        ui->maxSySpinBox->setValue(arg1);
    }
}

void Settings::on_presetsCBox_currentIndexChanged(int index)
{
    // Changes the preset description based on the choosen preset
    QString desc;
    switch (index)
    {
        case 0:
        {
            desc.append("Has 3 states and given a blank tape (0's) it will write the most 1's it can until halting.\n");
            desc.append("Tape: Empty tape with the blank symbol equal to the fisrt symbol of the machine.");
            ui->presetDescTBrows->setText(desc);
            QFont font = ui->presetDescTBrows->font();
            font.setPointSize(11);
            ui->presetDescTBrows->setFont(font);
            break;
        }
        case 1:
        {
            desc.append("Has 4 states and given a blank tape (0's) it will write the most 1's it can until halting.\n");
            desc.append("Tape: Empty tape with the blank symbol equal to the fisrt symbol of the machine.");
            ui->presetDescTBrows->setText(desc);
            QFont font = ui->presetDescTBrows->font();
            font.setPointSize(11);
            ui->presetDescTBrows->setFont(font);
            break;
        }
        case 2:
        {
            desc.append("It will write the sequence 0010110111011110... in the even cells of the tape.\n");
            desc.append("Tape: Empty tape with the blank symbol equal to the fisrt symbol of the machine.");
            ui->presetDescTBrows->setText(desc);
            QFont font = ui->presetDescTBrows->font();
            font.setPointSize(11);
            ui->presetDescTBrows->setFont(font);
            break;
        }
        case 3:
        {
            desc.append("Converts a number from binary to decimal. Head must be the most significant bit.\n");
            desc.append("Tape: Binary number with the blank symbol equal to the fisrt symbol of the machine.");
            ui->presetDescTBrows->setText(desc);
            QFont font = ui->presetDescTBrows->font();
            font.setPointSize(11);
            ui->presetDescTBrows->setFont(font);
            break;
        }
        case 4:
        {
            desc.append("Adds two binary numbers. Head must be the most significant bit of the first operand.\n");
            desc.append("Tape: 2 binary number separated by the blank symbol wich should be equal to the fisrt symbol of the machine.");
            ui->presetDescTBrows->setText(desc);
            QFont font = ui->presetDescTBrows->font();
            font.setPointSize(11);
            ui->presetDescTBrows->setFont(font);
            break;
        }
    }
}

void Settings::on_rBSyCheck_stateChanged(int arg1)
{
    // Enables or disables the blank symbol choice
    if (arg1 > 1)
    {
        ui->tapeBSymEdit->setEnabled(false);
    }
    else
    {
        ui->tapeBSymEdit->setEnabled(true);
    }
}

void Settings::on_rInStCheck_stateChanged(int arg1)
{
    // Enables or disables the initial state choice
    if (arg1 > 1)
    {
        ui->inStCBox->setEnabled(false);
    }
    else
    {
        ui->inStCBox->setEnabled(true);
    }
}

void Settings::on_tapeSySBox_valueChanged(int arg1)
{
    // Sets the line edits for the tape's symbols edition
    clearTapeSyLayout();
    tapeSymbols.clear();
    for (int i = 0; i < arg1; i++)
    {
        QLineEdit *lEdit = new QLineEdit;
        lEdit->setMaximumSize(QSize(50, ui->tapeSySBox->height()));
        lEdit->setAlignment(Qt::AlignCenter);
        lEdit->setPlaceholderText(QString::number(i).at(0));
        lEdit->setMaxLength(1);
        ui->tapeSyLayout->addWidget(lEdit);
    }
}

void Settings::setDefaults() {
    // Settings for the quick random machine tab
    randMachName = "Quick Random Machine - ";
    randTapeName = "Quick Random Tape - ";
    ui->machNameEdit->setPlaceholderText(randMachName);
    ui->tapeNameEdit->setPlaceholderText(randTapeName);
    for (int i = 2; i < 8; i++)
    {
        ui->machRandSuffix->addItem(QString::number(i) + " digit");
        ui->tapeRandSuffix->addItem(QString::number(i) + " digit");
    }
    randMachSuffix = 4;
    randTapeSuffix = 3;
    ui->machRandSuffix->setCurrentIndex(randMachSuffix - 2);
    ui->tapeRandSuffix->setCurrentIndex(randTapeSuffix - 2);
    haltState = 'H';
    ui->haltStEdit->setPlaceholderText(haltState);
    randInState = true;
    ui->rInStCheck->setChecked(randInState);
    machMinSt = 2; machMaxSt = 10;
    ui->minStSpinBox->setValue(machMinSt);
    ui->maxStSpinBox->setValue(machMaxSt);
    machMinSy = 2; machMaxSy = 10;
    ui->minSySpinBox->setValue(machMinSy);
    ui->maxSySpinBox->setValue(machMaxSy);
    inState = ui->inStCBox->itemText(0).at(0);

    // Settings for the quick random tapes tab
    numTapeSymbols = 2;
    ui->tapeSySBox->setValue(numTapeSymbols);
    tapeMaxSize = 10;
    ui->tapeMaxSizeSBox->setValue(tapeMaxSize);
    tapeMinSize = 2;
    ui->tapeMinSizeSBox->setValue(tapeMinSize);
    blankSym = '0';
    ui->tapeBSymEdit->setPlaceholderText(blankSym);
    randBSym = true;
    ui->rBSyCheck->setChecked(randBSym);

    fillStatesNSymbols();

    // Settings for the simulation tab
    concurrentSim = 4;
    ui->concurrentSim->setValue(concurrentSim);
    delayTime = 200;
    ui->delaySpinBox->setValue(delayTime);
    haltInXIt = true;
    ui->haltSimCheck->setChecked(haltInXIt);
    ui->haltSimSpinBox->setEnabled(haltInXIt);
    iterTilHalt = 1000;
    ui->haltSimSpinBox->setValue(iterTilHalt);
    simHistory = 100;
    ui->simHistSBox->setValue(simHistory);
}
