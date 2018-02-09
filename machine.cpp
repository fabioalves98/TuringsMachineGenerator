#include "machine.h"

Machine::Machine(QFile *machFile)
{
    valid = false;
    // Creates a machine from a text file
    if (!machFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QFileInfo *machInfo = new QFileInfo(*machFile);
    fileName = machInfo->baseName();
    QTextStream in(machFile);
    for (int i = 0; i < 2; i++)
    {
        QString prop = in.readLine();
        prop.replace(" ", ""); prop.replace(":", "");
        if (prop.length() != 3)
        {
            return;
        }
        if ((prop.mid(0, 2) == "is") && (initState == nullptr))
        {
            initState = prop.at(2);
        }
        else if ((prop.mid(0, 2) == "hs") && (haltState == nullptr))
        {
            haltState = prop.at(2);
        }
        else
        {
            return;
        }
    }
    while (!in.atEnd())
    {
        QString line = in.readLine();
        line.replace(" ", "");
        if (line.isEmpty())
        {
            break;
        }
        if (line.at(0) == '*')
        {
            line = line.mid(1);
            for (QChar c : line)
            {
                states.push_back(c);
            }
        }
        else
        {
            if (line.length() != (1 + 3*states.size()))
            {
               return;
            }
            symbols.push_back(line.at(0));
            line = line.mid(1);
            int count = 0;
            while (line.length() != 0)
            {
                QString elem = line.mid(0,3);
                line = line.mid(3);
                QChar state = states.at(count);
                QChar symbol = symbols.last();
                QString key = makeKey(state, symbol);
                action act;
                act.wSymbol = elem.at(0);
                act.mTape = elem.at(1);
                act.nState = elem.at(2);
                transFunct.insert(key, act);
                count++;
            }
        }
    }
    valid = true;
}

Machine::Machine(QString name, QVector<QChar> sts, QVector<QChar> syms, QMap<QString, QString> tFunct, QChar iSt, QChar hSt)
{
    // Creates a machine from the provided containers and variables
    fileName = name;
    states = sts;
    symbols = syms;
    for (QChar st : states)
    {
        for (QChar sy : symbols)
        {
            QString key = makeKey(st, sy);
            QString move = tFunct.value(key);
            action act;
            act.wSymbol = move.at(0);
            act.mTape = move.at(1);
            act.nState = move.at(2);
            transFunct.insert(key, act);
        }
    }
    initState = iSt;
    haltState = hSt;
}

bool Machine::isValid()
{
    // Checks if the machine created is valid
    return valid;
}

void Machine::advance()
{
    // Advances one step in the simulation
    cSymbol = *head;
    QString key = makeKey(pState, cSymbol);
    action move = transFunct[key];
    if (move.wSymbol != nullptr)
    {
        *head = move.wSymbol;
        if (move.mTape == 'R')
        {
            if (startP == 0)
            {
                tape.push_front(blankSym);
            }
            else
            {
                startP--;
                endP--;
            }
            head = std::prev(head);
        }
        else if (move.mTape == 'L')
        {
            startP++;
            endP++;
            head = std::next(head);
            if (tape.size() < endP)
            {
                tape.push_back(blankSym);
            }
        }
        pState = move.nState;
        count++;
    }
    else
    {
        pState = haltState;
    }
}

QString Machine::funct(QChar st, QChar sy)
{
    // Return the action correspondent to the key provided
    QString key = makeKey(st, sy);
    action move = transFunct.value(key);
    QString toReturn;
    toReturn.append(move.wSymbol).append(move.mTape).append(move.nState);
    return toReturn;
}

QChar Machine::getBlankSym()
{
    // Returns the blank symbol
    return blankSym;
}

QChar Machine::getCurrentState()
{
    // Returns the current state
    return pState;
}

QChar Machine::getCurrentSymbol()
{
    // Returns the current symbol
    return *head;
}

QString Machine::getFileName()
{
    // Returns the name of the machine
    return fileName;
}

QChar Machine::getHaltState()
{
    // Returns the halt state
    return haltState;
}

QChar Machine::getInitState()
{
    // Returns the initial state
    return initState;
}

QVector<QChar> *Machine::getStates()
{
    // Returns the states list
    return &states;
}

QVector<QChar> *Machine::getSymbols()
{
    // Returns the symbols list
    return &symbols;
}

std::list<QChar> Machine::getTape()
{
    // Returns the tape
    return tape;
}

int Machine::getTapeHeadOffset()
{
    // Returns the offset of the heads position to the middle of the tape
    int index = tape.size()/2 - std::distance(tape.begin(), head);
    return index;
}

void Machine::halt()
{
    // Stops the simulation
    pState = haltState;
}

bool Machine::halted()
{
    // Checks if the machine halted
    return pState==haltState;
}

QString Machine::makeKey(QChar st, QChar sy)
{
    // Creates a key to access the transition function
    QString key;
    key.append(st);
    key.append(sy);
    return key;
}

void Machine::setHaltState(QChar halt)
{
    // Changes the halt state
    haltState = halt;
}

void Machine::setInitState(QChar init)
{
    // Changes the initial state
    initState = init;
}

void Machine::setTransFunct(QMap<QString, QString> *tFunct)
{
    // Changes the transition function
    for (QChar st : states)
    {
        for (QChar sy : symbols)
        {
            QString key = makeKey(st, sy);
            QString move = tFunct->value(key);
            action act;
            act.wSymbol = move.at(0);
            act.mTape = move.at(1);
            act.nState = move.at(2);
            transFunct.insert(key, act);
        }
    }
}

void Machine::start(std::list<QChar> inTape, int inPos, QChar bSym)
{
    // Asigns a tape to the machine to start the simulation
    tape.clear();
    tape = inTape;
    pState = initState;
    blankSym = bSym;
    head = tape.begin();
    int headPos = (inPos > 0) ? inPos : 1;
    std::advance(head, headPos);
    startP = 0;
    endP = tape.size();
    count = 0;
}
