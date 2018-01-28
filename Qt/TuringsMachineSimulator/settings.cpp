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
    ui->hltStEdit->setPlaceholderText("H");
    ui->hltStEdit->setAlignment(Qt::AlignCenter);
    ui->rInStCheck->setChecked(true);
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
            lEdit->setMaximumSize(ui->maxStSpinBox->size());
            lEdit->setAlignment(Qt::AlignCenter);
            lEdit->setPlaceholderText(st);
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
            lEdit->setMaximumSize(ui->maxSySpinBox->size());
            lEdit->setAlignment(Qt::AlignCenter);
            lEdit->setPlaceholderText(sy);
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
