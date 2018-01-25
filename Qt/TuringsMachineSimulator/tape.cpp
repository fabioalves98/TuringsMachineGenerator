#include "tape.h"

Tape::Tape(QFile *tapeFile)
{
    if (!tapeFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        name = "Default";
        custom = false;
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
        custom = true;
    }
}

QString Tape::getName() {
    return name;
}
