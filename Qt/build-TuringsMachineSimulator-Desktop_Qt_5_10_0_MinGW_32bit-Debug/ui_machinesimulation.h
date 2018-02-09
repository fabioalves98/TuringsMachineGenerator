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
    QWidget *zCentralwidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *tableSplit;
    QSplitter *specSplit;
    QWidget *layoutWidget;
    QVBoxLayout *zSpecsLayout;
    QLabel *zLabel_7;
    QTableWidget *tableView;
    QSplitter *propSplit;
    QWidget *layoutWidget_2;
    QVBoxLayout *zTablePropLayout;
    QLabel *zLabel_9;
    QListWidget *machPropList;
    QWidget *layoutWidget1;
    QVBoxLayout *zTapePropLayout;
    QLabel *zLabel_8;
    QListWidget *tapePropList;
    QSplitter *simSplit;
    QWidget *layoutWidget2;
    QVBoxLayout *zRightSimLayout;
    QVBoxLayout *zHeadLayout;
    QLabel *zLabel_4;
    QSpinBox *headPos;
    QVBoxLayout *zStatesLayout;
    QLabel *zLabel_5;
    QListWidget *statesList;
    QVBoxLayout *zStateLayout;
    QLabel *zLabel_6;
    QListWidget *stateList;
    QWidget *layoutWidget3;
    QVBoxLayout *zLeftSimLayout;
    QVBoxLayout *zInitialTapeLayout;
    QLabel *zLabel;
    QListWidget *inTape;
    QVBoxLayout *zTapeLayout;
    QLabel *zLabel_2;
    QListWidget *simList;
    QVBoxLayout *zCurTapeLayout;
    QLabel *zLabel_3;
    QListWidget *tapeList;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MachineSimulation)
    {
        if (MachineSimulation->objectName().isEmpty())
            MachineSimulation->setObjectName(QStringLiteral("MachineSimulation"));
        MachineSimulation->resize(797, 599);
        zCentralwidget = new QWidget(MachineSimulation);
        zCentralwidget->setObjectName(QStringLiteral("zCentralwidget"));
        verticalLayout_2 = new QVBoxLayout(zCentralwidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableSplit = new QSplitter(zCentralwidget);
        tableSplit->setObjectName(QStringLiteral("tableSplit"));
        tableSplit->setOrientation(Qt::Vertical);
        specSplit = new QSplitter(tableSplit);
        specSplit->setObjectName(QStringLiteral("specSplit"));
        specSplit->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(specSplit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        zSpecsLayout = new QVBoxLayout(layoutWidget);
        zSpecsLayout->setSpacing(0);
        zSpecsLayout->setObjectName(QStringLiteral("zSpecsLayout"));
        zSpecsLayout->setContentsMargins(0, 0, 0, 0);
        zLabel_7 = new QLabel(layoutWidget);
        zLabel_7->setObjectName(QStringLiteral("zLabel_7"));
        QFont font;
        font.setPointSize(16);
        zLabel_7->setFont(font);
        zLabel_7->setFrameShape(QFrame::Panel);
        zLabel_7->setFrameShadow(QFrame::Raised);
        zLabel_7->setAlignment(Qt::AlignCenter);
        zLabel_7->setMargin(3);

        zSpecsLayout->addWidget(zLabel_7);

        tableView = new QTableWidget(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setStyleSheet(QStringLiteral("QTableWidget::item:selected{ background-color: #3399ff }"));

        zSpecsLayout->addWidget(tableView);

        specSplit->addWidget(layoutWidget);
        propSplit = new QSplitter(specSplit);
        propSplit->setObjectName(QStringLiteral("propSplit"));
        propSplit->setOrientation(Qt::Vertical);
        layoutWidget_2 = new QWidget(propSplit);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        zTablePropLayout = new QVBoxLayout(layoutWidget_2);
        zTablePropLayout->setSpacing(0);
        zTablePropLayout->setObjectName(QStringLiteral("zTablePropLayout"));
        zTablePropLayout->setContentsMargins(0, 0, 0, 0);
        zLabel_9 = new QLabel(layoutWidget_2);
        zLabel_9->setObjectName(QStringLiteral("zLabel_9"));
        zLabel_9->setFont(font);
        zLabel_9->setFrameShape(QFrame::Panel);
        zLabel_9->setFrameShadow(QFrame::Raised);
        zLabel_9->setAlignment(Qt::AlignCenter);
        zLabel_9->setMargin(3);

        zTablePropLayout->addWidget(zLabel_9);

        machPropList = new QListWidget(layoutWidget_2);
        machPropList->setObjectName(QStringLiteral("machPropList"));

        zTablePropLayout->addWidget(machPropList);

        propSplit->addWidget(layoutWidget_2);
        layoutWidget1 = new QWidget(propSplit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        zTapePropLayout = new QVBoxLayout(layoutWidget1);
        zTapePropLayout->setSpacing(0);
        zTapePropLayout->setObjectName(QStringLiteral("zTapePropLayout"));
        zTapePropLayout->setContentsMargins(0, 0, 0, 0);
        zLabel_8 = new QLabel(layoutWidget1);
        zLabel_8->setObjectName(QStringLiteral("zLabel_8"));
        zLabel_8->setMinimumSize(QSize(0, 33));
        zLabel_8->setMaximumSize(QSize(16777215, 33));
        zLabel_8->setFont(font);
        zLabel_8->setFrameShape(QFrame::Panel);
        zLabel_8->setFrameShadow(QFrame::Raised);
        zLabel_8->setAlignment(Qt::AlignCenter);

        zTapePropLayout->addWidget(zLabel_8);

        tapePropList = new QListWidget(layoutWidget1);
        tapePropList->setObjectName(QStringLiteral("tapePropList"));
        tapePropList->setMinimumSize(QSize(0, 50));

        zTapePropLayout->addWidget(tapePropList);

        propSplit->addWidget(layoutWidget1);
        specSplit->addWidget(propSplit);
        tableSplit->addWidget(specSplit);
        simSplit = new QSplitter(tableSplit);
        simSplit->setObjectName(QStringLiteral("simSplit"));
        simSplit->setOrientation(Qt::Horizontal);
        layoutWidget2 = new QWidget(simSplit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        zRightSimLayout = new QVBoxLayout(layoutWidget2);
        zRightSimLayout->setSpacing(2);
        zRightSimLayout->setObjectName(QStringLiteral("zRightSimLayout"));
        zRightSimLayout->setContentsMargins(0, 0, 0, 0);
        zHeadLayout = new QVBoxLayout();
        zHeadLayout->setSpacing(0);
        zHeadLayout->setObjectName(QStringLiteral("zHeadLayout"));
        zLabel_4 = new QLabel(layoutWidget2);
        zLabel_4->setObjectName(QStringLiteral("zLabel_4"));
        zLabel_4->setMinimumSize(QSize(70, 24));
        zLabel_4->setMaximumSize(QSize(16777215, 24));
        QFont font1;
        font1.setPointSize(12);
        zLabel_4->setFont(font1);
        zLabel_4->setFrameShape(QFrame::Panel);
        zLabel_4->setFrameShadow(QFrame::Raised);
        zLabel_4->setAlignment(Qt::AlignCenter);

        zHeadLayout->addWidget(zLabel_4);

        headPos = new QSpinBox(layoutWidget2);
        headPos->setObjectName(QStringLiteral("headPos"));
        headPos->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setPointSize(10);
        headPos->setFont(font2);
        headPos->setAlignment(Qt::AlignCenter);
        headPos->setMinimum(-999);
        headPos->setMaximum(999);

        zHeadLayout->addWidget(headPos);


        zRightSimLayout->addLayout(zHeadLayout);

        zStatesLayout = new QVBoxLayout();
        zStatesLayout->setSpacing(0);
        zStatesLayout->setObjectName(QStringLiteral("zStatesLayout"));
        zLabel_5 = new QLabel(layoutWidget2);
        zLabel_5->setObjectName(QStringLiteral("zLabel_5"));
        zLabel_5->setMinimumSize(QSize(0, 36));
        zLabel_5->setFont(font);
        zLabel_5->setFrameShape(QFrame::Panel);
        zLabel_5->setFrameShadow(QFrame::Raised);
        zLabel_5->setAlignment(Qt::AlignCenter);

        zStatesLayout->addWidget(zLabel_5);

        statesList = new QListWidget(layoutWidget2);
        statesList->setObjectName(QStringLiteral("statesList"));

        zStatesLayout->addWidget(statesList);


        zRightSimLayout->addLayout(zStatesLayout);

        zStateLayout = new QVBoxLayout();
        zStateLayout->setSpacing(0);
        zStateLayout->setObjectName(QStringLiteral("zStateLayout"));
        zLabel_6 = new QLabel(layoutWidget2);
        zLabel_6->setObjectName(QStringLiteral("zLabel_6"));
        zLabel_6->setMaximumSize(QSize(16777215, 24));
        zLabel_6->setFont(font1);
        zLabel_6->setFrameShape(QFrame::Panel);
        zLabel_6->setFrameShadow(QFrame::Raised);
        zLabel_6->setAlignment(Qt::AlignCenter);

        zStateLayout->addWidget(zLabel_6);

        stateList = new QListWidget(layoutWidget2);
        stateList->setObjectName(QStringLiteral("stateList"));
        stateList->setMaximumSize(QSize(16777215, 40));

        zStateLayout->addWidget(stateList);


        zRightSimLayout->addLayout(zStateLayout);

        simSplit->addWidget(layoutWidget2);
        layoutWidget3 = new QWidget(simSplit);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        zLeftSimLayout = new QVBoxLayout(layoutWidget3);
        zLeftSimLayout->setSpacing(2);
        zLeftSimLayout->setObjectName(QStringLiteral("zLeftSimLayout"));
        zLeftSimLayout->setContentsMargins(0, 0, 0, 0);
        zInitialTapeLayout = new QVBoxLayout();
        zInitialTapeLayout->setSpacing(0);
        zInitialTapeLayout->setObjectName(QStringLiteral("zInitialTapeLayout"));
        zLabel = new QLabel(layoutWidget3);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setMinimumSize(QSize(0, 24));
        zLabel->setMaximumSize(QSize(16777215, 24));
        zLabel->setFont(font1);
        zLabel->setFrameShape(QFrame::Panel);
        zLabel->setFrameShadow(QFrame::Raised);
        zLabel->setAlignment(Qt::AlignCenter);

        zInitialTapeLayout->addWidget(zLabel);

        inTape = new QListWidget(layoutWidget3);
        inTape->setObjectName(QStringLiteral("inTape"));
        inTape->setMaximumSize(QSize(16777215, 25));

        zInitialTapeLayout->addWidget(inTape);


        zLeftSimLayout->addLayout(zInitialTapeLayout);

        zTapeLayout = new QVBoxLayout();
        zTapeLayout->setSpacing(0);
        zTapeLayout->setObjectName(QStringLiteral("zTapeLayout"));
        zLabel_2 = new QLabel(layoutWidget3);
        zLabel_2->setObjectName(QStringLiteral("zLabel_2"));
        zLabel_2->setMinimumSize(QSize(0, 36));
        zLabel_2->setFont(font);
        zLabel_2->setFrameShape(QFrame::Panel);
        zLabel_2->setFrameShadow(QFrame::Raised);
        zLabel_2->setAlignment(Qt::AlignCenter);
        zLabel_2->setMargin(3);

        zTapeLayout->addWidget(zLabel_2);

        simList = new QListWidget(layoutWidget3);
        simList->setObjectName(QStringLiteral("simList"));

        zTapeLayout->addWidget(simList);


        zLeftSimLayout->addLayout(zTapeLayout);

        zCurTapeLayout = new QVBoxLayout();
        zCurTapeLayout->setSpacing(0);
        zCurTapeLayout->setObjectName(QStringLiteral("zCurTapeLayout"));
        zLabel_3 = new QLabel(layoutWidget3);
        zLabel_3->setObjectName(QStringLiteral("zLabel_3"));
        zLabel_3->setMaximumSize(QSize(16777215, 24));
        zLabel_3->setFont(font1);
        zLabel_3->setFrameShape(QFrame::Panel);
        zLabel_3->setFrameShadow(QFrame::Raised);
        zLabel_3->setAlignment(Qt::AlignCenter);

        zCurTapeLayout->addWidget(zLabel_3);

        tapeList = new QListWidget(layoutWidget3);
        tapeList->setObjectName(QStringLiteral("tapeList"));
        tapeList->setMaximumSize(QSize(16777215, 40));

        zCurTapeLayout->addWidget(tapeList);


        zLeftSimLayout->addLayout(zCurTapeLayout);

        simSplit->addWidget(layoutWidget3);
        tableSplit->addWidget(simSplit);

        verticalLayout_2->addWidget(tableSplit);

        MachineSimulation->setCentralWidget(zCentralwidget);
        statusBar = new QStatusBar(MachineSimulation);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font3;
        font3.setPointSize(9);
        statusBar->setFont(font3);
        MachineSimulation->setStatusBar(statusBar);

        retranslateUi(MachineSimulation);

        QMetaObject::connectSlotsByName(MachineSimulation);
    } // setupUi

    void retranslateUi(QMainWindow *MachineSimulation)
    {
        MachineSimulation->setWindowTitle(QApplication::translate("MachineSimulation", "MainWindow", nullptr));
        zLabel_7->setText(QApplication::translate("MachineSimulation", "Machine's Table", nullptr));
        zLabel_9->setText(QApplication::translate("MachineSimulation", "Machine's Properties", nullptr));
        zLabel_8->setText(QApplication::translate("MachineSimulation", "Tape's Properties", nullptr));
        zLabel_4->setText(QApplication::translate("MachineSimulation", "Head", nullptr));
        zLabel_5->setText(QApplication::translate("MachineSimulation", "States", nullptr));
        zLabel_6->setText(QApplication::translate("MachineSimulation", "State", nullptr));
        zLabel->setText(QApplication::translate("MachineSimulation", "Initial Tape", nullptr));
        zLabel_2->setText(QApplication::translate("MachineSimulation", "Simulation", nullptr));
        zLabel_3->setText(QApplication::translate("MachineSimulation", "Current Tape", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MachineSimulation: public Ui_MachineSimulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACHINESIMULATION_H
