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
#include <QtWidgets/QSplitter>
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
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_3;
    QWidget *widget;
    QVBoxLayout *Tables;
    QLabel *tablesLabel;
    QListWidget *tablesList;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *Specs;
    QLabel *tableLabel;
    QTableWidget *tableView;
    QWidget *layoutWidget1;
    QVBoxLayout *Properties;
    QLabel *propLabel;
    QListWidget *propList;
    QWidget *layoutWidget2;
    QVBoxLayout *Simulation;
    QLabel *simLabel;
    QListWidget *simList;
    QPushButton *simBt;
    QPushButton *addTableBt;
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
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter_3);
        widget->setObjectName(QStringLiteral("widget"));
        Tables = new QVBoxLayout(widget);
        Tables->setSpacing(0);
        Tables->setObjectName(QStringLiteral("Tables"));
        Tables->setContentsMargins(0, 0, 0, 0);
        tablesLabel = new QLabel(widget);
        tablesLabel->setObjectName(QStringLiteral("tablesLabel"));
        QFont font;
        font.setPointSize(14);
        tablesLabel->setFont(font);
        tablesLabel->setFrameShape(QFrame::Panel);
        tablesLabel->setFrameShadow(QFrame::Raised);
        tablesLabel->setAlignment(Qt::AlignCenter);

        Tables->addWidget(tablesLabel);

        tablesList = new QListWidget(widget);
        tablesList->setObjectName(QStringLiteral("tablesList"));

        Tables->addWidget(tablesList);

        splitter_3->addWidget(widget);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        Specs = new QVBoxLayout(layoutWidget);
        Specs->setSpacing(0);
        Specs->setObjectName(QStringLiteral("Specs"));
        Specs->setContentsMargins(0, 0, 0, 0);
        tableLabel = new QLabel(layoutWidget);
        tableLabel->setObjectName(QStringLiteral("tableLabel"));
        tableLabel->setFont(font);
        tableLabel->setFrameShape(QFrame::Panel);
        tableLabel->setFrameShadow(QFrame::Raised);
        tableLabel->setAlignment(Qt::AlignCenter);

        Specs->addWidget(tableLabel);

        tableView = new QTableWidget(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        Specs->addWidget(tableView);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        Properties = new QVBoxLayout(layoutWidget1);
        Properties->setSpacing(0);
        Properties->setObjectName(QStringLiteral("Properties"));
        Properties->setContentsMargins(0, 0, 0, 0);
        propLabel = new QLabel(layoutWidget1);
        propLabel->setObjectName(QStringLiteral("propLabel"));
        propLabel->setFont(font);
        propLabel->setFrameShape(QFrame::Panel);
        propLabel->setFrameShadow(QFrame::Raised);
        propLabel->setAlignment(Qt::AlignCenter);

        Properties->addWidget(propLabel);

        propList = new QListWidget(layoutWidget1);
        propList->setObjectName(QStringLiteral("propList"));

        Properties->addWidget(propList);

        splitter->addWidget(layoutWidget1);
        splitter_2->addWidget(splitter);
        layoutWidget2 = new QWidget(splitter_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        Simulation = new QVBoxLayout(layoutWidget2);
        Simulation->setSpacing(0);
        Simulation->setObjectName(QStringLiteral("Simulation"));
        Simulation->setContentsMargins(0, 0, 0, 0);
        simLabel = new QLabel(layoutWidget2);
        simLabel->setObjectName(QStringLiteral("simLabel"));
        simLabel->setFont(font);
        simLabel->setFrameShape(QFrame::Panel);
        simLabel->setFrameShadow(QFrame::Raised);
        simLabel->setAlignment(Qt::AlignCenter);

        Simulation->addWidget(simLabel);

        simList = new QListWidget(layoutWidget2);
        simList->setObjectName(QStringLiteral("simList"));

        Simulation->addWidget(simList);

        splitter_2->addWidget(layoutWidget2);
        splitter_3->addWidget(splitter_2);

        verticalLayout->addWidget(splitter_3);

        simBt = new QPushButton(centralwidget);
        simBt->setObjectName(QStringLiteral("simBt"));
        simBt->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(simBt);

        addTableBt = new QPushButton(centralwidget);
        addTableBt->setObjectName(QStringLiteral("addTableBt"));

        verticalLayout->addWidget(addTableBt);

        UserMachines->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserMachines);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 22));
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
        tablesLabel->setText(QApplication::translate("UserMachines", "Machine's Tables", Q_NULLPTR));
        tableLabel->setText(QApplication::translate("UserMachines", "Table's Specification", Q_NULLPTR));
        propLabel->setText(QApplication::translate("UserMachines", "Table's Properties", Q_NULLPTR));
        simLabel->setText(QApplication::translate("UserMachines", "Table's Simulation", Q_NULLPTR));
        simBt->setText(QApplication::translate("UserMachines", "Simulate", Q_NULLPTR));
        addTableBt->setText(QApplication::translate("UserMachines", "Add Table", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("UserMachines", "File", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("UserMachines", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserMachines: public Ui_UserMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMACHINES_H
