/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidget;
    QWidget *general;
    QWidget *randomTables;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QComboBox *nameRandNum;
    QLabel *label_4;
    QGroupBox *statesGBox;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *stLabels;
    QLabel *minStLabel;
    QLabel *maxStLabel;
    QLabel *inStLabel;
    QLabel *hltStLabel;
    QVBoxLayout *stSettings;
    QHBoxLayout *customStates;
    QVBoxLayout *stSpinBoxs;
    QSpinBox *minStSpinBox;
    QSpinBox *maxStSpinBox;
    QHBoxLayout *stLayout;
    QSpacerItem *stSpinBoxSpacer;
    QHBoxLayout *inState;
    QComboBox *inStCBox;
    QCheckBox *rInStCheck;
    QSpacerItem *inStSpacer;
    QHBoxLayout *haltState;
    QLineEdit *haltStEdit;
    QSpacerItem *haltStSpacer;
    QGroupBox *symbolsGBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *syLabels;
    QLabel *minSyLabel;
    QLabel *maxSyLabel;
    QVBoxLayout *sySpinBoxs;
    QSpinBox *minSySpinBox;
    QSpinBox *maxSySpinBox;
    QHBoxLayout *syLayout;
    QSpacerItem *sySpinBoxerSpacer;
    QSpacerItem *verticalSpacer;
    QWidget *simulation;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *delaySpinBox;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *haltSimCheck;
    QSpinBox *haltSimSpinBox;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *about;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(800, 600);
        centralwidget = new QWidget(Settings);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(3, 3, 3, 3);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        general = new QWidget();
        general->setObjectName(QStringLiteral("general"));
        tabWidget->addTab(general, QString());
        randomTables = new QWidget();
        randomTables->setObjectName(QStringLiteral("randomTables"));
        verticalLayout_8 = new QVBoxLayout(randomTables);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        groupBox = new QGroupBox(randomTables);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setPointSize(13);
        groupBox->setFont(font1);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(11);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        QFont font3;
        font3.setPointSize(10);
        nameEdit->setFont(font3);

        horizontalLayout->addWidget(nameEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        horizontalLayout->addWidget(label_3);

        nameRandNum = new QComboBox(groupBox);
        nameRandNum->setObjectName(QStringLiteral("nameRandNum"));
        nameRandNum->setFont(font2);

        horizontalLayout->addWidget(nameRandNum);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        horizontalLayout->addWidget(label_4);


        verticalLayout_8->addWidget(groupBox);

        statesGBox = new QGroupBox(randomTables);
        statesGBox->setObjectName(QStringLiteral("statesGBox"));
        statesGBox->setFont(font1);
        horizontalLayout_5 = new QHBoxLayout(statesGBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        stLabels = new QVBoxLayout();
        stLabels->setObjectName(QStringLiteral("stLabels"));
        minStLabel = new QLabel(statesGBox);
        minStLabel->setObjectName(QStringLiteral("minStLabel"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        minStLabel->setFont(font4);

        stLabels->addWidget(minStLabel);

        maxStLabel = new QLabel(statesGBox);
        maxStLabel->setObjectName(QStringLiteral("maxStLabel"));
        maxStLabel->setFont(font2);

        stLabels->addWidget(maxStLabel);

        inStLabel = new QLabel(statesGBox);
        inStLabel->setObjectName(QStringLiteral("inStLabel"));
        inStLabel->setFont(font2);

        stLabels->addWidget(inStLabel);

        hltStLabel = new QLabel(statesGBox);
        hltStLabel->setObjectName(QStringLiteral("hltStLabel"));
        hltStLabel->setFont(font2);

        stLabels->addWidget(hltStLabel);


        horizontalLayout_5->addLayout(stLabels);

        stSettings = new QVBoxLayout();
        stSettings->setSpacing(6);
        stSettings->setObjectName(QStringLiteral("stSettings"));
        customStates = new QHBoxLayout();
        customStates->setObjectName(QStringLiteral("customStates"));
        stSpinBoxs = new QVBoxLayout();
        stSpinBoxs->setSpacing(6);
        stSpinBoxs->setObjectName(QStringLiteral("stSpinBoxs"));
        minStSpinBox = new QSpinBox(statesGBox);
        minStSpinBox->setObjectName(QStringLiteral("minStSpinBox"));
        minStSpinBox->setMinimumSize(QSize(50, 30));
        QFont font5;
        font5.setPointSize(12);
        minStSpinBox->setFont(font5);
        minStSpinBox->setMinimum(1);
        minStSpinBox->setMaximum(25);

        stSpinBoxs->addWidget(minStSpinBox);

        maxStSpinBox = new QSpinBox(statesGBox);
        maxStSpinBox->setObjectName(QStringLiteral("maxStSpinBox"));
        maxStSpinBox->setMinimumSize(QSize(50, 30));
        maxStSpinBox->setFont(font5);
        maxStSpinBox->setMinimum(1);
        maxStSpinBox->setMaximum(25);

        stSpinBoxs->addWidget(maxStSpinBox);


        customStates->addLayout(stSpinBoxs);

        stLayout = new QHBoxLayout();
        stLayout->setSpacing(6);
        stLayout->setObjectName(QStringLiteral("stLayout"));

        customStates->addLayout(stLayout);

        stSpinBoxSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        customStates->addItem(stSpinBoxSpacer);


        stSettings->addLayout(customStates);

        inState = new QHBoxLayout();
        inState->setObjectName(QStringLiteral("inState"));
        inStCBox = new QComboBox(statesGBox);
        inStCBox->setObjectName(QStringLiteral("inStCBox"));
        inStCBox->setMinimumSize(QSize(50, 30));
        inStCBox->setMaximumSize(QSize(50, 30));
        inStCBox->setFont(font5);

        inState->addWidget(inStCBox);

        rInStCheck = new QCheckBox(statesGBox);
        rInStCheck->setObjectName(QStringLiteral("rInStCheck"));
        rInStCheck->setFont(font3);

        inState->addWidget(rInStCheck);

        inStSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        inState->addItem(inStSpacer);


        stSettings->addLayout(inState);

        haltState = new QHBoxLayout();
        haltState->setObjectName(QStringLiteral("haltState"));
        haltStEdit = new QLineEdit(statesGBox);
        haltStEdit->setObjectName(QStringLiteral("haltStEdit"));
        haltStEdit->setMinimumSize(QSize(50, 30));
        haltStEdit->setMaximumSize(QSize(50, 30));
        haltStEdit->setFont(font5);

        haltState->addWidget(haltStEdit);

        haltStSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        haltState->addItem(haltStSpacer);


        stSettings->addLayout(haltState);


        horizontalLayout_5->addLayout(stSettings);


        verticalLayout_8->addWidget(statesGBox);

        symbolsGBox = new QGroupBox(randomTables);
        symbolsGBox->setObjectName(QStringLiteral("symbolsGBox"));
        symbolsGBox->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(symbolsGBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        syLabels = new QVBoxLayout();
        syLabels->setObjectName(QStringLiteral("syLabels"));
        minSyLabel = new QLabel(symbolsGBox);
        minSyLabel->setObjectName(QStringLiteral("minSyLabel"));
        minSyLabel->setFont(font4);

        syLabels->addWidget(minSyLabel);

        maxSyLabel = new QLabel(symbolsGBox);
        maxSyLabel->setObjectName(QStringLiteral("maxSyLabel"));
        maxSyLabel->setFont(font2);

        syLabels->addWidget(maxSyLabel);


        horizontalLayout_2->addLayout(syLabels);

        sySpinBoxs = new QVBoxLayout();
        sySpinBoxs->setObjectName(QStringLiteral("sySpinBoxs"));
        minSySpinBox = new QSpinBox(symbolsGBox);
        minSySpinBox->setObjectName(QStringLiteral("minSySpinBox"));
        minSySpinBox->setMinimumSize(QSize(50, 30));
        minSySpinBox->setFont(font5);
        minSySpinBox->setMinimum(1);
        minSySpinBox->setMaximum(10);

        sySpinBoxs->addWidget(minSySpinBox);

        maxSySpinBox = new QSpinBox(symbolsGBox);
        maxSySpinBox->setObjectName(QStringLiteral("maxSySpinBox"));
        maxSySpinBox->setMinimumSize(QSize(50, 30));
        maxSySpinBox->setFont(font5);
        maxSySpinBox->setMinimum(1);
        maxSySpinBox->setMaximum(10);

        sySpinBoxs->addWidget(maxSySpinBox);


        horizontalLayout_2->addLayout(sySpinBoxs);

        syLayout = new QHBoxLayout();
        syLayout->setObjectName(QStringLiteral("syLayout"));

        horizontalLayout_2->addLayout(syLayout);

        sySpinBoxerSpacer = new QSpacerItem(609, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(sySpinBoxerSpacer);


        verticalLayout_8->addWidget(symbolsGBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        tabWidget->addTab(randomTables, QString());
        simulation = new QWidget();
        simulation->setObjectName(QStringLiteral("simulation"));
        verticalLayout_2 = new QVBoxLayout(simulation);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_2 = new QGroupBox(simulation);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font1);
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        horizontalLayout_3->addWidget(label_2);

        delaySpinBox = new QSpinBox(groupBox_2);
        delaySpinBox->setObjectName(QStringLiteral("delaySpinBox"));
        delaySpinBox->setMinimum(50);
        delaySpinBox->setMaximum(1000000);
        delaySpinBox->setSingleStep(50);
        delaySpinBox->setValue(200);

        horizontalLayout_3->addWidget(delaySpinBox);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(477, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(simulation);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font1);
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        haltSimCheck = new QCheckBox(groupBox_3);
        haltSimCheck->setObjectName(QStringLiteral("haltSimCheck"));
        haltSimCheck->setFont(font2);

        horizontalLayout_6->addWidget(haltSimCheck);

        haltSimSpinBox = new QSpinBox(groupBox_3);
        haltSimSpinBox->setObjectName(QStringLiteral("haltSimSpinBox"));
        haltSimSpinBox->setMinimum(1);
        haltSimSpinBox->setMaximum(10000000);

        horizontalLayout_6->addWidget(haltSimSpinBox);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        horizontalLayout_6->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(groupBox_3);

        verticalSpacer_2 = new QSpacerItem(20, 418, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tabWidget->addTab(simulation, QString());
        about = new QWidget();
        about->setObjectName(QStringLiteral("about"));
        tabWidget->addTab(about, QString());

        verticalLayout_6->addWidget(tabWidget);

        Settings->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(Settings);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Settings->setStatusBar(statusBar);

        retranslateUi(Settings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QMainWindow *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(general), QApplication::translate("Settings", "General", nullptr));
        groupBox->setTitle(QApplication::translate("Settings", "Name Generation", nullptr));
        label->setText(QApplication::translate("Settings", "Name Prefix: ", nullptr));
        label_3->setText(QApplication::translate("Settings", "+", nullptr));
        label_4->setText(QApplication::translate("Settings", "Random integer", nullptr));
        statesGBox->setTitle(QApplication::translate("Settings", "States", nullptr));
        minStLabel->setText(QApplication::translate("Settings", "Minimum:", nullptr));
        maxStLabel->setText(QApplication::translate("Settings", "Maximum:", nullptr));
        inStLabel->setText(QApplication::translate("Settings", "Initial State:", nullptr));
        hltStLabel->setText(QApplication::translate("Settings", "Halt State:", nullptr));
        rInStCheck->setText(QApplication::translate("Settings", "Random", nullptr));
        symbolsGBox->setTitle(QApplication::translate("Settings", "Symbols", nullptr));
        minSyLabel->setText(QApplication::translate("Settings", "Minimum:", nullptr));
        maxSyLabel->setText(QApplication::translate("Settings", "Maximum:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(randomTables), QApplication::translate("Settings", "Quick Random Tables", nullptr));
        groupBox_2->setTitle(QApplication::translate("Settings", "Iteration Delay", nullptr));
        label_2->setText(QApplication::translate("Settings", "Delay between iterations (ms):", nullptr));
        groupBox_3->setTitle(QApplication::translate("Settings", "Halt Simulation", nullptr));
        haltSimCheck->setText(QApplication::translate("Settings", "Halt Simulation in ", nullptr));
        label_5->setText(QApplication::translate("Settings", "iterations", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(simulation), QApplication::translate("Settings", "Simulation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(about), QApplication::translate("Settings", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
