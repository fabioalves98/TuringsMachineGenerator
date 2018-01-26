/********************************************************************************
** Form generated from reading UI file 'machinesimulation.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACHINESIMULATION_H
#define UI_MACHINESIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MachineSimulation
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *tableSplit;
    QSplitter *specSplit;
    QWidget *layoutWidget;
    QVBoxLayout *Specs;
    QLabel *tableLabel;
    QTableWidget *tableView;
    QWidget *layoutWidget_2;
    QVBoxLayout *Properties;
    QLabel *propLabel;
    QListWidget *propList;
    QSplitter *simSplit;
    QWidget *widget;
    QVBoxLayout *rightSim;
    QVBoxLayout *Head;
    QLabel *headPosLabel;
    QSpinBox *headPos;
    QVBoxLayout *States;
    QLabel *stateLabel;
    QListWidget *stateList;
    QWidget *widget1;
    QVBoxLayout *leftSim;
    QVBoxLayout *InitialTape;
    QLabel *inTapeLabel;
    QListWidget *inTape;
    QVBoxLayout *Tape;
    QLabel *simLabel;
    QListWidget *simList;

    void setupUi(QMainWindow *MachineSimulation)
    {
        if (MachineSimulation->objectName().isEmpty())
            MachineSimulation->setObjectName(QStringLiteral("MachineSimulation"));
        MachineSimulation->resize(800, 600);
        centralwidget = new QWidget(MachineSimulation);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableSplit = new QSplitter(centralwidget);
        tableSplit->setObjectName(QStringLiteral("tableSplit"));
        tableSplit->setOrientation(Qt::Vertical);
        specSplit = new QSplitter(tableSplit);
        specSplit->setObjectName(QStringLiteral("specSplit"));
        specSplit->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(specSplit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        Specs = new QVBoxLayout(layoutWidget);
        Specs->setSpacing(0);
        Specs->setObjectName(QStringLiteral("Specs"));
        Specs->setContentsMargins(0, 0, 0, 0);
        tableLabel = new QLabel(layoutWidget);
        tableLabel->setObjectName(QStringLiteral("tableLabel"));
        QFont font;
        font.setPointSize(16);
        tableLabel->setFont(font);
        tableLabel->setFrameShape(QFrame::Panel);
        tableLabel->setFrameShadow(QFrame::Raised);
        tableLabel->setAlignment(Qt::AlignCenter);
        tableLabel->setMargin(3);

        Specs->addWidget(tableLabel);

        tableView = new QTableWidget(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        Specs->addWidget(tableView);

        specSplit->addWidget(layoutWidget);
        layoutWidget_2 = new QWidget(specSplit);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        Properties = new QVBoxLayout(layoutWidget_2);
        Properties->setSpacing(0);
        Properties->setObjectName(QStringLiteral("Properties"));
        Properties->setContentsMargins(0, 0, 0, 0);
        propLabel = new QLabel(layoutWidget_2);
        propLabel->setObjectName(QStringLiteral("propLabel"));
        propLabel->setFont(font);
        propLabel->setFrameShape(QFrame::Panel);
        propLabel->setFrameShadow(QFrame::Raised);
        propLabel->setAlignment(Qt::AlignCenter);
        propLabel->setMargin(3);

        Properties->addWidget(propLabel);

        propList = new QListWidget(layoutWidget_2);
        propList->setObjectName(QStringLiteral("propList"));

        Properties->addWidget(propList);

        specSplit->addWidget(layoutWidget_2);
        tableSplit->addWidget(specSplit);
        simSplit = new QSplitter(tableSplit);
        simSplit->setObjectName(QStringLiteral("simSplit"));
        simSplit->setOrientation(Qt::Horizontal);
        widget = new QWidget(simSplit);
        widget->setObjectName(QStringLiteral("widget"));
        rightSim = new QVBoxLayout(widget);
        rightSim->setSpacing(2);
        rightSim->setObjectName(QStringLiteral("rightSim"));
        rightSim->setContentsMargins(0, 0, 0, 0);
        Head = new QVBoxLayout();
        Head->setSpacing(0);
        Head->setObjectName(QStringLiteral("Head"));
        headPosLabel = new QLabel(widget);
        headPosLabel->setObjectName(QStringLiteral("headPosLabel"));
        headPosLabel->setMinimumSize(QSize(70, 24));
        headPosLabel->setMaximumSize(QSize(16777215, 24));
        QFont font1;
        font1.setPointSize(12);
        headPosLabel->setFont(font1);
        headPosLabel->setFrameShape(QFrame::Panel);
        headPosLabel->setFrameShadow(QFrame::Raised);
        headPosLabel->setAlignment(Qt::AlignCenter);

        Head->addWidget(headPosLabel);

        headPos = new QSpinBox(widget);
        headPos->setObjectName(QStringLiteral("headPos"));
        headPos->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setPointSize(10);
        headPos->setFont(font2);
        headPos->setAlignment(Qt::AlignCenter);

        Head->addWidget(headPos);


        rightSim->addLayout(Head);

        States = new QVBoxLayout();
        States->setSpacing(0);
        States->setObjectName(QStringLiteral("States"));
        stateLabel = new QLabel(widget);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));
        stateLabel->setMinimumSize(QSize(0, 36));
        stateLabel->setFont(font);
        stateLabel->setFrameShape(QFrame::Panel);
        stateLabel->setFrameShadow(QFrame::Raised);
        stateLabel->setAlignment(Qt::AlignCenter);

        States->addWidget(stateLabel);

        stateList = new QListWidget(widget);
        stateList->setObjectName(QStringLiteral("stateList"));

        States->addWidget(stateList);


        rightSim->addLayout(States);

        simSplit->addWidget(widget);
        widget1 = new QWidget(simSplit);
        widget1->setObjectName(QStringLiteral("widget1"));
        leftSim = new QVBoxLayout(widget1);
        leftSim->setSpacing(2);
        leftSim->setObjectName(QStringLiteral("leftSim"));
        leftSim->setContentsMargins(0, 0, 0, 0);
        InitialTape = new QVBoxLayout();
        InitialTape->setSpacing(0);
        InitialTape->setObjectName(QStringLiteral("InitialTape"));
        inTapeLabel = new QLabel(widget1);
        inTapeLabel->setObjectName(QStringLiteral("inTapeLabel"));
        inTapeLabel->setMinimumSize(QSize(0, 24));
        inTapeLabel->setMaximumSize(QSize(16777215, 24));
        inTapeLabel->setFont(font1);
        inTapeLabel->setFrameShape(QFrame::Panel);
        inTapeLabel->setFrameShadow(QFrame::Raised);
        inTapeLabel->setAlignment(Qt::AlignCenter);

        InitialTape->addWidget(inTapeLabel);

        inTape = new QListWidget(widget1);
        inTape->setObjectName(QStringLiteral("inTape"));
        inTape->setMaximumSize(QSize(16777215, 25));

        InitialTape->addWidget(inTape);


        leftSim->addLayout(InitialTape);

        Tape = new QVBoxLayout();
        Tape->setSpacing(0);
        Tape->setObjectName(QStringLiteral("Tape"));
        simLabel = new QLabel(widget1);
        simLabel->setObjectName(QStringLiteral("simLabel"));
        simLabel->setMinimumSize(QSize(0, 36));
        simLabel->setFont(font);
        simLabel->setFrameShape(QFrame::Panel);
        simLabel->setFrameShadow(QFrame::Raised);
        simLabel->setAlignment(Qt::AlignCenter);
        simLabel->setMargin(3);

        Tape->addWidget(simLabel);

        simList = new QListWidget(widget1);
        simList->setObjectName(QStringLiteral("simList"));

        Tape->addWidget(simList);


        leftSim->addLayout(Tape);

        simSplit->addWidget(widget1);
        tableSplit->addWidget(simSplit);

        verticalLayout->addWidget(tableSplit);

        MachineSimulation->setCentralWidget(centralwidget);

        retranslateUi(MachineSimulation);

        QMetaObject::connectSlotsByName(MachineSimulation);
    } // setupUi

    void retranslateUi(QMainWindow *MachineSimulation)
    {
        MachineSimulation->setWindowTitle(QApplication::translate("MachineSimulation", "MainWindow", nullptr));
        tableLabel->setText(QApplication::translate("MachineSimulation", "Table's Specification", nullptr));
        propLabel->setText(QApplication::translate("MachineSimulation", "Table's Properties", nullptr));
        headPosLabel->setText(QApplication::translate("MachineSimulation", "Head", nullptr));
        stateLabel->setText(QApplication::translate("MachineSimulation", "States", nullptr));
        inTapeLabel->setText(QApplication::translate("MachineSimulation", "Initial Tape", nullptr));
        simLabel->setText(QApplication::translate("MachineSimulation", "Table's Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MachineSimulation: public Ui_MachineSimulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACHINESIMULATION_H
