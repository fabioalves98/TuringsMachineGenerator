#include "randomtapes.h"
#include "ui_randomtapes.h"

RandomTapes::RandomTapes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RandomTapes)
{
    ui->setupUi(this);
    this->setWindowTitle("Random Tape Creation");
    this->setWindowIcon(QIcon(QPixmap(":rec/icons/random")));
    this->setWindowModality(Qt::ApplicationModal);

    // Setting class settings
    set = Settings::getInstance();

    // Generating seed for random number generation
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    // Initializing UI and class elements
    ui->bSymEdit->setPlaceholderText("0");
    ui->tapeList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->randBt->setEnabled(false);
    ui->saveBt->setEnabled(false);
    ui->nameEdit->setPlaceholderText("Custom Random Tape - " + QString::number(qrand() % 100));
}

RandomTapes::~RandomTapes()
{
    delete ui;
}

void RandomTapes::changeButState()
{
    // Changes the state of the buttons acording to the state of the machine creation
    if (generated)
    {
        ui->saveBt->setEnabled(true);
    }
    else
    {
        ui->saveBt->setEnabled(false);
    }
    if (ui->symLayout->count() == 0 || ui->sizeSBox->value() == 0)
    {
        ui->randBt->setEnabled(false);
    }
    else
    {
        ui->randBt->setEnabled(true);
    }
}

void RandomTapes::clearSymLayout()
{
    // Deletes all previous state line edits
    QLayoutItem *item;
    while((item = ui->symLayout->takeAt(0)))
    {
        delete item->widget();
        delete item;
    }
}

Tape *RandomTapes::getTape()
{
    // Returns the tape object
    return rand;
}

bool RandomTapes::isReady()
{
    // Checks if the tape is ready to be returned
    return ready;
}

void RandomTapes::on_randBt_clicked()
{
    // Fills the tape line edits with randomly geenrated symbols
    QVector<QChar> symbols;
    for (int i = 0; i < ui->symSBox->value(); i++)
    {
        QLineEdit *lEdit = dynamic_cast<QLineEdit*>(ui->symLayout->itemAt(i)->widget());;
        if (lEdit->text() == nullptr)
        {
            symbols.append(lEdit->placeholderText().at(0));
        }
        else
        {
            symbols.append(lEdit->text().at(0));
        }
    }
    for (int i = 0; i < ui->sizeSBox->value(); i++)
    {
        QChar rand = symbols.at(qrand() % symbols.size());
        dynamic_cast<QLineEdit*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout()->itemAt(i+1)->widget())->setText(rand);
    }
    generated = true;
    changeButState();
}

void RandomTapes::on_saveBt_clicked()
{
    // Saves the randomly created tape into a tape object
    QString name = ui->nameEdit->text();
    if (name == nullptr) {
        name = ui->nameEdit->placeholderText();
    }
    std::list<QChar> tape;
    for (int i = 0; i < ui->sizeSBox->value(); i++)
    {
        QLineEdit *lEdit = dynamic_cast<QLineEdit*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout()->itemAt(i+1)->widget());
        if (lEdit->text() == nullptr)
        {
            tape.push_back(lEdit->placeholderText().at(0));
        }
        else
        {
            tape.push_back(lEdit->text().at(0));
        }
    }
    QChar blankSym;
    QString text = ui->bSymEdit->text();
    if (text == nullptr)
    {
        blankSym = ui->bSymEdit->placeholderText().at(0);
    }
    else
    {
        blankSym = text.at(0);
    }
    int headPos = tape.size()/2;
    rand = new Tape(name, tape, blankSym, headPos);
    ready = true;
}

void RandomTapes::on_sizeSBox_valueChanged(int arg1)
{
    // Changes the size of the tape to be generated
    ui->tapeList->clear();
    QListWidgetItem *item = new QListWidgetItem;
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addStretch();
    for (int i = 0; i < arg1; i++)
    {
        QLineEdit *lEdit = new QLineEdit;
        lEdit->setMaximumWidth(30);
        QFont font = lEdit->font();
        font.setPointSize(12);
        lEdit->setFont(font);
        lEdit->setAlignment(Qt::AlignCenter);
        if (ui->bSymEdit->text() == nullptr)
        {
            lEdit->setPlaceholderText(ui->bSymEdit->placeholderText());
        }
        else
        {
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

void RandomTapes::on_symSBox_valueChanged(int arg1)
{
    // Sets the number of symbols to be inerted in the tape
    clearSymLayout();
    for (int i = 0; i < arg1; i++)
    {
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

void RandomTapes::quick()
{
    // Generates a tape with the random propertie extracted from the settings
    int numDigitsName = pow(10, set->getRandTapeSuffix() - 1);
    QString name = set->getRandTapeName() + QString::number(qrand() % (9*numDigitsName) + numDigitsName);
    int tapeSize = qrand() % (set->getTapeMaxSize() - set->getTapeMinSize()) + set->getTapeMinSize();
    QVector<QChar> *symbols = set->getTapeSymbols();
    std::list<QChar> tape;
    for (int i = 0; i < tapeSize; i++)
    {
        tape.push_back(symbols->at(qrand() % symbols->size()));
    }
    QChar blankSym = (set->getRandBSym() ? (symbols->at(qrand() % symbols->size())) : (set->getBlankSymbol()));
    int headPos = tape.size()/2;
    rand = new Tape(name, tape, blankSym, headPos);
}
