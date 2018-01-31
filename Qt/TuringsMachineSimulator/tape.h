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
    QString getName();
    std::list<QChar> getTape();
    QChar getBlanckSym();
    int getTapeSize();
    int getTapePos();

private:
    QString name;
    std::list<QChar> tape;
    QChar blanckSym;
    int headPos;
};

#endif // TAPE_H
