#include "edittapes.h"
#include "ui_edittapes.h"

EditTapes::EditTapes(std::list<QChar> toEdit, QChar bSym, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditTapes),
    tape(toEdit),
    blankSym(bSym)
{
    ui->setupUi(this);
    this->setWindowTitle("Tape Edition");
    this->setWindowIcon(QIcon(QPixmap(":rec/icons/edit")));
    this->setWindowModality(Qt::ApplicationModal);

    // Setting the scroll bar always on
    ui->tapeList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // Assigning icons to the resize buttons
    ui->plusLeftBt->setIcon(QIcon(QPixmap(":rec/icons/plus")));
    ui->plusLeftBt->setIconSize(QSize(25, 25));
    ui->plusLeftBt->setMaximumHeight(35);
    ui->minusLeftBt->setIcon(QIcon(QPixmap(":rec/icons/minus")));
    ui->minusLeftBt->setIconSize(QSize(25, 25));
    ui->minusLeftBt->setMaximumHeight(35);
    ui->minusRightBt->setIcon(QIcon(QPixmap(":rec/icons/minus")));
    ui->minusRightBt->setIconSize(QSize(25, 25));
    ui->minusRightBt->setMaximumHeight(35);
    ui->plusRightBt->setIcon(QIcon(QPixmap(":rec/icons/plus")));
    ui->plusRightBt->setIconSize(QSize(25, 25));
    ui->plusRightBt->setMaximumHeight(35);

    // Initializing the blank symbol line edit
    ui->blankSymLEdit->setPlaceholderText(blankSym);
    ui->blankSymLEdit->setText(blankSym);
}

EditTapes::~EditTapes()
{
    delete ui;
}

QChar EditTapes::getBlankSym()
{
    // Returns the blank symbol
    return blankSym;
}

std::list<QChar> EditTapes::getTape()
{
    // Returns the tape
    return tape;
}

bool EditTapes::isEdited()
{
    // Checks if the tape was edited
    return edited;
}

bool EditTapes::isReady()
{
    // Checks if the tape is ready to be returned
    return ready;
}

void EditTapes::loadTape()
{
    // Loads the tape into the line edits
    ui->tapeList->clear();
    QListWidgetItem *item = new QListWidgetItem;
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addStretch();
    for (auto it = tape.begin(); it != tape.end(); it++)
    {
        QLineEdit *lEdit = new QLineEdit;
        lEdit->setMaximumWidth(30);
        QFont font = lEdit->font();
        font.setPointSize(12);
        lEdit->setFont(font);
        lEdit->setAlignment(Qt::AlignCenter);
        lEdit->setPlaceholderText(*it);
        lEdit->setText(*it);
        lEdit->setMaxLength(1);
        layout->addWidget(lEdit);
    }
    layout->addStretch();
    layout->setMargin(1);
    widget->setLayout(layout);
    item->setSizeHint(widget->sizeHint());
    ui->tapeList->addItem(item);
    ui->tapeList->setItemWidget(item, widget);
}

void EditTapes::on_blankSymLEdit_textChanged(const QString &arg1)
{
    // Changes the blank symbol
    if (arg1 != nullptr)
    {
        blankSym = arg1.at(0);
    }
    else
    {
        blankSym = ui->blankSymLEdit->placeholderText().at(0);
    }
}

void EditTapes::on_minusLeftBt_clicked()
{
    // Deletes an element on the left side of the tape
    updateTape();
    tape.pop_front();
    loadTape();
}

void EditTapes::on_minusRightBt_clicked()
{
    // Deletes an element on the right side of the tape
    updateTape();
    tape.pop_back();
    loadTape();
}

void EditTapes::on_plusLeftBt_clicked()
{
    // Adds an element on the left side of the tape
    updateTape();
    tape.push_front(blankSym);
    loadTape();
}

void EditTapes::on_plusRightBt_clicked()
{
    // Adds an element on the right side of the tape
    updateTape();
    tape.push_back(blankSym);
    loadTape();
}

void EditTapes::on_restoreBt_clicked()
{
    // Restore the tape to its original state
    ready = true;
    edited = false;
}

void EditTapes::on_saveBt_clicked()
{
    // Saves the tape
    updateTape();
    ready = true;
}

void EditTapes::updateTape()
{
    // Updates the values of the tape
    QHBoxLayout *layout = dynamic_cast<QHBoxLayout*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout());
    auto it = tape.begin();
    for (int i = 1; i < layout->count() - 1; i++)
    {
        QString text = dynamic_cast<QLineEdit*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout()->itemAt(i)->widget())->text();
        if (text != nullptr)
        {
            *it = text.at(0);
        }
        else
        {
            *it = dynamic_cast<QLineEdit*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout()->itemAt(i)->widget())->placeholderText().at(0);
        }
        it++;
    }
    edited = true;
}
