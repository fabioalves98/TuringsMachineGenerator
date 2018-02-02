#include "settings.h"
#include "ui_settings.h"

Settings* Settings::instance = 0;

Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings");
    abc = "ABCDEFGIJKLMNOPQRSTUVWXYZ";
    this->setWindowModality(Qt::ApplicationModal);
    ui->tabWidget->setCurrentIndex(0);
    QList<int> sizes = ui->generalSplit->sizes();
    sizes[0] = (int)ui->generalSplit->width()*0.63;
    sizes[1] = (int)ui->generalSplit->width()*0.37;
    ui->generalSplit->setSizes(sizes);
    setDefaults();
    loadPresets();
    statusBar()->showMessage("Changes will be applied automatically by closing this window.");
}

Settings::~Settings()
{
    delete ui;
}

Settings* Settings::getInstance() {
    if (instance == 0) {
        instance = new Settings;
    }
    return instance;
}

void Settings::setDefaults() {
    // Settings for the quick random tables tab
    randTableName = "Quick Random Table - ";
    randTapeName = "Quick Random Tape - ";
    ui->tableNameEdit->setPlaceholderText(randTableName);
    ui->tapeNameEdit->setPlaceholderText(randTapeName);
    for (int i = 2; i < 8; i++) {
        ui->tableRandSuffix->addItem(QString::number(i) + " digit");
        ui->tapeRandSuffix->addItem(QString::number(i) + " digit");
    }
    randTableSuffix = 4;
    randTapeSuffix = 3;
    ui->tableRandSuffix->setCurrentIndex(randTableSuffix - 2);
    ui->tapeRandSuffix->setCurrentIndex(randTapeSuffix - 2);
    haltState = 'H';
    ui->haltStEdit->setPlaceholderText(haltState);
    randInState = true;
    ui->rInStCheck->setChecked(randInState);
    tableMinSt = 2; tableMaxSt = 10;
    ui->minStSpinBox->setValue(tableMinSt);
    ui->maxStSpinBox->setValue(tableMaxSt);
    tableMinSy = 2; tableMaxSy = 10;
    ui->minSySpinBox->setValue(tableMinSy);
    ui->maxSySpinBox->setValue(tableMaxSy);
    inState = ui->inStCBox->itemText(0).at(0);

    // Settings for the quick random tapes tab
    numTapeSymbols = 2;
    ui->tapeSySBox->setValue(numTapeSymbols);
    tapeMaxSize = 10;
    ui->tapeMaxSizeSBox->setValue(tapeMaxSize);
    tapeMinSize = 2;
    ui->tapeMinSizeSBox->setValue(tapeMinSize);
    blanckSym = '0';
    ui->tapeBSymEdit->setPlaceholderText(blanckSym);
    randBSym = true;
    ui->rBSyCheck->setChecked(randBSym);

    fillStatesNSymbols();

    // Settings for the simulation tab
    delayTime = 200;
    ui->delaySpinBox->setValue(delayTime);
    haltInXIt = false;
    ui->haltSimSpinBox->setEnabled(haltInXIt);
    iterTilHalt = 1000;
    ui->haltSimSpinBox->setValue(iterTilHalt);
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
    for (int i = 0; i < 16; i++) {
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

    // Creating the Binary to Decimal Converter
    name = "Bin2Dec Converter";
    ui->presetsCBox->addItem(name);
    states.clear();
    for (int i = 0; i < 8; i++) {
        states.append(abc.at(i));
        if (i == 6) states.append('H');
    }
    symbols.clear();
    symbols.append('.');
    for (int i = 0; i < 10; i++) {
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
}

void Settings::createPreset(QString name, QVector<QChar> states, QVector<QChar> symbols, QStringList cells, QChar inSt, QChar htSt)
{
    QMap<QString, QString> tFunct;
    int index = 0;
    QString key;
    for (int i = 0; i < symbols.size(); i++) {
        for (int j = 0; j < states.size(); j++) {
            key.clear();
            key.append(states.at(j));
            key.append(symbols.at(i));
            tFunct.insert(key, cells.at(index));
            index++;
        }
    }
    Machine *threeBusy = new Machine(name, states, symbols, tFunct, inSt, htSt);
    presets.append(threeBusy);
}

void Settings::fillStatesNSymbols() {
    for (int i = 0; i < ui->stLayout->count(); i++) {
        if (dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->text() == nullptr) {
            tableStates.append(dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->placeholderText().at(0));
        }
        else {
            tableStates.append(dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->text().at(0));
        }
    }
    for (int i = 0; i < ui->syLayout->count(); i++) {
        if (dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->text() == nullptr) {
            tableSymbols.append(dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->placeholderText().at(0));
        }
        else {
            tableSymbols.append(dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->text().at(0));
        }
    }
    for (int i = 0; i < ui->tapeSyLayout->count(); i++) {
        if (dynamic_cast<QLineEdit*>(ui->tapeSyLayout->itemAt(i)->widget())->text() == nullptr) {
            tapeSymbols.append(dynamic_cast<QLineEdit*>(ui->tapeSyLayout->itemAt(i)->widget())->placeholderText().at(0));
        }
        else {
            tapeSymbols.append(dynamic_cast<QLineEdit*>(ui->tapeSyLayout->itemAt(i)->widget())->text().at(0));
        }
    }
}

void Settings::closeEvent(QCloseEvent *event) {
    // Saving quick random machine settings
    if (ui->tableNameEdit->text() == nullptr) {
        randTableName = ui->tableNameEdit->placeholderText();
    }
    else {
        randTableName = ui->tableNameEdit->text();
    }
    randTableSuffix = ui->tableRandSuffix->currentIndex() + 2;
    tableMinSt = ui->minStSpinBox->value();
    tableMaxSt = ui->maxStSpinBox->value();
    tableStates.clear();
    tableMinSy = ui->minSySpinBox->value();
    tableMaxSy = ui->maxSySpinBox->value();
    tableSymbols.clear();
    randInState = ui->rInStCheck->isChecked();
    inState = ui->inStCBox->currentText().at(0);
    if (ui->haltStEdit->text() == nullptr) {
        haltState = ui->haltStEdit->placeholderText().at(0);
    }
    else {
        haltState = ui->haltStEdit->text().at(0);
    }

    // Saving the quick random tape settings
    if (ui->tapeNameEdit->text() == nullptr) {
        randTapeName = ui->tapeNameEdit->placeholderText();
    }
    else {
        randTapeName = ui->tapeNameEdit->text();
    }
    randTapeSuffix = ui->tapeRandSuffix->currentIndex() + 2;
    numTapeSymbols = ui->tapeSySBox->value();
    tapeSymbols.clear();
    tapeMaxSize = ui->tapeMaxSizeSBox->value();
    tapeMinSize = ui->tapeMinSizeSBox->value();
    randBSym = ui->rBSyCheck->isChecked();
    if (ui->tapeBSymEdit->text() == nullptr) {
        blanckSym = ui->tapeBSymEdit->placeholderText().at(0);
    }
    else {
        blanckSym = ui->tapeBSymEdit->text().at(0);
    }

    // Saving common settings
    fillStatesNSymbols();

    // Saving simulation settings
    delayTime = ui->delaySpinBox->value();
    haltInXIt = ui->haltSimCheck->isChecked();
    iterTilHalt = ui->haltSimSpinBox->value();

    close();
    QWidget::closeEvent(event);
}

int Settings::getIterTilHalt()
{
    return iterTilHalt;
}

bool Settings::getHaltInXIt()
{
    return haltInXIt;
}

QChar Settings::getHaltState()
{
    return haltState;
}

QString Settings::getRandTapeName()
{
    return randTapeName;
}

int Settings::getRandTapeSuffix()
{
    return randTapeSuffix;
}

int Settings::getTapeMaxSize()
{
    return tapeMaxSize;
}

int Settings::getTapeMinSize()
{
    return tapeMinSize;
}

QVector<QChar> *Settings::getTapeSymbols()
{
    return &tapeSymbols;
}

bool Settings::getRandBSym()
{
    return randBSym;
}

QChar Settings::getBlanckSymbol()
{
    return blanckSym;
}

QChar Settings::getInState()
{
    return inState;
}

bool Settings::getRandInState()
{
    return randInState;
}

QVector<QChar>* Settings::getTableSymbols()
{
    return &tableSymbols;
}

QVector<QChar>* Settings::getTableStates()
{
    return &tableStates;
}

int Settings::getTableMaxSy()
{
    return tableMaxSy;
}

int Settings::getTableMinSy()
{
    return tableMinSy;
}

int Settings::getTableMaxSt()
{
    return tableMaxSt;
}

int Settings::getTableMinSt()
{
    return tableMinSt;
}

int Settings::getRandTableSuffix()
{
    return randTableSuffix;
}

QString Settings::getRandTableName()
{
    return randTableName;
}

int Settings::getDelayTime()
{
    return delayTime;
}

void Settings::setDelayTime(int value)
{
    delayTime = value;
}

void Settings::on_maxStSpinBox_valueChanged(int arg1)
{
    ui->inStCBox->clear();
    QString previous;
    for (int i = 0; i < ui->stLayout->count(); i++) {
        QString state = dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->text();
        if (state == nullptr) {
            previous.append(dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->placeholderText());
        }
        else {
            previous.append(state);
        }
    }
    clearStLayout();
    if (arg1 != 0) {
        for (int i = 0; i < arg1; i++) {
            QString st;
            if (i > prevState || prevState == 0) {
                st.append(abc.at(i));
            }
            else {
                st.append(previous.at(i));
            }
            ui->inStCBox->addItem(st);

            QLineEdit *lEdit = new QLineEdit;
            lEdit->setMaximumSize(QSize(50, ui->maxStSpinBox->height()));
            lEdit->setAlignment(Qt::AlignCenter);
            lEdit->setPlaceholderText(st);
            QSignalMapper *sigMap = new QSignalMapper(this);
            connect(lEdit, SIGNAL(textChanged(QString)), sigMap, SLOT(map()));
            sigMap->setMapping(lEdit, i);
            connect(sigMap, SIGNAL(mapped(int)), SLOT(fixStates(int)));
            ui->stLayout->addWidget(lEdit);
        }
    }
    if (arg1 < ui->minStSpinBox->value()) {
        ui->minStSpinBox->setValue(arg1);
    }
    prevState = arg1 - 1;
}

void Settings::clearStLayout() {
    QLayoutItem *item;
    while((item = ui->stLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void Settings::on_minStSpinBox_valueChanged(int arg1)
{
    if (arg1 > ui->maxStSpinBox->value()) {
        ui->maxStSpinBox->setValue(arg1);
    }
}

void Settings::on_rInStCheck_stateChanged(int arg1)
{
    if (arg1 > 1) {
        ui->inStCBox->setEnabled(false);
    }
    else {
        ui->inStCBox->setEnabled(true);
    }
}

void Settings::on_maxSySpinBox_valueChanged(int arg1)
{
    QString previous;
    for (int i = 0; i < ui->syLayout->count(); i++) {
        QString state = dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->text();
        if (state == nullptr) {
            previous.append(dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->placeholderText());
        }
        else {
            previous.append(state);
        }
    }
    clearSyLayout();
    if (arg1 != 0) {
        for (int i = 0; i < arg1; i++) {
            QString sy;
            if (i > prevSymbol || prevSymbol == 0) {
                sy.append(QString::number(i));
            }
            else {
                sy.append(previous.at(i));
            }

            QLineEdit *lEdit = new QLineEdit;
            lEdit->setMaximumSize(QSize(50, ui->maxSySpinBox->height()));
            lEdit->setAlignment(Qt::AlignCenter);
            lEdit->setPlaceholderText(sy);
            QSignalMapper *sigMap = new QSignalMapper(this);
            connect(lEdit, SIGNAL(textChanged(QString)), sigMap, SLOT(map()));
            sigMap->setMapping(lEdit, i);
            connect(sigMap, SIGNAL(mapped(int)), SLOT(fixSymbols(int)));
            ui->syLayout->addWidget(lEdit);
        }
    }
    if (arg1 < ui->minSySpinBox->value()) {
        ui->minSySpinBox->setValue(arg1);
    }
    prevSymbol = arg1 - 1;
}

void Settings::clearSyLayout() {
    QLayoutItem *item;
    while((item = ui->syLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void Settings::clearTapeSyLayout()
{
    QLayoutItem *item;
    while((item = ui->tapeSyLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void Settings::on_minSySpinBox_valueChanged(int arg1)
{
    if (arg1 > ui->maxSySpinBox->value()) {
        ui->maxSySpinBox->setValue(arg1);
    }
}

void Settings::on_haltSimCheck_stateChanged(int arg1)
{
    if (arg1 > 1) {
        ui->haltSimSpinBox->setEnabled(true);
    }
    else {
        ui->haltSimSpinBox->setEnabled(false);
    }
}

void Settings::fixStates(int st)
{
    QString text = dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(st)->widget())->text();
    QChar state;
    if (text != nullptr) {
        state = text.at(0);
        dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(st)->widget())->setText(state);
    }
    else {
        state = dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(st)->widget())->placeholderText().at(0);
        dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(st)->widget())->setPlaceholderText(state);
    }
}

void Settings::fixSymbols(int sy)
{
    QString text = dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(sy)->widget())->text();
    QChar symbol;
    if (text != nullptr) {
        symbol = text.at(0);
        dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(sy)->widget())->setText(symbol);
    }
    else {
        symbol = dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(sy)->widget())->placeholderText().at(0);
        dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(sy)->widget())->setPlaceholderText(symbol);
    }
}

void Settings::on_tapeSySBox_valueChanged(int arg1)
{
    clearTapeSyLayout();
    tapeSymbols.clear();
    for (int i = 0; i < arg1; i++) {
        QLineEdit *lEdit = new QLineEdit;
        lEdit->setMaximumSize(QSize(50, ui->tapeSySBox->height()));
        lEdit->setAlignment(Qt::AlignCenter);
        lEdit->setPlaceholderText(QString::number(i).at(0));
        ui->tapeSyLayout->addWidget(lEdit);
    }
}

void Settings::on_rBSyCheck_stateChanged(int arg1)
{
    if (arg1 > 1) {
        ui->tapeBSymEdit->setEnabled(false);
    }
    else {
        ui->tapeBSymEdit->setEnabled(true);
    }
}

void Settings::on_loadPresetBt_clicked()
{
    emit loadPresetSgn(presets.at(ui->presetsCBox->currentIndex()));
}
