#ifndef MACHINEINFO_H
#define MACHINEINFO_H

#include <QWidget>
#include <QFileDialog>
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
    explicit MachineInfo(QString *name, QVector<QChar> *states, QVector<QChar> *symbols, QMap<QString, QString> *transFunct, QWidget *parent = nullptr);
    void setTransFunct(QMap<QString, QString> *tFunct);
    Machine *getMachine();
    QString getFileName();
    QListWidgetItem *getTableListItem();

    QVector<QTableWidgetItem*> *getHTableHeader();
    QVector<QTableWidgetItem*> *getVTableHeader();
    QVector<QTableWidgetItem*> *getTableElems();
signals:

public slots:

private:
    void genInfo();
    Machine *tMach;
    QVector<QChar> *symbols;
    QVector<QChar> *states;
    QListWidgetItem *tableItem;

    QVector<QTableWidgetItem*> vTableHeader;
    QVector<QTableWidgetItem*> hTableHeader;
    QVector<QTableWidgetItem*> tableElems;
    QVector<QWidget*> tableProp;
};

#endif // MACHINEINFO_H
