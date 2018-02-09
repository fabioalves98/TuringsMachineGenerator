/********************************************************************************
** Form generated from reading UI file 'randommachines.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMMACHINES_H
#define UI_RANDOMMACHINES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomMachines
{
public:
    QWidget *zCentralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *zSettingsLayout;
    QVBoxLayout *zLabelsLayout;
    QHBoxLayout *zNameLayout;
    QLabel *zLabel;
    QHBoxLayout *zStatesLayout;
    QLabel *zLabel_2;
    QLabel *zLabel_3;
    QVBoxLayout *zValuesLayout;
    QTextEdit *nameEdit;
    QHBoxLayout *zStsValueLayout;
    QSpinBox *stSel;
    QHBoxLayout *stLayout;
    QSpacerItem *zSpacer;
    QHBoxLayout *zSyValueLayout;
    QSpinBox *sySel;
    QHBoxLayout *syLayout;
    QSpacerItem *zSpacer_2;
    QVBoxLayout *zStateLayout;
    QLabel *zLabel_4;
    QLabel *zLabel_5;
    QSpacerItem *zSpacer_3;
    QVBoxLayout *zStValueLayout;
    QComboBox *initStCBox;
    QLineEdit *haltStEdit;
    QSpacerItem *zSpacer_4;
    QTableWidget *randTable;
    QHBoxLayout *zButtonLayout;
    QPushButton *randBut;
    QPushButton *saveBut;

    void setupUi(QMainWindow *RandomMachines)
    {
        if (RandomMachines->objectName().isEmpty())
            RandomMachines->setObjectName(QStringLiteral("RandomMachines"));
        RandomMachines->resize(800, 567);
        zCentralwidget = new QWidget(RandomMachines);
        zCentralwidget->setObjectName(QStringLiteral("zCentralwidget"));
        verticalLayout_5 = new QVBoxLayout(zCentralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        zSettingsLayout = new QHBoxLayout();
        zSettingsLayout->setObjectName(QStringLiteral("zSettingsLayout"));
        zLabelsLayout = new QVBoxLayout();
        zLabelsLayout->setObjectName(QStringLiteral("zLabelsLayout"));
        zNameLayout = new QHBoxLayout();
        zNameLayout->setObjectName(QStringLiteral("zNameLayout"));
        zLabel = new QLabel(zCentralwidget);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(14);
        zLabel->setFont(font);
        zLabel->setFrameShape(QFrame::Panel);
        zLabel->setFrameShadow(QFrame::Raised);

        zNameLayout->addWidget(zLabel);


        zLabelsLayout->addLayout(zNameLayout);

        zStatesLayout = new QHBoxLayout();
        zStatesLayout->setObjectName(QStringLiteral("zStatesLayout"));
        zLabel_2 = new QLabel(zCentralwidget);
        zLabel_2->setObjectName(QStringLiteral("zLabel_2"));
        zLabel_2->setMaximumSize(QSize(16777215, 16777215));
        zLabel_2->setFont(font);
        zLabel_2->setFrameShape(QFrame::Panel);
        zLabel_2->setFrameShadow(QFrame::Raised);

        zStatesLayout->addWidget(zLabel_2);


        zLabelsLayout->addLayout(zStatesLayout);

        zLabel_3 = new QLabel(zCentralwidget);
        zLabel_3->setObjectName(QStringLiteral("zLabel_3"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(zLabel_3->sizePolicy().hasHeightForWidth());
        zLabel_3->setSizePolicy(sizePolicy);
        zLabel_3->setMaximumSize(QSize(16777215, 16777215));
        zLabel_3->setFont(font);
        zLabel_3->setFrameShape(QFrame::Panel);
        zLabel_3->setFrameShadow(QFrame::Raised);

        zLabelsLayout->addWidget(zLabel_3);


        zSettingsLayout->addLayout(zLabelsLayout);

        zValuesLayout = new QVBoxLayout();
        zValuesLayout->setObjectName(QStringLiteral("zValuesLayout"));
        nameEdit = new QTextEdit(zCentralwidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setMaximumSize(QSize(16777215, 27));

        zValuesLayout->addWidget(nameEdit);

        zStsValueLayout = new QHBoxLayout();
        zStsValueLayout->setObjectName(QStringLiteral("zStsValueLayout"));
        stSel = new QSpinBox(zCentralwidget);
        stSel->setObjectName(QStringLiteral("stSel"));
        stSel->setMaximumSize(QSize(46, 26));
        QFont font1;
        font1.setPointSize(10);
        stSel->setFont(font1);
        stSel->setMaximum(25);

        zStsValueLayout->addWidget(stSel);

        stLayout = new QHBoxLayout();
        stLayout->setObjectName(QStringLiteral("stLayout"));

        zStsValueLayout->addLayout(stLayout);

        zSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zStsValueLayout->addItem(zSpacer);


        zValuesLayout->addLayout(zStsValueLayout);

        zSyValueLayout = new QHBoxLayout();
        zSyValueLayout->setObjectName(QStringLiteral("zSyValueLayout"));
        sySel = new QSpinBox(zCentralwidget);
        sySel->setObjectName(QStringLiteral("sySel"));
        sySel->setMaximumSize(QSize(46, 26));
        sySel->setFont(font1);
        sySel->setMaximum(10);

        zSyValueLayout->addWidget(sySel);

        syLayout = new QHBoxLayout();
        syLayout->setObjectName(QStringLiteral("syLayout"));

        zSyValueLayout->addLayout(syLayout);

        zSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zSyValueLayout->addItem(zSpacer_2);


        zValuesLayout->addLayout(zSyValueLayout);


        zSettingsLayout->addLayout(zValuesLayout);

        zStateLayout = new QVBoxLayout();
        zStateLayout->setObjectName(QStringLiteral("zStateLayout"));
        zLabel_4 = new QLabel(zCentralwidget);
        zLabel_4->setObjectName(QStringLiteral("zLabel_4"));
        zLabel_4->setMinimumSize(QSize(0, 26));
        zLabel_4->setMaximumSize(QSize(16777215, 16777215));
        zLabel_4->setFont(font);
        zLabel_4->setFrameShape(QFrame::Panel);
        zLabel_4->setFrameShadow(QFrame::Raised);
        zLabel_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        zStateLayout->addWidget(zLabel_4);

        zLabel_5 = new QLabel(zCentralwidget);
        zLabel_5->setObjectName(QStringLiteral("zLabel_5"));
        zLabel_5->setMinimumSize(QSize(0, 26));
        zLabel_5->setMaximumSize(QSize(16777215, 16777215));
        zLabel_5->setFont(font);
        zLabel_5->setFrameShape(QFrame::Panel);
        zLabel_5->setFrameShadow(QFrame::Raised);
        zLabel_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        zStateLayout->addWidget(zLabel_5);

        zSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        zStateLayout->addItem(zSpacer_3);


        zSettingsLayout->addLayout(zStateLayout);

        zStValueLayout = new QVBoxLayout();
        zStValueLayout->setObjectName(QStringLiteral("zStValueLayout"));
        initStCBox = new QComboBox(zCentralwidget);
        initStCBox->setObjectName(QStringLiteral("initStCBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(initStCBox->sizePolicy().hasHeightForWidth());
        initStCBox->setSizePolicy(sizePolicy1);
        initStCBox->setMinimumSize(QSize(40, 26));
        initStCBox->setMaximumSize(QSize(16777215, 16777215));
        initStCBox->setFont(font1);

        zStValueLayout->addWidget(initStCBox);

        haltStEdit = new QLineEdit(zCentralwidget);
        haltStEdit->setObjectName(QStringLiteral("haltStEdit"));
        sizePolicy1.setHeightForWidth(haltStEdit->sizePolicy().hasHeightForWidth());
        haltStEdit->setSizePolicy(sizePolicy1);
        haltStEdit->setMinimumSize(QSize(40, 26));
        haltStEdit->setMaximumSize(QSize(16777215, 16777215));
        haltStEdit->setFont(font1);
        haltStEdit->setAlignment(Qt::AlignCenter);

        zStValueLayout->addWidget(haltStEdit);

        zSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        zStValueLayout->addItem(zSpacer_4);


        zSettingsLayout->addLayout(zStValueLayout);


        verticalLayout_5->addLayout(zSettingsLayout);

        randTable = new QTableWidget(zCentralwidget);
        randTable->setObjectName(QStringLiteral("randTable"));

        verticalLayout_5->addWidget(randTable);

        zButtonLayout = new QHBoxLayout();
        zButtonLayout->setObjectName(QStringLiteral("zButtonLayout"));
        randBut = new QPushButton(zCentralwidget);
        randBut->setObjectName(QStringLiteral("randBut"));
        QFont font2;
        font2.setPointSize(12);
        randBut->setFont(font2);

        zButtonLayout->addWidget(randBut);

        saveBut = new QPushButton(zCentralwidget);
        saveBut->setObjectName(QStringLiteral("saveBut"));
        saveBut->setFont(font2);

        zButtonLayout->addWidget(saveBut);


        verticalLayout_5->addLayout(zButtonLayout);

        RandomMachines->setCentralWidget(zCentralwidget);

        retranslateUi(RandomMachines);

        QMetaObject::connectSlotsByName(RandomMachines);
    } // setupUi

    void retranslateUi(QMainWindow *RandomMachines)
    {
        RandomMachines->setWindowTitle(QApplication::translate("RandomMachines", "MainWindow", nullptr));
        zLabel->setText(QApplication::translate("RandomMachines", "Name", nullptr));
        zLabel_2->setText(QApplication::translate("RandomMachines", "States", nullptr));
        zLabel_3->setText(QApplication::translate("RandomMachines", "Symbols", nullptr));
        zLabel_4->setText(QApplication::translate("RandomMachines", "Initial State", nullptr));
        zLabel_5->setText(QApplication::translate("RandomMachines", "Halt State", nullptr));
        haltStEdit->setPlaceholderText(QApplication::translate("RandomMachines", "H", nullptr));
        randBut->setText(QApplication::translate("RandomMachines", "Random", nullptr));
        saveBut->setText(QApplication::translate("RandomMachines", "Save Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RandomMachines: public Ui_RandomMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMMACHINES_H
