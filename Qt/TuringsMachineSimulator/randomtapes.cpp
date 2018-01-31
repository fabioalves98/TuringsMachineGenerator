#include "randomtapes.h"
#include "ui_randomtapes.h"

RandomTapes::RandomTapes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RandomTapes)
{
    ui->setupUi(this);
    this->setWindowTitle("Random Tape Creation");
    this->setWindowModality(Qt::ApplicationModal);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    ui->bSymEdit->setPlaceholderText("0");
    ui->tapeList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->randBt->setEnabled(false);
    ui->saveBt->setEnabled(false);
    ui->nameEdit->setPlaceholderText("Custom Random Tape - " + QString::number(qrand() % 100));
    generated = false;
}

bool RandomTapes::isReady()
{
    return ready;
}

Tape *RandomTapes::getTape()
{
    return rand;
}

RandomTapes::~RandomTapes()
{
    delete ui;
}

void RandomTapes::on_symSBox_valueChanged(int arg1)
{
    clearSymLayout();
    for (int i = 0; i < arg1; i++) {
        QLineEdit *lEdit = new QLineEdit;
        lEdit->setMaximumSize(ui->symSBox->size());
        QFont font = lEdit->font();
        font.setPointSize(10);
        lEdit->setFont(font);
        lEdit->setAlignment(Qt::AlignCenter);
        lEdit->setPlaceholderText(QString::number(i));
        lEdit->setMaxLength(1);
        ui->symLayout->addWidget(lEdit);
    }
    changeButState();
}

void RandomTapes::clearSymLayout()
{
    QLayoutItem *item;
    while((item = ui->symLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void RandomTapes::changeButState()
{
    if (generated) {
        ui->saveBt->setEnabled(true);
    }
    else {
        ui->saveBt->setEnabled(false);
    }
    if (ui->symLayout->count() == 0 || ui->sizeSBox->value() == 0) {
        ui->randBt->setEnabled(false);
    }
    else {
        ui->randBt->setEnabled(true);
    }
}

void RandomTapes::on_sizeSBox_valueChanged(int arg1)
{
    ui->tapeList->clear();
    QListWidgetItem *item = new QListWidgetItem;
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addStretch();
    for (int i = 0; i < arg1; i++) {
        QLineEdit *lEdit = new QLineEdit;
        lEdit->setMaximumWidth(30);
        QFont font = lEdit->font();
        font.setPointSize(12);
        lEdit->setFont(font);
        lEdit->setAlignment(Qt::AlignCenter);
        if (ui->bSymEdit->text() == nullptr) {
            lEdit->setPlaceholderText(ui->bSymEdit->placeholderText());
        }
        else {
            lEdit->setPlaceholderText(ui->bSymEdit->text());
        }
        lEdit->setMaxLength(1);
        layout->addWidget(lEdit);
    }
    layout->addStretch();
    layout->setMargin(1);
    widget->setLayout(layout);
    item->setSizeHint(widget->sizeHint());
    ui->tapeList->addItem(item);
    ui->tapeList->setItemWidget(item, widget);
    changeButState();
}

void RandomTapes::on_randBt_clicked()
{
    QVector<QChar> symbols;
    for (int i = 0; i < ui->symSBox->value(); i++) {
        QLineEdit *lEdit = dynamic_cast<QLineEdit*>(ui->symLayout->itemAt(i)->widget());;
        if (lEdit->text() == nullptr) {
            symbols.append(lEdit->placeholderText().at(0));
        }
        else {
            symbols.append(lEdit->text().at(0));
        }
    }
    for (int i = 0; i < ui->sizeSBox->value(); i++) {
        QChar rand = symbols.at(qrand() % symbols.size());
        dynamic_cast<QLineEdit*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout()->itemAt(i+1)->widget())->setText(rand);
    }
    generated = true;
    changeButState();
}

void RandomTapes::on_saveBt_clicked()
{
    QString name = ui->nameEdit->text();
    if (name == nullptr) {
        name = ui->nameEdit->placeholderText();
    }
    std::list<QChar> tape;
    for (int i = 0; i < ui->sizeSBox->value(); i++) {
        QLineEdit *lEdit = dynamic_cast<QLineEdit*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout()->itemAt(i+1)->widget());
        if (lEdit->text() == nullptr) {
            tape.push_back(lEdit->placeholderText().at(0));
        }
        else {
            tape.push_back(lEdit->text().at(0));
        }
    }
    QChar blanckSym;
    QString text = ui->bSymEdit->text();
    if (text == nullptr) {
        blanckSym = ui->bSymEdit->placeholderText().at(0);
    }
    else {
        blanckSym = text.at(0);
    }
    int headPos = tape.size()/2;
    rand = new Tape(name, tape, blanckSym, headPos);
    ready = true;
}
