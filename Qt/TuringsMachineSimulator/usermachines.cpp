#include "usermachines.h"
#include "ui_usermachines.h"

UserMachines::UserMachines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMachines)
{
    ui->setupUi(this);
}

UserMachines::~UserMachines()
{
    delete ui;
}

void UserMachines::start()
{
    QList<int> sizes = ui->splitter->sizes();
    sizes[0] = (int)ui->splitter->width()*0.7;
    ui->splitter->setSizes(sizes);

    sizes = ui->splitter_2->sizes();
    sizes[1] = (int)ui->splitter_2->height()*0.7;
    ui->splitter_2->setSizes(sizes);

    sizes = ui->splitter_3->sizes();
    sizes[0] = (int)ui->splitter_3->width()*0.2;
    ui->splitter_3->setSizes(sizes);
}

void UserMachines::on_addTableBt_clicked()
{
    QFile *tableFile = new QFile(QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath() + "/Mega/Bolsa/Turings-Machine-Simulator/C++/tables", "Text Files (*.txt);;All Files(*)"));
    test = new Machine(tableFile);
    QListWidgetItem *newTable = new QListWidgetItem;
    QFileInfo fileInfo(*tableFile);
    newTable->setText(fileInfo.baseName());
    newTable->setFont(QFont("Meiryo", 10));
    newTable->setIcon(QIcon(":/rec/icons/table.png"));
    ui->tablesList->addItem(newTable);
    ui->tablesList->setIconSize(QSize(20, 20));

    QVector<QChar> *symbols = test->getSymbols();
    QVector<QChar> *states = test->getStates();
    ui->tableView->setRowCount(symbols->size());
    ui->tableView->setColumnCount(states->size());
    for (int i = 0; i < symbols->size(); i++) {
        ui->tableView->setRowHeight(i, (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/symbols->size());
        QTableWidgetItem *item = new QTableWidgetItem(symbols->value(i));
        ui->tableView->setVerticalHeaderItem(i, item);
    }
    for (int i = 0; i < states->size(); i++) {
        ui->tableView->setColumnWidth(i, (ui->tableView->width() - ui->tableView->verticalHeader()->width())/states->size());
        QTableWidgetItem *item = new QTableWidgetItem(states->value(i));
        ui->tableView->setHorizontalHeaderItem(i, item);
    }
    for (int i = 0; i < symbols->size(); i++) {
        for (int j = 0; j < states->size(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem(test->funct(states->value(j), symbols->value(i)));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
            ui->tableView->setItem(i, j, item);
        }
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QStringList properties;
    properties << "Name: " << "Symbols: " << "States: " << "Blanck Symbol: " << "Inicial State: " << "Halt State: ";
    ui->propList->clear();
    for (QString prop : properties) {
        QListWidgetItem *newProI = new QListWidgetItem;
        QWidget *newPropW = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;
        QLabel *propName = new QLabel;
        propName->setText(prop);
        propName->setFont(QFont("Meiryo", 10, QFont::Bold));
        layout->addWidget(propName);
        QLabel *propValue = new QLabel;
        switch(properties.indexOf(prop)) {
            case 0: {
                propValue->setText(fileInfo.baseName());
                break;
            }
            case 1: {
                QString *symbolsStr = new QString;
                for (QChar symbol : *symbols) {
                    symbolsStr->append(symbol);
                    symbolsStr->append((" "));
                }
                propValue->setText(*symbolsStr);
                break;
            }
            case 2: {
                QString *statesStr = new QString;
                for (QChar state : *states) {
                    statesStr->append(state);
                    statesStr->append((" "));
                }
                propValue->setText(*statesStr);
                break;
            }
            case 3: {
                QString bSym(test->getBlanckSym());
                propValue->setText(bSym);
                break;
            }
            case 4: {
                QString iSt(test->getInitState());
                propValue->setText(iSt);
                break;
            }
            case 5: {
                QString hSt(test->getHaltState());
                propValue->setText(hSt);
                break;
            }
        }
        layout->addWidget(propValue, Qt::AlignLeft);
        newPropW->setLayout(layout);
        newPropW->show();
        newProI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
        ui->propList->addItem(newProI);
        ui->propList->setItemWidget(newProI, newPropW);

        ui->simList->clear();
    }
}

void UserMachines::on_simBt_clicked()
{
    ui->simList->clear();
    test->reset();
    test->start();

    std::list<QChar> tape;
    QString tapeStr;
    while (!test->halted()) {
        QThread::msleep(100);
        QCoreApplication::processEvents();
        tape = test->advance();
        int offset = test->getTapeHeadOffset();
        tapeStr = "";
        for (QChar sym : tape) {
            tapeStr.append("[");
            tapeStr.append(sym);
            tapeStr.append("]");
        }
        if (tape.size() % 2 == 0) {
            tapeStr.append("   ");
        }
        if (offset > 0) {
            for (int i = 0; i < abs(offset); i++) {
                tapeStr.prepend("      ");
            }
        }
        else if (offset < 0) {
            for (int i = 0; i < abs(offset); i++) {
                tapeStr.append("      ");
            }
        }
        QListWidgetItem *newTapeI = new QListWidgetItem;
        QLabel *tableText = new QLabel;
        tableText->setText(tapeStr);
        tableText->setFont(QFont("Courier", 11, QFont::Bold));
        tableText->setAlignment(Qt::AlignCenter);
        newTapeI->setSizeHint(tableText->sizeHint());
        newTapeI->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
        ui->simList->addItem(newTapeI);
        ui->simList->setItemWidget(newTapeI, tableText);
        ui->simList->scrollToBottom();
    }
}

void UserMachines::resizeEvent(QResizeEvent *event)
{
    update();
    QWidget::resizeEvent(event);
}
