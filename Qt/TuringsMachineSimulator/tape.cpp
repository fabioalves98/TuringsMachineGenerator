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
}

QString Tape::getName() {
    return name;
}

std::list<QChar> Tape::getTape() {
    tempTape = tape;
    if (signed(headPos) >= signed(tape.size() - 1)) {
        for (int i = tape.size() - 1; i <= headPos; i++) {
            tempTape.push_back(blanckSym);
        }
    }
    else if (headPos <= 0) {
        for (int i = headPos; i <= 0; i++) {
            tempTape.push_front(blanckSym);
        }
    }
    return tempTape;
}

QChar Tape::getBlanckSym() {
    return blanckSym;
}

int Tape::getTapeSize() {
    return tape.size();
}

int Tape::getTapePos() {
    return headPos;
}

void Tape::setTapePos(int pos) {
    headPos = pos;
}
