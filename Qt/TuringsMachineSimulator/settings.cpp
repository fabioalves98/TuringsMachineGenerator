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

    setDefaults();

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
    namePrefix = "Quick Random - ";
    ui->nameEdit->setPlaceholderText(namePrefix);
    for (int i = 2; i < 8; i++) {
        ui->nameRandNum->addItem(QString::number(i) + " digit");
    }
    randSuffix = 4;
    ui->nameRandNum->setCurrentIndex(randSuffix - 2);
    haltState = 'H';
    ui->haltStEdit->setPlaceholderText(QString(haltState));
    ui->haltStEdit->setAlignment(Qt::AlignCenter);
    randInState = true;
    ui->rInStCheck->setChecked(randInState);
    minSt = 2; maxSt = 10;
    ui->minStSpinBox->setValue(minSt);
    ui->maxStSpinBox->setValue(maxSt);
    minSy = 2; maxSy = 10;
    ui->minSySpinBox->setValue(minSy);
    ui->maxSySpinBox->setValue(maxSy);
    fillStatesNSymbols();
    inState = ui->inStCBox->itemText(0).at(0);

    // Settings for the simulation tab
    delayTime = 200;
    ui->delaySpinBox->setValue(delayTime);
    haltInXIt = false;
    ui->haltSimSpinBox->setEnabled(haltInXIt);
    iterTilHalt = 1000;
    ui->haltSimSpinBox->setValue(iterTilHalt);
}

void Settings::fillStatesNSymbols() {
    for (int i = 0; i < ui->stLayout->count(); i++) {
        if (dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->text() == nullptr) {
            states.append(dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->placeholderText().at(0));
        }
        else {
            states.append(dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(i)->widget())->text().at(0));
        }
    }
    for (int i = 0; i < ui->syLayout->count(); i++) {
        if (dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->text() == nullptr) {
            symbols.append(dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->placeholderText().at(0));
        }
        else {
            symbols.append(dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(i)->widget())->text().at(0));
        }
    }
}

void Settings::closeEvent(QCloseEvent *event) {
    if (ui->nameEdit->text() == nullptr) {
        namePrefix = ui->nameEdit->placeholderText();
    }
    else {
        namePrefix = ui->nameEdit->text();
    }
    randSuffix = ui->nameRandNum->currentIndex() + 2;
    minSt = ui->minStSpinBox->value();
    maxSt = ui->maxStSpinBox->value();
    states.clear();
    minSy = ui->minSySpinBox->value();
    maxSy = ui->maxSySpinBox->value();
    symbols.clear();
    fillStatesNSymbols();
    randInState = ui->rInStCheck->isChecked();
    inState = ui->inStCBox->currentText().at(0);
    if (ui->haltStEdit->text() == nullptr) {
        haltState = ui->haltStEdit->placeholderText().at(0);
    }
    else {
        haltState = ui->haltStEdit->text().at(0);
    }
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

QChar Settings::getInState()
{
    return inState;
}

bool Settings::getRandInState()
{
    return randInState;
}

QVector<QChar>* Settings::getSymbols()
{
    return &symbols;
}

QVector<QChar>* Settings::getStates()
{
    return &states;
}

int Settings::getMaxSy()
{
    return maxSy;
}

int Settings::getMinSy()
{
    return minSy;
}

int Settings::getMaxSt()
{
    return maxSt;
}

int Settings::getMinSt()
{
    return minSt;
}

int Settings::getRandSuffix()
{
    return randSuffix;
}

QString Settings::getNamePrefix()
{
    return namePrefix;
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

void Settings::on_haltStEdit_textEdited(const QString &arg1)
{
    if (arg1 != nullptr) {
        ui->haltStEdit->setText(arg1.at(0));
    }
}
