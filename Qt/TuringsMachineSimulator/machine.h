#ifndef MACHINE_H
#define MACHINE_H

#include <QDebug>
#include <QFile>
#include <QDir>
#include <QLinkedList>
#include "tape.h"

class Machine
{
public:
    Machine(QFile *fileName);
    Machine(QString name, QVector<QChar> sts, QVector<QChar> syms, QMap<QString, QString> tFunct, QChar iSt, QChar hSt);
    bool isValid();
    // Control functions
    void start(std::list<QChar> inTape, int inPos, QChar bSym);
    void advance();
    bool halted();
    void halt();
    // Getters and Setters
    QChar getCurrentState();
    QChar getCurrentSymbol();
    std::list<QChar> getTape();
    int getTapeHeadOffset();
    QString getFileName();
    QChar getBlanckSym();
    QChar getInitState();
    void setInitState(QChar init);
    QChar getHaltState();
    void setHaltState(QChar halt);
    QVector<QChar> *getStates();
    QVector<QChar> *getSymbols();
    void setTransFunct(QMap<QString, QString> *tFunct);
    QString funct(QChar State, QChar Symbol);

private:
    QString makeKey(QChar st, QChar sy);
    void printTape(QChar st, int begin, int end);
    bool customTape = false;
    struct action {
        QChar wSymbol;
        QChar mTape;
        QChar nState;
    };
    // Machine variables
    bool valid;
    QVector<QChar> states;
    QVector<QChar> symbols;
    std::list<QChar> tape;
    QMap<QString, action> transFunct;
    QString fileName;
    QChar blanckSym;
    QChar initState;
    QChar haltState;
    // Simulation varaibles
    QChar pState;
    QChar cSymbol;
    std::list<QChar>::iterator head;
    int startP, endP, count;
};

#endif // MACHINE_H
