/********************************************************************************
** Form generated from reading UI file 'machinesimulation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
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
    QWidget *layoutWidget_3;
    QVBoxLayout *States;
    QLabel *stateLabel;
    QListWidget *stateList;
    QWidget *layoutWidget_4;
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
        layoutWidget_3 = new QWidget(simSplit);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        States = new QVBoxLayout(layoutWidget_3);
        States->setSpacing(0);
        States->setObjectName(QStringLiteral("States"));
        States->setContentsMargins(0, 0, 0, 0);
        stateLabel = new QLabel(layoutWidget_3);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));
        stateLabel->setMinimumSize(QSize(0, 36));
        stateLabel->setFont(font);
        stateLabel->setFrameShape(QFrame::Panel);
        stateLabel->setFrameShadow(QFrame::Raised);
        stateLabel->setAlignment(Qt::AlignCenter);

        States->addWidget(stateLabel);

        stateList = new QListWidget(layoutWidget_3);
        stateList->setObjectName(QStringLiteral("stateList"));

        States->addWidget(stateList);

        simSplit->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(simSplit);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        Tape = new QVBoxLayout(layoutWidget_4);
        Tape->setSpacing(0);
        Tape->setObjectName(QStringLiteral("Tape"));
        Tape->setContentsMargins(0, 0, 0, 0);
        simLabel = new QLabel(layoutWidget_4);
        simLabel->setObjectName(QStringLiteral("simLabel"));
        simLabel->setFont(font);
        simLabel->setFrameShape(QFrame::Panel);
        simLabel->setFrameShadow(QFrame::Raised);
        simLabel->setAlignment(Qt::AlignCenter);
        simLabel->setMargin(3);

        Tape->addWidget(simLabel);

        simList = new QListWidget(layoutWidget_4);
        simList->setObjectName(QStringLiteral("simList"));

        Tape->addWidget(simList);

        simSplit->addWidget(layoutWidget_4);
        tableSplit->addWidget(simSplit);

        verticalLayout->addWidget(tableSplit);

        MachineSimulation->setCentralWidget(centralwidget);

        retranslateUi(MachineSimulation);

        QMetaObject::connectSlotsByName(MachineSimulation);
    } // setupUi

    void retranslateUi(QMainWindow *MachineSimulation)
    {
        MachineSimulation->setWindowTitle(QApplication::translate("MachineSimulation", "MainWindow", Q_NULLPTR));
        tableLabel->setText(QApplication::translate("MachineSimulation", "Table's Specification", Q_NULLPTR));
        propLabel->setText(QApplication::translate("MachineSimulation", "Table's Properties", Q_NULLPTR));
        stateLabel->setText(QApplication::translate("MachineSimulation", "States", Q_NULLPTR));
        simLabel->setText(QApplication::translate("MachineSimulation", "Table's Simulation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MachineSimulation: public Ui_MachineSimulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACHINESIMULATION_H
