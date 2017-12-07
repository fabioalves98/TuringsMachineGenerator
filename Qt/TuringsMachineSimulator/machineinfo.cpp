#include "machineinfo.h"

MachineInfo::MachineInfo(QFile *file, QWidget *parent) : QWidget(parent)
{
    tMach = new Machine(file);
    symbols = tMach->getSymbols();
    states = tMach->getStates();
    tableItem = new QListWidgetItem;
    tableInfo = new QFileInfo(*file);
    tableItem->setText(tableInfo->baseName());
    tableItem->setFont(QFont("Meiryo", 10));
    tableItem->setIcon(QIcon(":/rec/icons/table.png"));

    for (int i = 0; i < symbols->size(); i++) {
        vTableHeader.append(new QTableWidgetItem(symbols->value(i)));
    }
    for (int i = 0; i < states->size(); i++) {
        hTableHeader.append(new QTableWidgetItem(states->value(i)));
    }
    for (int i = 0; i < symbols->size(); i++) {
        for (int j = 0; j < states->size(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem(tMach->funct(states->value(j), symbols->value(i)));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            tableElems.append(item);
        }
    }

    QStringList properties;
    properties << "Name: " << "Symbols: " << "States: " << "Blanck Symbol: " << "Inicial State: " << "Halt State: ";
    for (QString prop : properties) {
        QWidget *newPropW = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;
        QLabel *propName = new QLabel;
        propName->setText(prop);
        propName->setFont(QFont("Meiryo", 10, QFont::Bold));
        layout->addWidget(propName);
        QLabel *propValue = new QLabel;
        switch(properties.indexOf(prop)) {
            case 0: {
                propValue->setText(tableInfo->baseName());
                break;
            }
            case 1: {
                QString *symbolsStr = new QString;
                for (QChar symbol : *symbols) {
                    symbolsStr->append(symbol);
                    symbolsStr->append((" "));
                }
                propValue->setText(*symbolsStr);
                break;
            }
            case 2: {
                QString *statesStr = new QString;
                for (QChar state : *states) {
                    statesStr->append(state);
                    statesStr->append((" "));
                }
                propValue->setText(*statesStr);
                break;
            }
            case 3: {
                QString bSym(tMach->getBlanckSym());
                propValue->setText(bSym);
                break;
            }
            case 4: {
                QString iSt(tMach->getInitState());
                propValue->setText(iSt);
                break;
            }
            case 5: {
                QString hSt(tMach->getHaltState());
                propValue->setText(hSt);
                break;
            }
        }
        layout->addWidget(propValue, Qt::AlignLeft);
        newPropW->setLayout(layout);
        tableProp.append(newPropW);
    }
}

QListWidgetItem *MachineInfo::getTableListItem() {
    return tableItem;
}

Machine *MachineInfo::getMachine() {
    return tMach;
}

QFileInfo *MachineInfo::getFileInfo() {
    return tableInfo;
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

QVector<QWidget*> *MachineInfo::getTableProp() {
    return &tableProp;
}
