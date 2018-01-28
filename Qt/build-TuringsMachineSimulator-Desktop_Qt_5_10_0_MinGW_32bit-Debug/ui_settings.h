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
    QLineEdit *lineEdit;
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
    QHBoxLayout *hltState;
    QLineEdit *hltStEdit;
    QSpacerItem *hltStSpacer;
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
    QWidget *about;

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

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font3;
        font3.setPointSize(10);
        lineEdit->setFont(font3);

        horizontalLayout->addWidget(lineEdit);


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

        stSpinBoxs->addWidget(minStSpinBox);

        maxStSpinBox = new QSpinBox(statesGBox);
        maxStSpinBox->setObjectName(QStringLiteral("maxStSpinBox"));
        maxStSpinBox->setMinimumSize(QSize(50, 30));
        maxStSpinBox->setFont(font5);

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

        hltState = new QHBoxLayout();
        hltState->setObjectName(QStringLiteral("hltState"));
        hltStEdit = new QLineEdit(statesGBox);
        hltStEdit->setObjectName(QStringLiteral("hltStEdit"));
        hltStEdit->setMinimumSize(QSize(50, 30));
        hltStEdit->setMaximumSize(QSize(50, 30));
        hltStEdit->setFont(font5);

        hltState->addWidget(hltStEdit);

        hltStSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hltState->addItem(hltStSpacer);


        stSettings->addLayout(hltState);


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

        sySpinBoxs->addWidget(minSySpinBox);

        maxSySpinBox = new QSpinBox(symbolsGBox);
        maxSySpinBox->setObjectName(QStringLiteral("maxSySpinBox"));
        maxSySpinBox->setMinimumSize(QSize(50, 30));
        maxSySpinBox->setFont(font5);

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
        tabWidget->addTab(simulation, QString());
        about = new QWidget();
        about->setObjectName(QStringLiteral("about"));
        tabWidget->addTab(about, QString());

        verticalLayout_6->addWidget(tabWidget);

        Settings->setCentralWidget(centralwidget);

        retranslateUi(Settings);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QMainWindow *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(general), QApplication::translate("Settings", "General", nullptr));
        groupBox->setTitle(QApplication::translate("Settings", "Name Generation", nullptr));
        label->setText(QApplication::translate("Settings", "Name Prefix: ", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(simulation), QApplication::translate("Settings", "Simulation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(about), QApplication::translate("Settings", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
