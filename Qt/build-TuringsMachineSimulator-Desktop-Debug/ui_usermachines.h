/********************************************************************************
** Form generated from reading UI file 'usermachines.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMACHINES_H
#define UI_USERMACHINES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMachines
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QSplitter *listSplit;
    QWidget *layoutWidget;
    QVBoxLayout *Tables;
    QLabel *tablesLabel;
    QListWidget *tablesList;
    QSplitter *tableSplit;
    QSplitter *specSplit;
    QWidget *layoutWidget1;
    QVBoxLayout *Specs;
    QLabel *tableLabel;
    QTableWidget *tableView;
    QWidget *layoutWidget2;
    QVBoxLayout *Properties;
    QLabel *propLabel;
    QListWidget *propList;
    QSplitter *simSplit;
    QWidget *layoutWidget3;
    QVBoxLayout *States;
    QLabel *stateLabel;
    QListWidget *stateList;
    QWidget *layoutWidget4;
    QVBoxLayout *Tape;
    QLabel *simLabel;
    QListWidget *simList;
    QHBoxLayout *tableCtrlLt;
    QPushButton *addTableBt;
    QPushButton *editTableBt;
    QPushButton *randTableBt;
    QHBoxLayout *simCtrlLt;
    QPushButton *simBt;
    QPushButton *pauseBt;
    QPushButton *contBt;
    QPushButton *stopBt;

    void setupUi(QMainWindow *UserMachines)
    {
        if (UserMachines->objectName().isEmpty())
            UserMachines->setObjectName(QStringLiteral("UserMachines"));
        UserMachines->resize(1280, 720);
        UserMachines->setStyleSheet(QLatin1String("QListWidget::item {\n"
"  padding: 3px;\n"
"}"));
        centralwidget = new QWidget(UserMachines);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        listSplit = new QSplitter(centralwidget);
        listSplit->setObjectName(QStringLiteral("listSplit"));
        listSplit->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(listSplit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        Tables = new QVBoxLayout(layoutWidget);
        Tables->setSpacing(0);
        Tables->setObjectName(QStringLiteral("Tables"));
        Tables->setContentsMargins(0, 0, 0, 0);
        tablesLabel = new QLabel(layoutWidget);
        tablesLabel->setObjectName(QStringLiteral("tablesLabel"));
        tablesLabel->setEnabled(true);
        QFont font;
        font.setPointSize(16);
        tablesLabel->setFont(font);
        tablesLabel->setFrameShape(QFrame::Panel);
        tablesLabel->setFrameShadow(QFrame::Raised);
        tablesLabel->setAlignment(Qt::AlignCenter);
        tablesLabel->setMargin(3);

        Tables->addWidget(tablesLabel);

        tablesList = new QListWidget(layoutWidget);
        tablesList->setObjectName(QStringLiteral("tablesList"));
        tablesList->setStyleSheet(QStringLiteral(""));

        Tables->addWidget(tablesList);

        listSplit->addWidget(layoutWidget);
        tableSplit = new QSplitter(listSplit);
        tableSplit->setObjectName(QStringLiteral("tableSplit"));
        tableSplit->setOrientation(Qt::Vertical);
        specSplit = new QSplitter(tableSplit);
        specSplit->setObjectName(QStringLiteral("specSplit"));
        specSplit->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(specSplit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        Specs = new QVBoxLayout(layoutWidget1);
        Specs->setSpacing(0);
        Specs->setObjectName(QStringLiteral("Specs"));
        Specs->setContentsMargins(0, 0, 0, 0);
        tableLabel = new QLabel(layoutWidget1);
        tableLabel->setObjectName(QStringLiteral("tableLabel"));
        tableLabel->setFont(font);
        tableLabel->setFrameShape(QFrame::Panel);
        tableLabel->setFrameShadow(QFrame::Raised);
        tableLabel->setAlignment(Qt::AlignCenter);
        tableLabel->setMargin(3);

        Specs->addWidget(tableLabel);

        tableView = new QTableWidget(layoutWidget1);
        tableView->setObjectName(QStringLiteral("tableView"));

        Specs->addWidget(tableView);

        specSplit->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(specSplit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        Properties = new QVBoxLayout(layoutWidget2);
        Properties->setSpacing(0);
        Properties->setObjectName(QStringLiteral("Properties"));
        Properties->setContentsMargins(0, 0, 0, 0);
        propLabel = new QLabel(layoutWidget2);
        propLabel->setObjectName(QStringLiteral("propLabel"));
        propLabel->setFont(font);
        propLabel->setFrameShape(QFrame::Panel);
        propLabel->setFrameShadow(QFrame::Raised);
        propLabel->setAlignment(Qt::AlignCenter);
        propLabel->setMargin(3);

        Properties->addWidget(propLabel);

        propList = new QListWidget(layoutWidget2);
        propList->setObjectName(QStringLiteral("propList"));

        Properties->addWidget(propList);

        specSplit->addWidget(layoutWidget2);
        tableSplit->addWidget(specSplit);
        simSplit = new QSplitter(tableSplit);
        simSplit->setObjectName(QStringLiteral("simSplit"));
        simSplit->setOrientation(Qt::Horizontal);
        layoutWidget3 = new QWidget(simSplit);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        States = new QVBoxLayout(layoutWidget3);
        States->setSpacing(0);
        States->setObjectName(QStringLiteral("States"));
        States->setContentsMargins(0, 0, 0, 0);
        stateLabel = new QLabel(layoutWidget3);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));
        stateLabel->setMinimumSize(QSize(0, 36));
        stateLabel->setFont(font);
        stateLabel->setFrameShape(QFrame::Panel);
        stateLabel->setFrameShadow(QFrame::Raised);
        stateLabel->setAlignment(Qt::AlignCenter);

        States->addWidget(stateLabel);

        stateList = new QListWidget(layoutWidget3);
        stateList->setObjectName(QStringLiteral("stateList"));

        States->addWidget(stateList);

        simSplit->addWidget(layoutWidget3);
        layoutWidget4 = new QWidget(simSplit);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        Tape = new QVBoxLayout(layoutWidget4);
        Tape->setSpacing(0);
        Tape->setObjectName(QStringLiteral("Tape"));
        Tape->setContentsMargins(0, 0, 0, 0);
        simLabel = new QLabel(layoutWidget4);
        simLabel->setObjectName(QStringLiteral("simLabel"));
        simLabel->setFont(font);
        simLabel->setFrameShape(QFrame::Panel);
        simLabel->setFrameShadow(QFrame::Raised);
        simLabel->setAlignment(Qt::AlignCenter);
        simLabel->setMargin(3);

        Tape->addWidget(simLabel);

        simList = new QListWidget(layoutWidget4);
        simList->setObjectName(QStringLiteral("simList"));

        Tape->addWidget(simList);

        simSplit->addWidget(layoutWidget4);
        tableSplit->addWidget(simSplit);
        listSplit->addWidget(tableSplit);

        verticalLayout_6->addWidget(listSplit);

        tableCtrlLt = new QHBoxLayout();
        tableCtrlLt->setObjectName(QStringLiteral("tableCtrlLt"));
        addTableBt = new QPushButton(centralwidget);
        addTableBt->setObjectName(QStringLiteral("addTableBt"));
        QFont font1;
        font1.setPointSize(12);
        addTableBt->setFont(font1);

        tableCtrlLt->addWidget(addTableBt);

        editTableBt = new QPushButton(centralwidget);
        editTableBt->setObjectName(QStringLiteral("editTableBt"));
        editTableBt->setFont(font1);

        tableCtrlLt->addWidget(editTableBt);

        randTableBt = new QPushButton(centralwidget);
        randTableBt->setObjectName(QStringLiteral("randTableBt"));
        randTableBt->setFont(font1);

        tableCtrlLt->addWidget(randTableBt);


        verticalLayout_6->addLayout(tableCtrlLt);

        simCtrlLt = new QHBoxLayout();
        simCtrlLt->setObjectName(QStringLiteral("simCtrlLt"));
        simBt = new QPushButton(centralwidget);
        simBt->setObjectName(QStringLiteral("simBt"));
        simBt->setMinimumSize(QSize(0, 0));
        simBt->setFont(font1);

        simCtrlLt->addWidget(simBt);

        pauseBt = new QPushButton(centralwidget);
        pauseBt->setObjectName(QStringLiteral("pauseBt"));
        pauseBt->setFont(font1);

        simCtrlLt->addWidget(pauseBt);

        contBt = new QPushButton(centralwidget);
        contBt->setObjectName(QStringLiteral("contBt"));
        contBt->setFont(font1);

        simCtrlLt->addWidget(contBt);

        stopBt = new QPushButton(centralwidget);
        stopBt->setObjectName(QStringLiteral("stopBt"));
        stopBt->setFont(font1);

        simCtrlLt->addWidget(stopBt);


        verticalLayout_6->addLayout(simCtrlLt);

        UserMachines->setCentralWidget(centralwidget);

        retranslateUi(UserMachines);

        QMetaObject::connectSlotsByName(UserMachines);
    } // setupUi

    void retranslateUi(QMainWindow *UserMachines)
    {
        UserMachines->setWindowTitle(QApplication::translate("UserMachines", "MainWindow", Q_NULLPTR));
        tablesLabel->setText(QApplication::translate("UserMachines", "Machine's Tables", Q_NULLPTR));
        tableLabel->setText(QApplication::translate("UserMachines", "Table's Specification", Q_NULLPTR));
        propLabel->setText(QApplication::translate("UserMachines", "Table's Properties", Q_NULLPTR));
        stateLabel->setText(QApplication::translate("UserMachines", "States", Q_NULLPTR));
        simLabel->setText(QApplication::translate("UserMachines", "Table's Simulation", Q_NULLPTR));
        addTableBt->setText(QApplication::translate("UserMachines", "Add Table", Q_NULLPTR));
        editTableBt->setText(QApplication::translate("UserMachines", "Edit Table", Q_NULLPTR));
        randTableBt->setText(QApplication::translate("UserMachines", "Add Random Table", Q_NULLPTR));
        simBt->setText(QApplication::translate("UserMachines", "Simulate", Q_NULLPTR));
        pauseBt->setText(QApplication::translate("UserMachines", "Pause", Q_NULLPTR));
        contBt->setText(QApplication::translate("UserMachines", "Continue", Q_NULLPTR));
        stopBt->setText(QApplication::translate("UserMachines", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserMachines: public Ui_UserMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMACHINES_H
