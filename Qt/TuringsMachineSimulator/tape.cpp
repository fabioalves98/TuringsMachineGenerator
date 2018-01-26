#include "tape.h"

Tape::Tape(QFile *tapeFile)
{
    if (!tapeFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        name = "Default";
        for (int i = 0; i < 3; i++) {
            tape.push_back('0');
        }
        headPos = 1;
    }
    else {
        QFileInfo *tapeInfo = new QFileInfo(*tapeFile);
        name = tapeInfo->baseName();
        QTextStream in(tapeFile);
        headPos = in.readLine().toInt();
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
    return tape;
}

int Tape::getTapePos() {
    return headPos;
}

void Tape::setTapePos(int pos) {
    headPos = pos;
}
