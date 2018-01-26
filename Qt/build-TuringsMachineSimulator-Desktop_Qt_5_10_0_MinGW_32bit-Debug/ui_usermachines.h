/********************************************************************************
** Form generated from reading UI file 'usermachines.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
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
    QVBoxLayout *verticalLayout_7;
    QSplitter *listSplit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QSplitter *tapeSplit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *tablesLabel;
    QListWidget *tablesList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *uselAllBt;
    QPushButton *selAllBt;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *tapesLabel;
    QListWidget *tapesList;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addTapeBt;
    QPushButton *loadTapeBt;
    QPushButton *simBt;
    QStackedWidget *tableSim;
    QHBoxLayout *horizontalLayout;
    QPushButton *pauseBt;
    QPushButton *contBt;
    QPushButton *stopBt;
    QHBoxLayout *tableCtrlLt;
    QPushButton *addTableBt;
    QPushButton *editTableBt;
    QPushButton *saveTableBt;
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
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        listSplit = new QSplitter(centralwidget);
        listSplit->setObjectName(QStringLiteral("listSplit"));
        listSplit->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(listSplit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        tapeSplit = new QSplitter(layoutWidget);
        tapeSplit->setObjectName(QStringLiteral("tapeSplit"));
        tapeSplit->setOrientation(Qt::Vertical);
        layoutWidget1 = new QWidget(tapeSplit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tablesLabel = new QLabel(layoutWidget1);
        tablesLabel->setObjectName(QStringLiteral("tablesLabel"));
        tablesLabel->setEnabled(true);
        tablesLabel->setMinimumSize(QSize(0, 33));
        QFont font;
        font.setPointSize(16);
        tablesLabel->setFont(font);
        tablesLabel->setFrameShape(QFrame::Panel);
        tablesLabel->setFrameShadow(QFrame::Raised);
        tablesLabel->setAlignment(Qt::AlignCenter);
        tablesLabel->setMargin(3);

        verticalLayout->addWidget(tablesLabel);

        tablesList = new QListWidget(layoutWidget1);
        tablesList->setObjectName(QStringLiteral("tablesList"));
        tablesList->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(tablesList);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        uselAllBt = new QPushButton(layoutWidget1);
        uselAllBt->setObjectName(QStringLiteral("uselAllBt"));
        QFont font1;
        font1.setPointSize(10);
        uselAllBt->setFont(font1);

        horizontalLayout_2->addWidget(uselAllBt);

        selAllBt = new QPushButton(layoutWidget1);
        selAllBt->setObjectName(QStringLiteral("selAllBt"));
        selAllBt->setFont(font1);

        horizontalLayout_2->addWidget(selAllBt);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        tapeSplit->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(tapeSplit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tapesLabel = new QLabel(layoutWidget2);
        tapesLabel->setObjectName(QStringLiteral("tapesLabel"));
        tapesLabel->setMinimumSize(QSize(0, 33));
        tapesLabel->setFont(font);
        tapesLabel->setFrameShape(QFrame::Panel);
        tapesLabel->setFrameShadow(QFrame::Raised);
        tapesLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(tapesLabel);

        tapesList = new QListWidget(layoutWidget2);
        tapesList->setObjectName(QStringLiteral("tapesList"));

        verticalLayout_4->addWidget(tapesList);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        addTapeBt = new QPushButton(layoutWidget2);
        addTapeBt->setObjectName(QStringLiteral("addTapeBt"));
        addTapeBt->setFont(font1);

        horizontalLayout_3->addWidget(addTapeBt);

        loadTapeBt = new QPushButton(layoutWidget2);
        loadTapeBt->setObjectName(QStringLiteral("loadTapeBt"));
        loadTapeBt->setFont(font1);

        horizontalLayout_3->addWidget(loadTapeBt);


        verticalLayout_5->addLayout(horizontalLayout_3);

        tapeSplit->addWidget(layoutWidget2);

        verticalLayout_6->addWidget(tapeSplit);

        simBt = new QPushButton(layoutWidget);
        simBt->setObjectName(QStringLiteral("simBt"));
        simBt->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(12);
        simBt->setFont(font2);

        verticalLayout_6->addWidget(simBt);

        listSplit->addWidget(layoutWidget);
        tableSim = new QStackedWidget(listSplit);
        tableSim->setObjectName(QStringLiteral("tableSim"));
        listSplit->addWidget(tableSim);

        verticalLayout_7->addWidget(listSplit);

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


        verticalLayout_7->addLayout(horizontalLayout);

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

        saveTableBt = new QPushButton(centralwidget);
        saveTableBt->setObjectName(QStringLiteral("saveTableBt"));
        saveTableBt->setFont(font2);

        tableCtrlLt->addWidget(saveTableBt);

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


        verticalLayout_7->addLayout(tableCtrlLt);

        UserMachines->setCentralWidget(centralwidget);

        retranslateUi(UserMachines);

        QMetaObject::connectSlotsByName(UserMachines);
    } // setupUi

    void retranslateUi(QMainWindow *UserMachines)
    {
        UserMachines->setWindowTitle(QApplication::translate("UserMachines", "MainWindow", nullptr));
        tablesLabel->setText(QApplication::translate("UserMachines", "Machine's Tables", nullptr));
        uselAllBt->setText(QApplication::translate("UserMachines", "Select All", nullptr));
        selAllBt->setText(QApplication::translate("UserMachines", "Unselect All", nullptr));
        tapesLabel->setText(QApplication::translate("UserMachines", "Tapes", nullptr));
        addTapeBt->setText(QApplication::translate("UserMachines", "Add Tape", nullptr));
        loadTapeBt->setText(QApplication::translate("UserMachines", "Load Tape", nullptr));
        simBt->setText(QApplication::translate("UserMachines", "Simulate", nullptr));
        pauseBt->setText(QApplication::translate("UserMachines", "Pause", nullptr));
        contBt->setText(QApplication::translate("UserMachines", "Continue", nullptr));
        stopBt->setText(QApplication::translate("UserMachines", "Stop", nullptr));
        addTableBt->setText(QApplication::translate("UserMachines", "Add Table File", nullptr));
        editTableBt->setText(QApplication::translate("UserMachines", "Edit Table", nullptr));
        saveTableBt->setText(QApplication::translate("UserMachines", "Save Table", nullptr));
        qRandTableBt->setText(QApplication::translate("UserMachines", "Add Quick Random Table", nullptr));
        cRandTableBt->setText(QApplication::translate("UserMachines", "Add Custom Random Table", nullptr));
        settingsBt->setText(QApplication::translate("UserMachines", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserMachines: public Ui_UserMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMACHINES_H
