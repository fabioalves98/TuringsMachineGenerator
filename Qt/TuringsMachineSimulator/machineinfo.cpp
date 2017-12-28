#include "machineinfo.h"

MachineInfo::MachineInfo(QFile *file, QWidget *parent) : QWidget(parent)
{
    tMach = new Machine(file);
    symbols = tMach->getSymbols();
    states = tMach->getStates();
    tableItem = new QListWidgetItem;
    tableItem->setText(tMach->getFileName());
    tableItem->setFont(QFont("Meiryo", 11));
    tableItem->setIcon(QIcon(":/rec/icons/table.png"));

    for (int i = 0; i < symbols->size(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(symbols->value(i));
        item->setFont(QFont("Meiryo", 11));
        vTableHeader.append(item);
    }
    for (int i = 0; i < states->size(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(states->value(i));
        item->setFont(QFont("Meiryo", 11));
        hTableHeader.append(item);
    }
    for (int i = 0; i < symbols->size(); i++) {
        for (int j = 0; j < states->size(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem(tMach->funct(states->value(j), symbols->value(i)));
            item->setFont(QFont("Meiryo", 15));
            item->setTextColor(QColor(Qt::white));
            item->setTextAlignment(Qt::AlignCenter);
            //item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            tableElems.append(item);
        }
    }
}

MachineInfo::MachineInfo(QString *name, QVector<QChar> *states, QVector<QChar> *symbols, QMap<QString, QString> *transFunct, QWidget *parent) : QWidget(parent)
{
    tMach = new Machine(name, states, symbols, transFunct);
    symbols = tMach->getSymbols();
    states = tMach->getStates();
    tableItem = new QListWidgetItem;
    tableItem->setText(tMach->getFileName());
    tableItem->setFont(QFont("Meiryo", 11));
    tableItem->setIcon(QIcon(":/rec/icons/table.png"));

    for (int i = 0; i < symbols->size(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(symbols->value(i));
        item->setFont(QFont("Meiryo", 11));
        vTableHeader.append(item);
    }
    for (int i = 0; i < states->size(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(states->value(i));
        item->setFont(QFont("Meiryo", 11));
        hTableHeader.append(item);
    }
    for (int i = 0; i < symbols->size(); i++) {
        for (int j = 0; j < states->size(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem(tMach->funct(states->value(j), symbols->value(i)));
            item->setFont(QFont("Meiryo", 15));
            item->setTextColor(QColor(Qt::white));
            item->setTextAlignment(Qt::AlignCenter);
            //item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            tableElems.append(item);
        }
    }
}

QListWidgetItem *MachineInfo::getTableListItem() {
    return tableItem;
}

Machine *MachineInfo::getMachine() {
    return tMach;
}

QString MachineInfo::getFileName() {
    return tMach->getFileName();
}

QVector<QTableWidgetItem*> *MachineInfo::getHTableHeader() {
    return &hTableHeader;
}

QVector<QTableWidgetItem*> *MachineInfo::getVTableHeader() {
    return &vTableHeader;
}

QVector<QTableWidgetItem*> *MachineInfo::getTableElems() {
    return &tableElems;
}
