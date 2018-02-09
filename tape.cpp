#include "tape.h"

Tape::Tape(QFile *tapeFile)
{
    valid = false;
    // Constructs a tape from a text file
    if (!tapeFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        name = "Default";
        for (int i = 0; i < 3; i++)
        {
            tape.push_back('0');
        }
        headPos = 1;
        blankSym = '0';
    }
    else
    {
        QFileInfo *tapeInfo = new QFileInfo(*tapeFile);
        name = tapeInfo->baseName();
        QTextStream in(tapeFile);
        for (int i = 0; i < 2; i++)
        {
            QString prop = in.readLine();
            prop.replace(" ", ""); prop.replace(":", "");
            if (prop.length() < 3)
            {
                return;
            }
            if (prop.mid(0, 2) == "hp")
            {
                headPos = prop.split("hp").at(1).toInt();
            }
            else if ((prop.mid(0, 2) == "bs") && (blankSym == nullptr))
            {
                blankSym = prop.at(2);
            }
            else
            {
                return;
            }
        }
        QString tapeStr = in.readLine();
        for (int i = 0; i < tapeStr.length(); i++)
        {
            tape.push_back(tapeStr.at(i));
        }
    }
    valid = true;
}

Tape::Tape(QString name, std::list<QChar> tape, QChar blankSym, int headPos)
{
    // Creates a tape from the provided containers and variables
    this->name = name;
    this->tape = tape;
    this->blankSym = blankSym;
    this->headPos = headPos;
}

bool Tape::isValid()
{
    // Checks if the tape created is valid
    return valid;
}

QChar Tape::getBlankSym()
{
    // Returns the blank symbol
    return blankSym;
}

QString Tape::getName()
{
    // Returns the tape name
    return name;
}

std::list<QChar> Tape::getTape()
{
    // Returns the tape
    return tape;
}

int Tape::getTapePos()
{
    // Retruns the initial head position
    return headPos;
}

int Tape::getTapeSize()
{
    // Returns the tape size
    return tape.size();
}
