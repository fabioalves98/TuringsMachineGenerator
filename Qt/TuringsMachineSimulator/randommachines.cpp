#include "randommachines.h"
#include "ui_randommachines.h"

RandomMachines::RandomMachines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RandomMachines)
{
    ui->setupUi(this);
    this->setWindowTitle("Random Machine Creation");
    ui->randTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->randTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    states = new QVector<QChar>;
    symbols = new QVector<QChar>;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    ui->saveBut->setEnabled(false);
}

RandomMachines::~RandomMachines()
{
    delete ui;
}

void RandomMachines::on_stSel_valueChanged(int arg1)
{
    ui->randTable->clearContents();
    ui->randTable->setColumnCount(arg1);
    if (arg1 != 0) {
        states->clear();
        for (int i = 0; i < arg1; i++) {
            if (ui->randTable->rowCount() == 0) {
                ui->randTable->setColumnWidth(i, ui->randTable->width()/arg1);
            }
            else {
                ui->randTable->setColumnWidth(i, (ui->randTable->width() - ui->randTable->verticalHeader()->width())/arg1);
            }
            states->append(abc.at(i));
            QTableWidgetItem *hHeader = new QTableWidgetItem(QString(abc.at(i)));
            hHeader->setFont(QFont("Meiryo", 12));
            ui->randTable->setHorizontalHeaderItem(i, hHeader);
        }
    }
    clearStLayout();
    for (int i = 0; i < arg1; i++) {
        QLineEdit *lEdit = new QLineEdit;
        lEdit->setMaximumHeight(ui->stSel->height());
        lEdit->setMaximumWidth(ui->stSel->width());
        lEdit->setAlignment(Qt::AlignCenter);
        lEdit->setPlaceholderText(abc.at(i));
        QSignalMapper *sigMap = new QSignalMapper(this);
        connect(lEdit, SIGNAL(textChanged(QString)), sigMap, SLOT(map()));
        sigMap->setMapping(lEdit, i);
        connect(sigMap, SIGNAL(mapped(int)), SLOT(changeHorHeader(int)));
        ui->stLayout->addWidget(lEdit);
    }
}

void RandomMachines::changeHorHeader(int st) {
   QString state = dynamic_cast<QLineEdit*>(ui->stLayout->itemAt(st)->widget())->text();
   ui->randTable->setHorizontalHeaderItem(st, new QTableWidgetItem(state));
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
    ui->randTable->setRowCount(arg1);
    if (arg1 != 0) {
        symbols->clear();
        for (int i = 0; i < arg1; i++) {
            if (ui->randTable->columnCount() == 0) {
                ui->randTable->setRowHeight(i, ui->randTable->height()/arg1);
            }
            else {
                ui->randTable->setRowHeight(i, (ui->randTable->height() - ui->randTable->horizontalHeader()->height())/arg1);
            }
            symbols->append(QString::number(i).at(0));
            QTableWidgetItem *vHeader = new QTableWidgetItem(QString::number(i));
            vHeader->setFont(QFont("Meiryo", 12));
            ui->randTable->setVerticalHeaderItem(i, vHeader);
        }
    }
    clearSyLayout();
    for (int i = 0; i < arg1; i++) {
        QLineEdit *lEdit = new QLineEdit;
        lEdit->setMaximumHeight(ui->sySel->height());
        lEdit->setMaximumWidth(ui->sySel->width());
        lEdit->setAlignment(Qt::AlignCenter);
        lEdit->setPlaceholderText(QString::number(i));
        QSignalMapper *sigMap = new QSignalMapper(this);
        connect(lEdit, SIGNAL(textChanged(QString)), sigMap, SLOT(map()));
        sigMap->setMapping(lEdit, i);
        connect(sigMap, SIGNAL(mapped(int)), SLOT(changeVerHeader(int)));
        ui->syLayout->addWidget(lEdit);
    }
}

void RandomMachines::changeVerHeader(int sy) {
    QString symbol = dynamic_cast<QLineEdit*>(ui->syLayout->itemAt(sy)->widget())->text();
    ui->randTable->setVerticalHeaderItem(sy, new QTableWidgetItem(symbol));}

void RandomMachines::clearSyLayout() {
    QLayoutItem *item;
    while((item = ui->syLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void RandomMachines::on_randBut_clicked()
{
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
                action.append("H");
            }
            haltAct--;
            QTableWidgetItem *tbAction = new QTableWidgetItem(action);
            tbAction->setFont(QFont("Meiryo", 16));
            tbAction->setTextColor(QColor(Qt::white));
            tbAction->setTextAlignment(Qt::AlignCenter);
            tbAction->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            ui->randTable->setItem(i, j, tbAction);
        }
    }
    ui->saveBut->setEnabled(true);
}

void RandomMachines::on_saveBut_clicked()
{
    if (ui->nameEdit->toPlainText() == nullptr) {
        QPalette p = ui->nameEdit->palette();
        p.setColor(QPalette::Base, QColor(255, 0, 0, 100));
        ui->nameEdit->setPalette(p);
        return;
    }
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
    randMach = new Machine(&name, states, symbols, &transFunct);
    ready = true;
}

bool RandomMachines::isReady() {
    return ready;
}

Machine *RandomMachines::getRandMach() {
    return randMach;
}
