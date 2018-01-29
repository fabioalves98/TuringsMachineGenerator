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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MachineSimulation
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
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
    QWidget *layoutWidget1;
    QVBoxLayout *rightSim;
    QVBoxLayout *Head;
    QLabel *headPosLabel;
    QSpinBox *headPos;
    QVBoxLayout *States;
    QLabel *statesLabel;
    QListWidget *statesList;
    QVBoxLayout *State;
    QLabel *stateLabel;
    QListWidget *stateList;
    QWidget *layoutWidget2;
    QVBoxLayout *leftSim;
    QVBoxLayout *InitialTape;
    QLabel *inTapeLabel;
    QListWidget *inTape;
    QVBoxLayout *Tape;
    QLabel *simLabel;
    QListWidget *simList;
    QVBoxLayout *verticalLayout;
    QLabel *tapeLabel;
    QListWidget *tapeList;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MachineSimulation)
    {
        if (MachineSimulation->objectName().isEmpty())
            MachineSimulation->setObjectName(QStringLiteral("MachineSimulation"));
        MachineSimulation->resize(797, 599);
        centralwidget = new QWidget(MachineSimulation);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
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
        layoutWidget1 = new QWidget(simSplit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        rightSim = new QVBoxLayout(layoutWidget1);
        rightSim->setSpacing(2);
        rightSim->setObjectName(QStringLiteral("rightSim"));
        rightSim->setContentsMargins(0, 0, 0, 0);
        Head = new QVBoxLayout();
        Head->setSpacing(0);
        Head->setObjectName(QStringLiteral("Head"));
        headPosLabel = new QLabel(layoutWidget1);
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

        headPos = new QSpinBox(layoutWidget1);
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
        statesLabel = new QLabel(layoutWidget1);
        statesLabel->setObjectName(QStringLiteral("statesLabel"));
        statesLabel->setMinimumSize(QSize(0, 36));
        statesLabel->setFont(font);
        statesLabel->setFrameShape(QFrame::Panel);
        statesLabel->setFrameShadow(QFrame::Raised);
        statesLabel->setAlignment(Qt::AlignCenter);

        States->addWidget(statesLabel);

        statesList = new QListWidget(layoutWidget1);
        statesList->setObjectName(QStringLiteral("statesList"));

        States->addWidget(statesList);


        rightSim->addLayout(States);

        State = new QVBoxLayout();
        State->setSpacing(0);
        State->setObjectName(QStringLiteral("State"));
        stateLabel = new QLabel(layoutWidget1);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));
        stateLabel->setMaximumSize(QSize(16777215, 24));
        stateLabel->setFont(font1);
        stateLabel->setFrameShape(QFrame::Panel);
        stateLabel->setFrameShadow(QFrame::Raised);
        stateLabel->setAlignment(Qt::AlignCenter);

        State->addWidget(stateLabel);

        stateList = new QListWidget(layoutWidget1);
        stateList->setObjectName(QStringLiteral("stateList"));
        stateList->setMaximumSize(QSize(16777215, 40));

        State->addWidget(stateList);


        rightSim->addLayout(State);

        simSplit->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(simSplit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        leftSim = new QVBoxLayout(layoutWidget2);
        leftSim->setSpacing(2);
        leftSim->setObjectName(QStringLiteral("leftSim"));
        leftSim->setContentsMargins(0, 0, 0, 0);
        InitialTape = new QVBoxLayout();
        InitialTape->setSpacing(0);
        InitialTape->setObjectName(QStringLiteral("InitialTape"));
        inTapeLabel = new QLabel(layoutWidget2);
        inTapeLabel->setObjectName(QStringLiteral("inTapeLabel"));
        inTapeLabel->setMinimumSize(QSize(0, 24));
        inTapeLabel->setMaximumSize(QSize(16777215, 24));
        inTapeLabel->setFont(font1);
        inTapeLabel->setFrameShape(QFrame::Panel);
        inTapeLabel->setFrameShadow(QFrame::Raised);
        inTapeLabel->setAlignment(Qt::AlignCenter);

        InitialTape->addWidget(inTapeLabel);

        inTape = new QListWidget(layoutWidget2);
        inTape->setObjectName(QStringLiteral("inTape"));
        inTape->setMaximumSize(QSize(16777215, 25));

        InitialTape->addWidget(inTape);


        leftSim->addLayout(InitialTape);

        Tape = new QVBoxLayout();
        Tape->setSpacing(0);
        Tape->setObjectName(QStringLiteral("Tape"));
        simLabel = new QLabel(layoutWidget2);
        simLabel->setObjectName(QStringLiteral("simLabel"));
        simLabel->setMinimumSize(QSize(0, 36));
        simLabel->setFont(font);
        simLabel->setFrameShape(QFrame::Panel);
        simLabel->setFrameShadow(QFrame::Raised);
        simLabel->setAlignment(Qt::AlignCenter);
        simLabel->setMargin(3);

        Tape->addWidget(simLabel);

        simList = new QListWidget(layoutWidget2);
        simList->setObjectName(QStringLiteral("simList"));

        Tape->addWidget(simList);


        leftSim->addLayout(Tape);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tapeLabel = new QLabel(layoutWidget2);
        tapeLabel->setObjectName(QStringLiteral("tapeLabel"));
        tapeLabel->setMaximumSize(QSize(16777215, 24));
        tapeLabel->setFont(font1);
        tapeLabel->setFrameShape(QFrame::Panel);
        tapeLabel->setFrameShadow(QFrame::Raised);
        tapeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(tapeLabel);

        tapeList = new QListWidget(layoutWidget2);
        tapeList->setObjectName(QStringLiteral("tapeList"));
        tapeList->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(tapeList);


        leftSim->addLayout(verticalLayout);

        simSplit->addWidget(layoutWidget2);
        tableSplit->addWidget(simSplit);

        verticalLayout_2->addWidget(tableSplit);

        MachineSimulation->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MachineSimulation);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MachineSimulation->setStatusBar(statusBar);

        retranslateUi(MachineSimulation);

        QMetaObject::connectSlotsByName(MachineSimulation);
    } // setupUi

    void retranslateUi(QMainWindow *MachineSimulation)
    {
        MachineSimulation->setWindowTitle(QApplication::translate("MachineSimulation", "MainWindow", nullptr));
        tableLabel->setText(QApplication::translate("MachineSimulation", "Table's Specification", nullptr));
        propLabel->setText(QApplication::translate("MachineSimulation", "Table's Properties", nullptr));
        headPosLabel->setText(QApplication::translate("MachineSimulation", "Head", nullptr));
        statesLabel->setText(QApplication::translate("MachineSimulation", "States", nullptr));
        stateLabel->setText(QApplication::translate("MachineSimulation", "State", nullptr));
        inTapeLabel->setText(QApplication::translate("MachineSimulation", "Initial Tape", nullptr));
        simLabel->setText(QApplication::translate("MachineSimulation", "Table's Simulation", nullptr));
        tapeLabel->setText(QApplication::translate("MachineSimulation", "Tape", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MachineSimulation: public Ui_MachineSimulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACHINESIMULATION_H
