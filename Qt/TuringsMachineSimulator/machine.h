#ifndef MACHINE_H
#define MACHINE_H

#include <QDebug>
#include <QFile>
#include <QDir>
#include <QLinkedList>

class Machine
{
public:
    Machine(QFile *fileName);
    Machine(QString *name, QVector<QChar> *sts, QVector<QChar> *syms, QMap<QString, QString> *tFunct, QChar iSt, QChar bSy, QChar hSt);
    void setTape(QFile *fileName);
    void start();
    void reset();
    bool halted();
    void halt();
    void advance();
    QChar getCurrentState();
    QChar getCurrentSymbol();
    std::list<QChar> getTape();
    int getTapeHeadOffset();
    QString getFileName();
    QChar getBlanckSym();
    QChar getInitState();
    QChar getHaltState();
    QVector<QChar> *getStates();
    QVector<QChar> *getSymbols();
    void setTransFunct(QMap<QString, QString> *tFunct);
    QString funct(QChar State, QChar Symbol);
    static void verifyTable(QString fileName);

private:
    bool changeState(QString line, bool *i, bool *t);
    void removeSpaces(QString *line);
    void processInfo(QString line);
    void processTable(QString line);
    QString makeKey(QChar st, QChar sy);
    void printTape(QChar st, int begin, int end);
    bool customTape = false;
    QFile *tapeFile;
    struct action {
        QChar wSymbol;
        QChar mTape;
        QChar nState;
    };
    QVector<QChar> states;
    QVector<QChar> symbols;
    std::list<QChar> tape;
    QMap<QString, action> transFunct;
    QString fileName;
    QChar blanckSym;
    QChar initState;
    QChar haltState;

    QChar pState;
    QChar cSymbol;
    std::list<QChar>::iterator head;
    int startP, endP, count;
};

#endif // MACHINE_H
