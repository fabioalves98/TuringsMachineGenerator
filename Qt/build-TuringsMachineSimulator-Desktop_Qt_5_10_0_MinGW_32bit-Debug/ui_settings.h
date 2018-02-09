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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_13;
    QTabWidget *tabWidget;
    QWidget *Genereal;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *Usage;
    QHBoxLayout *horizontalLayout_8;
    QTextBrowser *usageTBrows;
    QSplitter *generalSplit;
    QGroupBox *MachineConf;
    QHBoxLayout *horizontalLayout_9;
    QTextBrowser *machineTBrows;
    QGroupBox *TapeConf;
    QHBoxLayout *horizontalLayout_10;
    QTextBrowser *tapeTBrows;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *presetsCBox;
    QPushButton *loadPresetBt;
    QSpacerItem *zSpacer_10;
    QTextBrowser *presetDescTBrows;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *zSpacer_11;
    QPushButton *defaultSetBt;
    QSpacerItem *verticalSpacer;
    QWidget *RandomTables;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *TableNameBox;
    QHBoxLayout *horizontalLayout;
    QLabel *zNameLabel;
    QLineEdit *tableNameEdit;
    QLabel *zPlusLabel;
    QComboBox *tableRandSuffix;
    QLabel *zIntLabel;
    QGroupBox *StatesBox;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *StLabels;
    QLabel *zMinStLabel;
    QLabel *zMaxStLabel;
    QLabel *zInStLabel;
    QLabel *zHltStLabel;
    QVBoxLayout *StSettings;
    QHBoxLayout *customStates;
    QVBoxLayout *stSpinBoxs;
    QSpinBox *minStSpinBox;
    QSpinBox *maxStSpinBox;
    QHBoxLayout *stLayout;
    QSpacerItem *zSpacer;
    QHBoxLayout *inState;
    QComboBox *inStCBox;
    QCheckBox *rInStCheck;
    QSpacerItem *zSpacer_2;
    QHBoxLayout *haltState;
    QLineEdit *haltStEdit;
    QSpacerItem *zSpacer_3;
    QGroupBox *SymbolsBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *syLabels;
    QLabel *zMinSyLabel;
    QLabel *zMaxSyLabel;
    QVBoxLayout *sySpinBoxs;
    QSpinBox *minSySpinBox;
    QSpinBox *maxSySpinBox;
    QHBoxLayout *syLayout;
    QSpacerItem *zSpacer_4;
    QSpacerItem *zSpacer_9;
    QWidget *RandomTapes;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *TapeNameBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *zLabel;
    QLineEdit *tapeNameEdit;
    QLabel *zLabel_2;
    QComboBox *tapeRandSuffix;
    QLabel *zLabel_3;
    QGroupBox *TapeBox;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *TapeLabels;
    QLabel *zLabel_7;
    QLabel *zLabel_6;
    QLabel *zLabel_5;
    QLabel *zLabel_4;
    QVBoxLayout *TapeSettings;
    QHBoxLayout *zSymLayout;
    QSpinBox *tapeSySBox;
    QHBoxLayout *tapeSyLayout;
    QSpacerItem *zSpacer_5;
    QHBoxLayout *MinSize;
    QSpinBox *tapeMinSizeSBox;
    QSpacerItem *zSpacer_6;
    QHBoxLayout *MaxSize;
    QSpinBox *tapeMaxSizeSBox;
    QSpacerItem *zSpacer_8;
    QHBoxLayout *BlacnkSymbol;
    QLineEdit *tapeBSymEdit;
    QCheckBox *rBSyCheck;
    QSpacerItem *zSpacer_7;
    QSpacerItem *verticalSpacer_3;
    QWidget *simulation;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_6;
    QSpinBox *concurrentSim;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *haltSimCheck;
    QSpinBox *haltSimSpinBox;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *delaySpinBox;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label;
    QSpinBox *simHistSBox;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(854, 599);
        centralwidget = new QWidget(Settings);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_13 = new QHBoxLayout(centralwidget);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        Genereal = new QWidget();
        Genereal->setObjectName(QStringLiteral("Genereal"));
        verticalLayout_4 = new QVBoxLayout(Genereal);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Usage = new QGroupBox(Genereal);
        Usage->setObjectName(QStringLiteral("Usage"));
        QFont font1;
        font1.setPointSize(13);
        Usage->setFont(font1);
        horizontalLayout_8 = new QHBoxLayout(Usage);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        usageTBrows = new QTextBrowser(Usage);
        usageTBrows->setObjectName(QStringLiteral("usageTBrows"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usageTBrows->sizePolicy().hasHeightForWidth());
        usageTBrows->setSizePolicy(sizePolicy);
        usageTBrows->setMinimumSize(QSize(0, 65));
        usageTBrows->setMaximumSize(QSize(16777215, 65));
        usageTBrows->setFrameShape(QFrame::NoFrame);

        horizontalLayout_8->addWidget(usageTBrows);


        verticalLayout_4->addWidget(Usage);

        generalSplit = new QSplitter(Genereal);
        generalSplit->setObjectName(QStringLiteral("generalSplit"));
        generalSplit->setOrientation(Qt::Horizontal);
        generalSplit->setHandleWidth(1);
        MachineConf = new QGroupBox(generalSplit);
        MachineConf->setObjectName(QStringLiteral("MachineConf"));
        MachineConf->setFont(font1);
        horizontalLayout_9 = new QHBoxLayout(MachineConf);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        machineTBrows = new QTextBrowser(MachineConf);
        machineTBrows->setObjectName(QStringLiteral("machineTBrows"));
        sizePolicy.setHeightForWidth(machineTBrows->sizePolicy().hasHeightForWidth());
        machineTBrows->setSizePolicy(sizePolicy);
        machineTBrows->setMinimumSize(QSize(460, 155));
        machineTBrows->setMaximumSize(QSize(16777215, 155));

        horizontalLayout_9->addWidget(machineTBrows);

        generalSplit->addWidget(MachineConf);
        TapeConf = new QGroupBox(generalSplit);
        TapeConf->setObjectName(QStringLiteral("TapeConf"));
        TapeConf->setFont(font1);
        horizontalLayout_10 = new QHBoxLayout(TapeConf);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        tapeTBrows = new QTextBrowser(TapeConf);
        tapeTBrows->setObjectName(QStringLiteral("tapeTBrows"));
        sizePolicy.setHeightForWidth(tapeTBrows->sizePolicy().hasHeightForWidth());
        tapeTBrows->setSizePolicy(sizePolicy);
        tapeTBrows->setMinimumSize(QSize(263, 155));
        tapeTBrows->setMaximumSize(QSize(16777215, 155));

        horizontalLayout_10->addWidget(tapeTBrows);

        generalSplit->addWidget(TapeConf);

        verticalLayout_4->addWidget(generalSplit);

        groupBox = new QGroupBox(Genereal);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font1);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        presetsCBox = new QComboBox(groupBox);
        presetsCBox->setObjectName(QStringLiteral("presetsCBox"));
        presetsCBox->setMinimumSize(QSize(180, 0));

        horizontalLayout_11->addWidget(presetsCBox);

        loadPresetBt = new QPushButton(groupBox);
        loadPresetBt->setObjectName(QStringLiteral("loadPresetBt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loadPresetBt->sizePolicy().hasHeightForWidth());
        loadPresetBt->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(11);
        loadPresetBt->setFont(font2);

        horizontalLayout_11->addWidget(loadPresetBt);

        zSpacer_10 = new QSpacerItem(491, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(zSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_11);

        presetDescTBrows = new QTextBrowser(groupBox);
        presetDescTBrows->setObjectName(QStringLiteral("presetDescTBrows"));
        presetDescTBrows->setMinimumSize(QSize(0, 48));
        presetDescTBrows->setMaximumSize(QSize(16777215, 48));

        verticalLayout_3->addWidget(presetDescTBrows);


        verticalLayout_4->addWidget(groupBox);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        zSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(zSpacer_11);

        defaultSetBt = new QPushButton(Genereal);
        defaultSetBt->setObjectName(QStringLiteral("defaultSetBt"));
        QFont font3;
        font3.setPointSize(12);
        defaultSetBt->setFont(font3);

        horizontalLayout_15->addWidget(defaultSetBt);


        verticalLayout_4->addLayout(horizontalLayout_15);

        verticalSpacer = new QSpacerItem(20, 144, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        tabWidget->addTab(Genereal, QString());
        RandomTables = new QWidget();
        RandomTables->setObjectName(QStringLiteral("RandomTables"));
        verticalLayout_8 = new QVBoxLayout(RandomTables);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        TableNameBox = new QGroupBox(RandomTables);
        TableNameBox->setObjectName(QStringLiteral("TableNameBox"));
        TableNameBox->setFont(font1);
        horizontalLayout = new QHBoxLayout(TableNameBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        zNameLabel = new QLabel(TableNameBox);
        zNameLabel->setObjectName(QStringLiteral("zNameLabel"));
        zNameLabel->setMaximumSize(QSize(85, 16777215));
        zNameLabel->setFont(font2);

        horizontalLayout->addWidget(zNameLabel);

        tableNameEdit = new QLineEdit(TableNameBox);
        tableNameEdit->setObjectName(QStringLiteral("tableNameEdit"));
        tableNameEdit->setFont(font3);

        horizontalLayout->addWidget(tableNameEdit);

        zPlusLabel = new QLabel(TableNameBox);
        zPlusLabel->setObjectName(QStringLiteral("zPlusLabel"));
        zPlusLabel->setFont(font2);

        horizontalLayout->addWidget(zPlusLabel);

        tableRandSuffix = new QComboBox(TableNameBox);
        tableRandSuffix->setObjectName(QStringLiteral("tableRandSuffix"));
        tableRandSuffix->setMinimumSize(QSize(80, 0));
        tableRandSuffix->setMaximumSize(QSize(80, 16777215));
        tableRandSuffix->setFont(font3);

        horizontalLayout->addWidget(tableRandSuffix);

        zIntLabel = new QLabel(TableNameBox);
        zIntLabel->setObjectName(QStringLiteral("zIntLabel"));
        zIntLabel->setFont(font2);

        horizontalLayout->addWidget(zIntLabel);


        verticalLayout_8->addWidget(TableNameBox);

        StatesBox = new QGroupBox(RandomTables);
        StatesBox->setObjectName(QStringLiteral("StatesBox"));
        StatesBox->setFont(font1);
        horizontalLayout_5 = new QHBoxLayout(StatesBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        StLabels = new QVBoxLayout();
        StLabels->setObjectName(QStringLiteral("StLabels"));
        zMinStLabel = new QLabel(StatesBox);
        zMinStLabel->setObjectName(QStringLiteral("zMinStLabel"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        zMinStLabel->setFont(font4);

        StLabels->addWidget(zMinStLabel);

        zMaxStLabel = new QLabel(StatesBox);
        zMaxStLabel->setObjectName(QStringLiteral("zMaxStLabel"));
        zMaxStLabel->setFont(font2);

        StLabels->addWidget(zMaxStLabel);

        zInStLabel = new QLabel(StatesBox);
        zInStLabel->setObjectName(QStringLiteral("zInStLabel"));
        zInStLabel->setFont(font2);

        StLabels->addWidget(zInStLabel);

        zHltStLabel = new QLabel(StatesBox);
        zHltStLabel->setObjectName(QStringLiteral("zHltStLabel"));
        zHltStLabel->setFont(font2);

        StLabels->addWidget(zHltStLabel);


        horizontalLayout_5->addLayout(StLabels);

        StSettings = new QVBoxLayout();
        StSettings->setSpacing(6);
        StSettings->setObjectName(QStringLiteral("StSettings"));
        customStates = new QHBoxLayout();
        customStates->setObjectName(QStringLiteral("customStates"));
        stSpinBoxs = new QVBoxLayout();
        stSpinBoxs->setSpacing(6);
        stSpinBoxs->setObjectName(QStringLiteral("stSpinBoxs"));
        minStSpinBox = new QSpinBox(StatesBox);
        minStSpinBox->setObjectName(QStringLiteral("minStSpinBox"));
        minStSpinBox->setMinimumSize(QSize(50, 30));
        minStSpinBox->setFont(font3);
        minStSpinBox->setMinimum(1);
        minStSpinBox->setMaximum(25);

        stSpinBoxs->addWidget(minStSpinBox);

        maxStSpinBox = new QSpinBox(StatesBox);
        maxStSpinBox->setObjectName(QStringLiteral("maxStSpinBox"));
        maxStSpinBox->setMinimumSize(QSize(50, 30));
        maxStSpinBox->setFont(font3);
        maxStSpinBox->setMinimum(1);
        maxStSpinBox->setMaximum(25);

        stSpinBoxs->addWidget(maxStSpinBox);


        customStates->addLayout(stSpinBoxs);

        stLayout = new QHBoxLayout();
        stLayout->setSpacing(6);
        stLayout->setObjectName(QStringLiteral("stLayout"));

        customStates->addLayout(stLayout);

        zSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        customStates->addItem(zSpacer);


        StSettings->addLayout(customStates);

        inState = new QHBoxLayout();
        inState->setObjectName(QStringLiteral("inState"));
        inStCBox = new QComboBox(StatesBox);
        inStCBox->setObjectName(QStringLiteral("inStCBox"));
        inStCBox->setMinimumSize(QSize(50, 30));
        inStCBox->setMaximumSize(QSize(50, 30));
        inStCBox->setFont(font3);

        inState->addWidget(inStCBox);

        rInStCheck = new QCheckBox(StatesBox);
        rInStCheck->setObjectName(QStringLiteral("rInStCheck"));
        QFont font5;
        font5.setPointSize(10);
        rInStCheck->setFont(font5);

        inState->addWidget(rInStCheck);

        zSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        inState->addItem(zSpacer_2);


        StSettings->addLayout(inState);

        haltState = new QHBoxLayout();
        haltState->setObjectName(QStringLiteral("haltState"));
        haltStEdit = new QLineEdit(StatesBox);
        haltStEdit->setObjectName(QStringLiteral("haltStEdit"));
        haltStEdit->setMinimumSize(QSize(50, 30));
        haltStEdit->setMaximumSize(QSize(50, 30));
        haltStEdit->setFont(font3);
        haltStEdit->setMaxLength(1);
        haltStEdit->setAlignment(Qt::AlignCenter);

        haltState->addWidget(haltStEdit);

        zSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        haltState->addItem(zSpacer_3);


        StSettings->addLayout(haltState);


        horizontalLayout_5->addLayout(StSettings);


        verticalLayout_8->addWidget(StatesBox);

        SymbolsBox = new QGroupBox(RandomTables);
        SymbolsBox->setObjectName(QStringLiteral("SymbolsBox"));
        SymbolsBox->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(SymbolsBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        syLabels = new QVBoxLayout();
        syLabels->setObjectName(QStringLiteral("syLabels"));
        zMinSyLabel = new QLabel(SymbolsBox);
        zMinSyLabel->setObjectName(QStringLiteral("zMinSyLabel"));
        zMinSyLabel->setFont(font4);

        syLabels->addWidget(zMinSyLabel);

        zMaxSyLabel = new QLabel(SymbolsBox);
        zMaxSyLabel->setObjectName(QStringLiteral("zMaxSyLabel"));
        zMaxSyLabel->setFont(font2);

        syLabels->addWidget(zMaxSyLabel);


        horizontalLayout_2->addLayout(syLabels);

        sySpinBoxs = new QVBoxLayout();
        sySpinBoxs->setObjectName(QStringLiteral("sySpinBoxs"));
        minSySpinBox = new QSpinBox(SymbolsBox);
        minSySpinBox->setObjectName(QStringLiteral("minSySpinBox"));
        minSySpinBox->setMinimumSize(QSize(50, 30));
        minSySpinBox->setFont(font3);
        minSySpinBox->setMinimum(1);
        minSySpinBox->setMaximum(10);

        sySpinBoxs->addWidget(minSySpinBox);

        maxSySpinBox = new QSpinBox(SymbolsBox);
        maxSySpinBox->setObjectName(QStringLiteral("maxSySpinBox"));
        maxSySpinBox->setMinimumSize(QSize(50, 30));
        maxSySpinBox->setFont(font3);
        maxSySpinBox->setMinimum(1);
        maxSySpinBox->setMaximum(10);

        sySpinBoxs->addWidget(maxSySpinBox);


        horizontalLayout_2->addLayout(sySpinBoxs);

        syLayout = new QHBoxLayout();
        syLayout->setObjectName(QStringLiteral("syLayout"));

        horizontalLayout_2->addLayout(syLayout);

        zSpacer_4 = new QSpacerItem(609, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(zSpacer_4);


        verticalLayout_8->addWidget(SymbolsBox);

        zSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(zSpacer_9);

        tabWidget->addTab(RandomTables, QString());
        RandomTapes = new QWidget();
        RandomTapes->setObjectName(QStringLiteral("RandomTapes"));
        verticalLayout_5 = new QVBoxLayout(RandomTapes);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        TapeNameBox = new QGroupBox(RandomTapes);
        TapeNameBox->setObjectName(QStringLiteral("TapeNameBox"));
        TapeNameBox->setFont(font1);
        horizontalLayout_7 = new QHBoxLayout(TapeNameBox);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        zLabel = new QLabel(TapeNameBox);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setFont(font2);

        horizontalLayout_7->addWidget(zLabel);

        tapeNameEdit = new QLineEdit(TapeNameBox);
        tapeNameEdit->setObjectName(QStringLiteral("tapeNameEdit"));
        tapeNameEdit->setFont(font3);

        horizontalLayout_7->addWidget(tapeNameEdit);

        zLabel_2 = new QLabel(TapeNameBox);
        zLabel_2->setObjectName(QStringLiteral("zLabel_2"));
        zLabel_2->setFont(font2);

        horizontalLayout_7->addWidget(zLabel_2);

        tapeRandSuffix = new QComboBox(TapeNameBox);
        tapeRandSuffix->setObjectName(QStringLiteral("tapeRandSuffix"));
        tapeRandSuffix->setMinimumSize(QSize(80, 0));
        tapeRandSuffix->setMaximumSize(QSize(80, 16777215));
        tapeRandSuffix->setFont(font3);

        horizontalLayout_7->addWidget(tapeRandSuffix);

        zLabel_3 = new QLabel(TapeNameBox);
        zLabel_3->setObjectName(QStringLiteral("zLabel_3"));
        zLabel_3->setFont(font2);

        horizontalLayout_7->addWidget(zLabel_3);


        verticalLayout_5->addWidget(TapeNameBox);

        TapeBox = new QGroupBox(RandomTapes);
        TapeBox->setObjectName(QStringLiteral("TapeBox"));
        TapeBox->setFont(font1);
        horizontalLayout_12 = new QHBoxLayout(TapeBox);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        TapeLabels = new QVBoxLayout();
        TapeLabels->setObjectName(QStringLiteral("TapeLabels"));
        zLabel_7 = new QLabel(TapeBox);
        zLabel_7->setObjectName(QStringLiteral("zLabel_7"));
        zLabel_7->setFont(font2);

        TapeLabels->addWidget(zLabel_7);

        zLabel_6 = new QLabel(TapeBox);
        zLabel_6->setObjectName(QStringLiteral("zLabel_6"));
        zLabel_6->setFont(font2);

        TapeLabels->addWidget(zLabel_6);

        zLabel_5 = new QLabel(TapeBox);
        zLabel_5->setObjectName(QStringLiteral("zLabel_5"));
        zLabel_5->setFont(font2);

        TapeLabels->addWidget(zLabel_5);

        zLabel_4 = new QLabel(TapeBox);
        zLabel_4->setObjectName(QStringLiteral("zLabel_4"));
        zLabel_4->setFont(font2);

        TapeLabels->addWidget(zLabel_4);


        horizontalLayout_12->addLayout(TapeLabels);

        TapeSettings = new QVBoxLayout();
        TapeSettings->setObjectName(QStringLiteral("TapeSettings"));
        zSymLayout = new QHBoxLayout();
        zSymLayout->setObjectName(QStringLiteral("zSymLayout"));
        tapeSySBox = new QSpinBox(TapeBox);
        tapeSySBox->setObjectName(QStringLiteral("tapeSySBox"));
        tapeSySBox->setMinimumSize(QSize(0, 30));
        tapeSySBox->setFont(font3);
        tapeSySBox->setMinimum(1);
        tapeSySBox->setMaximum(10);

        zSymLayout->addWidget(tapeSySBox);

        tapeSyLayout = new QHBoxLayout();
        tapeSyLayout->setObjectName(QStringLiteral("tapeSyLayout"));

        zSymLayout->addLayout(tapeSyLayout);

        zSpacer_5 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zSymLayout->addItem(zSpacer_5);


        TapeSettings->addLayout(zSymLayout);

        MinSize = new QHBoxLayout();
        MinSize->setObjectName(QStringLiteral("MinSize"));
        tapeMinSizeSBox = new QSpinBox(TapeBox);
        tapeMinSizeSBox->setObjectName(QStringLiteral("tapeMinSizeSBox"));
        tapeMinSizeSBox->setMinimumSize(QSize(0, 30));
        tapeMinSizeSBox->setFont(font3);
        tapeMinSizeSBox->setMinimum(3);

        MinSize->addWidget(tapeMinSizeSBox);

        zSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        MinSize->addItem(zSpacer_6);


        TapeSettings->addLayout(MinSize);

        MaxSize = new QHBoxLayout();
        MaxSize->setObjectName(QStringLiteral("MaxSize"));
        tapeMaxSizeSBox = new QSpinBox(TapeBox);
        tapeMaxSizeSBox->setObjectName(QStringLiteral("tapeMaxSizeSBox"));
        tapeMaxSizeSBox->setMinimumSize(QSize(0, 30));
        tapeMaxSizeSBox->setMinimum(3);

        MaxSize->addWidget(tapeMaxSizeSBox);

        zSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        MaxSize->addItem(zSpacer_8);


        TapeSettings->addLayout(MaxSize);

        BlacnkSymbol = new QHBoxLayout();
        BlacnkSymbol->setObjectName(QStringLiteral("BlacnkSymbol"));
        tapeBSymEdit = new QLineEdit(TapeBox);
        tapeBSymEdit->setObjectName(QStringLiteral("tapeBSymEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tapeBSymEdit->sizePolicy().hasHeightForWidth());
        tapeBSymEdit->setSizePolicy(sizePolicy2);
        tapeBSymEdit->setMinimumSize(QSize(45, 30));
        tapeBSymEdit->setMaximumSize(QSize(45, 16777215));
        tapeBSymEdit->setFont(font3);
        tapeBSymEdit->setMaxLength(1);
        tapeBSymEdit->setAlignment(Qt::AlignCenter);

        BlacnkSymbol->addWidget(tapeBSymEdit);

        rBSyCheck = new QCheckBox(TapeBox);
        rBSyCheck->setObjectName(QStringLiteral("rBSyCheck"));
        rBSyCheck->setFont(font5);

        BlacnkSymbol->addWidget(rBSyCheck);

        zSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        BlacnkSymbol->addItem(zSpacer_7);


        TapeSettings->addLayout(BlacnkSymbol);


        horizontalLayout_12->addLayout(TapeSettings);


        verticalLayout_5->addWidget(TapeBox);

        verticalSpacer_3 = new QSpacerItem(20, 267, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        tabWidget->addTab(RandomTapes, QString());
        simulation = new QWidget();
        simulation->setObjectName(QStringLiteral("simulation"));
        verticalLayout_6 = new QVBoxLayout(simulation);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_5 = new QGroupBox(simulation);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setFont(font1);
        horizontalLayout_16 = new QHBoxLayout(groupBox_5);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        horizontalLayout_16->addWidget(label_6);

        concurrentSim = new QSpinBox(groupBox_5);
        concurrentSim->setObjectName(QStringLiteral("concurrentSim"));
        concurrentSim->setMinimum(1);
        concurrentSim->setMaximum(50);
        concurrentSim->setValue(1);

        horizontalLayout_16->addWidget(concurrentSim);

        horizontalSpacer_4 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_4);


        verticalLayout_6->addWidget(groupBox_5);

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
        haltSimSpinBox->setValue(1);

        horizontalLayout_6->addWidget(haltSimSpinBox);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        horizontalLayout_6->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_6->addWidget(groupBox_3);

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
        delaySpinBox->setValue(50);

        horizontalLayout_3->addWidget(delaySpinBox);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(477, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_6->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(simulation);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);

        horizontalLayout_14->addWidget(label);

        simHistSBox = new QSpinBox(groupBox_4);
        simHistSBox->setObjectName(QStringLiteral("simHistSBox"));
        simHistSBox->setMinimum(1);
        simHistSBox->setMaximum(1000);

        horizontalLayout_14->addWidget(simHistSBox);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        horizontalLayout_14->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_14);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        verticalLayout_2->addWidget(label_4);


        verticalLayout_6->addWidget(groupBox_4);

        verticalSpacer_2 = new QSpacerItem(20, 418, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        tabWidget->addTab(simulation, QString());

        horizontalLayout_13->addWidget(tabWidget);

        Settings->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(Settings);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Settings->setStatusBar(statusBar);

        retranslateUi(Settings);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QMainWindow *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "MainWindow", nullptr));
        Usage->setTitle(QApplication::translate("Settings", "Usage", nullptr));
        usageTBrows->setHtml(QApplication::translate("Settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">This program reproduces the behavior of a Turing's Machine in a given tape filled with symbols. It acepts both machine's and tape's configurations as text files. It can also generate, edit and save them with the default configuration.</span></p></body></html>", nullptr));
        MachineConf->setTitle(QApplication::translate("Settings", "Machine's File Configuration", nullptr));
        machineTBrows->setHtml(QApplication::translate("Settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">is: A		 </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// Initial State</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">hs: H		</span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\"> // Halt State</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-"
                        "indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">  *    A    B    C	 </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// vHeader = States</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">  0   1RB  0RC  1LC	 </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// hHeader = Symbols</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">  1   1RH  1RB  1LA	 </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// Ex: 1RB</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e"
                        "7e;\">		 // When the machine is in the state A and the head reads a '0', it will write a '1', move the tape to the right ('R') and jump to the state 'B'</span></p></body></html>", nullptr));
        TapeConf->setTitle(QApplication::translate("Settings", "Tape's File Configuration", nullptr));
        tapeTBrows->setHtml(QApplication::translate("Settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">hp: 4	  </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// Head Position</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">bs: 1	  </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// Blanck Symbol</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-blo"
                        "ck-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">0101011100  </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// Tape Content</span></p></body></html>", nullptr));
        groupBox->setTitle(QApplication::translate("Settings", "Load Machine's Presets", nullptr));
        loadPresetBt->setText(QApplication::translate("Settings", "Load", nullptr));
        defaultSetBt->setText(QApplication::translate("Settings", "Set Default Settings", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Genereal), QApplication::translate("Settings", "General", nullptr));
        TableNameBox->setTitle(QApplication::translate("Settings", "Name Generation", nullptr));
        zNameLabel->setText(QApplication::translate("Settings", "Name Prefix: ", nullptr));
        zPlusLabel->setText(QApplication::translate("Settings", "+", nullptr));
        zIntLabel->setText(QApplication::translate("Settings", "Random integer", nullptr));
        StatesBox->setTitle(QApplication::translate("Settings", "States", nullptr));
        zMinStLabel->setText(QApplication::translate("Settings", "Minimum:", nullptr));
        zMaxStLabel->setText(QApplication::translate("Settings", "Maximum:", nullptr));
        zInStLabel->setText(QApplication::translate("Settings", "Initial State:", nullptr));
        zHltStLabel->setText(QApplication::translate("Settings", "Halt State:", nullptr));
        rInStCheck->setText(QApplication::translate("Settings", "Random", nullptr));
        SymbolsBox->setTitle(QApplication::translate("Settings", "Symbols", nullptr));
        zMinSyLabel->setText(QApplication::translate("Settings", "Minimum:", nullptr));
        zMaxSyLabel->setText(QApplication::translate("Settings", "Maximum:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RandomTables), QApplication::translate("Settings", "Quick Random Tables", nullptr));
        TapeNameBox->setTitle(QApplication::translate("Settings", "Name Generation", nullptr));
        zLabel->setText(QApplication::translate("Settings", "Name Prefix:", nullptr));
        zLabel_2->setText(QApplication::translate("Settings", "+", nullptr));
        zLabel_3->setText(QApplication::translate("Settings", "Random integer", nullptr));
        TapeBox->setTitle(QApplication::translate("Settings", "Tape", nullptr));
        zLabel_7->setText(QApplication::translate("Settings", "Symbols:", nullptr));
        zLabel_6->setText(QApplication::translate("Settings", "Minimum Size:", nullptr));
        zLabel_5->setText(QApplication::translate("Settings", "Maximum Size:", nullptr));
        zLabel_4->setText(QApplication::translate("Settings", "Blanck Symbol:", nullptr));
        rBSyCheck->setText(QApplication::translate("Settings", "Random", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RandomTapes), QApplication::translate("Settings", "Quick Random Tapes", nullptr));
        groupBox_5->setTitle(QApplication::translate("Settings", "Concurrent Simulation", nullptr));
        label_6->setText(QApplication::translate("Settings", "Number of machines that can be simulated simultaneously:", nullptr));
        groupBox_3->setTitle(QApplication::translate("Settings", "Halt Simulation", nullptr));
        haltSimCheck->setText(QApplication::translate("Settings", "Halt Simulation in ", nullptr));
        label_5->setText(QApplication::translate("Settings", "iterations", nullptr));
        groupBox_2->setTitle(QApplication::translate("Settings", "Iteration Delay", nullptr));
        label_2->setText(QApplication::translate("Settings", "Delay between iterations (ms):", nullptr));
        groupBox_4->setTitle(QApplication::translate("Settings", "Simulation History", nullptr));
        label->setText(QApplication::translate("Settings", "Save the previous ", nullptr));
        label_3->setText(QApplication::translate("Settings", "iterations", nullptr));
        label_4->setText(QApplication::translate("Settings", "The higher the number, the slower the simulation will be.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(simulation), QApplication::translate("Settings", "Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
