#include "randommachines.h"
#include "ui_randommachines.h"

RandomMachines::RandomMachines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RandomMachines)
{
    ui->setupUi(this);
    this->setWindowTitle("Random Machine Creation");
    this->setWindowModality(Qt::ApplicationModal);
    ui->randTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->randTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    abc = "ABCDEFGIJKLMNOPQRSTUVWXYZ";
    states = new QVector<QChar>;
    symbols = new QVector<QChar>;
    set = Settings::getInstance();
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    changeButState();
    resizable = true;
    ui->randTable->setSelectionMode(QAbstractItemView::NoSelection);
    ui->randTable->verticalScrollBar()->setEnabled(false);
    ui->randTable->horizontalScrollBar()->setEnabled(false);
    this->on_stSel_valueChanged(0);
    this->on_sySel_valueChanged(0);
}

RandomMachines::~RandomMachines()
{
    delete ui;
}

void RandomMachines::resizeEvent(QResizeEvent *event)
{
    resizeTable();
    update();
    QWidget::resizeEvent(event);
}

void RandomMachines::quick() {
    states->clear();
    symbols->clear();
    int maxSt = set->getTableMaxSt();
    int minSt = set->getTableMinSt();
    int maxSy = set->getTableMaxSy();
    int minSy = set->getTableMinSy();
    int numSt = qrand() % ((maxSt - minSt) + 1) + minSt;
    int numSy = qrand() % ((maxSy - minSy) + 1) + minSy;
    for (int i = 0; i < numSt; i++) {
        states->append(set->getTableStates()->at(i));
        }
    for (int i = 0; i < numSy; i++) {
        symbols->append(set->getTableSymbols()->at(i));
    }
    int haltAct;
    haltAct = qrand() % (numSt * numSy);
    QChar haltState = set->getHaltState();
    QMap<QString, QString> transFunct;
    for (int i = 0; i < numSy; i++) {
        for (int j = 0; j < numSt; j++) {
            QString action;
            action.append(symbols->at(qrand() % numSy));
            action.append((qrand()%2 == 1) ? "R" : "L");
            if (haltAct != 0) {
                action.append(states->at(qrand()%numSt));
            }
            else {
                action.append(QString(haltState));
            }
            haltAct--;
            QString key;
            key.append(states->at(j));
            key.append(symbols->at(i));
            transFunct.insert(key, action);
        }
    }
    int numDigitsName = pow(10, set->getRandTableSuffix() - 1);
    QString name = set->getRandTableName() +  QString::number(qrand() % (9*numDigitsName) + numDigitsName);
    QChar initState = (set->getRandInState() ? (states->at(qrand() % numSt)) : (set->getInState()));
    QChar blanckSymbol = symbols->at(0);
    randMach = new Machine(&name, states, symbols, &transFunct, initState, blanckSymbol, haltState);
}

void RandomMachines::on_stSel_valueChanged(int arg1)
{
    ui->randTable->clearContents();
    ui->initStCBox->clear();
    clearStLayout();
    ui->randTable->setColumnCount(arg1);
    if (arg1 != 0) {
        for (int i = 0; i < arg1; i++) {
            QString st;
            if (i > prevState || prevState == 0) {
                st.append(abc.at(i));
            }
            else {
                st.append(ui->randTable->horizontalHeaderItem(i)->text());
            }
            ui->initStCBox->addItem(st);
            QTableWidgetItem *hHeader = new QTableWidgetItem(st);
            hHeader->setFont(QFont("Meiryo", 12));
            ui->randTable->setHorizontalHeaderItem(i, hHeader);

            QLineEdit *lEdit = new QLineEdit;
            lEdit->setMaximumHeight(ui->stSel->height());
            lEdit->setMaximumWidth(ui->stSel->width());
            lEdit->setAlignment(Qt::AlignCenter);
            lEdit->setPlaceholderText(ui->randTable->horizontalHeaderItem(i)->text());
            QSignalMapper *sigMap = new QSignalMapper(this);
            connect(lEdit, SIGNAL(textChanged(QString)), this, SLOT(headersChanged()));
            connect(lEdit, SIGNAL(textChanged(QString)), sigMap, SLOT(map()));
            sigMap->setMapping(lEdit, i);
            connect(sigMap, SIGNAL(mapped(int)), SLOT(changeHorHeader(int)));
            ui->stLayout->addWidget(lEdit);
        }
    }
    prevState = arg1 - 1;
    changeButState();
    generated = false;
    resizeTable();
}

