#include "edittapes.h"
#include "ui_edittapes.h"

EditTapes::EditTapes(Tape *toEdit, int tapePos, bool tapeEdited, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditTapes),
    tape(toEdit)
{
    ui->setupUi(this);
    this->setWindowTitle("Tape Edition");
    this->setWindowModality(Qt::ApplicationModal);

    ui->tapeList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QPixmap plusL(":rec/icons/plus");
    QIcon iconPL(plusL);
    ui->plusLeftBt->setIcon(iconPL);
    ui->plusLeftBt->setIconSize(QSize(25, 25));
    ui->plusLeftBt->setMaximumHeight(35);
    QPixmap minusL(":rec/icons/minus");
    QIcon iconML(minusL);
    ui->minusLeftBt->setIcon(iconML);
    ui->minusLeftBt->setIconSize(QSize(25, 25));
    ui->minusLeftBt->setMaximumHeight(35);
    QPixmap minusR(":rec/icons/minus");
    QIcon iconMR(minusR);
    ui->minusRightBt->setIcon(iconMR);
    ui->minusRightBt->setIconSize(QSize(25, 25));
    ui->minusRightBt->setMaximumHeight(35);
    QPixmap plusR(":rec/icons/plus");
    QIcon iconPR(plusR);
    ui->plusRightBt->setIcon(iconPR);
    ui->plusRightBt->setIconSize(QSize(25, 25));
    ui->plusRightBt->setMaximumHeight(35);

    if (tapeEdited) {
        tapeList = tape->getEditedTape(tapePos);
    }
    else {
        tapeList = tape->getTempTape(tapePos);
    }

    ui->blanckSymLEdit->setPlaceholderText(tape->getBlanckSym());
    ui->blanckSymLEdit->setText(tape->getBlanckSym());
}

EditTapes::~EditTapes()
{
    delete ui;
}

void EditTapes::loadTape() {
    ui->tapeList->clear();
    QListWidgetItem *item = new QListWidgetItem;
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addStretch();
    for (auto it = tapeList.begin(); it != tapeList.end(); it++) {
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

bool EditTapes::isReady()
{
    return ready;
}

bool EditTapes::isEdited()
{
    return edited;
}

void EditTapes::applyEdits()
{
    tape->setEditedTape(tapeList);
}

void EditTapes::on_plusLeftBt_clicked()
{
    updateTape();
    tapeList.push_front(tape->getBlanckSym());
    loadTape();
}

void EditTapes::on_minusLeftBt_clicked()
{
    updateTape();
    tapeList.pop_front();
    loadTape();
}

void EditTapes::on_minusRightBt_clicked()
{
    updateTape();
    tapeList.pop_back();
    loadTape();
}

void EditTapes::on_plusRightBt_clicked()
{
    updateTape();
    tapeList.push_back(tape->getBlanckSym());
    loadTape();
}

void EditTapes::updateTape()
{
    QHBoxLayout *layout = dynamic_cast<QHBoxLayout*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout());
    auto it = tapeList.begin();
    for (int i = 1; i < layout->count() - 1; i++) {
        QString text = dynamic_cast<QLineEdit*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout()->itemAt(i)->widget())->text();
        if (text != nullptr) {
            *it = text.at(0);
        }
        else {
            *it = dynamic_cast<QLineEdit*>(ui->tapeList->itemWidget(ui->tapeList->item(0))->layout()->itemAt(i)->widget())->placeholderText().at(0);
        }
        it++;
    }
    edited = true;
}

void EditTapes::on_blanckSymLEdit_textChanged(const QString &arg1)
{
    if (arg1 != nullptr) {
        tape->setBlanckSym(arg1.at(0));
    }
    else {
        tape->setBlanckSym(ui->blanckSymLEdit->placeholderText().at(0));
    }
    qDebug() << arg1;
}

void EditTapes::on_saveBt_clicked()
{
    updateTape();
    ready = true;
}

void EditTapes::on_restoreBt_clicked()
{
    tapeList = tape->getTape();
    ui->blanckSymLEdit->setPlaceholderText(tape->getDefBlanckSym());
    ui->blanckSymLEdit->setText(tape->getDefBlanckSym());
    loadTape();
    edited = false;
}
