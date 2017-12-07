#include "machine.h"

Machine::Machine(QFile *tableFile) {
    if (!tableFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error Opening Table File" << endl;
        return;
    }
    bool info = false, table = false;
    QTextStream in(tableFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line << endl;
        if (changeState(line, &info, &table)) {
            continue;
        }
        else {
            if (info) {
                removeSpaces(&line);
                processInfo(line);
            }
            else if (table) {
                removeSpaces(&line);
                processTable(line);
            }
            else {
                break;
            }
        }
        qDebug() << line << endl;
    }
    qDebug() << blanckSym << initState << haltState;
    qDebug() << "States";
    for (QChar s : states) {
        qDebug() << s;
    }
    qDebug() << "Symbols";
    for (QChar s : symbols) {
        qDebug() << s;
    }
    qDebug() << "Table";
    for (QChar st : states) {
        for (QChar sy : symbols) {
            QString key = makeKey(st, sy);
            action aux = transFunct.value(key);
            qDebug() << key << aux.wSymbol << aux.mTape << aux.nState;
        }
    }
}

void Machine::start() {
    qDebug() << "Simulation";
    int tapeSize = 3;
    tape.assign(3, blanckSym);
    /*for (int i = 0; i < tapeSize; i++) {
        tape.append(blanckSym);
    }*/
    pState = initState;
    head = tape.begin();
    std::advance(head, tapeSize/2);
    startP = 0;
    endP = tapeSize;
    count = 0;
    printTape(pState, 0, tape.size());
}

void Machine::reset() {
    tape.clear();
}

std::list<QChar> Machine::advance() {
    QChar symbol = *head;
    QString key = makeKey(pState, symbol);
    qDebug() << key;
    action move = transFunct[key];
    *head = move.wSymbol;
    if (move.mTape == 'R') {
        if (startP == 0){
            tape.push_front(blanckSym);
        }
        else{
            startP--;
            endP--;
        }
        head = std::prev(head);
    }
    else {
        startP++;
        endP++;
        head = std::next(head);
        if (tape.size() < endP) {
            tape.push_back(blanckSym);
        }
    }
    pState = move.nState;
    count++;
    qDebug() << move.wSymbol << " " << move.mTape << " " << move.nState;
    qDebug() << getTapeHeadOffset();
    printTape(pState, 0, tape.size());
    return tape;
}

bool Machine::halted() {
    return pState==haltState;
}

std::list<QChar> Machine::getTape() {
    return tape;
}

int Machine::getTapeHeadOffset() {
    int index = tape.size()/2 - std::distance(tape.begin(), head);
    return index;
}

QChar Machine::getBlanckSym() {
    return blanckSym;
}

QChar Machine::getInitState() {
    return initState;
}

QChar Machine::getHaltState() {
    return haltState;
}

QVector<QChar> *Machine::getStates() {
    return &states;
}

QVector<QChar> *Machine::getSymbols() {
    return &symbols;
}

QString Machine::funct(QChar st, QChar sy) {
    QString key = makeKey(st, sy);
    action move = transFunct.value(key);
    QString toReturn;
    toReturn.append(move.wSymbol).append(move.mTape).append(move.nState);
    return toReturn;
}

void Machine::printTape(QChar st, int begin, int end) {
    auto begin_it = tape.begin();
    auto end_it = tape.begin();
    std::advance(begin_it, begin);
    std::advance(end_it, end);
    QString toPrint;
    toPrint.append(QString::number(count));
    toPrint.append(" - ");
    toPrint.append(" ");
    toPrint.append(st);
    toPrint.append(" ");
    for (;begin_it != end_it; begin_it++) {
        toPrint.append("[");
        toPrint.append(*begin_it);
        toPrint.append("]");
    }
    qDebug() << toPrint;
}

bool Machine::changeState(QString line, bool *i, bool *t) {
    if (line == "begin_info") {
            *i = true;
            return true;
        }
        else if (line == "begin_table") {
            *i = false;
            *t = true;
            return true;
        }
        else if (line == "end_table") {
            *t = false;
            return true;
        }
    else {
        return false;
    }
}

void Machine::removeSpaces(QString *line) {
    line->replace(" ", "");
}

void Machine::processInfo(QString line) {
    QString type = line.mid(0, 2);
    line.replace(" ", "");
    if (type == "bs") {
        blanckSym = line.at(3);
    }
    else if (type == "is") {
        initState = line.at(3);
    }
    else if (type == "fs") {
        haltState = line.at(3);
    }
    else {
        qDebug() << "ERROR Processing Table Info" << endl;
    }
}

void Machine::processTable(QString line) {
    if (line.at(0) == '*') {
        line = line.mid(1);
        for (QChar c : line) {
            states.push_back(c);
        }
    }
    else {
        symbols.push_back(line.at(0));
        line = line.mid(1);
        int count = 0;
        while (line.length() != 0) {
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

QString Machine::makeKey(QChar st, QChar sy) {
    QString key;
    key.append(st);
    key.append(sy);
    return key;
}

void Machine::verifyTable(QString fileName) {
    qDebug() << fileName << endl;
}
