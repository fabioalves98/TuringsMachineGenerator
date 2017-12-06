#ifndef MACHINE_H
#define MACHINE_H

#include <QDebug>
#include <QFile>
#include <QLinkedList>

class Machine
{
public:
    Machine(QFile *fileName);
    void start();
    void reset();
    QLinkedList<QChar> getTape();
    QChar getBlanckSym();
    QChar getInitState();
    QChar getHaltState();
    QVector<QChar> *getStates();
    QVector<QChar> *getSymbols();
    QString funct(QChar State, QChar Symbol);
    static void verifyTable(QString fileName);
    
private:
    bool changeState(QString line, bool *i, bool *t);
    void removeSpaces(QString *line);
    void processInfo(QString line);
    void processTable(QString line);
    QString makeKey(QChar st, QChar sy);
    void printTape(QChar st, int begin, int end);
    struct action {
        QChar wSymbol;
        QChar mTape;
        QChar nState;
    };
    QVector<QChar> states;
    QVector<QChar> symbols;
    QLinkedList<QChar> tape;
    QMap<QString, action> transFunct;
    QString fileName;
    QChar blanckSym;
    QChar initState;
    QChar haltState;
};

#endif // MACHINE_H
