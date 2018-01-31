#include "tape.h"

Tape::Tape(QFile *tapeFile)
{
    if (!tapeFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        name = "Default";
        for (int i = 0; i < 3; i++) {
            tape.push_back('0');
        }
        headPos = 1;
        blanckSym = '0';
    }
    else {
        QFileInfo *tapeInfo = new QFileInfo(*tapeFile);
        name = tapeInfo->baseName();
        QTextStream in(tapeFile);
        QString prop = in.readLine();
        if (prop.split(":").at(0) == "hp") {
            headPos = prop.split(" ").at(1).toInt();
            prop = in.readLine();
            blanckSym = prop.split(" ").at(1).at(0);
        }
        else if (prop.split(":").at(0) == "bs") {
            blanckSym = prop.split(" ").at(1).at(0);
            prop = in.readLine();
            headPos = prop.split(" ").at(1).toInt();
        }
        else {
            qDebug() << "Error Reading Tape File";
        }
        QString tapeStr = in.readLine();
        for (int i = 0; i < tapeStr.length(); i++) {
            tape.push_back(tapeStr.at(i));
        }
    }
    defBlanckSym = blanckSym;
}

QString Tape::getName() {
    return name;
}

std::list<QChar> Tape::getTape()
{
    return tape;
}

std::list<QChar> Tape::getTempTape(int tempHeadPos) {
    tempTape = tape;
    if (signed(tempHeadPos) >= signed(tape.size() - 1)) {
        for (int i = tape.size() - 1; i <= tempHeadPos; i++) {
            tempTape.push_back(blanckSym);
        }
    }
    else if (tempHeadPos <= 0) {
        for (int i = tempHeadPos; i <= 0; i++) {
            tempTape.push_front(blanckSym);
        }
    }
    return tempTape;
}

std::list<QChar> Tape::getEditedTape(int tempHeadPos)
{
    tempTape = editedTape;
    if (signed(tempHeadPos) >= signed(editedTape.size() - 1)) {
        for (int i = editedTape.size() - 1; i <= tempHeadPos; i++) {
            tempTape.push_back(blanckSym);
        }
    }
    else if (tempHeadPos <= 0) {
        for (int i = tempHeadPos; i <= 0; i++) {
            tempTape.push_front(blanckSym);
        }
    }
    return tempTape;
}

void Tape::setEditedTape(std::list<QChar> inTape)
{
    editedTape = inTape;
}

QChar Tape::getBlanckSym() {
    return blanckSym;
}

QChar Tape::getDefBlanckSym()
{
    return defBlanckSym;
}

void Tape::setBlanckSym(QChar bs)
{
    blanckSym = bs;
}

int Tape::getTapeSize() {
    return tape.size();
}

int Tape::getTapePos() {
    return headPos;
}