void RandomMachines::changeHorHeader(int st) {
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
   ui->randTable->horizontalHeaderItem(st)->setText(state);
   ui->initStCBox->setItemText(st, state);
}

void RandomMachines::clearStLayout() {
    QLayoutItem *item;
    while((item = ui->stLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void RandomMachines::on_sySel_valueChanged(int arg1)
{
    ui->randTable->clearContents();
    ui->blanckSyCBox->clear();
    clearSyLayout();
    ui->randTable->setRowCount(arg1);
    if (arg1 != 0) {
        for (int i = 0; i < arg1; i++) {
            QString sy;
            if (i > prevSymbol || prevSymbol == 0) {
                sy.append(QString::number(i));
            }
            else {
                sy.append(ui->randTable->verticalHeaderItem(i)->text());
            }
            ui->blanckSyCBox->addItem(sy);
            QTableWidgetItem *vHeader = new QTableWidgetItem(sy);
            vHeader->setFont(QFont("Meiryo", 12));
            ui->randTable->setVerticalHeaderItem(i, vHeader);

            QLineEdit *lEdit = new QLineEdit;
            lEdit->setMaximumHeight(ui->sySel->height());
            lEdit->setMaximumWidth(ui->sySel->width());
            lEdit->setAlignment(Qt::AlignCenter);
            lEdit->setPlaceholderText(ui->randTable->verticalHeaderItem(i)->text());
            QSignalMapper *sigMap = new QSignalMapper(this);
            connect(lEdit, SIGNAL(textChanged(QString)), this, SLOT(headersChanged()));
            connect(lEdit, SIGNAL(textChanged(QString)), sigMap, SLOT(map()));
            sigMap->setMapping(lEdit, i);
            connect(sigMap, SIGNAL(mapped(int)), SLOT(changeVerHeader(int)));
            ui->syLayout->addWidget(lEdit);
        }
    }
    if (prevSymbol == - 1) {
        QCoreApplication::processEvents();
    }
    prevSymbol = arg1 - 1;
    changeButState();
    generated = false;
    resizeTable();
}

void RandomMachines::changeVerHeader(int sy) {
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

    ui->randTable->verticalHeaderItem(sy)->setText(symbol);
    ui->blanckSyCBox->setItemText(sy, symbol);
}

void RandomMachines::clearSyLayout() {
    QLayoutItem *item;
    while((item = ui->syLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void RandomMachines::resizeTable() {
    if (resizable) {
        if (ui->randTable->rowCount() == 0 && ui->randTable->columnCount() == 0) {
            return;
        }
        else if (ui->randTable->rowCount() == 0) {
            int columnWidth = ui->randTable->width()/ui->randTable->columnCount();
            int horExccess = ui->randTable->width() - ui->randTable->columnCount()*columnWidth;
            for (int i = 0; i < ui->randTable->columnCount(); i++) {
                if (horExccess > 1) {
                    ui->randTable->setColumnWidth(i, columnWidth + 1);
                    horExccess--;
                }
                else {
                    ui->randTable->setColumnWidth(i, columnWidth);
                }
            }
        }
        else if (ui->randTable->columnCount() == 0) {
            int rowHeigth = ui->randTable->height()/ui->randTable->rowCount();
            int verExccess = ui->randTable->height() - ui->randTable->rowCount()*rowHeigth;
            for (int i = 0; i < ui->randTable->rowCount(); i++) {
                if (verExccess > 1) {
                    ui->randTable->setRowHeight(i, rowHeigth + 1);
                    verExccess--;
                }
                else {
                    ui->randTable->setRowHeight(i, rowHeigth);
                }
            }
        }
        else {
            int rowHeigth = (ui->randTable->height() - ui->randTable->horizontalHeader()->height())/ui->randTable->rowCount();
            int columnWidth = (ui->randTable->width() - ui->randTable->verticalHeader()->width())/ui->randTable->columnCount();
            int horExccess = (ui->randTable->width() - ui->randTable->verticalHeader()->width()) - ui->randTable->columnCount()*columnWidth;
            int verExccess = (ui->randTable->height() - ui->randTable->horizontalHeader()->height()) - ui->randTable->rowCount()*rowHeigth;
            for (int i = 0; i < ui->randTable->rowCount(); i++) {
                if (verExccess > 1) {
                    ui->randTable->setRowHeight(i, rowHeigth + 1);
                    verExccess--;
                }
                else {
                    ui->randTable->setRowHeight(i, rowHeigth);
                }
            }
            for (int i = 0; i < ui->randTable->columnCount(); i++) {
                if (horExccess > 1) {
                    ui->randTable->setColumnWidth(i, columnWidth + 1);
                    horExccess--;
                }
                else {
                    ui->randTable->setColumnWidth(i, columnWidth);
                }
            }
        }
    }
}

void RandomMachines::headersChanged() {
    generated = false;
    changeButState();
}

void RandomMachines::on_nameEdit_textChanged()
{
    changeButState();
}

void RandomMachines::on_haltStEdit_textChanged(const QString &arg1)
{
    generated = false;
    changeButState();
    if (arg1 != nullptr) {
        ui->haltStEdit->setText(arg1.at(0));
    }
}

void RandomMachines::on_randBut_clicked()
{
    states->clear();
    symbols->clear();
    for (int i = 0; i < ui->randTable->columnCount(); i++) {
        states->append(ui->randTable->horizontalHeaderItem(i)->text().at(0));
    }
    for (int i = 0; i < ui->randTable->rowCount(); i++) {
        symbols->append(ui->randTable->verticalHeaderItem(i)->text().at(0));
    }
    int haltAct;
    if ((states->size() != 0) && (symbols->size() != 0)) {
        haltAct = qrand() % (states->size() * symbols->size());
    }
    for (int i = 0; i < symbols->size(); i++) {
        for (int j = 0; j < states->size(); j++) {
            QString action;
            action.append(symbols->at(qrand()%symbols->size()));
            action.append((qrand()%2 == 1) ? "R" : "L");
            if (haltAct != 0) {
                action.append(states->at(qrand()%states->size()));
            }
            else {
                action.append((ui->haltStEdit->text() == "" ? ui->haltStEdit->placeholderText() : ui->haltStEdit->text()));
            }
            haltAct--;
            QTableWidgetItem *tbAction = new QTableWidgetItem(action);
            tbAction->setFont(QFont("Meiryo", 16));
            tbAction->setTextAlignment(Qt::AlignCenter);
            tbAction->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            ui->randTable->setItem(i, j, tbAction);
        }
    }
    generated = true;
    changeButState();
}

void RandomMachines::changeButState() {
    ui->randBut->setEnabled(true);
    ui->saveBut->setEnabled(true);
    if (ui->stSel->text() == "" || ui->sySel->text() == "" || ui->stSel->text() == "0" || ui->sySel->text() == "0") {
        ui->randBut->setEnabled(false);
        ui->saveBut->setEnabled(false);
    }
    if (ui->nameEdit->toPlainText() == "") {
        ui->saveBut->setEnabled(false);
    }
    if (!generated) {
        ui->saveBut->setEnabled(false);
    }
}

void RandomMachines::on_saveBut_clicked()
{
    QMap<QString, QString> transFunct;
    for (int i = 0; i < symbols->size(); i++) {
        for (int j = 0; j < states->size(); j++) {
            QString key;
            key.append(states->at(j));
            key.append(symbols->at(i));
            transFunct.insert(key, ui->randTable->item(i, j)->text());
        }
    }
    QString name = ui->nameEdit->toPlainText();
    QChar initState = ui->initStCBox->currentText().at(0);
    QChar blanckSymbol = ui->blanckSyCBox->currentText().at(0);
    QChar haltState = (ui->haltStEdit->text() == "" ? ui->haltStEdit->placeholderText().at(0) : ui->haltStEdit->text().at(0));
    randMach = new Machine(&name, states, symbols, &transFunct, initState, blanckSymbol, haltState);
    ready = true;
}

bool RandomMachines::isReady() {
    return ready;
}

Machine *RandomMachines::getRandMach() {
    return randMach;
}
