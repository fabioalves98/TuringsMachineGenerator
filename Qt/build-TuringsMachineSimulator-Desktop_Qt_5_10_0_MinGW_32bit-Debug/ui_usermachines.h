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
#include <QtWidgets/QComboBox>
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
    QWidget *zCentralwidget;
    QVBoxLayout *verticalLayout_4;
    QSplitter *listSplit;
    QWidget *layoutWidget;
    QVBoxLayout *zListsLayout;
    QSplitter *tapeSplit;
    QWidget *layoutWidget1;
    QVBoxLayout *zMachLayout;
    QVBoxLayout *zMachListLayout;
    QLabel *zMachLabel;
    QListWidget *machList;
    QHBoxLayout *zMachBtLayout;
    QPushButton *selAllBt;
    QPushButton *uSelAllBt;
    QPushButton *simBt;
    QWidget *layoutWidget2;
    QVBoxLayout *zTapeLayout;
    QVBoxLayout *zTapeListLayout;
    QLabel *zTapeLabel;
    QListWidget *tapesList;
    QHBoxLayout *zLoadBtLayout;
    QPushButton *loadTapeBt;
    QHBoxLayout *zSimulationLayout;
    QPushButton *pauseBt;
    QPushButton *contBt;
    QPushButton *stopBt;
    QPushButton *slowerBt;
    QPushButton *fasterBt;
    QLabel *delayLb;
    QStackedWidget *machSim;
    QHBoxLayout *zControlLayout;
    QComboBox *buttonSelect;
    QPushButton *addBt;
    QPushButton *editBt;
    QPushButton *saveBt;
    QPushButton *qRandBt;
    QPushButton *cRandBt;
    QPushButton *settingsBt;

    void setupUi(QMainWindow *UserMachines)
    {
        if (UserMachines->objectName().isEmpty())
            UserMachines->setObjectName(QStringLiteral("UserMachines"));
        UserMachines->resize(1280, 720);
        UserMachines->setStyleSheet(QLatin1String("QListWidget::item {\n"
"  padding: 3px;\n"
"}"));
        zCentralwidget = new QWidget(UserMachines);
        zCentralwidget->setObjectName(QStringLiteral("zCentralwidget"));
        verticalLayout_4 = new QVBoxLayout(zCentralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        listSplit = new QSplitter(zCentralwidget);
        listSplit->setObjectName(QStringLiteral("listSplit"));
        listSplit->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(listSplit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        zListsLayout = new QVBoxLayout(layoutWidget);
        zListsLayout->setObjectName(QStringLiteral("zListsLayout"));
        zListsLayout->setContentsMargins(0, 0, 0, 0);
        tapeSplit = new QSplitter(layoutWidget);
        tapeSplit->setObjectName(QStringLiteral("tapeSplit"));
        tapeSplit->setOrientation(Qt::Vertical);
        layoutWidget1 = new QWidget(tapeSplit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        zMachLayout = new QVBoxLayout(layoutWidget1);
        zMachLayout->setSpacing(2);
        zMachLayout->setObjectName(QStringLiteral("zMachLayout"));
        zMachLayout->setContentsMargins(0, 0, 0, 0);
        zMachListLayout = new QVBoxLayout();
        zMachListLayout->setSpacing(0);
        zMachListLayout->setObjectName(QStringLiteral("zMachListLayout"));
        zMachLabel = new QLabel(layoutWidget1);
        zMachLabel->setObjectName(QStringLiteral("zMachLabel"));
        zMachLabel->setEnabled(true);
        zMachLabel->setMinimumSize(QSize(0, 33));
        QFont font;
        font.setPointSize(16);
        zMachLabel->setFont(font);
        zMachLabel->setFrameShape(QFrame::Panel);
        zMachLabel->setFrameShadow(QFrame::Raised);
        zMachLabel->setAlignment(Qt::AlignCenter);
        zMachLabel->setMargin(3);

        zMachListLayout->addWidget(zMachLabel);

        machList = new QListWidget(layoutWidget1);
        machList->setObjectName(QStringLiteral("machList"));
        machList->setStyleSheet(QStringLiteral(""));

        zMachListLayout->addWidget(machList);


        zMachLayout->addLayout(zMachListLayout);

        zMachBtLayout = new QHBoxLayout();
        zMachBtLayout->setObjectName(QStringLiteral("zMachBtLayout"));
        selAllBt = new QPushButton(layoutWidget1);
        selAllBt->setObjectName(QStringLiteral("selAllBt"));
        QFont font1;
        font1.setPointSize(10);
        selAllBt->setFont(font1);

        zMachBtLayout->addWidget(selAllBt);

        uSelAllBt = new QPushButton(layoutWidget1);
        uSelAllBt->setObjectName(QStringLiteral("uSelAllBt"));
        uSelAllBt->setFont(font1);

        zMachBtLayout->addWidget(uSelAllBt);


        zMachLayout->addLayout(zMachBtLayout);

        simBt = new QPushButton(layoutWidget1);
        simBt->setObjectName(QStringLiteral("simBt"));
        simBt->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(14);
        simBt->setFont(font2);

        zMachLayout->addWidget(simBt);

        tapeSplit->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(tapeSplit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        zTapeLayout = new QVBoxLayout(layoutWidget2);
        zTapeLayout->setSpacing(2);
        zTapeLayout->setObjectName(QStringLiteral("zTapeLayout"));
        zTapeLayout->setContentsMargins(0, 0, 0, 0);
        zTapeListLayout = new QVBoxLayout();
        zTapeListLayout->setSpacing(0);
        zTapeListLayout->setObjectName(QStringLiteral("zTapeListLayout"));
        zTapeLabel = new QLabel(layoutWidget2);
        zTapeLabel->setObjectName(QStringLiteral("zTapeLabel"));
        zTapeLabel->setMinimumSize(QSize(0, 33));
        zTapeLabel->setFont(font);
        zTapeLabel->setFrameShape(QFrame::Panel);
        zTapeLabel->setFrameShadow(QFrame::Raised);
        zTapeLabel->setAlignment(Qt::AlignCenter);

        zTapeListLayout->addWidget(zTapeLabel);

        tapesList = new QListWidget(layoutWidget2);
        tapesList->setObjectName(QStringLiteral("tapesList"));

        zTapeListLayout->addWidget(tapesList);


        zTapeLayout->addLayout(zTapeListLayout);

        zLoadBtLayout = new QHBoxLayout();
        zLoadBtLayout->setObjectName(QStringLiteral("zLoadBtLayout"));
        loadTapeBt = new QPushButton(layoutWidget2);
        loadTapeBt->setObjectName(QStringLiteral("loadTapeBt"));
        loadTapeBt->setFont(font1);

        zLoadBtLayout->addWidget(loadTapeBt);


        zTapeLayout->addLayout(zLoadBtLayout);

        tapeSplit->addWidget(layoutWidget2);

        zListsLayout->addWidget(tapeSplit);

        zSimulationLayout = new QHBoxLayout();
        zSimulationLayout->setObjectName(QStringLiteral("zSimulationLayout"));
        pauseBt = new QPushButton(layoutWidget);
        pauseBt->setObjectName(QStringLiteral("pauseBt"));
        pauseBt->setMinimumSize(QSize(30, 27));
        pauseBt->setMaximumSize(QSize(16777215, 27));
        QFont font3;
        font3.setPointSize(12);
        pauseBt->setFont(font3);

        zSimulationLayout->addWidget(pauseBt);

        contBt = new QPushButton(layoutWidget);
        contBt->setObjectName(QStringLiteral("contBt"));
        contBt->setMinimumSize(QSize(30, 27));
        contBt->setMaximumSize(QSize(16777215, 27));
        contBt->setFont(font3);

        zSimulationLayout->addWidget(contBt);

        stopBt = new QPushButton(layoutWidget);
        stopBt->setObjectName(QStringLiteral("stopBt"));
        stopBt->setMinimumSize(QSize(30, 27));
        stopBt->setMaximumSize(QSize(16777215, 27));
        stopBt->setFont(font3);

        zSimulationLayout->addWidget(stopBt);

        slowerBt = new QPushButton(layoutWidget);
        slowerBt->setObjectName(QStringLiteral("slowerBt"));
        slowerBt->setMinimumSize(QSize(30, 27));
        slowerBt->setMaximumSize(QSize(16777215, 27));

        zSimulationLayout->addWidget(slowerBt);

        fasterBt = new QPushButton(layoutWidget);
        fasterBt->setObjectName(QStringLiteral("fasterBt"));
        fasterBt->setMinimumSize(QSize(30, 27));
        fasterBt->setMaximumSize(QSize(16777215, 27));

        zSimulationLayout->addWidget(fasterBt);

        delayLb = new QLabel(layoutWidget);
        delayLb->setObjectName(QStringLiteral("delayLb"));
        delayLb->setAlignment(Qt::AlignCenter);

        zSimulationLayout->addWidget(delayLb);


        zListsLayout->addLayout(zSimulationLayout);

        listSplit->addWidget(layoutWidget);
        machSim = new QStackedWidget(listSplit);
        machSim->setObjectName(QStringLiteral("machSim"));
        listSplit->addWidget(machSim);

        verticalLayout_4->addWidget(listSplit);

        zControlLayout = new QHBoxLayout();
        zControlLayout->setObjectName(QStringLiteral("zControlLayout"));
        buttonSelect = new QComboBox(zCentralwidget);
        buttonSelect->addItem(QString());
        buttonSelect->addItem(QString());
        buttonSelect->setObjectName(QStringLiteral("buttonSelect"));
        buttonSelect->setMaximumSize(QSize(92, 16777215));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        buttonSelect->setFont(font4);

        zControlLayout->addWidget(buttonSelect);

        addBt = new QPushButton(zCentralwidget);
        addBt->setObjectName(QStringLiteral("addBt"));
        addBt->setFont(font3);

        zControlLayout->addWidget(addBt);

        editBt = new QPushButton(zCentralwidget);
        editBt->setObjectName(QStringLiteral("editBt"));
        editBt->setFont(font3);

        zControlLayout->addWidget(editBt);

        saveBt = new QPushButton(zCentralwidget);
        saveBt->setObjectName(QStringLiteral("saveBt"));
        saveBt->setFont(font3);

        zControlLayout->addWidget(saveBt);

        qRandBt = new QPushButton(zCentralwidget);
        qRandBt->setObjectName(QStringLiteral("qRandBt"));
        qRandBt->setFont(font3);

        zControlLayout->addWidget(qRandBt);

        cRandBt = new QPushButton(zCentralwidget);
        cRandBt->setObjectName(QStringLiteral("cRandBt"));
        cRandBt->setFont(font3);

        zControlLayout->addWidget(cRandBt);

        settingsBt = new QPushButton(zCentralwidget);
        settingsBt->setObjectName(QStringLiteral("settingsBt"));
        settingsBt->setFont(font3);

        zControlLayout->addWidget(settingsBt);


        verticalLayout_4->addLayout(zControlLayout);

        UserMachines->setCentralWidget(zCentralwidget);

        retranslateUi(UserMachines);

        QMetaObject::connectSlotsByName(UserMachines);
    } // setupUi

    void retranslateUi(QMainWindow *UserMachines)
    {
        UserMachines->setWindowTitle(QApplication::translate("UserMachines", "MainWindow", nullptr));
        zMachLabel->setText(QApplication::translate("UserMachines", "Turing's Machines", nullptr));
        selAllBt->setText(QApplication::translate("UserMachines", "Select All", nullptr));
        uSelAllBt->setText(QApplication::translate("UserMachines", "Unselect All", nullptr));
        simBt->setText(QApplication::translate("UserMachines", "Run", nullptr));
        zTapeLabel->setText(QApplication::translate("UserMachines", "Tapes", nullptr));
        loadTapeBt->setText(QApplication::translate("UserMachines", "Load Tape", nullptr));
        pauseBt->setText(QString());
        contBt->setText(QString());
        stopBt->setText(QString());
        slowerBt->setText(QString());
        fasterBt->setText(QString());
        delayLb->setText(QString());
        buttonSelect->setItemText(0, QApplication::translate("UserMachines", "Machine", nullptr));
        buttonSelect->setItemText(1, QApplication::translate("UserMachines", "Tape", nullptr));

        addBt->setText(QString());
        editBt->setText(QString());
        saveBt->setText(QString());
        qRandBt->setText(QString());
        cRandBt->setText(QString());
        settingsBt->setText(QApplication::translate("UserMachines", "Help / Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserMachines: public Ui_UserMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMACHINES_H
