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
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_3;
    QWidget *layoutWidget;
    QVBoxLayout *Tables;
    QLabel *tablesLabel;
    QListWidget *tablesList;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QWidget *layoutWidget1;
    QVBoxLayout *Specs;
    QLabel *tableLabel;
    QTableWidget *tableView;
    QWidget *layoutWidget2;
    QVBoxLayout *Properties;
    QLabel *propLabel;
    QListWidget *propList;
    QWidget *layoutWidget3;
    QVBoxLayout *Simulation;
    QLabel *simLabel;
    QListWidget *simList;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addTableBt;
    QPushButton *editTableBt;
    QPushButton *randTableBt;
    QHBoxLayout *horizontalLayout_2;
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
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter_3);
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

        splitter_3->addWidget(layoutWidget);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(splitter);
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

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
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

        splitter->addWidget(layoutWidget2);
        splitter_2->addWidget(splitter);
        layoutWidget3 = new QWidget(splitter_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        Simulation = new QVBoxLayout(layoutWidget3);
        Simulation->setSpacing(0);
        Simulation->setObjectName(QStringLiteral("Simulation"));
        Simulation->setContentsMargins(0, 0, 0, 0);
        simLabel = new QLabel(layoutWidget3);
        simLabel->setObjectName(QStringLiteral("simLabel"));
        simLabel->setFont(font);
        simLabel->setFrameShape(QFrame::Panel);
        simLabel->setFrameShadow(QFrame::Raised);
        simLabel->setAlignment(Qt::AlignCenter);
        simLabel->setMargin(3);

        Simulation->addWidget(simLabel);

        simList = new QListWidget(layoutWidget3);
        simList->setObjectName(QStringLiteral("simList"));

        Simulation->addWidget(simList);

        splitter_2->addWidget(layoutWidget3);
        splitter_3->addWidget(splitter_2);

        verticalLayout_2->addWidget(splitter_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addTableBt = new QPushButton(centralwidget);
        addTableBt->setObjectName(QStringLiteral("addTableBt"));
        QFont font1;
        font1.setPointSize(12);
        addTableBt->setFont(font1);

        horizontalLayout->addWidget(addTableBt);

        editTableBt = new QPushButton(centralwidget);
        editTableBt->setObjectName(QStringLiteral("editTableBt"));
        editTableBt->setFont(font1);

        horizontalLayout->addWidget(editTableBt);

        randTableBt = new QPushButton(centralwidget);
        randTableBt->setObjectName(QStringLiteral("randTableBt"));
        randTableBt->setFont(font1);

        horizontalLayout->addWidget(randTableBt);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        simBt = new QPushButton(centralwidget);
        simBt->setObjectName(QStringLiteral("simBt"));
        simBt->setMinimumSize(QSize(0, 0));
        simBt->setFont(font1);

        horizontalLayout_2->addWidget(simBt);

        pauseBt = new QPushButton(centralwidget);
        pauseBt->setObjectName(QStringLiteral("pauseBt"));
        pauseBt->setFont(font1);

        horizontalLayout_2->addWidget(pauseBt);

        contBt = new QPushButton(centralwidget);
        contBt->setObjectName(QStringLiteral("contBt"));
        contBt->setFont(font1);

        horizontalLayout_2->addWidget(contBt);

        stopBt = new QPushButton(centralwidget);
        stopBt->setObjectName(QStringLiteral("stopBt"));
        stopBt->setFont(font1);

        horizontalLayout_2->addWidget(stopBt);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

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
