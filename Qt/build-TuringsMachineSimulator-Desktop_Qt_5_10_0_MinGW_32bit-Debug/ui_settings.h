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
    QWidget *zCentralwidget;
    QHBoxLayout *horizontalLayout_13;
    QTabWidget *tabWidget;
    QWidget *zGenerealLayout;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *zUsageLayout;
    QHBoxLayout *horizontalLayout_8;
    QTextBrowser *usageTBrows;
    QSplitter *generalSplit;
    QGroupBox *zMachineConfLayout;
    QHBoxLayout *horizontalLayout_9;
    QTextBrowser *machineTBrows;
    QGroupBox *zTapeConfLayout;
    QHBoxLayout *horizontalLayout_10;
    QTextBrowser *tapeTBrows;
    QGroupBox *zPresetLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *zPresetChoiceLayout;
    QComboBox *presetsCBox;
    QPushButton *loadPresetBt;
    QSpacerItem *zSpacer_10;
    QTextBrowser *presetDescTBrows;
    QHBoxLayout *zDefaultLayout;
    QSpacerItem *zSpacer_11;
    QPushButton *defaultSetBt;
    QSpacerItem *zSpacer_12;
    QWidget *zRandomMachinesLayout;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *zTableNameBoxLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *zLabel_15;
    QLineEdit *tableNameEdit;
    QLabel *zLabel_16;
    QComboBox *tableRandSuffix;
    QLabel *zLabel_14;
    QGroupBox *zStatesBoxLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *zStLabelsLayout;
    QLabel *zLabel_11;
    QLabel *zLabel_10;
    QLabel *zLabel_9;
    QLabel *zLabel_8;
    QVBoxLayout *zStSettingsLayout;
    QHBoxLayout *zCustomStatesLayout;
    QVBoxLayout *zStSpinBoxsLayout;
    QSpinBox *minStSpinBox;
    QSpinBox *maxStSpinBox;
    QHBoxLayout *stLayout;
    QSpacerItem *zSpacer;
    QHBoxLayout *zInStateLayout;
    QComboBox *inStCBox;
    QCheckBox *rInStCheck;
    QSpacerItem *zSpacer_2;
    QHBoxLayout *zHaltStateLayout;
    QLineEdit *haltStEdit;
    QSpacerItem *zSpacer_3;
    QGroupBox *zSymbolsBoxLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *zSyLabelsLayout;
    QLabel *zLabel_13;
    QLabel *zLabel_12;
    QVBoxLayout *zSySpinBoxsLayout;
    QSpinBox *minSySpinBox;
    QSpinBox *maxSySpinBox;
    QHBoxLayout *syLayout;
    QSpacerItem *zSpacer_4;
    QSpacerItem *zSpacer_9;
    QWidget *zRandomTapesLayout;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *zTapeNameBoxLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *zLabel;
    QLineEdit *tapeNameEdit;
    QLabel *zLabel_2;
    QComboBox *tapeRandSuffix;
    QLabel *zLabel_3;
    QGroupBox *zTapeBoxLayout;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *zTapeLabelsLayout;
    QLabel *zLabel_7;
    QLabel *zLabel_6;
    QLabel *zLabel_5;
    QLabel *zLabel_4;
    QVBoxLayout *zTapeSettingsLayout;
    QHBoxLayout *zSymLayout;
    QSpinBox *tapeSySBox;
    QHBoxLayout *tapeSyLayout;
    QSpacerItem *zSpacer_5;
    QHBoxLayout *zMinSizeLayout;
    QSpinBox *tapeMinSizeSBox;
    QSpacerItem *zSpacer_6;
    QHBoxLayout *zMaxSizeLayout;
    QSpinBox *tapeMaxSizeSBox;
    QSpacerItem *zSpacer_8;
    QHBoxLayout *zBlanckSymbolLayout;
    QLineEdit *tapeBSymEdit;
    QCheckBox *rBSyCheck;
    QSpacerItem *zSpacer_7;
    QSpacerItem *verticalSpacer_3;
    QWidget *zSimulationLayout;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *zConcSimLayout;
    QHBoxLayout *horizontalLayout_16;
    QLabel *zLabel_17;
    QSpinBox *concurrentSim;
    QSpacerItem *zSpacer_14;
    QGroupBox *zHaltSimLayout;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *haltSimCheck;
    QSpinBox *haltSimSpinBox;
    QLabel *zLabel_19;
    QSpacerItem *zSpacer_16;
    QGroupBox *zDelayBoxLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *zDelayLayout;
    QHBoxLayout *zDelayValueLayout;
    QLabel *zLabel_18;
    QSpinBox *delaySpinBox;
    QSpacerItem *zSpacer_15;
    QGroupBox *zSimHistLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *zSimHistValueLayout;
    QLabel *zLabel_20;
    QSpinBox *simHistSBox;
    QLabel *zLabel_21;
    QSpacerItem *zSpacer_17;
    QLabel *zLabel_22;
    QSpacerItem *zSpacer_13;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(854, 599);
        zCentralwidget = new QWidget(Settings);
        zCentralwidget->setObjectName(QStringLiteral("zCentralwidget"));
        horizontalLayout_13 = new QHBoxLayout(zCentralwidget);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        tabWidget = new QTabWidget(zCentralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        zGenerealLayout = new QWidget();
        zGenerealLayout->setObjectName(QStringLiteral("zGenerealLayout"));
        verticalLayout_4 = new QVBoxLayout(zGenerealLayout);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        zUsageLayout = new QGroupBox(zGenerealLayout);
        zUsageLayout->setObjectName(QStringLiteral("zUsageLayout"));
        QFont font1;
        font1.setPointSize(13);
        zUsageLayout->setFont(font1);
        horizontalLayout_8 = new QHBoxLayout(zUsageLayout);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        usageTBrows = new QTextBrowser(zUsageLayout);
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


        verticalLayout_4->addWidget(zUsageLayout);

        generalSplit = new QSplitter(zGenerealLayout);
        generalSplit->setObjectName(QStringLiteral("generalSplit"));
        generalSplit->setOrientation(Qt::Horizontal);
        generalSplit->setHandleWidth(1);
        zMachineConfLayout = new QGroupBox(generalSplit);
        zMachineConfLayout->setObjectName(QStringLiteral("zMachineConfLayout"));
        zMachineConfLayout->setFont(font1);
        horizontalLayout_9 = new QHBoxLayout(zMachineConfLayout);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        machineTBrows = new QTextBrowser(zMachineConfLayout);
        machineTBrows->setObjectName(QStringLiteral("machineTBrows"));
        sizePolicy.setHeightForWidth(machineTBrows->sizePolicy().hasHeightForWidth());
        machineTBrows->setSizePolicy(sizePolicy);
        machineTBrows->setMinimumSize(QSize(460, 155));
        machineTBrows->setMaximumSize(QSize(16777215, 155));

        horizontalLayout_9->addWidget(machineTBrows);

        generalSplit->addWidget(zMachineConfLayout);
        zTapeConfLayout = new QGroupBox(generalSplit);
        zTapeConfLayout->setObjectName(QStringLiteral("zTapeConfLayout"));
        zTapeConfLayout->setFont(font1);
        horizontalLayout_10 = new QHBoxLayout(zTapeConfLayout);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        tapeTBrows = new QTextBrowser(zTapeConfLayout);
        tapeTBrows->setObjectName(QStringLiteral("tapeTBrows"));
        sizePolicy.setHeightForWidth(tapeTBrows->sizePolicy().hasHeightForWidth());
        tapeTBrows->setSizePolicy(sizePolicy);
        tapeTBrows->setMinimumSize(QSize(263, 155));
        tapeTBrows->setMaximumSize(QSize(16777215, 155));

        horizontalLayout_10->addWidget(tapeTBrows);

        generalSplit->addWidget(zTapeConfLayout);

        verticalLayout_4->addWidget(generalSplit);

        zPresetLayout = new QGroupBox(zGenerealLayout);
        zPresetLayout->setObjectName(QStringLiteral("zPresetLayout"));
        zPresetLayout->setFont(font1);
        verticalLayout_3 = new QVBoxLayout(zPresetLayout);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        zPresetChoiceLayout = new QHBoxLayout();
        zPresetChoiceLayout->setObjectName(QStringLiteral("zPresetChoiceLayout"));
        presetsCBox = new QComboBox(zPresetLayout);
        presetsCBox->setObjectName(QStringLiteral("presetsCBox"));
        presetsCBox->setMinimumSize(QSize(180, 0));

        zPresetChoiceLayout->addWidget(presetsCBox);

        loadPresetBt = new QPushButton(zPresetLayout);
        loadPresetBt->setObjectName(QStringLiteral("loadPresetBt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loadPresetBt->sizePolicy().hasHeightForWidth());
        loadPresetBt->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(11);
        loadPresetBt->setFont(font2);

        zPresetChoiceLayout->addWidget(loadPresetBt);

        zSpacer_10 = new QSpacerItem(491, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zPresetChoiceLayout->addItem(zSpacer_10);


        verticalLayout_3->addLayout(zPresetChoiceLayout);

        presetDescTBrows = new QTextBrowser(zPresetLayout);
        presetDescTBrows->setObjectName(QStringLiteral("presetDescTBrows"));
        presetDescTBrows->setMinimumSize(QSize(0, 48));
        presetDescTBrows->setMaximumSize(QSize(16777215, 48));

        verticalLayout_3->addWidget(presetDescTBrows);


        verticalLayout_4->addWidget(zPresetLayout);

        zDefaultLayout = new QHBoxLayout();
        zDefaultLayout->setObjectName(QStringLiteral("zDefaultLayout"));
        zSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zDefaultLayout->addItem(zSpacer_11);

        defaultSetBt = new QPushButton(zGenerealLayout);
        defaultSetBt->setObjectName(QStringLiteral("defaultSetBt"));
        QFont font3;
        font3.setPointSize(12);
        defaultSetBt->setFont(font3);

        zDefaultLayout->addWidget(defaultSetBt);


        verticalLayout_4->addLayout(zDefaultLayout);

        zSpacer_12 = new QSpacerItem(20, 144, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(zSpacer_12);

        tabWidget->addTab(zGenerealLayout, QString());
        zRandomMachinesLayout = new QWidget();
        zRandomMachinesLayout->setObjectName(QStringLiteral("zRandomMachinesLayout"));
        verticalLayout_8 = new QVBoxLayout(zRandomMachinesLayout);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        zTableNameBoxLayout = new QGroupBox(zRandomMachinesLayout);
        zTableNameBoxLayout->setObjectName(QStringLiteral("zTableNameBoxLayout"));
        zTableNameBoxLayout->setFont(font1);
        horizontalLayout = new QHBoxLayout(zTableNameBoxLayout);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        zLabel_15 = new QLabel(zTableNameBoxLayout);
        zLabel_15->setObjectName(QStringLiteral("zLabel_15"));
        zLabel_15->setMaximumSize(QSize(85, 16777215));
        zLabel_15->setFont(font2);

        horizontalLayout->addWidget(zLabel_15);

        tableNameEdit = new QLineEdit(zTableNameBoxLayout);
        tableNameEdit->setObjectName(QStringLiteral("tableNameEdit"));
        tableNameEdit->setFont(font3);

        horizontalLayout->addWidget(tableNameEdit);

        zLabel_16 = new QLabel(zTableNameBoxLayout);
        zLabel_16->setObjectName(QStringLiteral("zLabel_16"));
        zLabel_16->setFont(font2);

        horizontalLayout->addWidget(zLabel_16);

        tableRandSuffix = new QComboBox(zTableNameBoxLayout);
        tableRandSuffix->setObjectName(QStringLiteral("tableRandSuffix"));
        tableRandSuffix->setMinimumSize(QSize(80, 0));
        tableRandSuffix->setMaximumSize(QSize(80, 16777215));
        tableRandSuffix->setFont(font3);

        horizontalLayout->addWidget(tableRandSuffix);

        zLabel_14 = new QLabel(zTableNameBoxLayout);
        zLabel_14->setObjectName(QStringLiteral("zLabel_14"));
        zLabel_14->setFont(font2);

        horizontalLayout->addWidget(zLabel_14);


        verticalLayout_8->addWidget(zTableNameBoxLayout);

        zStatesBoxLayout = new QGroupBox(zRandomMachinesLayout);
        zStatesBoxLayout->setObjectName(QStringLiteral("zStatesBoxLayout"));
        zStatesBoxLayout->setFont(font1);
        horizontalLayout_5 = new QHBoxLayout(zStatesBoxLayout);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        zStLabelsLayout = new QVBoxLayout();
        zStLabelsLayout->setObjectName(QStringLiteral("zStLabelsLayout"));
        zLabel_11 = new QLabel(zStatesBoxLayout);
        zLabel_11->setObjectName(QStringLiteral("zLabel_11"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        zLabel_11->setFont(font4);

        zStLabelsLayout->addWidget(zLabel_11);

        zLabel_10 = new QLabel(zStatesBoxLayout);
        zLabel_10->setObjectName(QStringLiteral("zLabel_10"));
        zLabel_10->setFont(font2);

        zStLabelsLayout->addWidget(zLabel_10);

        zLabel_9 = new QLabel(zStatesBoxLayout);
        zLabel_9->setObjectName(QStringLiteral("zLabel_9"));
        zLabel_9->setFont(font2);

        zStLabelsLayout->addWidget(zLabel_9);

        zLabel_8 = new QLabel(zStatesBoxLayout);
        zLabel_8->setObjectName(QStringLiteral("zLabel_8"));
        zLabel_8->setFont(font2);

        zStLabelsLayout->addWidget(zLabel_8);


        horizontalLayout_5->addLayout(zStLabelsLayout);

        zStSettingsLayout = new QVBoxLayout();
        zStSettingsLayout->setSpacing(6);
        zStSettingsLayout->setObjectName(QStringLiteral("zStSettingsLayout"));
        zCustomStatesLayout = new QHBoxLayout();
        zCustomStatesLayout->setObjectName(QStringLiteral("zCustomStatesLayout"));
        zStSpinBoxsLayout = new QVBoxLayout();
        zStSpinBoxsLayout->setSpacing(6);
        zStSpinBoxsLayout->setObjectName(QStringLiteral("zStSpinBoxsLayout"));
        minStSpinBox = new QSpinBox(zStatesBoxLayout);
        minStSpinBox->setObjectName(QStringLiteral("minStSpinBox"));
        minStSpinBox->setMinimumSize(QSize(50, 30));
        minStSpinBox->setFont(font3);
        minStSpinBox->setMinimum(1);
        minStSpinBox->setMaximum(25);

        zStSpinBoxsLayout->addWidget(minStSpinBox);

        maxStSpinBox = new QSpinBox(zStatesBoxLayout);
        maxStSpinBox->setObjectName(QStringLiteral("maxStSpinBox"));
        maxStSpinBox->setMinimumSize(QSize(50, 30));
        maxStSpinBox->setFont(font3);
        maxStSpinBox->setMinimum(1);
        maxStSpinBox->setMaximum(25);

        zStSpinBoxsLayout->addWidget(maxStSpinBox);


        zCustomStatesLayout->addLayout(zStSpinBoxsLayout);

        stLayout = new QHBoxLayout();
        stLayout->setSpacing(6);
        stLayout->setObjectName(QStringLiteral("stLayout"));

        zCustomStatesLayout->addLayout(stLayout);

        zSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zCustomStatesLayout->addItem(zSpacer);


        zStSettingsLayout->addLayout(zCustomStatesLayout);

        zInStateLayout = new QHBoxLayout();
        zInStateLayout->setObjectName(QStringLiteral("zInStateLayout"));
        inStCBox = new QComboBox(zStatesBoxLayout);
        inStCBox->setObjectName(QStringLiteral("inStCBox"));
        inStCBox->setMinimumSize(QSize(50, 30));
        inStCBox->setMaximumSize(QSize(50, 30));
        inStCBox->setFont(font3);

        zInStateLayout->addWidget(inStCBox);

        rInStCheck = new QCheckBox(zStatesBoxLayout);
        rInStCheck->setObjectName(QStringLiteral("rInStCheck"));
        QFont font5;
        font5.setPointSize(10);
        rInStCheck->setFont(font5);

        zInStateLayout->addWidget(rInStCheck);

        zSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zInStateLayout->addItem(zSpacer_2);


        zStSettingsLayout->addLayout(zInStateLayout);

        zHaltStateLayout = new QHBoxLayout();
        zHaltStateLayout->setObjectName(QStringLiteral("zHaltStateLayout"));
        haltStEdit = new QLineEdit(zStatesBoxLayout);
        haltStEdit->setObjectName(QStringLiteral("haltStEdit"));
        haltStEdit->setMinimumSize(QSize(50, 30));
        haltStEdit->setMaximumSize(QSize(50, 30));
        haltStEdit->setFont(font3);
        haltStEdit->setMaxLength(1);
        haltStEdit->setAlignment(Qt::AlignCenter);

        zHaltStateLayout->addWidget(haltStEdit);

        zSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zHaltStateLayout->addItem(zSpacer_3);


        zStSettingsLayout->addLayout(zHaltStateLayout);


        horizontalLayout_5->addLayout(zStSettingsLayout);


        verticalLayout_8->addWidget(zStatesBoxLayout);

        zSymbolsBoxLayout = new QGroupBox(zRandomMachinesLayout);
        zSymbolsBoxLayout->setObjectName(QStringLiteral("zSymbolsBoxLayout"));
        zSymbolsBoxLayout->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(zSymbolsBoxLayout);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        zSyLabelsLayout = new QVBoxLayout();
        zSyLabelsLayout->setObjectName(QStringLiteral("zSyLabelsLayout"));
        zLabel_13 = new QLabel(zSymbolsBoxLayout);
        zLabel_13->setObjectName(QStringLiteral("zLabel_13"));
        zLabel_13->setFont(font4);

        zSyLabelsLayout->addWidget(zLabel_13);

        zLabel_12 = new QLabel(zSymbolsBoxLayout);
        zLabel_12->setObjectName(QStringLiteral("zLabel_12"));
        zLabel_12->setFont(font2);

        zSyLabelsLayout->addWidget(zLabel_12);


        horizontalLayout_2->addLayout(zSyLabelsLayout);

        zSySpinBoxsLayout = new QVBoxLayout();
        zSySpinBoxsLayout->setObjectName(QStringLiteral("zSySpinBoxsLayout"));
        minSySpinBox = new QSpinBox(zSymbolsBoxLayout);
        minSySpinBox->setObjectName(QStringLiteral("minSySpinBox"));
        minSySpinBox->setMinimumSize(QSize(50, 30));
        minSySpinBox->setFont(font3);
        minSySpinBox->setMinimum(1);
        minSySpinBox->setMaximum(10);

        zSySpinBoxsLayout->addWidget(minSySpinBox);

        maxSySpinBox = new QSpinBox(zSymbolsBoxLayout);
        maxSySpinBox->setObjectName(QStringLiteral("maxSySpinBox"));
        maxSySpinBox->setMinimumSize(QSize(50, 30));
        maxSySpinBox->setFont(font3);
        maxSySpinBox->setMinimum(1);
        maxSySpinBox->setMaximum(10);

        zSySpinBoxsLayout->addWidget(maxSySpinBox);


        horizontalLayout_2->addLayout(zSySpinBoxsLayout);

        syLayout = new QHBoxLayout();
        syLayout->setObjectName(QStringLiteral("syLayout"));

        horizontalLayout_2->addLayout(syLayout);

        zSpacer_4 = new QSpacerItem(609, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(zSpacer_4);


        verticalLayout_8->addWidget(zSymbolsBoxLayout);

        zSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(zSpacer_9);

        tabWidget->addTab(zRandomMachinesLayout, QString());
        zRandomTapesLayout = new QWidget();
        zRandomTapesLayout->setObjectName(QStringLiteral("zRandomTapesLayout"));
        verticalLayout_5 = new QVBoxLayout(zRandomTapesLayout);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        zTapeNameBoxLayout = new QGroupBox(zRandomTapesLayout);
        zTapeNameBoxLayout->setObjectName(QStringLiteral("zTapeNameBoxLayout"));
        zTapeNameBoxLayout->setFont(font1);
        horizontalLayout_7 = new QHBoxLayout(zTapeNameBoxLayout);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        zLabel = new QLabel(zTapeNameBoxLayout);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setFont(font2);

        horizontalLayout_7->addWidget(zLabel);

        tapeNameEdit = new QLineEdit(zTapeNameBoxLayout);
        tapeNameEdit->setObjectName(QStringLiteral("tapeNameEdit"));
        tapeNameEdit->setFont(font3);

        horizontalLayout_7->addWidget(tapeNameEdit);

        zLabel_2 = new QLabel(zTapeNameBoxLayout);
        zLabel_2->setObjectName(QStringLiteral("zLabel_2"));
        zLabel_2->setFont(font2);

        horizontalLayout_7->addWidget(zLabel_2);

        tapeRandSuffix = new QComboBox(zTapeNameBoxLayout);
        tapeRandSuffix->setObjectName(QStringLiteral("tapeRandSuffix"));
        tapeRandSuffix->setMinimumSize(QSize(80, 0));
        tapeRandSuffix->setMaximumSize(QSize(80, 16777215));
        tapeRandSuffix->setFont(font3);

        horizontalLayout_7->addWidget(tapeRandSuffix);

        zLabel_3 = new QLabel(zTapeNameBoxLayout);
        zLabel_3->setObjectName(QStringLiteral("zLabel_3"));
        zLabel_3->setFont(font2);

        horizontalLayout_7->addWidget(zLabel_3);


        verticalLayout_5->addWidget(zTapeNameBoxLayout);

        zTapeBoxLayout = new QGroupBox(zRandomTapesLayout);
        zTapeBoxLayout->setObjectName(QStringLiteral("zTapeBoxLayout"));
        zTapeBoxLayout->setFont(font1);
        horizontalLayout_12 = new QHBoxLayout(zTapeBoxLayout);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        zTapeLabelsLayout = new QVBoxLayout();
        zTapeLabelsLayout->setObjectName(QStringLiteral("zTapeLabelsLayout"));
        zLabel_7 = new QLabel(zTapeBoxLayout);
        zLabel_7->setObjectName(QStringLiteral("zLabel_7"));
        zLabel_7->setFont(font2);

        zTapeLabelsLayout->addWidget(zLabel_7);

        zLabel_6 = new QLabel(zTapeBoxLayout);
        zLabel_6->setObjectName(QStringLiteral("zLabel_6"));
        zLabel_6->setFont(font2);

        zTapeLabelsLayout->addWidget(zLabel_6);

        zLabel_5 = new QLabel(zTapeBoxLayout);
        zLabel_5->setObjectName(QStringLiteral("zLabel_5"));
        zLabel_5->setFont(font2);

        zTapeLabelsLayout->addWidget(zLabel_5);

        zLabel_4 = new QLabel(zTapeBoxLayout);
        zLabel_4->setObjectName(QStringLiteral("zLabel_4"));
        zLabel_4->setFont(font2);

        zTapeLabelsLayout->addWidget(zLabel_4);


        horizontalLayout_12->addLayout(zTapeLabelsLayout);

        zTapeSettingsLayout = new QVBoxLayout();
        zTapeSettingsLayout->setObjectName(QStringLiteral("zTapeSettingsLayout"));
        zSymLayout = new QHBoxLayout();
        zSymLayout->setObjectName(QStringLiteral("zSymLayout"));
        tapeSySBox = new QSpinBox(zTapeBoxLayout);
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


        zTapeSettingsLayout->addLayout(zSymLayout);

        zMinSizeLayout = new QHBoxLayout();
        zMinSizeLayout->setObjectName(QStringLiteral("zMinSizeLayout"));
        tapeMinSizeSBox = new QSpinBox(zTapeBoxLayout);
        tapeMinSizeSBox->setObjectName(QStringLiteral("tapeMinSizeSBox"));
        tapeMinSizeSBox->setMinimumSize(QSize(0, 30));
        tapeMinSizeSBox->setFont(font3);
        tapeMinSizeSBox->setMinimum(3);

        zMinSizeLayout->addWidget(tapeMinSizeSBox);

        zSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zMinSizeLayout->addItem(zSpacer_6);


        zTapeSettingsLayout->addLayout(zMinSizeLayout);

        zMaxSizeLayout = new QHBoxLayout();
        zMaxSizeLayout->setObjectName(QStringLiteral("zMaxSizeLayout"));
        tapeMaxSizeSBox = new QSpinBox(zTapeBoxLayout);
        tapeMaxSizeSBox->setObjectName(QStringLiteral("tapeMaxSizeSBox"));
        tapeMaxSizeSBox->setMinimumSize(QSize(0, 30));
        tapeMaxSizeSBox->setMinimum(3);

        zMaxSizeLayout->addWidget(tapeMaxSizeSBox);

        zSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zMaxSizeLayout->addItem(zSpacer_8);


        zTapeSettingsLayout->addLayout(zMaxSizeLayout);

        zBlanckSymbolLayout = new QHBoxLayout();
        zBlanckSymbolLayout->setObjectName(QStringLiteral("zBlanckSymbolLayout"));
        tapeBSymEdit = new QLineEdit(zTapeBoxLayout);
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

        zBlanckSymbolLayout->addWidget(tapeBSymEdit);

        rBSyCheck = new QCheckBox(zTapeBoxLayout);
        rBSyCheck->setObjectName(QStringLiteral("rBSyCheck"));
        rBSyCheck->setFont(font5);

        zBlanckSymbolLayout->addWidget(rBSyCheck);

        zSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zBlanckSymbolLayout->addItem(zSpacer_7);


        zTapeSettingsLayout->addLayout(zBlanckSymbolLayout);


        horizontalLayout_12->addLayout(zTapeSettingsLayout);


        verticalLayout_5->addWidget(zTapeBoxLayout);

        verticalSpacer_3 = new QSpacerItem(20, 267, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        tabWidget->addTab(zRandomTapesLayout, QString());
        zSimulationLayout = new QWidget();
        zSimulationLayout->setObjectName(QStringLiteral("zSimulationLayout"));
        verticalLayout_6 = new QVBoxLayout(zSimulationLayout);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        zConcSimLayout = new QGroupBox(zSimulationLayout);
        zConcSimLayout->setObjectName(QStringLiteral("zConcSimLayout"));
        zConcSimLayout->setFont(font1);
        horizontalLayout_16 = new QHBoxLayout(zConcSimLayout);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        zLabel_17 = new QLabel(zConcSimLayout);
        zLabel_17->setObjectName(QStringLiteral("zLabel_17"));
        zLabel_17->setFont(font2);

        horizontalLayout_16->addWidget(zLabel_17);

        concurrentSim = new QSpinBox(zConcSimLayout);
        concurrentSim->setObjectName(QStringLiteral("concurrentSim"));
        concurrentSim->setMinimum(1);
        concurrentSim->setMaximum(50);
        concurrentSim->setValue(1);

        horizontalLayout_16->addWidget(concurrentSim);

        zSpacer_14 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(zSpacer_14);


        verticalLayout_6->addWidget(zConcSimLayout);

        zHaltSimLayout = new QGroupBox(zSimulationLayout);
        zHaltSimLayout->setObjectName(QStringLiteral("zHaltSimLayout"));
        zHaltSimLayout->setFont(font1);
        horizontalLayout_6 = new QHBoxLayout(zHaltSimLayout);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        haltSimCheck = new QCheckBox(zHaltSimLayout);
        haltSimCheck->setObjectName(QStringLiteral("haltSimCheck"));
        haltSimCheck->setFont(font2);

        horizontalLayout_6->addWidget(haltSimCheck);

        haltSimSpinBox = new QSpinBox(zHaltSimLayout);
        haltSimSpinBox->setObjectName(QStringLiteral("haltSimSpinBox"));
        haltSimSpinBox->setMinimum(1);
        haltSimSpinBox->setMaximum(10000000);
        haltSimSpinBox->setValue(1);

        horizontalLayout_6->addWidget(haltSimSpinBox);

        zLabel_19 = new QLabel(zHaltSimLayout);
        zLabel_19->setObjectName(QStringLiteral("zLabel_19"));
        zLabel_19->setFont(font2);

        horizontalLayout_6->addWidget(zLabel_19);

        zSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(zSpacer_16);


        verticalLayout_6->addWidget(zHaltSimLayout);

        zDelayBoxLayout = new QGroupBox(zSimulationLayout);
        zDelayBoxLayout->setObjectName(QStringLiteral("zDelayBoxLayout"));
        zDelayBoxLayout->setFont(font1);
        horizontalLayout_4 = new QHBoxLayout(zDelayBoxLayout);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        zDelayLayout = new QVBoxLayout();
        zDelayLayout->setObjectName(QStringLiteral("zDelayLayout"));
        zDelayValueLayout = new QHBoxLayout();
        zDelayValueLayout->setObjectName(QStringLiteral("zDelayValueLayout"));
        zLabel_18 = new QLabel(zDelayBoxLayout);
        zLabel_18->setObjectName(QStringLiteral("zLabel_18"));
        zLabel_18->setFont(font2);

        zDelayValueLayout->addWidget(zLabel_18);

        delaySpinBox = new QSpinBox(zDelayBoxLayout);
        delaySpinBox->setObjectName(QStringLiteral("delaySpinBox"));
        delaySpinBox->setMinimum(50);
        delaySpinBox->setMaximum(1000000);
        delaySpinBox->setSingleStep(50);
        delaySpinBox->setValue(50);

        zDelayValueLayout->addWidget(delaySpinBox);


        zDelayLayout->addLayout(zDelayValueLayout);


        horizontalLayout_4->addLayout(zDelayLayout);

        zSpacer_15 = new QSpacerItem(477, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(zSpacer_15);


        verticalLayout_6->addWidget(zDelayBoxLayout);

        zSimHistLayout = new QGroupBox(zSimulationLayout);
        zSimHistLayout->setObjectName(QStringLiteral("zSimHistLayout"));
        zSimHistLayout->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(zSimHistLayout);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        zSimHistValueLayout = new QHBoxLayout();
        zSimHistValueLayout->setObjectName(QStringLiteral("zSimHistValueLayout"));
        zLabel_20 = new QLabel(zSimHistLayout);
        zLabel_20->setObjectName(QStringLiteral("zLabel_20"));
        zLabel_20->setFont(font2);

        zSimHistValueLayout->addWidget(zLabel_20);

        simHistSBox = new QSpinBox(zSimHistLayout);
        simHistSBox->setObjectName(QStringLiteral("simHistSBox"));
        simHistSBox->setMinimum(1);
        simHistSBox->setMaximum(1000);

        zSimHistValueLayout->addWidget(simHistSBox);

        zLabel_21 = new QLabel(zSimHistLayout);
        zLabel_21->setObjectName(QStringLiteral("zLabel_21"));
        zLabel_21->setFont(font2);

        zSimHistValueLayout->addWidget(zLabel_21);

        zSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zSimHistValueLayout->addItem(zSpacer_17);


        verticalLayout_2->addLayout(zSimHistValueLayout);

        zLabel_22 = new QLabel(zSimHistLayout);
        zLabel_22->setObjectName(QStringLiteral("zLabel_22"));
        zLabel_22->setFont(font2);

        verticalLayout_2->addWidget(zLabel_22);


        verticalLayout_6->addWidget(zSimHistLayout);

        zSpacer_13 = new QSpacerItem(20, 418, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(zSpacer_13);

        tabWidget->addTab(zSimulationLayout, QString());

        horizontalLayout_13->addWidget(tabWidget);

        Settings->setCentralWidget(zCentralwidget);
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
        zUsageLayout->setTitle(QApplication::translate("Settings", "Usage", nullptr));
        usageTBrows->setHtml(QApplication::translate("Settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">This program reproduces the behavior of a Turing's Machine in a given tape filled with symbols. It acepts both machine's and tape's configurations as text files. It can also generate, edit and save them with the default configuration.</span></p></body></html>", nullptr));
        zMachineConfLayout->setTitle(QApplication::translate("Settings", "Machine's File Configuration", nullptr));
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
        zTapeConfLayout->setTitle(QApplication::translate("Settings", "Tape's File Configuration", nullptr));
        tapeTBrows->setHtml(QApplication::translate("Settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">hp: 4	  </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// Head Position</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">bs: 1	  </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// Blanck Symbol</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-blo"
                        "ck-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas'; font-size:11pt;\">0101011100  </span><span style=\" font-family:'Consolas'; font-size:11pt; color:#7e7e7e;\">// Tape Content</span></p></body></html>", nullptr));
        zPresetLayout->setTitle(QApplication::translate("Settings", "Load Machine's Presets", nullptr));
        loadPresetBt->setText(QApplication::translate("Settings", "Load", nullptr));
        defaultSetBt->setText(QApplication::translate("Settings", "Set Default Settings", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(zGenerealLayout), QApplication::translate("Settings", "General", nullptr));
        zTableNameBoxLayout->setTitle(QApplication::translate("Settings", "Name Generation", nullptr));
        zLabel_15->setText(QApplication::translate("Settings", "Name Prefix: ", nullptr));
        zLabel_16->setText(QApplication::translate("Settings", "+", nullptr));
        zLabel_14->setText(QApplication::translate("Settings", "Random integer", nullptr));
        zStatesBoxLayout->setTitle(QApplication::translate("Settings", "States", nullptr));
        zLabel_11->setText(QApplication::translate("Settings", "Minimum:", nullptr));
        zLabel_10->setText(QApplication::translate("Settings", "Maximum:", nullptr));
        zLabel_9->setText(QApplication::translate("Settings", "Initial State:", nullptr));
        zLabel_8->setText(QApplication::translate("Settings", "Halt State:", nullptr));
        rInStCheck->setText(QApplication::translate("Settings", "Random", nullptr));
        zSymbolsBoxLayout->setTitle(QApplication::translate("Settings", "Symbols", nullptr));
        zLabel_13->setText(QApplication::translate("Settings", "Minimum:", nullptr));
        zLabel_12->setText(QApplication::translate("Settings", "Maximum:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(zRandomMachinesLayout), QApplication::translate("Settings", "Quick Random Machines", nullptr));
        zTapeNameBoxLayout->setTitle(QApplication::translate("Settings", "Name Generation", nullptr));
        zLabel->setText(QApplication::translate("Settings", "Name Prefix:", nullptr));
        zLabel_2->setText(QApplication::translate("Settings", "+", nullptr));
        zLabel_3->setText(QApplication::translate("Settings", "Random integer", nullptr));
        zTapeBoxLayout->setTitle(QApplication::translate("Settings", "Tape", nullptr));
        zLabel_7->setText(QApplication::translate("Settings", "Symbols:", nullptr));
        zLabel_6->setText(QApplication::translate("Settings", "Minimum Size:", nullptr));
        zLabel_5->setText(QApplication::translate("Settings", "Maximum Size:", nullptr));
        zLabel_4->setText(QApplication::translate("Settings", "Blanck Symbol:", nullptr));
        rBSyCheck->setText(QApplication::translate("Settings", "Random", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(zRandomTapesLayout), QApplication::translate("Settings", "Quick Random Tapes", nullptr));
        zConcSimLayout->setTitle(QApplication::translate("Settings", "Concurrent Simulation", nullptr));
        zLabel_17->setText(QApplication::translate("Settings", "Number of machines that can be simulated simultaneously:", nullptr));
        zHaltSimLayout->setTitle(QApplication::translate("Settings", "Halt Simulation", nullptr));
        haltSimCheck->setText(QApplication::translate("Settings", "Halt Simulation in ", nullptr));
        zLabel_19->setText(QApplication::translate("Settings", "iterations", nullptr));
        zDelayBoxLayout->setTitle(QApplication::translate("Settings", "Iteration Delay", nullptr));
        zLabel_18->setText(QApplication::translate("Settings", "Delay between iterations (ms):", nullptr));
        zSimHistLayout->setTitle(QApplication::translate("Settings", "Simulation History", nullptr));
        zLabel_20->setText(QApplication::translate("Settings", "Save the previous ", nullptr));
        zLabel_21->setText(QApplication::translate("Settings", "iterations", nullptr));
        zLabel_22->setText(QApplication::translate("Settings", "The higher the number, the slower the simulation will be.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(zSimulationLayout), QApplication::translate("Settings", "Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
