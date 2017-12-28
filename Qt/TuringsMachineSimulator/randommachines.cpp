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
    randMach = new MachineInfo(&name, states, symbols, &transFunct);
    ready = true;
}

bool RandomMachines::isReady() {
    return ready;
}

MachineInfo *RandomMachines::getRandMach() {
    return randMach;
}

