#ifndef TAPE_H
#define TAPE_H

#include <QDebug>
#include <QFile>
#include <QFileInfo>

class Tape
{
public:
    Tape(QFile *tapeFile);
    Tape(QString name, std::list<QChar> tape, QChar blanckSym, int headPos);
    bool isValid();
    QString getName();
    std::list<QChar> getTape();
    QChar getBlankSym();
    int getTapeSize();
    int getTapePos();

private:
    bool valid;
    QString name;
    std::list<QChar> tape;
    QChar blankSym;
    int headPos;
};

#endif // TAPE_H
