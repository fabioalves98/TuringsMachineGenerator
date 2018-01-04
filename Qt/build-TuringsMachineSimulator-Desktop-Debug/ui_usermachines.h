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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMachines
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *listSplit;
    QWidget *layoutWidget;
    QVBoxLayout *Tables;
    QLabel *tablesLabel;
    QListWidget *tablesList;
    QStackedWidget *tableSim;
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
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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
        tableSim = new QStackedWidget(listSplit);
        tableSim->setObjectName(QStringLiteral("tableSim"));
        listSplit->addWidget(tableSim);

        verticalLayout->addWidget(listSplit);

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


        verticalLayout->addLayout(tableCtrlLt);

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


        verticalLayout->addLayout(simCtrlLt);

        UserMachines->setCentralWidget(centralwidget);

        retranslateUi(UserMachines);

        QMetaObject::connectSlotsByName(UserMachines);
    } // setupUi

    void retranslateUi(QMainWindow *UserMachines)
    {
        UserMachines->setWindowTitle(QApplication::translate("UserMachines", "MainWindow", Q_NULLPTR));
        tablesLabel->setText(QApplication::translate("UserMachines", "Machine's Tables", Q_NULLPTR));
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
