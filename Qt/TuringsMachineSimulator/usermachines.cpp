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

    connect(ui->tablesList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(getMachToDispay(QListWidgetItem*)));
}

void UserMachines::resizeEvent(QResizeEvent *event)
{
    update();
    QWidget::resizeEvent(event);
}

void UserMachines::on_addTableBt_clicked()
{
    // Initialize new Table, and display it
    QFile *tableFile = new QFile(QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath() + "/Mega/Bolsa/Turings-Machine-Simulator/C++/tables", "Text Files (*.txt);;All Files(*)"));
    MachineInfo *machI = new MachineInfo(tableFile);
    listMach.append(machI);
    displayMach(listMach.back());
    current = listMach.back()->getMachine();

    // Get the name of the table, list it in the TablesList
    ui->tablesList->addItem(listMach.back()->getTableListItem());
    ui->tablesList->setIconSize(QSize(20, 20));
}

void UserMachines::on_simBt_clicked()
{
    ui->simList->clear();
    current->reset();
    current->start();

    std::list<QChar> tape;
    QString tapeStr;
    while (!current->halted()) {
        QThread::msleep(100);
        QCoreApplication::processEvents();
        tape = current->advance();
        int offset = current->getTapeHeadOffset();
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

void UserMachines::getMachToDispay(QListWidgetItem *item) {
    qDebug() << item->text();
    QFile *tableFile = new QFile(QFileDialog::getOpenFileName(this, "Open a Text File containing a Turing's Machine Table", QDir::homePath() + "/Mega/Bolsa/Turings-Machine-Simulator/C++/tables", "Text Files (*.txt);;All Files(*)"));
    //listMach.append(new MachineInfo(tableFile));
    MachineInfo *lol = new MachineInfo(tableFile);
    listMach.append(lol);
    //MachineInfo *lol = listMach.back();
    displayMach(listMach.back());
    //current = listMach.at(0)->getMachine();
    /*for (int i = 0; i < listMach.size(); i++) {
        qDebug() << listMach.at(i)->getTableListItem()->text();
        if (listMach.at(i)->getTableListItem()->text() == item->text()) {
            displayMach(listMach.at(i));
            break;
        }
    }*/
}

void UserMachines::displayMach(MachineInfo *toDisplay) {
    // Get the states, symbols and instructions, fill a table with them
    QVector<QTableWidgetItem*> *vTableHeader = toDisplay->getVTableHeader();
    QVector<QTableWidgetItem*> *hTableHeader = toDisplay->getHTableHeader();
    QVector<QTableWidgetItem*> *tableElems = toDisplay->getTableElems();
    ui->tableView->setRowCount(vTableHeader->size());
    ui->tableView->setColumnCount(hTableHeader->size());
    for (int i = 0, k = 0; i < vTableHeader->size(); i++) {
        ui->tableView->setRowHeight(i, (ui->tableView->height() - ui->tableView->horizontalHeader()->height())/vTableHeader->size());
        ui->tableView->setVerticalHeaderItem(i, vTableHeader->at(i));
        for (int j = 0; j < hTableHeader->size(); j++, k++) {
            if (i == 0) {
                ui->tableView->setColumnWidth(j, (ui->tableView->width() - ui->tableView->verticalHeader()->width())/hTableHeader->size());
                ui->tableView->setHorizontalHeaderItem(j, hTableHeader->at(j));
            }
            ui->tableView->setItem(i, j, tableElems->at(k));
        }
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Get the remaining properties, and fill the PropertiesList
    ui->propList->clear();
    QVector<QWidget*> *listWidgets = toDisplay->getTableProp();
    for (int i = 0; i < listWidgets->size(); i++) {
        QListWidgetItem *newProI = new QListWidgetItem;
        listWidgets->at(i)->show();
        ui->propList->addItem(newProI);
        ui->propList->setItemWidget(newProI, listWidgets->at(i));
    }
    //Clear the Simulation View
    ui->simList->clear();
}
