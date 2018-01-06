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
    QVBoxLayout *verticalLayout_4;
    QSplitter *listSplit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *tablesLabel;
    QListWidget *tablesList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *uselAllBt;
    QPushButton *selAllBt;
    QPushButton *simBt;
    QStackedWidget *tableSim;
    QHBoxLayout *horizontalLayout;
    QPushButton *pauseBt;
    QPushButton *contBt;
    QPushButton *stopBt;
    QHBoxLayout *tableCtrlLt;
    QPushButton *addTableBt;
    QPushButton *editTableBt;
    QPushButton *qRandTableBt;
    QPushButton *cRandTableBt;
    QPushButton *settingsBt;

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
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        listSplit = new QSplitter(centralwidget);
        listSplit->setObjectName(QStringLiteral("listSplit"));
        listSplit->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(listSplit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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

        verticalLayout->addWidget(tablesLabel);

        tablesList = new QListWidget(layoutWidget);
        tablesList->setObjectName(QStringLiteral("tablesList"));
        tablesList->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(tablesList);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        uselAllBt = new QPushButton(layoutWidget);
        uselAllBt->setObjectName(QStringLiteral("uselAllBt"));
        QFont font1;
        font1.setPointSize(10);
        uselAllBt->setFont(font1);

        horizontalLayout_2->addWidget(uselAllBt);

        selAllBt = new QPushButton(layoutWidget);
        selAllBt->setObjectName(QStringLiteral("selAllBt"));
        selAllBt->setFont(font1);

        horizontalLayout_2->addWidget(selAllBt);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        simBt = new QPushButton(layoutWidget);
        simBt->setObjectName(QStringLiteral("simBt"));
        simBt->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(12);
        simBt->setFont(font2);

        verticalLayout_3->addWidget(simBt);

        listSplit->addWidget(layoutWidget);
        tableSim = new QStackedWidget(listSplit);
        tableSim->setObjectName(QStringLiteral("tableSim"));
        listSplit->addWidget(tableSim);

        verticalLayout_4->addWidget(listSplit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pauseBt = new QPushButton(centralwidget);
        pauseBt->setObjectName(QStringLiteral("pauseBt"));
        pauseBt->setFont(font2);

        horizontalLayout->addWidget(pauseBt);

        contBt = new QPushButton(centralwidget);
        contBt->setObjectName(QStringLiteral("contBt"));
        contBt->setFont(font2);

        horizontalLayout->addWidget(contBt);

        stopBt = new QPushButton(centralwidget);
        stopBt->setObjectName(QStringLiteral("stopBt"));
        stopBt->setFont(font2);

        horizontalLayout->addWidget(stopBt);


        verticalLayout_4->addLayout(horizontalLayout);

        tableCtrlLt = new QHBoxLayout();
        tableCtrlLt->setObjectName(QStringLiteral("tableCtrlLt"));
        addTableBt = new QPushButton(centralwidget);
        addTableBt->setObjectName(QStringLiteral("addTableBt"));
        addTableBt->setFont(font2);

        tableCtrlLt->addWidget(addTableBt);

        editTableBt = new QPushButton(centralwidget);
        editTableBt->setObjectName(QStringLiteral("editTableBt"));
        editTableBt->setFont(font2);

        tableCtrlLt->addWidget(editTableBt);

        qRandTableBt = new QPushButton(centralwidget);
        qRandTableBt->setObjectName(QStringLiteral("qRandTableBt"));
        qRandTableBt->setFont(font2);

        tableCtrlLt->addWidget(qRandTableBt);

        cRandTableBt = new QPushButton(centralwidget);
        cRandTableBt->setObjectName(QStringLiteral("cRandTableBt"));
        cRandTableBt->setFont(font2);

        tableCtrlLt->addWidget(cRandTableBt);

        settingsBt = new QPushButton(centralwidget);
        settingsBt->setObjectName(QStringLiteral("settingsBt"));
        settingsBt->setFont(font2);

        tableCtrlLt->addWidget(settingsBt);


        verticalLayout_4->addLayout(tableCtrlLt);

        UserMachines->setCentralWidget(centralwidget);

        retranslateUi(UserMachines);

        QMetaObject::connectSlotsByName(UserMachines);
    } // setupUi

    void retranslateUi(QMainWindow *UserMachines)
    {
        UserMachines->setWindowTitle(QApplication::translate("UserMachines", "MainWindow", Q_NULLPTR));
        tablesLabel->setText(QApplication::translate("UserMachines", "Machine's Tables", Q_NULLPTR));
        uselAllBt->setText(QApplication::translate("UserMachines", "Select All", Q_NULLPTR));
        selAllBt->setText(QApplication::translate("UserMachines", "Unselect All", Q_NULLPTR));
        simBt->setText(QApplication::translate("UserMachines", "Simulate", Q_NULLPTR));
        pauseBt->setText(QApplication::translate("UserMachines", "Pause", Q_NULLPTR));
        contBt->setText(QApplication::translate("UserMachines", "Continue", Q_NULLPTR));
        stopBt->setText(QApplication::translate("UserMachines", "Stop", Q_NULLPTR));
        addTableBt->setText(QApplication::translate("UserMachines", "Add Table", Q_NULLPTR));
        editTableBt->setText(QApplication::translate("UserMachines", "Edit Table", Q_NULLPTR));
        qRandTableBt->setText(QApplication::translate("UserMachines", "Add Quick Random Table", Q_NULLPTR));
        cRandTableBt->setText(QApplication::translate("UserMachines", "Add Custom Random Table", Q_NULLPTR));
        settingsBt->setText(QApplication::translate("UserMachines", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserMachines: public Ui_UserMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMACHINES_H
