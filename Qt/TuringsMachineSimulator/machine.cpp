#include "machine.h"

Machine::Machine(QFile *tableFile) {
    if (!tableFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error Opening Machine File" << endl;
        return;
    }
    QFileInfo *tableInfo = new QFileInfo(*tableFile);
    fileName = tableInfo->baseName();
    QTextStream in(tableFile);
    for (int i = 0; i < 2; i++) {
        QString prop = in.readLine();
        prop.replace(" ", ""); prop.replace(":", "");
        if ((prop.mid(0, 2) == "is") && (initState == nullptr)) {
            initState = prop.at(2);
        }
        else if ((prop.mid(0, 2) == "hs") && (haltState == nullptr)) {
            haltState = prop.at(2);
        }
        else {
            qDebug() << "Error Reading Machine File";
        }
    }
    while (!in.atEnd()) {
        QString line = in.readLine();
        line.replace(" ", "");
        if (line.at(0) == '*') {
            line = line.mid(1);
            for (QChar c : line) {
                states.push_back(c);
            }
        }
        else if (line == nullptr) {
            qDebug() << "reached end";
            break;
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
}

Machine::Machine(QString *name, QVector<QChar> *sts, QVector<QChar> *syms, QMap<QString, QString> *tFunct, QChar iSt, QChar bSy, QChar hSt) {
    fileName = *name;
    states = *sts;
    symbols = *syms;
    for (QChar st : states) {
        for (QChar sy : symbols) {
            QString key = makeKey(st, sy);
            QString move = tFunct->value(key);
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

void Machine::start(std::list<QChar> inTape, int inPos, QChar bSym) {
    tape.clear();
    tape = inTape;
    pState = initState;
    blanckSym = bSym;
    head = tape.begin();
    int headPos = (inPos > 0) ? inPos : 1;
    std::advance(head, headPos);
    startP = 0;
    endP = tape.size();
    count = 0;
}

bool Machine::halted() {
    return pState==haltState;
}

void Machine::halt() {
    pState = haltState;
}

void Machine::advance() {
    cSymbol = *head;
    QString key = makeKey(pState, cSymbol);
    action move = transFunct[key];
    if (move.wSymbol != nullptr) {
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
    }
    else {
        pState = haltState;
    }
}

QChar Machine::getCurrentState() {
    return pState;
}

QChar Machine::getCurrentSymbol() {
    return *head;
}

std::list<QChar> Machine::getTape() {
    return tape;
}

int Machine::getTapeHeadOffset() {
    int index = tape.size()/2 - std::distance(tape.begin(), head);
    return index;
}

QString Machine::getFileName() {
    return fileName;
}

QChar Machine::getBlanckSym() {
    return blanckSym;
}

QChar Machine::getInitState() {
    return initState;
}

void Machine::setInitState(QChar init) {
    initState = init;
}

QChar Machine::getHaltState() {
    return haltState;
}

void Machine::setHaltState(QChar halt) {
    haltState = halt;
}

QVector<QChar> *Machine::getStates() {
    return &states;
}

QVector<QChar> *Machine::getSymbols() {
    return &symbols;
}

void Machine::setTransFunct(QMap<QString, QString> *tFunct) {
    for (QChar st : states) {
        for (QChar sy : symbols) {
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

QString Machine::makeKey(QChar st, QChar sy) {
    QString key;
    key.append(st);
    key.append(sy);
    return key;
}

void Machine::verifyTable(QString fileName) {
    qDebug() << fileName << endl;
}
