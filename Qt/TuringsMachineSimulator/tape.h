#ifndef TAPE_H
#define TAPE_H

#include <QDebug>
#include <QFile>
#include <QFileInfo>

class Tape
{
public:
    Tape(QFile *tapeFile);
    QString getName();
    std::list<QChar> getTape();
    std::list<QChar> getTempTape(int tempHeadPos);
    std::list<QChar> getEditedTape(int tempHeadPos);
    void setEditedTape(std::list<QChar> inTape);
    QChar getBlanckSym();
    QChar getDefBlanckSym();
    void setBlanckSym(QChar bs);
    int getTapeSize();
    int getTapePos();

private:
    QString name;
    QChar defBlanckSym;
    QChar blanckSym;
    std::list<QChar> tape;
    int headPos;
    std::list<QChar> editedTape;
    std::list<QChar> tempTape;

};

#endif // TAPE_H
