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

Tape::Tape(QString name, std::list<QChar> tape, QChar blanckSym, int headPos)
{
    this->name = name;
    this->tape = tape;
    this->blanckSym = blanckSym;
    this->headPos = headPos;
}

QString Tape::getName() {
    return name;
}

std::list<QChar> Tape::getTape()
{
    return tape;
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

