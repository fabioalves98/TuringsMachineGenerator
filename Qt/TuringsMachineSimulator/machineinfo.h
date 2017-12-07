#ifndef MACHINEINFO_H
#define MACHINEINFO_H

#include <QWidget>
#include <QFileDialog>
#include <QDir>
#include <QListWidget>
#include <QTableWidget>
#include <QLayout>
#include <QLabel>
#include <machine.h>

class MachineInfo : public QWidget
{
    Q_OBJECT
public:
    explicit MachineInfo(QFile *file, QWidget *parent = nullptr);
    Machine *getMachine();
    QFileInfo *getFileInfo();
    QListWidgetItem *getTableListItem();

    QVector<QTableWidgetItem*> *getHTableHeader();
    QVector<QTableWidgetItem*> *getVTableHeader();
    QVector<QTableWidgetItem*> *getTableElems();
    QVector<QWidget*> *getTableProp();
signals:

public slots:

private:
    Machine *tMach;
    QVector<QChar> *symbols;
    QVector<QChar> *states;
    QFileInfo *tableInfo;
    QListWidgetItem *tableItem;

    QVector<QTableWidgetItem*> vTableHeader;
    QVector<QTableWidgetItem*> hTableHeader;
    QVector<QTableWidgetItem*> tableElems;

    QVector<QWidget*> tableProp;
};

#endif // MACHINEINFO_H
