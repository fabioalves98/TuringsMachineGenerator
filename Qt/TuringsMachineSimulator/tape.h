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
    int getTapeSize();
    int getTapePos();
    void setTapePos(int pos);

private:
    QString name;
    std::list<QChar> tape;
    std::list<QChar> tempTape;
    int headPos;
};

#endif // TAPE_H
