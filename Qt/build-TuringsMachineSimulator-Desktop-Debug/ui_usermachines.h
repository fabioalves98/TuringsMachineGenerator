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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMachines
{
public:
    QWidget *centralwidget;
    QPushButton *addTableBt;
    QPushButton *simBt;
    QWidget *widget;
    QVBoxLayout *Properties;
    QLabel *propLabel;
    QListWidget *propList;
    QWidget *widget1;
    QVBoxLayout *Specs;
    QLabel *tableLabel;
    QTableWidget *tableView;
    QWidget *widget2;
    QVBoxLayout *Tables;
    QLabel *tablesLabel;
    QListWidget *tablesList;
    QWidget *widget3;
    QVBoxLayout *Simulation;
    QLabel *simLabel;
    QListWidget *simList;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *UserMachines)
    {
        if (UserMachines->objectName().isEmpty())
            UserMachines->setObjectName(QStringLiteral("UserMachines"));
        UserMachines->resize(1280, 720);
        centralwidget = new QWidget(UserMachines);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        addTableBt = new QPushButton(centralwidget);
        addTableBt->setObjectName(QStringLiteral("addTableBt"));
        addTableBt->setGeometry(QRect(10, 590, 121, 31));
        simBt = new QPushButton(centralwidget);
        simBt->setObjectName(QStringLiteral("simBt"));
        simBt->setGeometry(QRect(140, 590, 131, 31));
        simBt->setMinimumSize(QSize(0, 0));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(780, 10, 491, 311));
        Properties = new QVBoxLayout(widget);
        Properties->setSpacing(0);
        Properties->setObjectName(QStringLiteral("Properties"));
        Properties->setContentsMargins(0, 0, 0, 0);
        propLabel = new QLabel(widget);
        propLabel->setObjectName(QStringLiteral("propLabel"));
        QFont font;
        font.setPointSize(14);
        propLabel->setFont(font);
        propLabel->setFrameShape(QFrame::Panel);
        propLabel->setFrameShadow(QFrame::Raised);
        propLabel->setAlignment(Qt::AlignCenter);

        Properties->addWidget(propLabel);

        propList = new QListWidget(widget);
        propList->setObjectName(QStringLiteral("propList"));

        Properties->addWidget(propList);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(280, 10, 491, 311));
        Specs = new QVBoxLayout(widget1);
        Specs->setSpacing(0);
        Specs->setObjectName(QStringLiteral("Specs"));
        Specs->setContentsMargins(0, 0, 0, 0);
        tableLabel = new QLabel(widget1);
        tableLabel->setObjectName(QStringLiteral("tableLabel"));
        tableLabel->setFont(font);
        tableLabel->setFrameShape(QFrame::Panel);
        tableLabel->setFrameShadow(QFrame::Raised);
        tableLabel->setAlignment(Qt::AlignCenter);

        Specs->addWidget(tableLabel);

        tableView = new QTableWidget(widget1);
        tableView->setObjectName(QStringLiteral("tableView"));

        Specs->addWidget(tableView);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 10, 261, 571));
        Tables = new QVBoxLayout(widget2);
        Tables->setSpacing(0);
        Tables->setObjectName(QStringLiteral("Tables"));
        Tables->setContentsMargins(0, 0, 0, 0);
        tablesLabel = new QLabel(widget2);
        tablesLabel->setObjectName(QStringLiteral("tablesLabel"));
        tablesLabel->setFont(font);
        tablesLabel->setFrameShape(QFrame::Panel);
        tablesLabel->setFrameShadow(QFrame::Raised);
        tablesLabel->setAlignment(Qt::AlignCenter);

        Tables->addWidget(tablesLabel);

        tablesList = new QListWidget(widget2);
        tablesList->setObjectName(QStringLiteral("tablesList"));

        Tables->addWidget(tablesList);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(280, 330, 991, 251));
        Simulation = new QVBoxLayout(widget3);
        Simulation->setSpacing(0);
        Simulation->setObjectName(QStringLiteral("Simulation"));
        Simulation->setContentsMargins(0, 0, 0, 0);
        simLabel = new QLabel(widget3);
        simLabel->setObjectName(QStringLiteral("simLabel"));
        simLabel->setFont(font);
        simLabel->setFrameShape(QFrame::Panel);
        simLabel->setFrameShadow(QFrame::Raised);
        simLabel->setAlignment(Qt::AlignCenter);

        Simulation->addWidget(simLabel);

        simList = new QListWidget(widget3);
        simList->setObjectName(QStringLiteral("simList"));

        Simulation->addWidget(simList);

        UserMachines->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserMachines);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        UserMachines->setMenuBar(menubar);
        statusbar = new QStatusBar(UserMachines);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserMachines->setStatusBar(statusbar);
        toolBar = new QToolBar(UserMachines);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        UserMachines->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(UserMachines);

        QMetaObject::connectSlotsByName(UserMachines);
    } // setupUi

    void retranslateUi(QMainWindow *UserMachines)
    {
        UserMachines->setWindowTitle(QApplication::translate("UserMachines", "MainWindow", Q_NULLPTR));
        addTableBt->setText(QApplication::translate("UserMachines", "Add Table", Q_NULLPTR));
        simBt->setText(QApplication::translate("UserMachines", "Simulate", Q_NULLPTR));
        propLabel->setText(QApplication::translate("UserMachines", "Table's Properties", Q_NULLPTR));
        tableLabel->setText(QApplication::translate("UserMachines", "Table's Specification", Q_NULLPTR));
        tablesLabel->setText(QApplication::translate("UserMachines", "Machine's Tables", Q_NULLPTR));
        simLabel->setText(QApplication::translate("UserMachines", "Table's Simulation", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("UserMachines", "File", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("UserMachines", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserMachines: public Ui_UserMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMACHINES_H
